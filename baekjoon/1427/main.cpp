


#include <stdio.h>



int main() {

	int dummy;

	int list[10] = {0, };

	char c;
	while (c = getchar()) {
		if (c == -1) break;
		list[c - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < list[9 - i]; j++) {
			putchar(9 - i + '0');
		}
	}

	printf("\n");

	return 0;
}



