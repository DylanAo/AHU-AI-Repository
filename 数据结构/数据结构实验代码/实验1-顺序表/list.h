#ifndef list_h_
#define list_h_
#include <stdio.h>
#define max 5
typedef struct list_1{
	int *data;
	int length;
}*list,listnode;
//�������Ա�
int create_list(list& L);
//��������һ�θ����������������
int indata_list(list& L, int* a);
//��ӡ���Ա�
int print_list(list L);
//��ȡ���Ա��n���������ݷ���e��
int get_list(list L, int n, int& e);
//�����Ա�ֵΪe�����صڼ���
int find_list(list L, int e);
//ɾ����i��
int delete_list(list& L, int i);
//��i��λ�ò���ֵΪe
int insert_list(list& L, int i, int e);
#endif 

