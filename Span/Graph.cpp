// File Name: Graph.cpp
// Date: May 6,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Implementation of the Graph class.  See Graph.h for more information.

#include "Graph.h"

#pragma region PublicMethods

Graph::Graph(std::string fileName)
{
	this->verticies = new List<Vertex>();
	this->edges = new List<Edge>();
	std::ifstream file = std::ifstream(fileName);
	if (!file) // No file!
	{
		std::cerr << "File Path not found\nExiting Program";
		exit(-1);
	}
	file >> this->numberOfVerticies;
	this->verticies = this->getVerticies(file);
	this->edges = this->getEdges(file);
}

List<Vertex>* Graph::getAdjacentVerticies(Vertex* vertex)
{
	List<Vertex>* adjacentVerticies = new List<Vertex>();
	for (int i = 0; i < this->edges->getSize(); i++) // iterate through the edges to find adjacent verticies
	{
		Edge* edge = this->edges->get(i);

		// If the edges start or ending id equals the vertex id, it must be adjacent.
		if (edge->startId == vertex->id)
		{
			adjacentVerticies->insert(this->getVertexById(edge->endingId));
		}
		else if (edge->endingId == vertex->id)
		{
			adjacentVerticies->insert(this->getVertexById(edge->startId));
		}
	}
	return adjacentVerticies;
}

Vertex* Graph::getVertexById(unsigned int id)
{
	for (int i = 0; i < this->verticies->getSize(); i++)
	{
		Vertex* vertex = verticies->get(i);
		if (vertex->id == id)
		{
			return vertex; // Found it.
		}
	}
	return nullptr; // Not found
}

Edge* Graph::getEdge(Vertex* vertexU, Vertex* vertexV)
{
	for (int i = 0; i < edges->getSize(); i++)
	{
		Edge* edge = edges->get(i);
		// An edge can be defined as a-b or b-a, thus the or check
		if ((edge->startId == vertexU->id && edge->endingId == vertexV->id)
			|| (edge->startId == vertexV->id && edge->endingId == vertexU->id))
		{
			return edge;
		}
	}
	return nullptr; // Not found.
}

void Graph::sortEdgesByWeight(List<Edge>* edges)
{
	for (int i = 1; i < edges->getSize(); i++)
	{
		// Perform an insertion sort on the edges.
		Edge* edge = edges->get(i);
		Edge* tempEdge = new Edge(edge->weight,
			edge->startId,
			edge->endingId,
			edge->startingVertexName,
			edge->endingVertexName);

		int j;
		for (j = i - 1; j >= 0 && tempEdge->weight < edges->get(j)->weight; j--) // if the weight is less, swap them
		{
			this->copyEdge(edges->get(j), edges->get(j + 1));
		}
		this->copyEdge(tempEdge, edges->get(j + 1));
	}
}

void Graph::sortEdgesByName()
{
	// Insertion sort here.
	for (int i = 1; i < this->edges->getSize(); i++)
	{
		Edge* edge = this->edges->get(i);
		Edge* tempEdge = new Edge(
			edge->weight,
			edge->startId,
			edge->endingId,
			edge->startingVertexName,
			edge->endingVertexName
		);

		int j;
		for (j = i - 1; j > -1 && tempEdge->toString() < edges->get(j)->toString(); j--)
		{
			this->copyEdge(edges->get(j), edges->get(j + 1));
		}

		this->copyEdge(tempEdge, edges->get(j + 1));
	}
}

void Graph::sortEdgesByName(List<Edge>* edges)
{
	// Insertion sort here
	for (int i = 1; i < edges->getSize(); i++)
	{
		Edge* edge = edges->get(i);
		Edge* tempEdge = new Edge(
			edge->weight,
			edge->startId,
			edge->endingId,
			edge->startingVertexName,
			edge->endingVertexName
		);
		int j;
		for (j = i - 1; j >= 0 && tempEdge->toString() < edges->get(j)->toString(); j--)
		{
			this->copyEdge(edges->get(j), edges->get(j + 1));
		}

		this->copyEdge(tempEdge, edges->get(j + 1));
	}
}

void Graph::copyEdge(Edge* source, Edge* destination)
{
	// Straight forward copy here.
	destination->endingId = source->endingId;
	destination->endingVertexName = source->endingVertexName;
	destination->startId = source->startId;
	destination->startingVertexName = source->startingVertexName;
	destination->weight = source->weight;
}
#pragma endregion

#pragma region PrivateMethods

bool Graph::isEdgeInGraph(unsigned int row, unsigned int column)
{
	unsigned int index = 0;
	Edge* edge = this->edges->get(index);
	while (edge != nullptr)
	{
		// Checks to see if an edge is in the graph.  Edges can be stored in either direction, thus the OR check.
		// Returns true if this edge is found
		if ((edge->startId == row && edge->endingId == column) ||
			(edge->startId == column && edge->endingId == row))
		{
			return true;
		}
		edge = this->edges->get(++index); // Did find this yet, grab the next one.
	}
	return false; // The edge was not found.
}

List<Vertex>* Graph::getVerticies(std::ifstream& fileStream)
{
	// File check completed before the call
	List<Vertex>* verticies = new List<Vertex>();
	std::string vertexName = std::string();
	for (unsigned int i = 0; i < this->numberOfVerticies; i++)
	{
		fileStream >> vertexName;
		verticies->insert(new Vertex(i, vertexName));
	}
	return verticies;
}

List<Edge>* Graph::getEdges(std::ifstream& fileStream)
{
	// File check completed before the call
	unsigned int numberOfRows, numberOfColumns;
	numberOfColumns = numberOfRows = this->numberOfVerticies;
	auto edges = new List<Edge>();
	// This is a nxn matrix.  Number of rows = Number of Columns =  Number of Verticies
	for (unsigned int row = 0; row < numberOfRows; row++)
	{
		for (unsigned int column = 0; column < numberOfColumns; column++)
		{
			double weight = 0;
			fileStream >> weight;
			if (weight != 0)
			{
				if (!isEdgeInGraph(row, column))
				{
					Vertex* rowVertex = this->getVertexById(row);
					Vertex* columnVertex = this->getVertexById(column);
					if (columnVertex->name < rowVertex->name)
					{
						auto edge = new Edge
						(
							weight, column, row, columnVertex->name, rowVertex->name
						);
						edges->insert(edge);

					}
					else
					{
						Edge* edge = new Edge
						(
							weight, row, column, this->getVertexById(row)->name, this->getVertexById(column)->name
						);
						edges->insert(edge);

					}
				}
			}
		}
	}
	return edges;
}

#pragma endregion
