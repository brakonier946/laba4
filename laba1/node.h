#pragma once

#include <iostream>

using namespace std;

template <typename T>
struct node {
public:
	T data;
	node* prev;
	node* next;
};