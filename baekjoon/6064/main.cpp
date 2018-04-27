


#include <stdio.h>


int go(int M, int N, int x, int y) {

	int left = x, right = y;
	int max = M * N;

	while (true) {
		if (left > max && right > max)
			return -1;
		if (left == right)
			return left;

		if (left < right)
			left += M;
		else
			right += N;
	}
}

int main() {

	int T;
	int M, N, x, y;
	int dummy;

	dummy = scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		dummy = scanf("%d %d %d %d", &M, &N, &x, &y);
		int output = go(M, N, x, y);
		printf("%d\n", output);
	}

	return 0;
}



