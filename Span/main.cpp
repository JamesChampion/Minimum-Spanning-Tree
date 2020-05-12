// File Name: main.cpp
// Date: May 6, 2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Command Prompt program used to find Minimum Spanning Trees
//				This program uses 2 seperate algorithms (Kruskal, Primm) to find a minimum
//				span tree. Required parameter is a file path that has a graph.txt file
//				See https://en.wikipedia.org/wiki/Prim%27s_algorithm
//				See https://en.wikipedia.org/wiki/Kruskal%27s_algorithm

#include <iostream>
#include "Graph.h"
#include "Kruskal.h"
#include "Prim.h"

#pragma region Constants
const unsigned int FILE_PATH_INDEX = 1;
#pragma endregion

int main(int numberOfArguments, char* argumentArray[])
{
	if (numberOfArguments != 2)
	{
		std::cerr << "Invalid Parameters\nExiting Program";
		exit(-1);
	}
	auto graph = new Graph((std::string)argumentArray[FILE_PATH_INDEX]);
	auto primHelper = new Prim();
	auto kruskalHelper = new Kruskal();
	kruskalHelper->findMinimumSpanningTree(graph);
	std::cout << "-------------\n";
	primHelper->findMinimumSpanningTree(graph, graph->verticies->get(0)); // Arbitrarily choose the second index
	return 0;
}



