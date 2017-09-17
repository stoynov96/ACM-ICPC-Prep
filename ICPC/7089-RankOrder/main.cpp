#include <iostream>
#include <algorithm>	// sort
#include <vector>		// vector
#include <utility>		// pair, make_pair
using namespace std;

typedef pair<int, int> ipair;

bool comparePairs(ipair a, ipair b) {
	return (a.first > b.first);
}

int main() {
	int numCompetitors, score, i, caseNumber = 1;
	bool agreed;

	while (cin >> numCompetitors) {
		/* Pair is: <score, index> */
		vector<ipair> firstJudgeScores(numCompetitors), secondJudgeScores(numCompetitors);
		agreed = true;

		/* Pairs up contestant scores with index */
		for (i = 0; i < numCompetitors; i++) {
			cin >> score;
			firstJudgeScores[i] = make_pair(score, i);
		}
		for (i = 0; i < numCompetitors; i++) {
			cin >> score;
			secondJudgeScores[i] = make_pair(score, i);
		}

		/* Sort by score (descending) */
		sort(firstJudgeScores.begin(), firstJudgeScores.end(), comparePairs);
		sort(secondJudgeScores.begin(), secondJudgeScores.end(), comparePairs);

		/* Prints index+1 wherever they disagreed; otherwise prints agree */
		for (i = 0; i < numCompetitors; i++) {
			if (firstJudgeScores[i].second != secondJudgeScores[i].second) {
				cout << "Case " << caseNumber++ << ": " << i + 1 << endl;
				agreed = false;
				break;
			}
		}
		if (agreed)
			cout << "Case " << caseNumber++ << ": agree" << endl;
	}

	return 0;
}