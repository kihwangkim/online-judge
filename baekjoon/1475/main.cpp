


#include <stdio.h>

#define SIZE 20

int main() {

	char N[SIZE];
	int counter[9] = {0, };
	int dummy;

	dummy = scanf("%s", N);

	for (int i = 0; i < SIZE; i++) {
		if (N[i] == '\0') break;
		if (N[i] == '9') N[i] = '6';
		if (N[i] == '6') counter[N[i] - '0'] += 1;
		else counter[N[i] - '0'] += 2;
	}

	int* ptr = counter;
	for (int i = 0; i < 9; i++) {
		if (counter[i] > *ptr)
			ptr = &counter[i];
	}

	printf("%d\n", (*ptr) / 2 + (*ptr) % 2);

	return 0;
}



