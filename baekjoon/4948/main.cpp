


#include <stdio.h>

#define MAX (123456*2)

bool prime_list[MAX] = {false, };
int index_list[MAX] = {0, };

void make_prime_list() {
	prime_list[0] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime_list[i - 1] == true)
			continue;
		int num = i + i;
		for (;;) {
			if (num > MAX)
				break;
			prime_list[num - 1] = true;
			num += i;
		}
	}
}

bool is_prime(int num) {
	return !prime_list[num - 1];
}

void make_index_list() {
	int count = 0;
	for (int i = 0; i < MAX; i++) {
		if (is_prime(i + 1) == true) {
			count++;
		}
		index_list[i] = count;
	}
}

int main() {

	int dummy;
	int n;

	make_prime_list();
	make_index_list();

	for (;;) {
		dummy = scanf("%d", &n);
		if (n == 0) break;
		int count = index_list[2 * n - 1] - index_list[n - 1];
		printf("%d\n", count);
	}

	return 0;
}



