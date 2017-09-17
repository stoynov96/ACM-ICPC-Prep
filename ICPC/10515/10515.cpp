#include <iostream>
#include <string>

short cycleLen[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
bool cycleStartsWithOne[] = {false, false, false, true, false, false, false, true, false, true};

void getInput(short &n, short &m);

int main() {
	short n = 1, m = 1;
	std::string sn, sm;
	while (true) {
		std::cin >> sn >> sm;
		n = sn[sn.size()-1] - '0';
		m = sm[sm.size()-1] - '0';

		if (!(n || m)) break;

		short oldM = m;
		n = n % 10;
		m = m % cycleLen[n];
		if (cycleStartsWithOne && m == 0) m = oldM;

		short startN = n;
		n = 1;
		for (short i = 0; i < m; i++) {
			n = (n*startN) % 10;
		}
		std::cout << n << '\n';
	}
}
