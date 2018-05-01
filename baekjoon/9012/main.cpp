


#include <stdio.h>



int main() {

	int T;
	int dummy;

	dummy = scanf("%d", &T);

	dummy = getchar();

	for (int i = 0; i < T; i++) {
		int count = 0;
		bool flag = true;
		while (true) {
			char c = getchar();
			if (c == '\0' || c == '\n') {
				if (count == 0)
					printf("YES\n");
				else
					printf("NO\n");
				break;
			}
			else if (c == '(') {
				count++;
			}
			else if (c == ')') {
				count--;
				if (count < 0) {
					printf("NO\n");
					flag = false;
					break;
				}
			}
		}

		if (flag == false) {
			while (true) {
				char c = getchar();
				if (c == '\0' || c == '\n')
					break;
			}
		}
	}

	return 0;
}



