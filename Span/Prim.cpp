// File Name: Prim.cpp
// Date: May 6,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Implementation of Prim helper class that finds the minimum spanning tree given a graph and an arbitrary vertex.
//				Follow the paths of the vertex that you start and find the minimum path to each connected vertex, and continue
//				until a minimum spanning tree is formed.

#include "Prim.h"
#include "PriorityQueue.h"

#pragma region PublicMethods


void Prim::findMinimumSpanningTree(Graph* graph, Vertex* startingVertex)
{
	// Set each weight equal to the maxium value alloted. Be careful of overflow ( 1 + INT_MAX may result in overflow).
	for (int i = 0; i < graph->verticies->getSize(); i++)
	{
		Vertex* vertex = graph->verticies->get(i);
		vertex->weight = INT_MAX;
	}

	startingVertex->weight = 0; // weight to itself will always be 0.

	// Create a new priority queue and add each vertex to the queue
	PriorityQueue* queue = new PriorityQueue();
	for (int i = 0; i < graph->verticies->getSize(); i++)
	{
		queue->insert(graph->verticies->get(i)); // Insert these into the queue
	}

	while (!queue->isEmpty())
	{
		// Grab the vertex with smallest weight, and the adjacent verticies
		Vertex* vertex = queue->extractMinimum();
		List<Vertex>* adjacentVerticies = graph->getAdjacentVerticies(vertex);

		// Go through the adjacents and see if their is a smaller weighted path
		for (int i = 0; i < adjacentVerticies->getSize(); i++)
		{
			Vertex* adjacentVertex = adjacentVerticies->get(i);
			if (queue->contains(adjacentVertex) && graph->getEdge(vertex, adjacentVertex)->weight < adjacentVertex->weight)
			{
				// We found a smaller weighted path.  
				adjacentVertex->parent = vertex;
				adjacentVertex->weight = graph->getEdge(vertex, adjacentVertex)->weight;
			}
		}
	}
	this->printResults(graph); // Print the results to the console.
	return;
}

#pragma endregion

#pragma region PrivateMethods

void Prim::printResults(Graph* graph)
{
	std::cout << "Prim Minimum Spanning Tree\n";
	double weightOfTree = 0;
	for (int i = 0; i < graph->verticies->getSize(); i++)
	{
		if (graph->verticies->get(i)->weight != INT_MAX)
		{
			weightOfTree += graph->verticies->get(i)->weight;
		}
	}
	std::cout << weightOfTree << std::endl;
	List<Edge>* edges = new List<Edge>();
	for (int i = 0; i < graph->verticies->getSize(); i++)
	{
		if (graph->verticies->get(i)->weight != 0)
		{
			Vertex* vertex = graph->verticies->get(i);
			edges->insert(graph->getEdge(graph->verticies->get(i), graph->verticies->get(i)->parent));
		}
	}
	graph->sortEdgesByName(edges);
	for (int i = 0; i < edges->getSize(); i++)
	{
		Edge* edge = edges->get(i);
		std::cout << edge->toString() + ": " << edge->weight << std::endl;
	}
}

#pragma endregion