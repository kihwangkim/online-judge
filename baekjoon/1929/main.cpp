


#include <stdio.h>

#define MAX 1000000

bool prime_list[MAX] = {false, };

void make_prime_list(int max) {
	prime_list[0] = true;
	for (int i = 2; i * i <= max; i++) {
		if (prime_list[i - 1] == true)
			continue;
		int num = i + i;
		while (true) {
			if (num > max)
				break;
			prime_list[num - 1] = true;
			num += i;
		}
	}
}

bool is_prime(int num) {
	return !prime_list[num - 1];
}

int main() {

	int min, max;
	int dummy;

	dummy = scanf("%d %d", &min, &max);

	make_prime_list(max);

	for (int i = min; i <= max; i++) {
		if (is_prime(i) == true)
			printf("%d\n", i);
	}

	return 0;
}



