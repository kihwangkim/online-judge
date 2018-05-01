


#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define N 20000
#define LEN 55

char string[N][LEN];
std::vector<std::vector<char*>> len_sorted(LEN, std::vector<char*> ());

bool cmp(char* a, char* b) { return strcmp(a, b) < 0; }

int main() {

	int num;
	int dummy;

	dummy = scanf("%d", &num);

	for (int i = 0; i < num; i++) {

		dummy = scanf("%s", string[i]);

		len_sorted[strlen(string[i])].emplace_back(string[i]);
	}

	for (int i = 0; i < LEN; i++) {
		std::sort (len_sorted[i].begin(), len_sorted[i].end(), cmp);
		char* pre = NULL;
		for ( auto it : len_sorted[i] ) {
			if (pre && strcmp(pre, it) == 0)
				continue;
			printf("%s\n", it);
			pre = it;
		}
	}


	return 0;
}



