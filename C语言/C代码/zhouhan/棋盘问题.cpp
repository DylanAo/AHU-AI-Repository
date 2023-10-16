#include <stdio.h>
#include <math.h>
#include <time.h>

void ChessBoard(char **board,int a,int b,int size,int dire){
	//board是棋盘，a,b是(子)棋盘左上角和右下角,size是棋盘规模,dire是子棋盘在母棋盘中的方位
	//1.将棋盘分为四个部分（若size为0,则无法分割）
	//2.判断子部分中是否有已覆盖部分，若有，则不动，若没有，判断其在母盘中的位置，放置黑块
	//3.对分割成的四个子棋盘重复该步骤
}

int main() 
{
    int k;
    printf("please input k：");
    scanf("%d", &k);

    int n = pow(2, k);  // 计算矩形棋盘边长

    char board[n][n];   // 定义矩形棋盘数组

    // 初始化矩形棋盘数组，将所有格子都填充为0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] ='0';
        }
    }

    // 在矩形棋盘中标记一个点
    srand(time(0));
    int x=rand() % n;
    int y=rand() % n;
	
	board[x][y]='1';
    // 输出矩形棋盘
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    
    ChessBoard(board,0,n,k,0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
