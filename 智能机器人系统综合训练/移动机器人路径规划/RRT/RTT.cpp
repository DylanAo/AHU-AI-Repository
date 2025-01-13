#include "RTT.h"


double get_point_distance(Point point_1, Point point_2) {
	return sqrt(pow(point_1.x - point_2.x, 2) + pow(point_1.y - point_2.y, 2));
}


void point_init(Point &point, int ID, int x, int y, int father_ID) {
	point.ID = ID;
	point.father_ID = father_ID;
	point.x = x;
	point.y = y;
}


Point get_point_middle(Point point_1, Point point_2, int point_ID) {
	Point p;
	point_init(p, point_ID, (int)abs((point_1.x - point_2.x) / 2), (int)abs((point_1.y - point_2.y) / 2), 0);
	return p;
}


bool if_conflict_point_same(list<Point> RTT_list, Point point) {
	for (list<Point>::iterator it = RTT_list.begin(); it != RTT_list.end(); ++it) {
		if (it->x == point.x && it->y == point.y) {
			return true;
		}
	}
	return false;
}


bool if_conflict_point_barrier(Point point_1, Point point_2) {
	if ((point_1.x < 7 && point_2.x < 7) || (point_1.x > 9 && point_2.x > 9)) {
		return false;
	}

	if ((point_2.x > 7 && point_2.x < 9) || (point_1.y < 2 && point_2.y > 12)) {
		return true;
	}

	double k;
	double b;
	auto f = [&k, &b](int x) -> double {
		return k * x + b;
	};

	k = (double)(point_1.y - point_2.y) / (double)(point_1.x - point_2.x);
	b = point_1.y - k * point_1.x;

	if ((f(7) > 2 && f(7) < 12) || (f(9) > 2 && f(9) < 12)) {
		return true;
	}
	return false;
}


void RTT_list_init(list<Point> &RTT_list, int begin_x, int begin_y) {
	Point p;
	point_init(p, 0, begin_x, begin_y, 0);
	RTT_list.push_back(p);
}


Point RTT_list_find_min_distance(list<Point> RTT_list, Point point) {
	int min_distance = 114514;
	int current_distance = 0;
	Point min_point;
	for (list<Point>::iterator it = RTT_list.begin(); it != RTT_list.end(); ++it) {
		current_distance = get_point_distance(*it, point);
		if (current_distance < min_distance) {
			min_distance = current_distance;
			min_point = *it;
		}
	}
	return min_point;
}


Point RTT_list_find_ID(list<Point> RTT_list, int ID) {
	for (list<Point>::iterator it = RTT_list.begin(); it != RTT_list.end(); ++it) {
		if (it->ID == ID) {
			return *it;
		}
	}
}


bool RTT_stop(list<Point>& RTT_list, Point end_point, int range) {
	if (get_point_distance(RTT_list.back(), end_point) < range) {
		return false;
	}
	return true;

}

void RTT(list<Point> &RTT_list, int end_x, int end_y, int range) {
	int current_random_x;
	int current_random_y;
	int current_ID = 1;
	Point end_Point;
	point_init(end_Point, -1, end_x, end_y, -1);
	RTT_list_init(RTT_list, 0, 0);


	while (RTT_stop(RTT_list, end_Point, range)) {
		Point current_point;
		Point current_min_distance_point;
		Point current_point_middle;
		current_random_x = (rand() % (19 - 0 + 1)) + 0;
		current_random_y = (rand() % (19 - 0 + 1)) + 0;
		point_init(current_point, current_ID, current_random_x, current_random_y, 0);
		current_min_distance_point = RTT_list_find_min_distance(RTT_list, current_point);
		current_point_middle = get_point_middle(current_min_distance_point, current_point, current_ID);
		
		if (if_conflict_point_same(RTT_list, current_point_middle)) {
			continue;
		}
		
		if (if_conflict_point_barrier(current_min_distance_point, current_point_middle)) {
			continue;
		}
		
		/*
		current_min_distance_point = RTT_list_find_min_distance(RTT_list, current_point);
		if (if_conflict_point_same(RTT_list, current_point)) {
			continue;
		}

		if (if_conflict_point_barrier(current_min_distance_point, current_point)) {
			continue;
		}*/
		current_point_middle.father_ID = current_min_distance_point.ID;
		//current_point.father_ID = current_min_distance_point.ID;
		current_ID++;
		RTT_list.push_back(current_point_middle);
		//RTT_list.push_back(current_point);
		
	}
}


void show_RTT_list2matrix(list<Point> RTT_list, int matrix[20][20]) {
	File f("point_tree.txt");
	Point current_point = RTT_list.back();
	for (list<Point>::iterator it = RTT_list.begin(); it != RTT_list.end(); ++it) {
		matrix[it->x][it->y] = 5;
	}

	while (current_point.ID != 0) {
		matrix[current_point.x][current_point.y] = 10;
		f.write(to_string(current_point.x) + "," + to_string(current_point.y) + "\n");
		current_point = RTT_list_find_ID(RTT_list, current_point.father_ID);
	}
	matrix[current_point.x][current_point.y] = 10;
	matrix[18][18] = 10;
	f.write("0,0\n");
}