


#include <stdio.h>



int main() {

	int N;
	bool count[2001] = {false, };
	int dummy;

	dummy = scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%d", &num);
		count[num + 1000] = true;
	}

	for (int i = 0; i < 2001; i++) {
		if (count[i] == true)
			printf("%d\n", i - 1000);
	}

	return 0;
}



