#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void solution_1() {
	int T, numPrizes, numTypes, currTypeLength;
	cin >> T;
	while (T--)
	{
		cin >> numPrizes >> numTypes;
		vector<vector<int>> typesForPrizes(numPrizes);
		vector<int> values(numPrizes);
		vector<int> userTypes(numTypes);

		/* Store types needed to get prize */
		for (int i = 0; i < numPrizes; i++)
		{
			cin >> currTypeLength;
			typesForPrizes[i] = vector<int>(currTypeLength);

			for (int j = 0; j < currTypeLength; j++)
				cin >> typesForPrizes[i][j];

			/* Store value for this prize */
			cin >> values[i];
		}

		/* Store amount user has of each sticker type */
		for (int i = 0; i < numTypes; i++)
			cin >> userTypes[i];

		/* Find total from minimum sticker type of user for typesForPrizes row */
		int total = 0;
		for (int i = 0; i < numPrizes; i++)
		{
			int leastType = userTypes[typesForPrizes[i][0] - 1];

			for (int j = 0; j < typesForPrizes[i].size(); j++)
				if (userTypes[typesForPrizes[i][j] - 1] < leastType)
					leastType = userTypes[typesForPrizes[i][j] - 1];

			/* Increase by how many times the user can buy the prize */
			total += leastType * values[i];
		}

		cout << total << endl;
	}
}

int main() {
	solution_1();

	return 0;
}