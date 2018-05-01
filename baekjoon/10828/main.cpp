


#include <stdio.h>
#include <string.h>

int stack[10000];
int sp;


int main() {

	int N;
	int dummy;

	char str[20];

	sp = -1;

	dummy = scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%s", str);
		if (!strcmp(str, "push")) {
			dummy = scanf("%d", &num);
			stack[++sp] = num;
		}
		else if (!strcmp(str, "pop")) {
			printf("%d\n", sp == -1 ? -1 : stack[sp--]);
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", sp + 1);
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", sp == -1 ? 1 : 0);
		}
		else if (!strcmp(str, "top")) {
			printf("%d\n", sp == -1 ? -1 : stack[sp]);
		}
	}

	return 0;
}



