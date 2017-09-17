#include <iostream>
#include <string>
using namespace std;

int main() {
	string base, exp;
	int iBase, iExp;

	/* Store patterns from exponents */
	int expPattern[10][10];
	for (int i = 0; i < 10; i++) {
		if (i == 0 || i == 1 || i == 5 || i == 6) continue;
		if (i == 4) {
			expPattern[i][0] = 6;
			expPattern[i][1] = 4;
			expPattern[i][2] = 6;
			expPattern[i][3] = 4;
		} else if (i == 9) {
			expPattern[i][0] = 1;
			expPattern[i][1] = 9;
			expPattern[i][2] = 1;
			expPattern[i][3] = 9;
		} else if (i == 2) {
			expPattern[i][0] = 6;
			expPattern[i][1] = 2;
			expPattern[i][2] = 4;
			expPattern[i][3] = 8;
		} else if (i == 3) {
			expPattern[i][0] = 1;
			expPattern[i][1] = 3;
			expPattern[i][2] = 9;
			expPattern[i][3] = 7;
		} else if (i == 7) {
			expPattern[i][0] = 1;
			expPattern[i][1] = 7;
			expPattern[i][2] = 9;
			expPattern[i][3] = 3;
		} else {
			expPattern[i][0] = 6;
			expPattern[i][1] = 8;
			expPattern[i][2] = 4;
			expPattern[i][3] = 2;
		}
	}

	while (true) {
		cin >> base >> exp;
		if (base == "0" && exp == "0") {
			break;
		}

		/* Convert from string to int */
		if (exp.length() > 2) {
			exp = exp.substr(exp.length() - 2, 2);	// Get last two digits
			if (exp == "00") {	// Edge case: Large number ending in 00 is divisible by 4 (since we can divide by 100)
				exp = "4";
			}
			iExp = stoi(exp);
		} else {
			iExp = stoi(exp);
		}
		iBase = base.back() - '0';	// Distance from '0' in ASCII is the integer representation

		if (iExp == 0) {
			cout << "1" << endl;
			continue;
		}

		/* Single Cycle: 0, 1, 5, 6 */
		else if (iBase == 0 || iBase == 1 || iBase == 5 || iBase == 6) {
			cout << iBase << endl;
			continue;
		}

		/* Double and Quad Cycles */
		iExp %= 4;
		cout << expPattern[iBase][iExp] << endl;
	}

	return 0;
}