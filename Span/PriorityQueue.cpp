// File Name: PriorityQueue.cpp
// Date: May 7,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Implementation of a minimum priority queue <Vertex*>.
//				The Vertex with the smallest weight has the highest priority

#include "PriorityQueue.h"

#pragma region PublicMethods

PriorityQueue::PriorityQueue()
{
	this->list = new List<Vertex>();
}

void PriorityQueue::insert(Vertex* item)
{
	this->list->insert(item);
}

Vertex* PriorityQueue::getMinimum()
{
	Vertex* minimum = nullptr;
	for (int i = 0; i < list->getSize(); i++)
	{
		Vertex* vertex = list->get(i);
		if (minimum == nullptr || vertex->weight < minimum->weight)
		{
			minimum = vertex;
		}
	}
	return minimum;
}

Vertex* PriorityQueue::extractMinimum()
{
	Vertex* minimum = getMinimum();
	this->list->remove(minimum);
	return minimum;
}

bool PriorityQueue::contains(Vertex* item)
{
	return this->list->contains(item);
}

unsigned int PriorityQueue::getSize()
{
	return this->list->getSize();
}

bool PriorityQueue::isEmpty()
{
	return this->list->getSize() == 0;
}

#pragma endregion