#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned long long ll;

class Solution {
public:
	static void hotelRewards(ll n, ll k) {
	/*
	Contains solution to the problem
	Parameters:
		n:	ll - number of hotels
		k:	ll - number of points needed to win a free stay
	Returns:	void
	*/
		int i = 0;
		int price;
		int *prices = new int[n+1];
		prices[n] = 0;	// set the last price to 0 to signal end of array (0 is an invalid value for Pi)

		// Input prices
		for (i = 0; i < n; ++i)
			cin >> prices[i];
		
		cout << minCost(n, k, (ll)prices[0], 1, prices+1) << endl;


		// Deallocate memory
		delete [] prices;
	}
	static ll minCost(ll n, ll k, ll rSum, int currPoints, int *prices) {
	/*
	TODO: Add description
	*/
		if (currPoints < 0) return ULLONG_MAX;
		// cout << *prices << ":\trSum= " << rSum << " \tp= " << currPoints << "\n";
		if (!*prices) return rSum;
		return min (minCost(n, k, rSum+prices[0], currPoints+1, prices+1), minCost(n, k, rSum, currPoints-k, prices+1));
	}
};

int main() {
	ll n, k;
	while (cin >> n) {
		cin >> k;
		Solution::hotelRewards(n,k);
	}
}

