#include <iostream>
#include <math.h>

long long getMultiplier(long long n);

int main() {
	long long n;
	long long * multipliers;
	while (std::cin>>n) {
		long long sm = 0;
		long long halfN = n/2;
		long long multiplier = 1;
		long long * multipliers;

		multipliers = new long long [halfN+1];
		for (long long i = 0; i <= halfN; ++i)	multipliers[i] = 0;
		
		for (long long i = 2; i <= halfN; ++i) {
			multiplier = multipliers[i] + i-1;
			for (long long j = 2*i; j <= halfN; j+= i) {

				multipliers[j] -= (i-1) + (multipliers[i]);
			}

			sm += multiplier * (n/i - 1);
		}
		sm *= 2;
		sm += n-1;

		std::cout << n*n - sm + 3 << '\n';
		delete [] multipliers;
	}
}