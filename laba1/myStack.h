#pragma once

#include <iostream>
#include "baseOutputClass.h"
#include "quickSort.h"
#include "node.h"

using namespace std;

template <class T>
class myStack {
private:
	node<T>* last;
	int countElements;
public:

	myStack() {
		last = NULL;
		countElements = 0;
	};

	node<T>* getLastNode() {
		return last;
	}

	// add new element
	void push(T data) {
		node<T>* addElement = new node<T>;
		addElement->data = data;
		addElement->next = NULL;
		addElement->prev = NULL;
		if (last == NULL)
			this->last = addElement;
		else {
			last->next = addElement;
			last->next->prev = last;
			last = addElement;
		}
		countElements++;
	}

	// delete element from top 
	T pop() {
		if (last == NULL)
			throw exception("not found elements for delete");
		T copy = this->last->data;
		node<T>* del = last;
		last = last->prev;
		delete del;
		countElements--;
		return copy;
	}

	// get last element
	T getLast() {
		T copy = this->last->data;
		return copy;
	}

	int isEmpty() { if (last == NULL) return 1; return 0; };

	T search() {
		return last->data;
	}

	// sort datas in stack
	void sort() {
		quickSortClass<T> q;
		q.sort(last);
	}

	// print all data in stack to console
	void show() {
		node<T>* head = last;
		while (head) {
			cout << head->data.writeToConsole() << endl << endl;
			head = head->prev;
		}
		cout << endl;
	}

	// print all data in stack to stream
	// this method will be good for write data to file
	void show(ostream& output) {
		node<T>* head = last;
		while (head) {
			output << head->data << endl;
			head = head->prev;
		}
		output << endl;
	}

	int size() {
		return countElements;
	}

	T at(int index) {
		int i = 0;
		node<T>* head = last;
		while (head) {
			if (i == index)
				return head->data;
			i++;
			head = head->prev;
		}
	}


	friend istream& operator >> (istream& input, myStack<T>& stack) {
		T data;
		input >> data;
		stack.push(data);
		return input;
	}

	friend ostream& operator << (ostream& output, myStack<T>& stack) {
		stack.show(output);
		return output;
	}
};

