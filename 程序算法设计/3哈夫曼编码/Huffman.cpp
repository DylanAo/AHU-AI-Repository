#include"head.h"

//读取文件
void TxtReader(struct DataType arr[]){

    fstream fin;
    fin.open("Words.txt");//该代码要求words文件必须在该文件夹内，可改为绝对路径
    
    char ch;
    int distance;
    while(fin && fin.get(ch)){
        //cout << ch;
        distance = (int)tolower(ch) - 97;
        if(distance == -65)
            arr[N-1].weight ++;//空格统计
        else 
            arr[distance].weight ++;
    }
    fin.close();
    cout << ">File Read Finished.<" <<endl;
}//读写文件
//哈夫曼树建立
HuffmanTree CreateHuffmanTree(DataMode* arr, int n){
    HuffmanTree forest[N];
    HuffmanTree root = NULL;
    for(int i = 0; i < N; i++){
        HuffmanTree temp;
        temp =  (HuffmanTree)malloc(sizeof(HuffmanTree));
        temp->data.word = arr[i].word;//将ASCII码存入word
        temp->data.weight = arr[i].weight;
        temp->lchild = temp->rchild = NULL;
        forest[i] = temp;
    }//将所有点存入森林
    //n-1次循环建立哈夫曼树
    for(int i = 0; i < n-1; i++){
        int min = -1, minsub;//min为设置的最小值树根的下标，minsub为次最小值树根下标
        for(int j = 0; j < n; j++){
            if(forest[j] != NULL && min == -1){
                min = j;
                continue;
            }//循环开始，将第一个不为空的树下标设置为最小值树根，设置min为-1保证赋值过一次后下次跳过此函数块
            if(forest[j] != NULL){
                minsub = j;
                break;
            }//找到除去第一个被设为最小值树外的第一个非空树为次最小值树
        }
        for(int j = minsub; j < n; j++){//根据min和minsub的大小去赋值
            if(forest[j] != NULL){
                if(forest[j]->data.weight < forest[min]->data.weight){
                    minsub = min;
                    min = j;
                }else if(forest[j]->data.weight < forest[minsub]->data.weight){
                    minsub = j;
                }//如果此时树为空（此前的循环被摘去）则不执行并跳过，非空则判断大小
            }
        }
        //建新树
        root = (HuffmanTree)malloc(sizeof(HTNode));
        root->data.word = 0;
        root->data.weight = forest[min]->data.weight + forest[minsub]->data.weight;
        root->lchild = forest[min];
        root->rchild = forest[minsub];

        forest[min] = root; //将合成的新树的指针指向min位置
        forest[minsub] = NULL; //将minsub位置指向空防止重复摘取
    }
    return root;
}
//哈夫曼编码
void HuffmanCoding(HuffmanTree root, int len, int arr[]){
    ofstream fout;
    fout.open("decode.txt",ios::out|ios::app);
    if ( !fout){
    cout << "Can not create." <<endl;
    }

    if(root != NULL){
        if(root->lchild == NULL && root->rchild == NULL){
            printf("节点为'%c'的字符,权重为%d的编码为:",root->data.word , root->data.weight);
            fout << "节点为" << char(root->data.word) << "的字符,权重为" << root->data.weight << "的编码为:"<< endl; 
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
    int DeCode[M] = {0};//用于临时存放编写的哈夫曼编码 待优化为可变长数组

    for(int i = 0; i < N - 1; i++){
        Word[i].word = 65 + i;//a的ASCII码为65
        Word[i].weight = 0;
    }
    Word[N-1].word = 32;
    Word[N-1].weight = 0;//空格

    TxtReader(Word);
    //循环对自定义数组初始化
    HuffmanTree HuffRoot;
    HuffRoot = CreateHuffmanTree(Word, N);//建树
    
    ofstream fout;
    fout.open("decode.txt");
    if ( !fout){
    cout << "Can not create." <<endl;
    }
    fout.close();//每一次运行函数把原本上次写的文件覆盖

    HuffmanCoding(HuffRoot, 0, DeCode);

    system("pause");
    return 0;
}