#pragma once

#include "node.h"

template<typename T>
class quickSortClass
{
private:
	/* A utility function to swap two elements */
	void swap(T* a, T* b) {
		T t = *a; *a = *b; *b = t;
	}
	//A utility function to find 
	//last node of linked list
	node<T>* lastNode(node<T>* root) {
		while (root && root->prev)
			root = root->prev;
		return root;
	}
	/* Considers last element as pivot,
	places the pivot element at its
	correct position in sorted array,
	and places all smaller (smaller than
	pivot) to left of pivot and all greater
	elements to right of pivot */
	node<T>* partition(node<T>* l, node<T>* h) {
		//set pivot as h element  
		T x = h->data;

		// similar to i = l-1 for array implementation  
		node<T>* i = l->prev;

		//Similar to "for (int j = l; j <= h- 1; j++)"  
		for (node<T>* j = l; j != h; j = j->next)
		{
			if (j && j->data >= x)
			{
				//Similar to i++ for array  
				i = (i == NULL) ? l : i->next;

				swap(&(i->data), &(j->data));
			}
		}
		i = (i == NULL) ? l : i->next; // Similar to i++  
		swap(&(i->data), &(h->data));
		return i;
	}
	/* A recursive implementation
	of quicksort for linked list */
	void _quickSort(node<T>* l, node<T>* h)
	{
		if (h != NULL && l != h && l != h->next)
		{
			node<T>* p = partition(l, h);
			_quickSort(l, p->prev);
			_quickSort(p->next, h);
		}
	}
public:
	//The main function to sort a linked list. 
	//It mainly calls _quickSort()
	void sort(node<T>* head) {
		//Find last node  
		node<T>* h = lastNode(head);

		//Call the recursive QuickSort  
		_quickSort(h, head);
	}
};

