#include <iostream>
#include <vector>

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
		int *prices = new int[n];

		ll sm = 0, smAll = 0;

		vector <int> lst;

		// Input prices
		smAll = 0;	// TODO: remove. redundant
		for (i = 0; i < n; ++i) {
			cin >> prices[i];
			smAll += prices[i];
		}
		
		for (i = k; i < n; ++i) {
			if ( ! ((i+1) % (k+1)) ) {
				lst.insert(lst.begin(), 0);
			}
			// cout << i << ": " << lst.size() << endl;	// debug
			// cout << "  lst= [ "; for (int j = 0; j < lst.size(); j++) {cout << lst[j] << " ";} cout << "]" << endl;	// debug
			if (prices[i] > lst[0]) {
				insert(lst, prices[i]);
			}
			// cout << "  lst= [ "; for (int j = 0; j < lst.size(); j++) {cout << lst[j] << " ";} cout << "]" << endl;	// debug
		}

		sm = 0;	// TODO: remove. redundant
		for (i = 0; i < lst.size(); ++i) {
			sm += lst[i];
		}
		// cout << "DEBUG: " << smAll << " " << sm << endl; 	//debug
		cout << smAll - sm;
	}
	static void insert(vector<int> &lst, int num) {
		int ind = binS(lst, num, 0, lst.size()-1);
		// cout << "  ind = " << ind << endl;	// debug
		for (int i = 0; i < ind; ++i) {
			lst[i] = lst[i+1];
		}
		lst[ind] = num;
	}
	static int binS(vector<int> &lst, int num, int l, int r) {
		if (l >= r) return l;
		int m = (l + r + 1) / 2;
		if (num < lst[m]) return binS(lst, num, l, m-1);
		return binS(lst, num, m, r);
	}
};

int main() {
	ll n, k;
	char el = '\0';
	while (cin >> n) {
		cin >> k;
		cout << el;
		el = '\n';
		Solution::hotelRewards(n,k);
	}
}

