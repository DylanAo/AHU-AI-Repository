#include <iostream>
#include "matrix.h"
#include "file.h"
#include "RTT.h"
using namespace std;

int main()
{
    int matrix[20][20] = {0};
    matrix_init(matrix);
    list<Point> RTT_list;
    RTT(RTT_list, 18, 18, 3);
    show_RTT_list2matrix(RTT_list, matrix);
    File f("matrix.txt");
    f.matrix_out2file(matrix);
    matrix_print(matrix);
}


