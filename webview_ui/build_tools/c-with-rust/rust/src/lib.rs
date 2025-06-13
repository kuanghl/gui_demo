use std::ffi::{CStr, CString};
use std::fs::File;
use std::io::Read;
use std::os::raw::c_char;
use serde_json::Value;
use libc::c_int;

// Rust 结构体（对应 C 的 "JSON 解析器对象"）
#[repr(C)]
pub struct JsonParser {
    data: Value,  // 存储解析后的 JSON 数据
}

impl JsonParser {
    // 从文件加载 JSON
    fn from_file(path: &str) -> Result<Self, String> {
        let mut file = File::open(path).map_err(|e| e.to_string())?;
        let mut content = String::new();
        file.read_to_string(&mut content).map_err(|e| e.to_string())?;
        let data: Value = serde_json::from_str(&content).map_err(|e| e.to_string())?;
        Ok(JsonParser { data })
    }

    // 获取 JSON 字段值（字符串类型）
    fn get_string(&self, key: &str) -> Option<String> {
        self.data.get(key).and_then(|v| v.as_str()).map(|s| s.to_string())
    }
}

// 暴露给 C 的接口函数
#[unsafe(no_mangle)]
pub extern "C" fn json_parser_new(path: *const c_char) -> *mut JsonParser {
    let path_str = unsafe { CStr::from_ptr(path).to_str().unwrap() };
    match JsonParser::from_file(path_str) {
        Ok(parser) => Box::into_raw(Box::new(parser)),
        Err(_) => std::ptr::null_mut(), // 返回空指针表示失败
    }
}

#[unsafe(no_mangle)]
pub extern "C" fn json_parser_get_string(
    handle: *mut JsonParser,
    key: *const c_char,
    output: *mut c_char,
    output_len: usize,
) -> c_int {
    let parser = unsafe { &*handle };
    let key_str = unsafe { CStr::from_ptr(key).to_str().unwrap() };
    if let Some(s) = parser.get_string(key_str) {
        let c_string = CString::new(s).unwrap();
        let bytes = c_string.as_bytes_with_nul();
        if bytes.len() <= output_len {
            unsafe {
                std::ptr::copy_nonoverlapping(bytes.as_ptr(), output as *mut u8, bytes.len());
            }
            return 0; // 成功
        }
    }
    -1 // 失败
}

#[unsafe(no_mangle)]
pub extern "C" fn json_parser_free(handle: *mut JsonParser) {
    unsafe { drop(Box::from_raw(handle)) }; // 显式释放内存
}