### 1.[OpenGL](https://so.csdn.net/so/search?q=OpenGL&spm=1001.2101.3001.7020)总览

  
OpenGL只有框架没有实现，换句话说就是OpenGL只有函数声明没有源文件实现，类似于接口和虚函数。所有的实现是显卡生产商提供。比如NVIDIA或者AMD就要自己实现OpenGL函数内容，所以不同的生产商可以对自己的产品提供优化，毕竟代码是自己写的。

OpenGL函数库相关的API有核心库(gl)，实用库(glu)，辅助库(aux)、实用工具库(glut)，窗口库(glx、agl、wgl)和扩展函数库等。gl是核心，glu是对gl的部分封装。glx、agl、wgl 是针对不同窗口系统的函数。glut是为跨平台的OpenGL程序的工具包，比aux功能强大（aux很大程度上已经被glut库取代）。扩展函数库是硬件厂商为实现硬件更新利用OpenGL的扩展机制开发的函数。

https://opengl.org/

### 2.gult

  
OpenGL Utility Toolkit

https://www.opengl.org/resources/libraries/glut/glut\_downloads.php

里面有32位的库文件下载，glutdlls37beta.zip，但是版本太老了，理应被时代淘汰，不推荐使用。gult最后版本v3.7beta的历史可追溯至1998年8月，且该项目已经被废弃。它的许可证禁止任何人发布修改后的库代码。

这部分函数以glut开头，主要包括窗口操作函数，窗口初始化、窗口大小、窗口位置等函数；回调函数：响应刷新消息、键盘消息、鼠标消息、定时器函数等；创建复杂的三维物体；菜单函数；程序运行函数。gult对应的开源实现是freegult。

### 3.freeglut

  
FreeGLUT is a free-software/open-source alternative to the OpenGL Utility Toolkit (GLUT) library

因为OpenGL没有窗口管理的功能，所以很多热心的人写了工具来支持这些功能，比如早期的glut，现在的freeglut等。

freeglut完全兼容glut，是glut的代替品，开源，功能齐全。目前来看，freeglut 3.0版本比其它版本稳定，推荐使用。帕维尔在1999年12月1日开始freeglut的开发。目前，该项目几乎可以100%的替代原来的GLUT，只有少数差别（如，the abandonment of SGI-specific features，按钮盒子和动态视频分辨率）和 其他一小部分程序Bug。

http://freeglut.sourceforge.net/

### 4.glew

  
The OpenGL Extension Wrangler Library

glut或者freegult主要是OpenGL 1.0的基本函数功能；glew是使用OpenGL 2.0之后的一个工具函数。

不同的显卡公司，也会发布一些只有自家显卡才支持的扩展函数，你要想用这数涵数，不得不去寻找最新的glext.h,有了GLEW扩展库，你就再也不用为找不到函数的接口而烦恼，因为GLEW能自动识别你的平台所支持的全部OpenGL高级扩展函数。也就是说，只要包含一个glew.h头文件，你就能使用gl,glu,glext,wgl,glx的全部函数。

glew包含了OpenGL所需的核心。前面已经说过openGL的实现是显卡生产商，那么系统如何才能找到这些实现好的函数呢？而且不同的平台函数存放地方还不同，文件结构也不同。有没有一种方式能够自动找到OpenGL的函数？这就是glew的作用：用来找openGL的函数，并初始化，这样我们就能直接调用OpenGL的函数了。  
http://glew.sourceforge.net/

### 5.glfw

  
glfw is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop. It provides a simple API for creating windows, contexts and surfaces, receiving input and events.

glfw无愧于其号称的lightweight的OpenGL框架，的确是除了跨平台必要做的事情都没有做，所以一个头文件，很少量的API，就完成了任务。glfw的开发目的是用于替代glut的。它是一个轻量级的，开源的，跨平台的library。支持OpenGL及OpenGL ES，用来管理窗口，读取输入，处理事件等。

那么glfw有何优势呢？glut太老了，最后一个版本还是90年代的。freeglut完全兼容glut，算是glut的代替品，功能齐全，但是bug太多。稳定性也不好（不是我说的啊），glfw应运而生。

总之，glfw是glut/freegult的升级和改进。glfw是用来显示窗口和捕捉窗口事件的一套API，可以理解成Qt和windows平台的WPF。OpenGL只是一套控制GPU的规则，并没有对于跨平台窗口显示和事件进行规定，所以需要一个显示显卡渲染的窗口，这就是glfw的作用。

https://www.glfw.org/

### 6.glad

  
Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator

glad是继gl3w，glew之后，当前最新的用来访问OpenGL规范接口的第三方库。简单说glad是glew的升级版，就是说glew比较老，glad比较新。

https://glad.dav1d.de/

### 7.结论与项目使用

  
窗口管理  
老产品：glut/freeglut  
替代品：glfw

函数加载  
老产品：glew  
替代品：glad

项目开发，通常有三种组合  
(1)freeglut+glew

(2)glfw+glew

(3)glfw+glad

![](https://i-blog.csdnimg.cn/blog_migrate/a3bdb41c5615d3056e98c89064c74ffe.png)

### x1.源码和库下载

  
https://download.csdn.net/download/libaineu2004/12402662

更多的详情请访问我的另一篇博文：

https://libaineu2004.blog.csdn.net/article/details/105308235

### x2.参考文献

  
学习教程  
https://learnopengl-cn.github.io/ ++ https://learnopengl.com/

https://github.com/JoeyDeVries/LearnOpenGL ++ https://github.com/JoeyDeVries/Cell

http://www.opengl-tutorial.org/ ++ https://github.com/opengl-tutorials/ogl

OpenGL超级宝典visual studio 2013开发环境配置 GLTools  
http://www.it165.net/pro/html/201504/38164.html

OpenGL+VS2017 环境配置(亲测好使)  
https://blog.csdn.net/AvatarForTest/article/details/79199807

《OpenGL编程指南》  
红宝书，Khronos小组编写的OpenGL官方权威指南

《OpenGL超级宝典》  
蓝宝书，配套源码使用的是freeglut+glew

### OpenGL GUI

  
NanoGUI 是基于opengl以及GLFW，GLAD，NanoVG，Eigen这些库形成的一个可视化GUI库，在窗口的设计上非常的简约，程序使用上也非常的方便。

https://github.com/wjakob/nanogui

https://github.com/memononen/NanoVG

https://nanogui.readthedocs.io/en/latest/

### libqglviewer

  
libQGLViewer 是一个用以简化了Qt开发OpenGL三维浏览器的C++库。它提供了一些典型的3D查看器的功能，如能够移动相机使用鼠标。

http://libqglviewer.com/

https://github.com/GillesDebunne/libQGLViewer

[参考2](https://blog.csdn.net/libaineu2004/article/details/105879521)

[参考1](https://blog.csdn.net/qq_40565033/article/details/107715956?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242)
