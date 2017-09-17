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
	// TODO: Optimize by only checking prime numbers (a complex number will never be the FIRST divisor)
	//		Note: Start the seave of erathosetenes from 4 instead of 2, because 2 and 3 cannot be used as an answer for the first divisor because the base needs to be > 3
	int halfN = n / 2;
	for (int i = 4; i <= halfN; i++) {
		if (! (n%i) ) return i;
	}
	return n;
}