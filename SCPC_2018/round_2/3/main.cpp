


#include <stdio.h>

#include <vector>
#include <map>
#include <queue>

#include <utility>
#include <tuple>


int main() {

	setbuf(stdout, NULL);


	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N, M;

		scanf("%d %d", &N, &M);

		std::vector<std::map<int, int>> graph(N, std::map<int, int>());

		for (int j = 0; j < M; j++) {
			int a, b, c;

			scanf("%d %d %d", &a, &b, &c);

			graph[a - 1][b - 1] = c;
			graph[b - 1][a - 1] = c;
		}

		std::vector<int> left(N, -1);
		std::vector<int> left_e(N, 200005);
		std::vector<int> right(N, -1);
		std::vector<int> right_e(N, 200005);

		


		std::queue<std::tuple<int, int, int>> q;

		left[0] = 0;
		left_e[0] = 0;
		q.push(std::make_tuple(0, 0, 0));
		while (!q.empty()) {
			int node1 = std::get<0>(q.front());
			int edge1 = std::get<1>(q.front());
			int acc1 = std::get<2>(q.front());
			q.pop();

			for ( auto it : graph[node1] ) {
				int node2 = it.first;
				int edge2 = it.second;
				int acc2 = acc1 + edge2;

				if (edge2 >= edge1) {
					if (left[node2] == -1) {
						left[node2] = acc2;
						left_e[node2] = edge2;
						q.push(std::make_tuple(node2, edge2, acc2));
					} else if (left[node2] > acc2) {
						left[node2] = acc2;
						q.push(std::make_tuple(node2, edge2, acc2));
						if (left_e[node2] > edge2)
							left_e[node2] = edge2;
					} else if (left_e[node2] > edge2) {
						left_e[node2] = edge2;
						q.push(std::make_tuple(node2, edge2, acc2));
					}
				}
			}
		}


		std::queue<std::tuple<int, int, int>> q1;

		right[N - 1] = 0;
		right_e[N - 1] = 0;
		q1.push(std::make_tuple(N - 1, 0, 0));
		while (!q1.empty()) {
			int node1 = std::get<0>(q1.front());
			int edge1 = std::get<1>(q1.front());
			int acc1 = std::get<2>(q1.front());
			q1.pop();

			for ( auto it : graph[node1] ) {
				int node2 = it.first;
				int edge2 = it.second;
				int acc2 = acc1 + edge2;

				if (edge2 >= edge1) {
					if (right[node2] == -1) {
						right[node2] = acc2;
						right_e[node2] = edge2;
						q1.push(std::make_tuple(node2, edge2, acc2));
					} else if (right[node2] > acc2) {
						right[node2] = acc2;
						q1.push(std::make_tuple(node2, edge2, acc2));
						if (right_e[node2] > edge2)
							right_e[node2] = edge2;
					} else if (right_e[node2] > edge2) {
						right_e[node2] = edge2;
						q1.push(std::make_tuple(node2, edge2, acc2));
					}
				}
			}
		}
		

		//for (int j = 0; j < N; j++) {
			//printf("%d : %d %d\n", j, left[j], right[j]);
		//}


		int Answer;

		Answer = -1;

		for (int j = 0; j < N; j++) {
			if (left[j] != -1 && right[j] != -1) {
				if (Answer == -1)
					Answer = left[j] + right[j];
				else if (Answer > left[j] + right[j])
					Answer = left[j] + right[j];
			}
		}



		printf("Case #%d\n", i + 1);
		printf("%d\n", Answer);

	}


	return 0;
}



