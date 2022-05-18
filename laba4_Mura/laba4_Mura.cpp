// laba4_Mura.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Graph.h"

int main()
{
	Graph g(8);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 1);
	g.addEdge(1, 4);
	g.addEdge(4, 3);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(3, 1);
	g.addEdge(3, 6);
	g.addEdge(1, 6);
	g.addEdge(7, 2);
	g.addEdge(7, 0);
	std::ofstream file("commands.js");
	file << "window.prog=`\n";
	file << g;
	g.getEulerCycle(file);
	file << "`";
	file.close();
}
