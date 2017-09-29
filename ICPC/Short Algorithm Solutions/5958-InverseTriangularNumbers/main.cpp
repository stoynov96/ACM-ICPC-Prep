#include <iostream>
using namespace std;
typedef long long ll;

ll sumMul(ll n) {
	return n * (n + 1) / 2;
}

ll search(bool & isTri, ll n) {
	ll x = 0, y = 0;
	while (x < n) {
		y++;
		x = y * (y + 1) / 2;
	}
	if (x != n)	isTri = false;
	else		isTri = true;
	return y;
}

int main() {
	ll n, k;
	bool isTri = false;
	while (cin >> n) {
		int sideDots = search(isTri, n);
		if (isTri)	cout << sideDots << endl;
		else		cout << "bad" << endl;
	}

	return 0;
}