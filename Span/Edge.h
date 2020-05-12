// File Name: Edge.h
// Date: May 6,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Edge struct.  This struct is utilized by the graph class.
//				An edge has a startId, endId, weight, startName, and endName.

#pragma once
#include <string>
#include "Vertex.h"

// Todo: Refactor this to contain 2 verticies.
// Todo: Make the edge struct part of the graph class
struct Edge
{
	// Description: Constructor for Edge struct.
	// Parameters: edgeWeight <double>, startId <int>, endId <int>, startName <string>, endName <string>
	// Returns: void
	Edge(
		double edgeWeight,
		int startId,
		int endId,
		std::string startVertexName,
		std::string endVertexName
	);
	double weight; // Weighted graphs contain weights between edges.
	int startId; // A starting ID for an edge.  If a graph has a connection between a-b, the starting id would identify a.
	int endingId; // An ending ID for an edge.  If a graph has a connection between a-b, the ending id would identify b.
	std::string startingVertexName; // Name that is attributed to a starting vertex of an edge.
	std::string endingVertexName;	// Name that is attributed to an ending vertex of an edge.

	// Description: Gets a nicely formated string for Edge class (startingVertexName-EndingVertexName).
	// Parameters: void 
	// Returns: A nicely formated string <string>.
	std::string toString();
};

inline Edge::Edge(double edgeWeight, int startId, int endId, std::string startingVertexName, std::string endingVertexName)
{
	this->weight = edgeWeight;
	this->startId = startId;
	this->endingId = endId;
	this->startingVertexName = startingVertexName;
	this->endingVertexName = endingVertexName;
}

inline std::string Edge::toString()  
{
	return this->startingVertexName + "-" + this->endingVertexName;
}