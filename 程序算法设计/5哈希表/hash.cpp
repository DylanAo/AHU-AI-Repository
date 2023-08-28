#include "hashproblem.h"

//������ϵ�˱�
vector<PersonInfo> ContactReader(const vector<PersonInfo>& vec, const string& filename){
    vector<PersonInfo> updatedVec = vec; //����һ�����������ڴ洢���º����ϵ���б�
    ifstream fin(filename,ios::in);//����ϵ�˱��������򴴽�
    if(fin.is_open()){//�ж��Ƿ�ɹ���
        string line;
        while(getline(fin,line)){//���ж�ȡ�ļ��е�����
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
//��ʾ��ǰ��ϵ�˱�ע��Ϊ��ʾ��ǰ�����������е���ϵ�˱�
void ContactViewer(const vector<PersonInfo>& container){
    for (const auto& person : container) {//��const��ֹ��ѭ�����޸ģ���auto�Զ��ƶ�person������
        cout << "Name:" << person.name <<"\t";
        cout << "Sex:" << person.sex <<"\t";
        cout << "Age:" << person.age <<"\t";
        cout << "Phones:" << person.phones <<"\t";
        cout << "Address:" << person.address << endl;
    }
    cout << "Print Over." <<endl;
}
//������ϵ��(ͬ��Ϊ����������ϵ������������)
void ContactAppend(vector<PersonInfo>& ContactList) {
    PersonInfo newContact;
    cout << "�Ա�����female/male,��������ʱ�м䲻Ҫʹ�ÿո�����Ʊ��\n";
    cin.ignore(); // �������뻺�����еĻ��з�
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter sex: ";
    getline(cin, newContact.sex);
    cout << "Enter age: ";
    cin >> newContact.age;
    cin.ignore(); // �������뻺�����еĻ��з�
    cout << "Enter phones: ";
    getline(cin, newContact.phones);
    cout << "Enter address: ";
    getline(cin, newContact.address);

    ContactList.push_back(newContact);
}
//������ϵ��
int FindContactByPhone(const vector<PersonInfo>& ContactList, const string& phone) {
    int size = ContactList.size();
    int hash1 = stoi(phone) % size;  // ��һ��ɢ��
    int hash2 = 1 + (stoi(phone) % (size - 1));  // �ڶ���ɢ��

    int position = hash1;
    int i = 0;
    while (ContactList[position].phones != phone && !ContactList[position].phones.empty()) {
        position = (hash1 + i * hash2) % size;
        i++;
        if (i >= size) {
            // ����������������δ�ҵ�ƥ�����ϵ��
            position = -1;
            break;
        }
    }
    cout << "position is " << position <<endl;
    return position;
}
//ɾ
void DeleteContactByPosition(vector<PersonInfo>& ContactList) {
    int position;//�ڸú����ڵ��ò��Һ���������Ҫɾ��������λ��
    string phone;

    cout << "������Ҫɾ����Ŀ����ϵ�˵��ֻ���:";
    cin >> phone;
    position = FindContactByPhone(ContactList,phone);
    if (position >= 0 && position < ContactList.size()) {
        ContactList.erase(ContactList.begin() + position);
        cout << "Contact at position " << position << " has been deleted." << endl;
    } else {
        cout << "Invalid position. Contact not deleted." << endl;
    }
}
//��
void ModifyContactByPosition(vector<PersonInfo>& ContactList) {
    int position;
    string phone;//�½�һ�����󱣴���Ҫ�޸ĵ���ϵ����Ϣ���ֻ���
    
    cout << "������Ҫ�޸ĵ�Ŀ����ϵ�˵��ֻ���:";
    cin >> phone;
    position = FindContactByPhone(ContactList,phone);
    if (position >= 0 && position < ContactList.size()) {
        PersonInfo& person = ContactList[position];
        // �޸���ϵ����Ϣ
        cout << "Enter the updated information for the contact at position " << position << ":" << endl;
        cout << "Name: ";
        getline(cin, person.name);
        cout << "Sex: ";
        getline(cin, person.sex);
        cout << "Age: ";
        cin >> person.age;
        cin.ignore();  // ���Ի��з�
        cout << "Phones: ";
        getline(cin, person.phones);
        cout << "Address: ";
        getline(cin, person.address);

        cout << "Contact at position " << position << " has been modified." << endl;
    } else {
        cout << "Invalid position. Contact not modified." << endl;
    }
}
//�����ϵ��
void ClearContactList(vector<PersonInfo>& ContactList) {
    ContactList.clear();
    if(ContactList.empty()) cout << "Contact list has been cleared." << endl;//����Ƿ����
}
//����
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
    string filename = "Hash\\Contacts.txt";//���޸���ϵ�˱�ı�����������Ҫ�ڴ˴��޸�Դ����ʵ��
    vector<PersonInfo> ContactList;//����������ϵ�˱�

    int mode = -1;
    int read = 1;//Ĭ��ִ��ǰ�ȶ�ȡ����ϵ�˱�
    char save = 'N';//Ĭ���˳��󲻱��湤������ϵ�˱�
    char Control = 'N';//Ĭ�ϲ��˳����ظ�ִ��
        cout << "�Ƿ��������ϵ�˱�?(0.����ȡ 1.��ȡ)" << endl;
        cin >> read;
        if(read){//Ĭ��(��0)Ϊ��ȡ
            ContactList = ContactReader(ContactList,filename);//��ȡ�ļ��е���ϵ�˱�
        }

        cout << "0.��ȡ����ϵ�˱�(ԭ������δ������Ȼ�ɥʧ)" << "\n"
             << "1.��ʾ��ǰ��ϵ�˱�" << "\n"
             << "2.������ϵ��" << "\n"
             << "3.�½���ϵ��" << "\n"
             << "4.�޸ĵ�ǰ��ϵ�˱�" << "\n"
             << "5.ɾ����ϵ��" << "\n"
             << "6.��յ�ǰ��ϵ�˱�" << "\n"
             << "7.�˳�ͨѶ¼" << endl;
    while(Control != 'Y'){
        cout << "ѡ��Ҫִ�еĲ�����";
        cin >> mode;
        switch (mode){//ѡ�����ģʽ
        case 0:{//��ȡ
            ContactList.clear();
            ContactList = ContactReader(ContactList,filename);
            }break;
        case 1:{//��ʾ
            ContactViewer(ContactList);
            }break;
        case 2:{//����
            string phone;//�½�һ�����󱣴���Ҫ���ҵ���ϵ���ֻ���
            int position;//���淵�ص�λ��
            cout << "������Ҫ���ҵ���ϵ�˵��ֻ���:";
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
        case 3:{//�½�
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
            cout << "�Ƿ��˳�ͨѶ¼(Y/N):";
            cin >> Control;//ѭ����ֹ����
            cout << "�Ƿ񱣴浱ǰ����(Y/N):";
            cin >> save;
        }break;
        default:{
            cout << "Invaild operate mode" <<endl;
                Control = 'Y';//������ֹѭ��
                save = 'N';//������ֹ�������湤��
            }
            break;
        }
        if(save == 'Y'){
            SaveContactList(ContactList,filename);
        }
    }
    return 0;
}