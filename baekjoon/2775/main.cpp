


#include <stdio.h>


int go(int k, int n) {
	bool flag = true;
	int* v = new int[n];
	int* r = new int[n];
	int *up;
	int *down;

	int output;

	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}

	for (int i = 0; i < k; i++) {
		down = flag ? v : r;
		up = flag ? r : v;

		flag = !flag;

		up[0] = down[0];
		for (int j = 1; j < n; j++) {
			up[j] = up[j - 1] + down[j];
		}
	}
	output = up[n - 1];

	delete v, r;

	return output;
}


int main() {

	int T;
	int k, n;

	int dummy;

	dummy = scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		dummy = scanf("%d %d", &k, &n);
		printf("%d\n", go(k, n));
	}


	return 0;
}



