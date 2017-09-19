#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
typedef vector<list<int>> adjList;

void set_false(bool*& visited, unsigned int numSections) {
	for (int i = 0; i < numSections; i++) {
		visited[i] = false;
	}
}

void dfs(adjList& trails, bool*& visited, unsigned int section) {
	visited[section] = true;
	list<int>::iterator it;
	for (it = trails[section].begin(); it != trails[section].end(); it++)
		if (!visited[*it])
			dfs(trails, visited, *it);
}

void dfs_order(stack<int>& stack, adjList& trails, bool*& visited, unsigned int section) {
	visited[section] = true;
	list<int>::iterator it;
	for (it = trails[section].begin(); it != trails[section].end(); it++)
		if (!visited[*it])
			dfs_order(stack, trails, visited, *it);

	stack.push(section);
}

int main() {
	unsigned int T, numSections, numConnections, x, y, i;
	cin >> T;
	if (T <= 0) return 0;
	while (T--) {
		cin >> numSections >> numConnections;
		int components = 0;
		adjList trails(numSections), revTrails(numSections);
		bool * visited = new bool[numSections]();
		stack<int> stack;
		bool cannotEscape = false;

		/* Create adjacency lists */
		for (i = 0; i < numConnections; i++) {
			cin >> x >> y;
			trails[x].push_back(y);
			revTrails[y].push_back(x);
		}

		for (i = 0; i < numSections; i++)
			if (!visited[i])
				dfs_order(stack, trails, visited, i);

		set_false(visited, numSections);

		while (!stack.empty()) {
			int v = stack.top();
			stack.pop();
			if (!visited[v]) {
				dfs(revTrails, visited, v);
				components++;
				if (components != 1) {
					while (!stack.empty())
						stack.pop();
					cannotEscape = true;
					break;
				}
			}
		}

		if (cannotEscape)
			cout << "Oh, oh!" << endl;
		else
			cout << "Gotta Catch Them All!" << endl;
	}

	return 0;
}