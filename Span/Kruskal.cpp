// File Name: Kruskal.cpp 
// Date: May 6,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Implementation of Kruskal helper class.  See Kruskal.h for more information.

#include "Kruskal.h"

#pragma region PublicMethods

void Kruskal::findMinimumSpanningTree(Graph* graph)
{
	// Edge List used for minimum spanning tree
	List<Edge>* edges = new List<Edge>();

	// Make each of the verticies a set.
	for (int i = 0; i < graph->verticies->getSize(); i++)
	{
		this->makeSet(graph->verticies->get(i));
	}
	graph->sortEdgesByWeight(graph->edges);

	// Since the edges are sorted, we will grab the minimum from each set and combine them.
	// Create a forest of subtrees.
	for (int i = 0; i < graph->edges->getSize(); i++)
	{
		Edge* edge = graph->edges->get(i);
		Vertex* vertexU = graph->getVertexById(edge->startId);
		Vertex* vertexV = graph->getVertexById(edge->endingId);
		if (vertexU != nullptr || vertexV != nullptr) // Null Check just to make sure.
		{
			if (this->findSet(vertexU) != this->findSet(vertexV))
			{
				edges->insert(edge);
				this->unionVerticies(vertexU, vertexV); // Combine these into sub tree.
			}
		}
	}
	printResults(graph, edges);
}

#pragma endregion

#pragma region PrivateMethods

void Kruskal::makeSet(Vertex* vertex)
{
	vertex->parent = vertex;
	vertex->rank = 0;
}

Vertex* Kruskal::findSet(Vertex* vertex)
{
	if (vertex != vertex->parent)
	{
		vertex->parent = this->findSet(vertex->parent); // Recurively check
	}
	return vertex->parent; // Found it.
}

void Kruskal::printResults(Graph* graph, List<Edge>* edges)
{
	std::cout << "Kruskal Minimum Spanning Tree\n";
	double weightOfTree = 0;
	for (int i = 0; i < edges->getSize(); i++)
	{
		weightOfTree += edges->get(i)->weight;
	}
	std::cout << weightOfTree << std::endl;
	graph->sortEdgesByName(edges); // Graph is only passed for the sorting function
	// Output each edge and its weight
	for (int i = 0; i < edges->getSize(); i++)
	{
		Edge* edge = edges->get(i);
		std::cout << edge->toString() + ": " << edge->weight << std::endl;
	}
}

void Kruskal::unionVerticies(Vertex* vertexU, Vertex* vertexV)
{
	this->linkVerticies(this->findSet(vertexU), this->findSet(vertexV));
}

void Kruskal::linkVerticies(Vertex* vertexU, Vertex* vertexV)
{
	if (vertexU->rank > vertexV->rank)
	{
		vertexV->parent = vertexU; // Set the larger one to become its parent
	}
	else
	{
		vertexU->parent = vertexV;
		if (vertexU->rank == vertexV->rank)
		{
			vertexV->rank++; // Increase the rank
		}
	}
}

#pragma endregion
