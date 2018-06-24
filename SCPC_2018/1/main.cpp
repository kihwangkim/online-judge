


#include <stdio.h>
#include <cstdint>
#include <functional>

#include <vector>
#include <utility>
#include <algorithm>


int main() {
	setbuf(stdout, NULL);

	uint64_t T;
	scanf("%lu", &T);

	uint64_t number;
	uint64_t inter;
	uint64_t score;
	uint64_t i, j;

	uint64_t answer;

	for (i = 0; i < T; i++) {
		scanf("%lu %lu", &number, &inter);

		std::vector<uint64_t> players(number, 0);

		for (j = 0; j < number; j++) {
			scanf("%lu", &score);
			players[j] = score;
		}

		std::sort (players.begin(), players.end());

		std::vector<uint64_t> cross;
		std::make_heap(cross.begin(), cross.end(), std::greater<uint64_t>());
		uint64_t max = 0;

		for ( auto it : players ) {
			uint64_t start = it;
			uint64_t end = it + inter + 1;

			cross.push_back(end);
			std::push_heap(cross.begin(), cross.end(), std::greater<uint64_t>());

			while (cross.front() <= start) {
				std::pop_heap(cross.begin(), cross.end(), std::greater<uint64_t>());
				cross.pop_back();
			}

			if (max < cross.size())
				max = cross.size();
		}
		
		answer = max;

		printf("Case #%lu\n", i + 1);
		printf("%lu\n", answer);
	}

	return 0;
}



