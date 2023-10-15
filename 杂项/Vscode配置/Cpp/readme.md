## 说明  
+ 本文件夹为基本的VScode中的cpp配置文件，下面将给出一些细则  
### 使用说明  
>配置文件在使用时受限于工作区文件，需要做出一些修改（由于在配置之初用的是绝对路径，所以对应的地方也需要修改为绝对路径，但仍有别的办法无需麻烦，这些技巧且由读者自学，os：或者哪天我想修了）  
>>1. 将launch.json中的"preLaunchTask"标签后的内容保证与task.json中的"label"后内容保持一致
>>2. 注意将launch.json中的"miDebuggerPath"中路径改为编译器GCC的绝对路径，下为示例
```cpp
"miDebuggerPath": "c:\\GCC\\mingw64\\bin\\gdb.exe"
```
>>3. 注意c_cpp_properties.json中的"compilerPath"与tasks.json中的"command"与"detail"中的部分内容应保持一致且为准确的编译器地址，示例如下：
```cpp
"compilerPath": "C:\\GCC\\mingw64\\bin\\gcc.exe"
"command": "C:\\GCC\\mingw64\\bin\\g++.exe"
"detail": "编译器: C:\\GCC\\mingw64\\bin\\g++.exe"
```
