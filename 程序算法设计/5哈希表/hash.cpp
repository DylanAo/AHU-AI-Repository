#include "hashproblem.h"

//读入联系人表
vector<PersonInfo> ContactReader(const vector<PersonInfo>& vec, const string& filename){
    vector<PersonInfo> updatedVec = vec; //创建一个新容器用于存储更新后的联系人列表
    ifstream fin(filename,ios::in);//打开联系人表，不存在则创建
    if(fin.is_open()){//判断是否成功打开
        string line;
        while(getline(fin,line)){//逐行读取文件中的内容
            PersonInfo info;
            istringstream record(line);
            record >> info.name;
            record >> info.sex;
            record >> info.age;
            record >> info.phones;
            record >> info.address;
            updatedVec.push_back(info);
        }
        fin.close();
        cout << "Read Over" << endl;
    } else {
        cout << "Failed to open the file." << endl;
    }
    return updatedVec;
}
//显示当前联系人表（注：为显示当前工作区容器中的联系人表
void ContactViewer(const vector<PersonInfo>& container){
    for (const auto& person : container) {//用const防止在循环中修改，并auto自动推断person的类型
        cout << "Name:" << person.name <<"\t";
        cout << "Sex:" << person.sex <<"\t";
        cout << "Age:" << person.age <<"\t";
        cout << "Phones:" << person.phones <<"\t";
        cout << "Address:" << person.address << endl;
    }
    cout << "Print Over." <<endl;
}
//新增联系人(同样为将新增的联系人纳入容器中)
void ContactAppend(vector<PersonInfo>& ContactList) {
    PersonInfo newContact;
    cout << "性别栏填female/male,输入数据时中间不要使用空格符或制表符\n";
    cin.ignore(); // 忽略输入缓冲区中的换行符
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter sex: ";
    getline(cin, newContact.sex);
    cout << "Enter age: ";
    cin >> newContact.age;
    cin.ignore(); // 忽略输入缓冲区中的换行符
    cout << "Enter phones: ";
    getline(cin, newContact.phones);
    cout << "Enter address: ";
    getline(cin, newContact.address);

    ContactList.push_back(newContact);
}
//查找联系人
int FindContactByPhone(const vector<PersonInfo>& ContactList, const string& phone) {
    int size = ContactList.size();
    int hash1 = stoi(phone) % size;  // 第一次散列
    int hash2 = 1 + (stoi(phone) % (size - 1));  // 第二次散列

    int position = hash1;
    int i = 0;
    while (ContactList[position].phones != phone && !ContactList[position].phones.empty()) {
        position = (hash1 + i * hash2) % size;
        i++;
        if (i >= size) {
            // 遍历了整个容器，未找到匹配的联系人
            position = -1;
            break;
        }
    }
    cout << "position is " << position <<endl;
    return position;
}
//删
void DeleteContactByPosition(vector<PersonInfo>& ContactList) {
    int position;//在该函数内调用查找函数返回需要删除的容器位置
    string phone;

    cout << "输入需要删除的目标联系人的手机号:";
    cin >> phone;
    position = FindContactByPhone(ContactList,phone);
    if (position >= 0 && position < ContactList.size()) {
        ContactList.erase(ContactList.begin() + position);
        cout << "Contact at position " << position << " has been deleted." << endl;
    } else {
        cout << "Invalid position. Contact not deleted." << endl;
    }
}
//改
void ModifyContactByPosition(vector<PersonInfo>& ContactList) {
    int position;
    string phone;//新建一个对象保存需要修改的联系人信息的手机号
    
    cout << "输入需要修改的目标联系人的手机号:";
    cin >> phone;
    position = FindContactByPhone(ContactList,phone);
    if (position >= 0 && position < ContactList.size()) {
        PersonInfo& person = ContactList[position];
        // 修改联系人信息
        cout << "Enter the updated information for the contact at position " << position << ":" << endl;
        cout << "Name: ";
        getline(cin, person.name);
        cout << "Sex: ";
        getline(cin, person.sex);
        cout << "Age: ";
        cin >> person.age;
        cin.ignore();  // 忽略换行符
        cout << "Phones: ";
        getline(cin, person.phones);
        cout << "Address: ";
        getline(cin, person.address);

        cout << "Contact at position " << position << " has been modified." << endl;
    } else {
        cout << "Invalid position. Contact not modified." << endl;
    }
}
//清空联系人
void ClearContactList(vector<PersonInfo>& ContactList) {
    ContactList.clear();
    if(ContactList.empty()) cout << "Contact list has been cleared." << endl;//检查是否清空
}
//保存
void SaveContactList(const vector<PersonInfo>& ContactList, const string& filename) {
    ofstream fout(filename,ios::out);
    if (fout) {
        for (const auto& person : ContactList) {
            fout << person.name << "\t"
                 << person.sex << "\t"
                 << person.age << "\t"
                 << person.phones << "\t"
                 << person.address << endl;
        }
        fout.close();
        cout << "Contact list has been written to the file." << endl;
    } else {
        cout << "Failed to open the file for writing." << endl;
    }
}

int main(){
    string filename = "Hash\\Contacts.txt";//可修改联系人表的保存名，但需要在此处修改源代码实现
    vector<PersonInfo> ContactList;//工作区的联系人表

    int mode = -1;
    int read = 1;//默认执行前先读取总联系人表
    char save = 'N';//默认退出后不保存工作区联系人表
    char Control = 'N';//默认不退出，重复执行
        cout << "是否读入总联系人表?(0.不读取 1.读取)" << endl;
        cin >> read;
        if(read){//默认(非0)为读取
            ContactList = ContactReader(ContactList,filename);//读取文件中的联系人表
        }

        cout << "0.读取总联系人表(原工作区未保存进度会丧失)" << "\n"
             << "1.显示当前联系人表" << "\n"
             << "2.查找联系人" << "\n"
             << "3.新建联系人" << "\n"
             << "4.修改当前联系人表" << "\n"
             << "5.删除联系人" << "\n"
             << "6.清空当前联系人表" << "\n"
             << "7.退出通讯录" << endl;
    while(Control != 'Y'){
        cout << "选择要执行的操作：";
        cin >> mode;
        switch (mode){//选择操作模式
        case 0:{//读取
            ContactList.clear();
            ContactList = ContactReader(ContactList,filename);
            }break;
        case 1:{//显示
            ContactViewer(ContactList);
            }break;
        case 2:{//查找
            string phone;//新建一个对象保存需要查找的联系人手机号
            int position;//保存返回的位置
            cout << "输入需要查找的联系人的手机号:";
            cout <<"2";
            cin >> phone;
            cout<<"1";
            position = FindContactByPhone(ContactList,phone);
            if (position >= 0 && position < ContactList.size()) {
            cout << "Position: " << position + 1 << endl
                 << "Name: " << ContactList[position].name << endl
                 << "Sex: " << ContactList[position].sex << endl
                 << "Age: " << ContactList[position].age << endl
                 << "Phones: " << ContactList[position].phones << endl
                 << "Address: " << ContactList[position].address <<endl;
                 } else {
                    cout << "Invalid position of this phone number."<< endl;
                 }
            }break;
        case 3:{//新建
            ContactAppend(ContactList);
            }break;
        case 4:{
            ModifyContactByPosition(ContactList);
            }break;
        case 5:{
            DeleteContactByPosition(ContactList);
            }break;
        case 6:{
            ClearContactList(ContactList);
        }break;
        case 7:{
            cout << "是否退出通讯录(Y/N):";
            cin >> Control;//循环终止条件
            cout << "是否保存当前工作(Y/N):";
            cin >> save;
        }break;
        default:{
            cout << "Invaild operate mode" <<endl;
                Control = 'Y';//意外终止循环
                save = 'N';//意外终止，不保存工作
            }
            break;
        }
        if(save == 'Y'){
            SaveContactList(ContactList,filename);
        }
    }
    return 0;
}