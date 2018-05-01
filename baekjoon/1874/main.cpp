


#include <stdio.h>


int stack[100000] = {0, };
int pc = -1;



void push(int num) {
	stack[++pc] = num;
}

int pop() {
	return stack[pc--];
}

int top() {
	return stack[pc];
}

int main() {

	int N;
	int dummy;


	dummy = scanf("%d", &N);

	int output[100000] = {0, };
	int p = 0;

	int asc = 1;
	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%d", &num);

		while (true) {
			if (num > top()) {
				push(asc++);
				output[p]++;
			}
			else if (num == top()) {
				pop();
				p++;
				break;
			}
			else {
				printf("NO\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < output[i]; j++) {
			printf("+\n");
		}
		printf("-\n");
	}
		

	return 0;
}



