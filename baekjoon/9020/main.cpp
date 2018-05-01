


#include <stdio.h>

#define MAX 10000

#define IS_PRIME(X) (!prime_list[X-1])

bool prime_list[MAX] = {false, };

void make_prime_list() {
	prime_list[0] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime_list[i - 1] == true)
			continue;
		int num = i + i;
		while (true) {
			if (num > MAX)
				break;
			prime_list[num - 1] = true;
			num += i;
		}
	}
}

int main() {

	int N;
	int dummy;

	make_prime_list();

	dummy = scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%d", &num);
		
		for (int j = num / 2; j > 0; j--) {
			int left = j;
			int right = num - j;

			if (IS_PRIME(left) && IS_PRIME(right)) {
				printf("%d %d\n", left, right);
				break;
			}
		}
	}

	return 0;
}



