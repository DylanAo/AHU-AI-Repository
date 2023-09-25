#include"graph.h"
string point_names[POINT_NUM] = { "�����������", "������������", "�춼��", "ӭ����", "����Ϫվ", "����ͤ", "������", "�׺���", "ʼ�ŷ�", "�ɹ���վ", "�ƹ��������", "�ƹ���������" };
Graph::Graph(int departure[], int destination[], int weight[]) {
	// ����ڵ�ͱߵ���Ϣ
	for (int i = 0; i < SIDE_NUM; i++) {
		site[i].departure = departure[i];
		site[i].destination = destination[i];
		site[i].weight = weight[i];
	}

	//�����ڽӾ���
	for (int i = 0; i < POINT_NUM; i++) {
		for (int j = 0; j < POINT_NUM; j++) {
			map[i][j] = INFINITE;
		}
	}
	for (int i = 0; i < SIDE_NUM; i++) {
		for (int j = 0; j < SIDE_NUM; j++) {
			for (int site_index = 0; site_index < SIDE_NUM; site_index++) {
				if (site[site_index].departure == i && site[site_index].destination == j) {
					map[i][j] = site[site_index].weight;
					map[j][i] = site[site_index].weight;
					site_index++;
				}
			}
		}
	}

	//�Ͻ�˹������ÿ���ڵ�����·��
	for (int i = 0; i < POINT_NUM; i++) {
		for (int j = 0; j < POINT_NUM; j++) {
			path[i][j] = INFINITE;
		}
	}
	for (int point_index = 0; point_index < POINT_NUM; point_index++) {
		dijstra(point_index);
	}
}


bool Graph::dijstra(int point_index) {
	bool now_point_set[POINT_NUM];
	int now_point_weight[POINT_NUM];
	for (int index = 0; index < POINT_NUM; index++) {
		now_point_set[index] = false;
		now_point_weight[index] = map[point_index][index];
		if (now_point_weight[index] < INFINITE) {
			path[point_index][index] = point_index;
		}
		else{
			path[point_index][index] = NO_PRODROMAL;
		}
	}
	now_point_set[point_index] = true;
	now_point_weight[point_index] = 0;

	for (int i = 0; i < POINT_NUM; i++) {
		int now_min_weight = INFINITE;
		int now_min_point = point_index;
		for (int w = 0; w < POINT_NUM; w++) {
			if (!now_point_set[w] && now_point_weight[w] < now_min_weight) {
				now_min_point = w;
				now_min_weight = now_point_weight[w];
			}
		}
		now_point_set[now_min_point] = true;
		for (int w = 0; w < POINT_NUM; w++) {
			if (!now_point_set[w] && now_point_set[now_min_point] + map[now_min_point][w]) {
				now_point_weight[w] = now_point_set[now_min_point] + map[now_min_point][w];
				path[point_index][w] = now_min_point;
			}
		}
	}
}

void Graph::print(int departure, int destination) {
	if (path[departure][destination] == -1) {
		cout << "��" << point_names[departure] << " �� " << point_names[destination] << " ֮��û��·,�������Ѿ�������!";
	}
	else {
		int now_point = departure;
		cout << point_names[departure] << " - >";
		while (path[destination][now_point] != -1) {
			if (path[destination][now_point] == destination) {
				cout << point_names[path[destination][now_point]];
				break;
			}
			else {
				cout << point_names[path[destination][now_point]] << " - >";
				now_point = path[destination][now_point];
			}
		}
	}
	cout << endl;
}

void Graph::print() {
	for (int i = 0; i < POINT_NUM; i++) {
		cout << endl << "****" << "�����ڵ�λ��Ϊ: " << point_names[i] << "****" << endl;
		for (int j = 0; j < POINT_NUM; j++) {
			print(i, j);
		}
	}
}