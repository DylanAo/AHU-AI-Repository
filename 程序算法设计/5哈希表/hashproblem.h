#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
/*
enum sexmode{
    Male,
    Female,
};
*/
typedef struct PersonInfo{
    string name;//姓名
    string sex;//性别
    int age;//年龄
    string phones;//号码
    string address;//地址
}PersonInfo;