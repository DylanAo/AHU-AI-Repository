#include "stack.h"

int main() {
	LinkStack S;
	create_linkstack(S);
	char str[10];
	gets_s(str);
	if (match(S, str)) printf("YES\n");
	else printf("NO\n");
	delete S;
	create_linkstack(S);
	int num = 0;
	scanf("%d", &num);
	conversion(S, num);
	delete S;
}