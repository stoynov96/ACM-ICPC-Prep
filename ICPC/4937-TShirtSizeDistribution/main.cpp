#include <iostream>
using namespace std;

int main() {
	int sum, P, Q, shortage, tmp, i, j;

	while (cin >> tmp) {
		sum = 0;
		int arr[7];

		// Get the amount of each shirt size
		arr[0] = tmp;
		sum += arr[0];
		for (i = 1; i <= 6; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		// Get projected attendance
		cin >> P;
		shortage = P;

		// Update the array with formula
		for (i = 0; i < 7; i++) {
			arr[i] = (arr[i] * P) / sum;
			shortage -= arr[i];
		}

		// Fill empty size counts
		for (i = 0; i < 7; i++) {
			if (shortage == 0) break;
			if (arr[i] == 0) {
				arr[i] = 1;
				shortage--;
			}
		}

		// Fill with XL (arr[4])
		arr[4] += shortage;

		// Print out first six elements
		for (i = 0; i < 6; i++)
			cout << arr[i] << " ";

		// Then last one without trailing space
		cout << arr[6] << endl;
	}

	return 0;
}
