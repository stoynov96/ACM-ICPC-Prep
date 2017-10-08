#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned long long ll;

struct Package {

	int getVolume() {
		return this->volume = this->length * this->width * this->height;
	}

	int length;
	int width;
	int height;
	int volume;
	int weight;
};
struct DeliveryCompany {
	string name;
	int minVolume;
	int dwDivisor;

	friend istream &operator>>(istream &is, DeliveryCompany &dc);
	friend ostream &operator<<(ostream &os, DeliveryCompany &dc);
};
istream &operator>> (istream &is, DeliveryCompany &dc) {
	is >> dc.name >> dc.minVolume >> dc.dwDivisor;
	return is;
}
ostream &operator<< (ostream &os, DeliveryCompany &dc) {
	os << dc.name << ": [" << dc.minVolume << ", " << dc.dwDivisor << "]";
	return os;
}

class Solution {
public:
	static void dimWeights(int c) {
	/*
	Contains solution to the dim weights problem
	Parameters:
		c:	int - number of delivery companies
	Returns:	void
	*/
		Package pac;
		DeliveryCompany* delComps = new DeliveryCompany[c];

		for (int i = 0; i < c; ++i) {
			cin >> delComps[i];
		}

		int dimW = -1, effW = 0;
		int minW = INT_MAX, minJ = 0;
		while (cin >> pac.length) {
			cin >> pac.width >> pac.height >> pac.weight;
			pac.getVolume();

			minW = INT_MAX;
			for (int j = 0; j < c; j++) {
				dimW = 0;
				if (pac.volume >= delComps[j].minVolume) {
					dimW = pac.volume / delComps[j].dwDivisor;
					if (pac.volume % delComps[j].dwDivisor) ++ dimW;
				}
				effW = max (pac.weight, dimW);
				if (effW < minW) {
					minW = effW;
					minJ = j;
				}
			}
			cout << delComps[minJ].name << " " << minW << endl;
		}


	}
};

int main() {
	int c;	// number of delivery companies
	char el = '\0';
	while (cin >> c) {
		// cout << "IN!";	// debug
		cout << el;
		el = '\n';
		Solution::dimWeights(c);
	}
}

