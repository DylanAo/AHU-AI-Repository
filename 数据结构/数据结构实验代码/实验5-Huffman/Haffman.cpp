#include "HaffmanTree.h"

void select(HTree H, int n, int& s1, int& s2) {
	int i = 1;
	//找s1
	for (i = 1; i < n; i++) //初始化s1，s1初始化在一个parent=0节点
		if (H[i].parent == 0) {
			s1 = i;
			break;
		}
	for (i = 1; i < n; i++) //比对，使s1最小
		if (H[i].parent == 0 && H[i].weight < H[s1].weight) s1 = i;
	H[s1].parent = 1;//为了不让s1再次被选上，这里H没有引用类型，不影响真正parent值
	//找s2
	for (i = 1; i < n; i++)
		if (H[i].parent == 0 && i != s1) {
			s2 = i;
			break;
		}
	for (i = 1; i < n; i++)
		if (H[i].parent == 0 && H[i].weight < H[s2].weight && i != s1) s2 = i;
	//注意初始化s1,s2位置的for不能写一起，否则可能出现s2初始化值恰好是s1最后应取值的bug
	//因为s1就是最小的，s2第二小，这个bug导致s2一定等于s2
}

void createHTree(HTree& H,char *str,int *rate) {
	//初始化
	int k = 0,n=0;
	for (k = 0; k < 26; k++)//找rate不为0有几个
		if (rate[k]) n++;
	if (n <= 1) return;
	int i = 1, j = 0;
	int m = n * 2 - 1;
	int s1 = 0, s2 = 0;
	H = new HNode[m + 1];
	for (i = 1; i <= m; i++) {
		H[i].lchild = 0;
		H[i].rchild = 0;
		H[i].parent = 0;
	}
	for (i = 1; i <= n; i++) {
		int a = 0;
		//scanf("%d", &a);
		for (; !rate[j]; j++);//找rate里不为0的数
		H[i].weight = rate[j];
		j++;
	}
	//构建哈夫曼树
	for (i = n + 1; i <= m; i++) {
		select(H, i, s1, s2);
		H[s1].parent = i;
		H[s2].parent = i;
		H[i].lchild = s1;
		H[i].rchild = s2;
		H[i].weight = H[s1].weight + H[s2].weight;
	}
}

void creatrHCode(HTree H, HuffmanCode& HC, int *rate) {
	int k = 0, n = 0;
	for (k = 0; k < 26; k++)//找rate不为0有几个
		if (rate[k]) n++;
	HC = new char* [n];
	char* cd;
	int i = 0;
	for (i = 1; i <= n; i++) {
		cd = new char[n];
		cd[n - 1] = '\0';
		int start = n - 1;
		int c = i;
		int f = H[i].parent;
		while (f) {
			start--;
			if (H[f].lchild == c) cd[start] = '0';
			else cd[start] = '1';
			c = f;
			f = H[f].parent;
		}
		*(HC + i) = new char[n - start];
		HC[i] = &cd[start];
		//strcpy(HC[i], &cd[start]);
	}
}

void collect(char *str,int *rate) {
	int i = 0,j=0;
	for (i = 0; str[i]; i++) {
		j=str[i] - 'a';
		rate[j]++;
	}
}

void print_all(int* rate,HuffmanCode& HC) {
	int k = 0,n=0;
	for (k = 0; k < 26; k++)//找rate不为0有几个
		if (rate[k]) n++;
	int i = 0, j = 0;
	k = 0;
	for (i = 0; i < 26; i++) {
		if (rate[i]) {
			printf("letter=%c  rate=%d ", 'a' + i, rate[i]);
			k++;
			j = 0;
			printf("code=");
			while (HC[k][j] != '\0') {
				printf("%c", HC[k][j]);
				j++;
				}
			printf("\n");
			}
		}
}