#include "HaffmanTree.h"

void select(HTree H, int n, int& s1, int& s2) {
	int i = 1;
	//��s1
	for (i = 1; i < n; i++) //��ʼ��s1��s1��ʼ����һ��parent=0�ڵ�
		if (H[i].parent == 0) {
			s1 = i;
			break;
		}
	for (i = 1; i < n; i++) //�ȶԣ�ʹs1��С
		if (H[i].parent == 0 && H[i].weight < H[s1].weight) s1 = i;
	H[s1].parent = 1;//Ϊ�˲���s1�ٴα�ѡ�ϣ�����Hû���������ͣ���Ӱ������parentֵ
	//��s2
	for (i = 1; i < n; i++)
		if (H[i].parent == 0 && i != s1) {
			s2 = i;
			break;
		}
	for (i = 1; i < n; i++)
		if (H[i].parent == 0 && H[i].weight < H[s2].weight && i != s1) s2 = i;
	//ע���ʼ��s1,s2λ�õ�for����дһ�𣬷�����ܳ���s2��ʼ��ֵǡ����s1���Ӧȡֵ��bug
	//��Ϊs1������С�ģ�s2�ڶ�С�����bug����s2һ������s2
}

void createHTree(HTree& H,char *str,int *rate) {
	//��ʼ��
	int k = 0,n=0;
	for (k = 0; k < 26; k++)//��rate��Ϊ0�м���
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
		for (; !rate[j]; j++);//��rate�ﲻΪ0����
		H[i].weight = rate[j];
		j++;
	}
	//������������
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
	for (k = 0; k < 26; k++)//��rate��Ϊ0�м���
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
	for (k = 0; k < 26; k++)//��rate��Ϊ0�м���
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