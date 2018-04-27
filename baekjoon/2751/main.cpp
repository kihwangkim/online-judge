


#include <stdio.h>

#define MAX 1000000

int main() {

	int N;
	bool count[MAX * 2 + 1] = {false, };
	int dummy;

	dummy = scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%d", &num);
		count[num + MAX] = true;
	}

	for (int i = 0; i < MAX * 2 + 1; i++) {
		if (count[i] == true)
			printf("%d\n", i - MAX);
	}

	return 0;
}



