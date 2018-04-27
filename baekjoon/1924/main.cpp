


#include <stdio.h>

#include <string>

std::string DAY[] = {
	"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};

int n[12] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {

	int x, y;
	int sum = 0;

	int dummy = scanf("%d %d", &x, &y);


	for (int i = 0; i < x - 1; i++) {
		sum += n[i];
	}

	sum += y;

	printf("%s\n", DAY[sum % 7].c_str());


	return 0;
}



