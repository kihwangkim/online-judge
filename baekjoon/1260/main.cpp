


#include <stdio.h>

#include <vector>
#include <queue>
#include <stack>


void DFS(vector<vector<bool>>& map, start) {
	vector<bool> visited(N, false);
	stack<int> st;

}

void BFS(vector<vector<bool>>& map, start) {
	vector<bool> visited(N, false);
}

int main() {

	int N, M, V;
	int dummy;

	dummy = scanf("%d %d %d", &N, &M, &V);

	std::vector<std::vector<bool>> graph(N, vector<bool>());

	for (int i = 0; i < M; i++) {
		int a, b;
		dummy = scanf("%d %d", &a, &b);
		map[a][b] = true;
		map[b][a] = true;
	}



	return 0;
}



