#include <stdio.h>
#include <math.h>
#include <windows.h>

int main () {
	system ("color 2");
	while (1) {
		int a = rand( ) % 9;
		printf("  %d  ", a);
		Sleep(0.1);
	}
}