


#include <stdio.h>

#include <vector>

#include <string>

#include <algorithm>

int pow(int n, int k) {
	int out = 1;
	for (int i = 0; i < k; i++) {
		out *= n;
	}
	return out;
}

bool is_h(int n) {
	int len = std::to_string(n).size();
	std::string s = std::to_string(n);
	std::reverse(s.begin(), s.end());
	int output = std::stoi(s);

	return (n == output);
}


int get_h(int n) {
	int len = std::to_string(n).size();
	int base;

	if (len == 1) {
		return n;
	}

	base = n / pow(10, len / 2);

	int output = 0;
	if (len % 2 == 1) {
		int center = base % 10;
		base = base / 10;

		output += base * pow(10, len / 2 + 1);
		output += center * pow(10, len / 2);
		std::string s = std::to_string(base);
		std::reverse(s.begin(), s.end());
		output += std::stoi(s);
	}
	else{
		output += base * pow(10, len / 2);
		std::string s = std::to_string(base);
		std::reverse(s.begin(), s.end());
		output += std::stoi(s);

	}

	return output;
}


int get_max_h(int n) {
	int len = std::to_string(n).size();

	int output = get_h(n);

	if (n == 10)
		output = 9;

	if (output > n) {
		output = get_h(n - pow(10, len / 2));
	}


	return output;
}



int main() {
	setbuf(stdout, NULL);

	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n;
		int K = 0;
		int j;

		std::vector<int> h;

		scanf("%d", &n);

		int t = n;
		for (j = 0; j < 3; j++) {
			int v = get_max_h(t);
			t = t - v;
			h.push_back(v);
			if (t == 0)
				break;
		}
		if (t != 0)
			K = 0;
		else
			K = j + 1;

		if (K == 3) {
			for (int l = 1; l < n / 2 + 1; l++) {
				if (is_h(l) && is_h(n - l)) {
					h.clear();
					h.push_back(n - l);
					h.push_back(l);
					K = 2;
					break;
				}
			}
		}



		printf("Case #%d\n", i + 1);
		printf("%d", K);
		for (int j = 0; j < K; j++)
			printf(" %d", h[j]);
		printf("\n");
	}

	return 0;
}



