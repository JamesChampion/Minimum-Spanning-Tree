// File Name: Kruskal.h
// Date: May 6,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: A helper class that runs Kruskal's Minimum Spanning Tree Algortihm.
//				This particular algortihm creates a forest of trees and merges them
//				until a minimum spanning tree is found.

#pragma once
#include "List.h"
#include "Graph.h"
class Kruskal
{
public:

	// Description: Finds the minimum spanning tree from the given graph.
	//				This function calles all private methods used to make
	//				a forest of trees until a minimum spanning tree is found.
	// Parameters: The populated graph.
	// Returns: void
	void findMinimumSpanningTree(Graph* graph);
	
private:

	// Description: This function sets a vertex as a parent of itself, and sets the rank of it equal to 0. 
	// Parameters: Vertex that needs to be made into a set.
	// Returns: void
	void makeSet(Vertex* vertex);

	// Description: This function recursively calls the verticies parents until the set is found. (If it is not it's parent.)
	// Parameters: Vertex in question
	// Returns: The base of the set <Vertex*>
	Vertex* findSet(Vertex* vertex);

	// Description: This function prints the weight of the minimum spanning tree, followed by a list of all edges in the minimum spanning tree(desc).
	// Parameters: The graph, and list of edges
	// Returns:
	void printResults(Graph* graph, List<Edge>* edges);

	// Description: This will take two verticies and link them together by making the larger the parent.  This calls linkVerticies
	// Parameters: 2 Verticies that need to be unioned
	// Returns: void
	void unionVerticies(Vertex* vertexU, Vertex* vertexV);

	// Description: This finds the set of the verticies and combines them.  This is called by Union Verticies.
	// Parameters: 2 Verticies that need to be combined
	// Returns: void
	void linkVerticies(Vertex* vertexU, Vertex* vertexV);
};

