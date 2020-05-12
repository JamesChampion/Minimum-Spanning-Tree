// File Name: Graph.h
// Date: May 7,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Graph class. This graph contains a list of verticies, a list of edges, and the number of verticies.
//				An edge is composed of 2 verticies that are connected.  This graph reads in a file with the first line
//				containing the number of verticies, the next N lines the vertex names, followed by a matrix with said connections.

#pragma once
#include <iostream>
#include <fstream>
#include "List.h"
#include "Edge.h"
#include "Vertex.h"
class Graph
{
public:

	// Description: Constructor for Graph class.  Takes a file path as a parameter.
	//				The first line is the number of verticies, followed by N vertex names, followed by a [n x n] adjacency matrix.
	//				This gets and sets the verticies and edges for the graph.
	// Parameters: filePath <string&>
	// Returns: void 
	Graph(std::string filePath);

	// Description: Copys and edge from source to destination. This function is utilized by sorting functions.
	// Parameters: source <Edge*>, destination <Edge*>
	// Returns: void
	void copyEdge(Edge* source, Edge* destination);

	// Description: Helper function that sorts a list of edges by their weight.  This function utilizes insertion sort to do so.
	// Parameters: List of edges <List<Edge>*>
	// Returns: void
	void sortEdgesByWeight(List<Edge>* edges);

	// Description: Helper function that sorts a list of edges by name.  This function utilizes insertion sort to do so.
	// Parameters: List of edges <List<Edge>*>
	// Returns: void
	void sortEdgesByName(List<Edge>* edges);

	// Description: Overloaded helper function that sorts this->graph's list of edges by name.  This function utilizes insertion sort to do so.
	// Parameters: void
	// Returns: void
	void sortEdgesByName();

	// Description:Given a starting vertex, this function gets all the adjacent verticies from the graph and returns a list of them.
	// Parameters: any vertex in the graph <Vertex*>
	// Returns: The list of adjacent verticies <List<Vertex>*>
	List<Vertex>* getAdjacentVerticies(Vertex* vertex);

	// Description: Retrieves the vertex of the graph with the given id.  Returns a nullptr if the ID is not found.
	// Parameters: ID <unsigned int>
	// Returns: The vertex in context (or nullptr if not found) <Vertex*>
	Vertex* getVertexById(unsigned int id);

	// Description: Given 2 verticies (Vertex U, Vertex V), this helper function returns the edge associated with it.
	//				This function returns a nullptr if the edge is not found
	// Parameters: 2 verticies (Vertex U, Vertex V) <Vertex*,Vertex*>
	// Returns: bv The edge associated with the verticies (or nullptr if not found) <Edge*>
	Edge* getEdge(Vertex* vertexU, Vertex* vertexV);


	List<Edge>* edges; // List of edges in the graph
	
	List<Vertex>* verticies; // List of verticies in the graph

private:

	unsigned int numberOfVerticies; // The number of verticies in the graph
	
	// Description: Gets verticies associated with the open file stream.  See above format of file.
	// Parameters: A reference to the open file stream.  See above for format of file.
	// Returns: List of verticies <List<Vertex>*>
	List<Vertex>* getVerticies(std::ifstream& fileStream);

	// Description: Gets verticies associated with the open file stream.  See above for the format.
    // Parameters: A reference of the open
	// Returns: List of verticies <List<Vertex>*>
	List<Edge>* getEdges(std::ifstream& fileStream);

	// Description: Checks to see if 2 verticies are an edge in the graph.
	// Parameters: Id's of 2 verticies to see if the edge exists
	// Returns: true if the edge is in the graph
	bool isEdgeInGraph(unsigned int vertexUId, unsigned int vertexVId);

};

