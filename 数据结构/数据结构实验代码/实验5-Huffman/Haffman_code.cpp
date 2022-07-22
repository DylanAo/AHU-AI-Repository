#include <stdio.h>
#include "HaffmanTree.h"
int main() {
	HTree H;
	HuffmanCode HC;
	char str[100];
	int rate[26]={0};
	gets_s(str);
	collect(str, rate);
	createHTree(H,str,rate);
	creatrHCode(H, HC, rate);
	print_all(rate, HC);
}