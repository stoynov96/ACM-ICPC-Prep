#include <iostream>
#include <math.h>

void Solution(int n);
int findFirstDivisor(int n);

int main() {
	int n;
	while (std::cin >> n) {
		Solution(n);
	}
}

void Solution(int n) {
	if (n == 3) { std::cout << 4 << '\n'; return; }
	if (n < 7) { std::cout << "No such base\n"; return; }
	int firstDiv = findFirstDivisor(n-3);
	std::cout << firstDiv << '\n';
}

int findFirstDivisor(int n) {
/*
Finds the first divisor of a given number n
*/
	int endPoint = n / 2;
	if (n > 20) endPoint = sqrt(n);
	for (int i = 4; i <= endPoint; i++) {
		if (! (n%i) ) return i;
	}
	if (n > 9) {
		if (! (n%2)) return n/2;
		if (! (n%3)) return n/3;
	}
	return n;
}