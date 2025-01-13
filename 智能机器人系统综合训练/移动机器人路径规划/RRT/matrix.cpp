#include "matrix.h"


void matrix_generate_barrier(int matrix[20][20], int line_begin, int line_end, int column_begin, int column_end) {

	for (int i = line_begin; i <= line_end; i++) {
		for (int j = column_begin; j <= column_end; j++) {
			matrix[i][j] = 20;
		}
	}
}



void matrix_init(int matrix[20][20]) {
	matrix_generate_barrier(matrix, 2, 12, 7, 9);
}

void matrix_print(int matrix[20][20]) {
	for (int i = 0; i < 20; i++) {
		if (i < 10) {
			cout << "line:" << i << "  ";
		}
		else {
			cout << "line:" << i << " ";
		}
		for (int j = 0; j < 20; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}