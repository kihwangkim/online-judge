


#include <stdio.h>

#include <vector>

#include <utility>

using namespace std;

vector<vector<char>> map;
int R_start_i, R_start_j;
int B_start_i, B_start_j;
int R_i, R_j;
int B_i, B_j;
int O_i, O_j;
bool R_flag, B_flag;
int end_len = 20;

vector<pair<int, int>> list = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)};
vector<pair<int, int>> stack = {};


void R_move(pair<int, int> way) {
	while (map[R_i][R_j] == '.') {
		R_i = R_i + way.first;
		R_j = R_j + way.second;
		if (R_i == B_i && R_j == B_j) break;
	}
	if (map[R_i][R_j] == 'O') {
		R_flag = true;
		R_i = -10;
		R_j = -10;
	}
	R_i = R_i - way.first;
	R_j = R_j - way.second;
}

void B_move(pair<int, int> way) {
	while (map[B_i][B_j] == '.') {
		B_i = B_i + way.first;
		B_j = B_j + way.second;
		if (R_i == B_i && R_j == B_j) break;
	}
	if (map[B_i][B_j] == 'O') {
		B_flag = true;
		B_i = -10;
		B_j = -10;
	}
	B_i = B_i - way.first;
	B_j = B_j - way.second;
}


void go() {
	R_i = R_start_i;
	R_j = R_start_j;
	B_i = B_start_i;
	B_j = B_start_j;
	R_flag = false;
	B_flag = false;

	int len = 0;

	for ( auto it : stack ) {
		len++;
		if ((R_i * it.first > B_i * it.first) || (R_j * it.second > B_j * it.second)) {
			R_move(it);
			B_move(it);
		}
		else {
			B_move(it);
			R_move(it);
		}


		if ((R_flag == true) || (B_flag == true)) {
			break;
		}
	}
	if ((R_flag == true) && (B_flag == false)) {
		if (len < end_len) {
			end_len = len;
		}
	}
}


void dfs() {
	if (stack.size() > end_len)
		return;
	if (stack.size() == 10 || stack.size() == end_len - 1) {
		go();
		return;
	}

	for ( auto it : list ) {
		stack.push_back(it);
		dfs();
		stack.pop_back();
	}
}

int main() {

	int N, M;
	int dummy;

	dummy = scanf("%d %d", &N, &M);

	map = vector<vector<char>>(N, vector<char>(M, 0));
	char temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			do {
				dummy = scanf("%c", &temp);
			} while (temp == '\n');
			map[i][j] = temp;
			if (temp == 'R') {
				R_start_i = i;
				R_start_j = j;
				map[i][j] = '.';
			} else if (temp == 'B') {
				B_start_i = i;
				B_start_j = j;
				map[i][j] = '.';
			} else if (temp == 'O') {
				O_i = i;
				O_j = j;
			}

		}
	}

	dfs();
	

	if (end_len <= 10)
		printf("%d\n", end_len);
	else
		printf("-1\n");




	return 0;
}



