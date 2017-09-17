#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, i, x, y, n;
	string fbStr;
	cin >> T;
	while (T--) {
		fbStr = "";
		cin >> x >> y >> n;
		for (i = 1; i <= n; i++) {
			if (i % x == 0)		fbStr += "Fizz";
			if (i % y == 0)		fbStr += "Buzz";
			if (fbStr == "")	cout << i << endl;
			else				cout << fbStr << endl;
			fbStr.clear();
		}
	}
	return 0;
}