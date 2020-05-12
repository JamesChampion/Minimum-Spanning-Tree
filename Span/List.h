// File Name: List.h
// Date: May 6,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Template Linked List.  This list utilizes a Node<T> struct. It keeps track of its size, its head and its tail.
//				This file contains the header information on the top, followed by inline implementations.

#pragma once
#include <iostream>
template <class T> class List
{
public:

	// Description: Constructor for the generic list.
	// Parameters: void 
	// Returns: void
	List<T>();

	// Description: Insert's a key at the end of the list.
	// Parameters: key <T*>
	// Returns: void 
	void insert(T* key);

	// Description: Retrieves the key associated with the given index.
	// Parameters: The key <T*>
	// Returns: The value associated with the index.  Returns a nullptr if not found.
	T* get(unsigned int index);

	// Description: Removes the key from our list.
	// Parameters: key to be removed <T*>
	// Returns: void
	void remove(T* key);

	// Description: Checks the list and determines if the key is already in the list.
	// Parameters: The key that needs to be checked in the list.
	// Returns: true/false: true if the key is in the list.
	bool contains(T* key);

	// Description: Gets the number of items in this list.  A tally is kept when a key is added or removed.
	// Parameters: void 
	// Returns: The size of the list <int>
	int getSize();

private:
	
	struct Node // Struct used for the link list.  Has a key and a next pointer.
	{
		Node(T* key, Node* next);
		T* key;
		Node* next;
	};
	Node* head; // Keep track of first key
	Node* tail; // Keep track of the last key
	int size; // Keep track of the size of the list.
};

#pragma region PublicMethods

template<class T>
inline List<T>::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<class T>
inline void List<T>::insert(T* key)
{
	// Create a linked list node and append it after the last item added.
	Node* node = new Node(key, nullptr);
	if (this->head == nullptr)
	{
		this->head = node;
		this->tail = node;
	}
	else if (this->tail != nullptr)
	{
		this->tail->next = node; // The key needs to be at the end of the list, so the current tail needs updated
	}
	this->tail = node; // Make the new node the current tail.
	this->size++;
}

template<class T>
inline T* List<T>::get(unsigned int index)
{
	unsigned int currentIndex = 0;
	Node* node = this->head;
	while (node != nullptr)
	{
		if (index == currentIndex)
		{
			return node->key; // We found the node,  return it.
		}
		node = node->next;
		currentIndex++;
	}
	return nullptr; // We did not find the node
}

template<class T>
inline void List<T>::remove(T* key)
{
	Node* node = this->head;
	Node* previousNode = nullptr;
	while (node != nullptr)
	{
		if (node->key == key)
		{
			if (previousNode == nullptr)
			{
				this->head = node->next; // There needs to be a new head.
			}
			else
			{
				previousNode->next = node->next;
			}
			this->size--;
			return;
		}
		previousNode = node;
		node = node->next;
	}
}

template<class T>
inline bool List<T>::contains(T* key)
{
	Node* node = this->head;
	while (node != nullptr)
	{
		if (node->key == key)
		{
			return true; // We found the key in the list.
		}
		node = node->next;
	}
	return false; // Not found
}

template<class T>
inline int List<T>::getSize()
{
	return this->size;
}

#pragma endregion

#pragma region PrivateMethods

template<class T>
inline List<T>::Node::Node(T* key, Node* next)
{
	this->key = key;
	this->next = next;
}

#pragma endregion
