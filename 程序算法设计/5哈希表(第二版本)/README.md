# 通讯录查询系统
## 使用方法
在本实验中，我封装好暴露给外部接口一共有如下:
```cpp
phone_dir();
bool add(phone_dir_page new_page);
bool erase(string phon_number);
bool revise(string phone_number, phone_dir_page new_page);
int find(string phone_number);
bool print();
bool load(string file_name);
bool out(string file_name);
bool clear();
bool display(string phone_bumber);
```
这些接口均是类phone_dir中的方法，见名知意<br>
若是不想自己调用，可以选择使用gui.cpp中home函数，那里是已经写好的GUI，但是**并没有对错误进行处理**
