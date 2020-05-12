// File Name: Vertex.h
// Date: May 5,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Vertex struct utilized by Graph class.
//				A vertex contains: id, name, weight, rank, and parent.
//				Rank and parent are utilized by Kruskal.cpp to make sets.

#pragma once
#include <string>

// Todo: Make the vertex struct part of the graph class.
struct Vertex
{

	// Description: Constructor for Vertex
	// Parameters: The id, and the name
	// Returns: void
	Vertex(int id, std::string& name);
	int id; // Id used for getting 
	std::string name; // A name for the vertex
	double weight; // weight of the vertex
	int rank; // Rank of the vertex.  Used exclusively in Kruskal.cpp.  Todo: Make a derived edge for Kruskal. 
	Vertex* parent; // Parent of vertex for building trees.  
};

inline Vertex::Vertex(int id, std::string& name)
{
	this->id = id;
	this->name = name;
	this->parent = nullptr;
	this->weight = 0;
	this->rank = 0;
}

