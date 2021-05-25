#include<iostream>
#define V 4

using namespace std;


void printSolution(int color[]);

bool isSafe(bool graph[V][V], int color[])
{
	// check for every edge
	for (int i = 1; i <= V; i++)
		for (int j = i + 1; j <= V; j++)
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}
bool graphColoring(bool graph[V][V], int m, int i, int color[V])
{
	// if current index reached end
	if (i == V) {

		// if coloring is safe
		if (isSafe(graph, color)) {

			// Print the solution
			printSolution(color);
			return true;
		}
		return false;
	}

	// Assign each color from 1 to m
	for (int j = 1; j <= m; j++) {
		color[i+1] = j;

		// Recur of the rest vertices
		if (graphColoring(graph, m, i + 1, color))
			return true;

		color[i+1] = 0;
	}

	return false;
}

void printSolution(int color[])
{
	cout << "Solution Exists:" " Following are the assigned colors \n";
	for (int i = 1; i <= V; i++)
		cout << "  " << color[i];
	cout << "\n";
}

// Driver code
int main()
{
	int path;
	int i, j, n;
	bool graph[V][V];

	cin >> n >> path;

	for (int k = 1; k <= path; k++){
		cin >> i >> j;
		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	int m = 4; // Number of colors

	int color[V];
	for (int i = 1; i <= V; i++)
		color[i] = 0;

	if (!graphColoring(graph, m, 0, color))
		cout << "Solution does not exist";

	return 0;
}
