#include <iostream>
#include <vector>
using namespace std;

int main() {
	short R, C, i, j, nextPage;
	char blockType;

	while (cin >> R) {
		cin >> C;
		nextPage = 1;

		// Create an (R+2) x (C+2) array (defaults to 0)
		vector<vector<short>> arr(R + 2);
		for (i = 0; i < R + 2; i++)
			arr[i] = vector<short>(C + 2);

		// Set array based on character inputs
		for (i = 1; i < R + 1; i++)
			for (j = 1; j < C + 1; j++) {
				cin >> blockType;
				if (blockType == '.')
					arr[i][j] = nextPage++;
			}

		// Print results
		for (i = 1; i < R + 1; i++) {
			for (j = 1; j < C + 1; j++) {
				if (arr[i][j] != 0) {
					cout << arr[i][j] << " "
						<< arr[i - 1][j] << " "
						<< arr[i][j + 1] << " "
						<< arr[i + 1][j] << " "
						<< arr[i][j - 1] << endl;
				}
			}
		}
		cout << endl;
	}

}