// File Name: Prim.h
// Date: May 5,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Prim helper class.  This helper class finds a minimum spanning tree given a graph and a starting vertex.
//				Prim's algorithm starts at any vertex in the graph and finds each connecting minimum path.  No cycles can occur. 

#pragma once
#include "List.h"
#include "Edge.h"
#include "Graph.h"
class Prim
{
public:

	// Description: Finds the minimum spanning tree from a given connected graph.  A MST is one that contains no cycles,
	//				and is the minimum path to each vertex.  Although not unique, an MST's weight will be unique.
	// Parameters: The graph and an arbitrary index to start looking for a minimum spanning tree. This prints the results to the console.
	// Returns: void
	void findMinimumSpanningTree(Graph* graph, Vertex* startingVertex);

private:

	// Description: Prints the weight of the minimum spanning tree followed by the minimum edges (desc name)
	// Parameters: Graph
	// Returns: void
	void printResults(Graph* graph);
};
