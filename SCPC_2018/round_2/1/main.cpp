


#include <stdio.h>

#include <vector>

int main() {

	setbuf(stdout, NULL);


	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;

		scanf("%d", &N);

		std::vector<int> list;

		list.resize(N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &list[j]);
		}

		std::vector<int> min_list;
		std::vector<int> max_list;

		min_list.resize(N);
		max_list.resize(N);

		int min = 10000001;
		int max = 0;

		for (int j = N - 1; j >= 0; j--) {
			if (min > list[j]) min = list[j];
			min_list[j] = min;
		}
		for (int j = 0; j < N; j++) {
			if (max < list[j]) max = list[j];
			max_list[j] = max;
		}

		int count = 0;
		for (int j = 1; j < N - 1; j++) {
			if (max_list[j - 1] < list[j])
				if (list[j] < min_list[j + 1])
					count++;
		}
		if (list[0] < min_list[1]) count++;
		if (max_list[N - 2] < list[N - 1]) count++;

		int Answer;

		Answer = count;

		printf("Case #%d\n", i + 1);
		printf("%d\n", Answer);

	}


	return 0;
}



