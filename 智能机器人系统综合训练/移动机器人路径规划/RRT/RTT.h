#pragma once
#include <math.h>
#include <list>
#include "file.h"
using namespace std;

typedef struct {
	int ID;
	int father_ID;
	int x;
	int y;
}Point;

void point_init(Point& point, int ID, int x, int y, int father_ID);
double get_point_distance(Point point_1, Point point_2);

void RTT_list_init(list<Point>& RTT_list, int begin_x, int begin_y);
void show_RTT_list2matrix(list<Point> RTT_list, int matrix[20][20]);
void RTT(list<Point>& RTT_list, int end_x, int end_y, int range);