


#include <stdio.h>


#define MAX 1001

bool prime_list[MAX] = {false, };

void make_prime_list() {
	prime_list[0] = true;
	prime_list[1] = true;

	for (int i = 2; i * i < MAX; i++) {
		if (prime_list[i] == true)
			continue;
		for (int j = 2; j < MAX; j++) {
			if (i * j >= MAX)
				break;
			prime_list[i * j] = true;
		}
	}
}

int main() {

	int N;
	int dummy;

	dummy = scanf("%d", &N);

	make_prime_list();

	int num;
	int count = 0;

	for (int i = 0; i < N; i++) {
		dummy = scanf("%d", &num);
		if (prime_list[num] == false)
			count++;
	}
	printf("%d\n", count);

	return 0;
}



