#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

typedef vector<list<int>> adjList;

/* Returns an adjacency list with reversed directed edges */
adjList transpose(adjList &trails, int numSections) {
	adjList invTrails(numSections);	// Inversed trails
	for (int v = 0; v < numSections; v++) {
		list<int>::iterator it;

		/* Edges put backwards */
		for (it = trails[v].begin(); it != trails[v].end(); it++)
			invTrails[*it].push_back(v);
	}

	return invTrails;
}

/* Depth First Search through adjacency list with stack tracking*/
void dfsStack(int section, vector<bool> &visited, stack<int> &stack, adjList &trails) {
	visited[section] = true;

	/* Recursively iterate as deep as possible */
	list<int>::iterator it;
	for (it = trails[section].begin(); it != trails[section].end(); it++)
		if (!visited[*it])
			dfsStack(*it, visited, stack, trails);

	/* This node is finished (All children visited) */
	stack.push(section);
}

/* Depth First Search through adjacency list */
/* Returns number of nodes traversed through */
int dfs(int section, vector<bool> &visited, adjList &trails, int &count) {
	visited[section] = true;

	/* Recursively iterate as deep as possible */
	list<int>::iterator it;
	for (it = trails[section].begin(); it != trails[section].end(); it++)
		if (!visited[*it])
			dfs(*it, visited, trails, ++count);
	return count;
}

int main() {
	int T, numSections, numConnections, x, y;
	cin >> T;
	while (T--) {
		cin >> numSections >> numConnections;
		adjList trails(numSections);
		vector<bool> visited(numSections);
		stack<int> stack;
		bool cannotEscape = false;

		/* Create adjacency list */
		for (int i = 0; i < numConnections; i++) {
			cin >> x >> y;
			trails[x].push_back(y);
		}

		/* Fill the stack based on completion time */
		for (int i = 0; i < numSections; i++)
			if (!visited[i])
				dfsStack(i, visited, stack, trails);

		/* Create reversed graph */
		adjList invTrails = transpose(trails, numSections);

		/* Reset boolean array */
		visited.clear();
		visited.resize(numSections);

		/* Process vertices in stack */
		while (!stack.empty()) {
			int v = stack.top(), count = 1;
			stack.pop();

			if (!visited[v]) {
				if (dfs(v, visited, invTrails, count) != numSections) {
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
