


#include <stdio.h>

#include <vector>

#include <utility>
#include <algorithm>

int main() {

	setbuf(stdout, NULL);


	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		int N, M, K;

		scanf("%d %d %d", &N, &M, &K);

		std::vector<int> data;
		data.resize(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &data[j]);
		}
		
		std::vector<std::pair<int, int>> index;
		index.resize(M);
		for (int j = 0; j < M; j++) {
			int num;
			scanf("%d", &num);
			index[j] = std::make_pair(num, j);
		}

		std::sort(index.begin(), index.end());


		int counter = 0;
		std::vector<int> inc(M, 0);
		for (int j = 0; j < N - M + 1; j++) {

			for (int k = 0; k < M; k++) {
				int penalty = 0;
				int n = data[j + index[k].second];
				int count = 0;
				for (int l = 0; l < k; l++) {
					int n2 = data[j + index[l].second];
					if (n2 < n) {
						if (count < inc[l]) {
							count = inc[l];
						}
						else {
							penalty++;
						}
					}
					else {
						penalty++;
					}
					if (penalty > K)
						break;
				}
				inc[k] = count + 1;
				if (inc[k] >= M - K) {
					counter++;
					break;
				}
			}
			
		}


		int Answer;

		Answer = counter;

		printf("Case #%d\n", i + 1);
		printf("%d\n", Answer);

	}


	return 0;
}



