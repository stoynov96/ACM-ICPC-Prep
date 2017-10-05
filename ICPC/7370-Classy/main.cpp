#include <algorithm> // Max
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ll;

struct Person {
	string name;
	stack<string> specStack;
	ll rSum = 0;

};

int main() {
	int numPeople, maxNumSpecs, currNumSpecs, specValue, i, j;
	string spec;
	char specFirst;
	while (cin >> numPeople) {
		vector<int> specValueArr(numPeople);
		Person * people = new Person[numPeople];
		maxNumSpecs = 0;

		for (i = 0; i < numPeople; i++) {
			cin >> people[i].name;	// Store name of person
			people[i].name.pop_back();	// Delete colon
			currNumSpecs = 0;

			spec = "";
			while (spec != "class") {
				cin >> spec;
				if (spec == "class") break;
				people[i].specStack.push(spec);
				currNumSpecs++;
			}

			maxNumSpecs = max(maxNumSpecs, currNumSpecs);
		}

		/* Find running sum (ranking) for each person */
		for (i = 0; i < numPeople; i++) {
			for (j = 0; j < maxNumSpecs; j++) {
				if (!people[i].specStack.empty()) {
					specFirst = (people[i].specStack.top())[0];	// Get first char of spec string on top of stack
					people[i].specStack.pop();

					if (specFirst == 'l') specValue = 0;
					else if (specFirst == 'm') specValue = 1;
					else if (specFirst == 'u') specValue = 2;

					people[i].rSum = people[i].rSum * 3 + specValue;
					continue;
				}
				else {
					people[i].rSum = people[i].rSum * 3 + 1;	// Assumed middle
				}
			}
		}

		/* Sort our peeps */
		for (i = 0; i < numPeople - 1; i++) {
			for (j = 0; j < numPeople - i - 1; j++) {
				if (people[j].rSum < people[j+1].rSum) {
					Person temp = people[j];
					people[j] = people[j + 1];
					people[j + 1] = temp;
				}
				else if (people[j].rSum == people[j + 1].rSum) {
					if (people[j].name > people[j + 1].name) {
						Person temp = people[j];
						people[j] = people[j + 1];
						people[j + 1] = temp;
					}
				}
			}
		}

		/* Print in order */
		for (i = 0; i < numPeople; i++) {
			cout << people[i].name << endl;
		}
	}

	return 0;
}