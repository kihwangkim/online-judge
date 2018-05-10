


#include <stdio.h>

#include <vector>
#include <set>
#include <queue>
#include <stack>

void DFS(std::vector<std::set<int>>& map, int start) {
	std::vector<bool> visited(map.size(), false);
	std::stack<int> st;

	int count = map.size();
	st.emplace(start);

	while (st.size() != 0) {
		int index = st.top();
		st.pop();
		if (visited[index] == true) {
			continue;
		}
		visited[index] = true;
		count--;
		if (count == 0) {
			printf("%d\n", index + 1);
			break;
		}
		else {
			printf("%d ", index + 1);
		}
		for (auto it = map[index].rbegin(); it != map[index].rend(); it++) {
			st.emplace(*it);
		}
	}
}

void BFS(std::vector<std::set<int>>& map, int start) {
	std::vector<bool> visited(map.size(), false);
	std::queue<int> q;

	int count = map.size();
	q.emplace(start);

	while (q.size() != 0) {
		int index = q.front();
		q.pop();
		if (visited[index] == true) {
			continue;
		}
		visited[index] = true;
		count--;
		if (count == 0) {
			printf("%d\n", index + 1);
			break;
		}
		else {
			printf("%d ", index + 1);
		}
		for (auto it = map[index].begin(); it != map[index].end(); it++) {
			q.emplace(*it);
		}
	}
}

int main() {

	int N, M, V;
	int dummy;

	dummy = scanf("%d %d %d", &N, &M, &V);

	std::vector<std::set<int>> map(N, std::set<int>());

	for (int i = 0; i < M; i++) {
		int a, b;
		dummy = scanf("%d %d", &a, &b);
		map[a - 1].insert(b - 1);
		map[b - 1].insert(a - 1);
	}

	DFS(map, V - 1);
	BFS(map, V - 1);

	return 0;
}



