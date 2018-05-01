


#include <stdio.h>

#define MAX 10001


int main() {

	int N;
	int dummy;
	int list[MAX] = {0, };

	dummy = scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%d", &num);
		list[num]++;
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < list[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}



