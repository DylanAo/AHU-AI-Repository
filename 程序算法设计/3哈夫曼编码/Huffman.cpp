#include"head.h"

//��ȡ�ļ�
void TxtReader(struct DataType arr[]){

    fstream fin;
    fin.open("Words.txt");//�ô���Ҫ��words�ļ������ڸ��ļ����ڣ��ɸ�Ϊ����·��
    
    char ch;
    int distance;
    while(fin && fin.get(ch)){
        //cout << ch;
        distance = (int)tolower(ch) - 97;
        if(distance == -65)
            arr[N-1].weight ++;//�ո�ͳ��
        else 
            arr[distance].weight ++;
    }
    fin.close();
    cout << ">File Read Finished.<" <<endl;
}//��д�ļ�
//������������
HuffmanTree CreateHuffmanTree(DataMode* arr, int n){
    HuffmanTree forest[N];
    HuffmanTree root = NULL;
    for(int i = 0; i < N; i++){
        HuffmanTree temp;
        temp =  (HuffmanTree)malloc(sizeof(HuffmanTree));
        temp->data.word = arr[i].word;//��ASCII�����word
        temp->data.weight = arr[i].weight;
        temp->lchild = temp->rchild = NULL;
        forest[i] = temp;
    }//�����е����ɭ��
    //n-1��ѭ��������������
    for(int i = 0; i < n-1; i++){
        int min = -1, minsub;//minΪ���õ���Сֵ�������±꣬minsubΪ����Сֵ�����±�
        for(int j = 0; j < n; j++){
            if(forest[j] != NULL && min == -1){
                min = j;
                continue;
            }//ѭ����ʼ������һ����Ϊ�յ����±�����Ϊ��Сֵ����������minΪ-1��֤��ֵ��һ�κ��´������˺�����
            if(forest[j] != NULL){
                minsub = j;
                break;
            }//�ҵ���ȥ��һ������Ϊ��Сֵ����ĵ�һ���ǿ���Ϊ����Сֵ��
        }
        for(int j = minsub; j < n; j++){//����min��minsub�Ĵ�Сȥ��ֵ
            if(forest[j] != NULL){
                if(forest[j]->data.weight < forest[min]->data.weight){
                    minsub = min;
                    min = j;
                }else if(forest[j]->data.weight < forest[minsub]->data.weight){
                    minsub = j;
                }//�����ʱ��Ϊ�գ���ǰ��ѭ����ժȥ����ִ�в��������ǿ����жϴ�С
            }
        }
        //������
        root = (HuffmanTree)malloc(sizeof(HTNode));
        root->data.word = 0;
        root->data.weight = forest[min]->data.weight + forest[minsub]->data.weight;
        root->lchild = forest[min];
        root->rchild = forest[minsub];

        forest[min] = root; //���ϳɵ�������ָ��ָ��minλ��
        forest[minsub] = NULL; //��minsubλ��ָ��շ�ֹ�ظ�ժȡ
    }
    return root;
}
//����������
void HuffmanCoding(HuffmanTree root, int len, int arr[]){
    ofstream fout;
    fout.open("decode.txt",ios::out|ios::app);
    if ( !fout){
    cout << "Can not create." <<endl;
    }

    if(root != NULL){
        if(root->lchild == NULL && root->rchild == NULL){
            printf("�ڵ�Ϊ'%c'���ַ�,Ȩ��Ϊ%d�ı���Ϊ:",root->data.word , root->data.weight);
            fout << "�ڵ�Ϊ" << char(root->data.word) << "���ַ�,Ȩ��Ϊ" << root->data.weight << "�ı���Ϊ:"<< endl; 
            for(int i = 0; i < len; i++){
                cout << arr[i];
                fout << arr[i];
            }
            cout << endl;
            fout << endl;
        } else{
            arr[len] = 0;
            HuffmanCoding(root->lchild, len + 1, arr);
            arr[len] = 1;
            HuffmanCoding(root->rchild, len + 1, arr);
        }
    }
    fout.close();
}

int main(){

    DataMode Word[N];
    int DeCode[M] = {0};//������ʱ��ű�д�Ĺ��������� ���Ż�Ϊ�ɱ䳤����

    for(int i = 0; i < N - 1; i++){
        Word[i].word = 65 + i;//a��ASCII��Ϊ65
        Word[i].weight = 0;
    }
    Word[N-1].word = 32;
    Word[N-1].weight = 0;//�ո�

    TxtReader(Word);
    //ѭ�����Զ��������ʼ��
    HuffmanTree HuffRoot;
    HuffRoot = CreateHuffmanTree(Word, N);//����
    
    ofstream fout;
    fout.open("decode.txt");
    if ( !fout){
    cout << "Can not create." <<endl;
    }
    fout.close();//ÿһ�����к�����ԭ���ϴ�д���ļ�����

    HuffmanCoding(HuffRoot, 0, DeCode);

    system("pause");
    return 0;
}