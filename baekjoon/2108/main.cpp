


#include <stdio.h>

#define MAX 4000

int main() {

	int N;
	int dummy;

	int list[MAX * 2 + 1] = {0, };

	dummy = scanf("%d", &N);

	int total = 0;

	for (int i = 0; i < N; i++) {
		int num;
		dummy = scanf("%d", &num);

		list[num + MAX]++;

		total += num;
	}

	int count = 0;
	int mid;
	bool mid_check = false;

	int bin_num0, bin_num1;
	int bin = 0;
	int bin_flag = 0;

	int min, max;
	int min_flag = false;

	for (int i = 0; i < MAX * 2 + 1; i++) {
		count += list[i];
		if (!mid_check && count >= N / 2 + 1) {
			mid = i - MAX;
			mid_check = true;
		}

		if (list[i] > bin && list[i] > 0) {
			bin = list[i];
			bin_num0 = i - MAX;
			bin_flag = 1;
		}
		else if (list[i] == bin && bin_flag == 1) {
			bin_num1 = i - MAX;
			bin_flag = 2;
		}

		if (min_flag == false && list[i] != 0) {
			min = i - MAX;
			min_flag = true;
		}
		if (list[i] != 0)
			max = i - MAX;
	}

	float avg = (float) total / (float) N;
	int bin_num = bin_flag == 1 ? bin_num0 : bin_num1;
	int range = max - min;

	printf("%.0f\n", avg);
	printf("%d\n", mid);
	printf("%d\n", bin_num);
	printf("%d\n", range);


	return 0;
}



