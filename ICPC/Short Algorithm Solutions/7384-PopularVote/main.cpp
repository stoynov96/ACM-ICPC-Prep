#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, total, maxVotes, maxCandidate, numCandidates, votes;
	bool winnerExists = false;
	cin >> T;
	while (T--) {
		cin >> numCandidates;
		total = 0;
		maxVotes = -1;

		/* See if a candidate has the most votes currently */
		for (int i = 1; i <= numCandidates; i++) {
			cin >> votes;
			total += votes;
			if (votes > maxVotes) {
				maxVotes = votes;
				maxCandidate = i;
				winnerExists = true;	// At least one unique number of votes
			}
			else if (votes == maxVotes)	// No unique number of votes
				winnerExists = false;
		}

		if (!winnerExists)
			cout << "no winner" << endl;
		else if (maxVotes > (total / 2))
			cout << "majority winner " << maxCandidate << endl;
		else
			cout << "minority winner " << maxCandidate << endl;
	}

	return 0;
}