#pragma once
#include <vector>
#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int N;
	vector<vector<bool>> edges;

public:
	Graph(int N);
	bool hasNeighbors(int i);
	void addEdge(int i, int j);

	std::vector<int> getEulerCycle(std::ostream& file);
	friend std::ostream& operator<<(std::ostream& file, const Graph& g);
};
std::ostream& operator<<(std::ostream& file, const Graph& g);



