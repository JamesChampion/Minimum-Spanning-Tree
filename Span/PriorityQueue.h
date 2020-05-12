// File Name: Priority.h
// Date: May 5,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Header file for implementation of a minimum Priority Queue.
//				This implementation uses a linked list for the queue, and is of type Vertex.
//              The priority is based on weights of the vertex.  The smaller the weight, the higher priority.

#pragma once
#include "List.h"
#include "Vertex.h"

// Todo: Make this a template
//		 I think I will have to overload operators on Vertex struct to do so.
class PriorityQueue
{
public:

	// Description: Constructor for Priority Queue.  Initializes a new List<Vertex>
	// Parameters: void
	// Returns: void 
	PriorityQueue();

	// Description: Inserts an element into the Queue. Appends the item to the end of the list.
	// Parameters: item <Vertex*>
	// Returns: void
	void insert(Vertex* item);

	// Description: Returns the item that has the highest priority (minimum weighted vertex).
	//				This does not remove any items from the queue.
	// Parameters: void
	// Returns: minimumVertex <Vertex*>
	Vertex* getMinimum();

	// Description: Returns the item that has the highest priority (minimum weighted vertex).
	//				This method removes the item from the queue as well.
	// Parameters: void 
	// Returns: minimumVertex <Vertex*>
	Vertex* extractMinimum();

	// Description: Checks to see if the given item is in the queue. Returns true if so.
	// Parameters: item <Vertex*>
	// Returns: true/false
	bool contains(Vertex* item);

	// Description: Gets the number of items that are currently in the queue.
	// Parameters: void
	// Returns: The size of the Queue <unsigned int>
	unsigned int getSize();

	// Description: Checks to see if the size of the queue == 0
	// Parameters: void
	// Returns: true if the queue is empty
	bool isEmpty();

private:
	
	// Description: Linked list used for implementation of the priority queue.
	List<Vertex>* list;
};

