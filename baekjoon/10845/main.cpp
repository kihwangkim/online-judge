


#include <stdio.h>
#include <string.h>


int queue[10000];
int head, tail;



int main() {
	head = 0;
	tail = 0;

	int N;
	int dummy;

	dummy = scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char oper[20];
		dummy = scanf("%s", oper);

		if (!strcmp(oper, "push")) {
			int num;
			dummy = scanf("%d", &num);
			queue[head++] = num;
		}
		else if (!strcmp(oper, "pop")) {
			if (head == tail) {
				printf("-1\n");
			}
			else {
				printf("%d\n", queue[tail++]);
			}
		}
		else if (!strcmp(oper, "size")) {
			printf("%d\n", head - tail);
		}
		else if (!strcmp(oper, "empty")) {
			printf("%d\n", head - tail == 0 ? 1 : 0);
		}
		else if (!strcmp(oper, "front")) {
			printf("%d\n", head - tail == 0 ? -1 : queue[tail]);
		}
		else if (!strcmp(oper, "back")) {
			printf("%d\n", head - tail == 0 ? -1 : queue[head - 1]);
		}
	}

	return 0;
}



