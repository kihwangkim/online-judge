


#include <stdio.h>
#include <cstdint>
#include <functional>

#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
#include <list>

bool sort_func(std::pair<int64_t, int64_t> a, std::pair<int64_t, int64_t> b) {
	return a.first < b.first;
}

int main() {

	int N;
	int dummy;

	dummy = scanf("%d", &N);

	std::vector<std::pair<int64_t, int64_t>> lecs(N, std::pair<int64_t, int64_t>());

	for (int i = 0; i < N; i++) {
		int64_t begin, end, num;

		dummy = scanf("%lu %lu %lu", &num, &begin, &end);

		lecs[i] = std::make_pair(begin, end);
	}

	std::sort (lecs.begin(), lecs.end(), sort_func);

	std::vector<int64_t> cross;
	std::make_heap(cross.begin(), cross.end(), std::greater<int64_t>());
	int64_t max = 0;

	for ( auto it : lecs ) {
		int64_t start = it.first;
		int64_t end = it.second;

		cross.push_back(end);
		std::push_heap(cross.begin(), cross.end(), std::greater<int64_t>());

		while (cross.front() <= start) {
			std::pop_heap(cross.begin(), cross.end(), std::greater<int64_t>());
			cross.pop_back();
		}

		if (max < cross.size())
			max = cross.size();
	}

	printf("%ld\n", max);



	return 0;
}



