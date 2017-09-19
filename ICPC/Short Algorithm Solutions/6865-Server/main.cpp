#include <iostream>
using namespace std;

int main() {
	int numTasks, totalTime, taskTime, tasksCompleted, timePassed;
	bool passedLimit;
	while (cin >> numTasks) {
		cin >> totalTime;
		timePassed = 0, tasksCompleted = 0;
		passedLimit = false;

		/* Find how many tasks can be done before we cross total time limit */
		while (numTasks--) {
			cin >> taskTime;
			if ((timePassed + taskTime <= totalTime) && !passedLimit) {
				tasksCompleted++;
				timePassed += taskTime;
			} else {
				passedLimit = true;
			}
		}

		cout << tasksCompleted << endl;
	}
	return 0;
}