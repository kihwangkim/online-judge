#include <stdio.h>

#include <vector>
#include <set>

#include <algorithm>


int main() {
	setbuf(stdout, NULL);

	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N, M;

		scanf("%d %d", &N, &M);

		std::vector<std::set<int>> graph_1way(N, std::set<int>());
		std::vector<std::set<int>> graph_2way(N, std::set<int>());

		for (int j = 0; j < M; j++) {
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			n1--;
			n2--;

			if (n1 < n2)
				graph_1way[n1].emplace(n2);
			else
				graph_1way[n2].emplace(n1);
			graph_2way[n1].emplace(n2);
			graph_2way[n2].emplace(n1);
		}

		int nop = 0;
		for (int j = 0; j < N; j++) {
			for ( auto it : graph_1way[j] ) {
				for ( auto it2 : graph_1way[it] ) {
					if (graph_1way[j].count(it2) == 1) {
						if (graph_2way[j].size() == 2 || graph_2way[it].size() == 2 || graph_2way[it2].size() == 2) {
							nop++;
							graph_2way[j].erase(it2);
							graph_2way[it2].erase(j);
							graph_1way[j].erase(it2);
						}
					}
				}
			}
		}
				


		int answer = N - nop;


		printf("Case #%d\n", i + 1);
		printf("%d\n", answer);
	}

	return 0;
}
