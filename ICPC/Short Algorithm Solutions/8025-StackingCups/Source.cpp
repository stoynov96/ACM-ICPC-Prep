#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Cup {
	string color;
	short size;
	
	Cup(string c, int s) : color(c), size(s) {}
};

struct comparitor {
	bool operator() (Cup& L, Cup& R) {
		return L.size > R.size;
	}
};

int main() {
	short i, N, in2;
	string in1;

	cin >> N;
	while (cin) {
		priority_queue<Cup, vector<Cup>, comparitor> cups;
		for (i = 0; i < N; i++) {
			cin >> in1;

			if (in1[0] >= 'a') {
				cin >> in2;
				cups.push(Cup(in1, in2 * 2));
			}
			else {
				in2 = stoi(in1);
				cin >> in1;
				cups.push(Cup(in1, in2));
			}
		}

		for (i = 0; i < N; i++) {
			cout << cups.top().color << endl;
			cups.pop();
		}
		cin >> N;
	}

	return 0;
}