// File: linkedlist.cpp 
// Author: Tim van der Kooi
// Date: 05/11/16
// Description: Implementation of doubly-linked list.
#ifdef _LINKEDLIST_H_

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include "linkedlist.h"

template <typename T>
LinkedList<T>::LinkedList() {
	size = 0;
	front = NULL;
	back = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll){
	CopyList(ll);
}

template <typename T>
void LinkedList<T>::CopyList(const LinkedList<T>& ll) {
	size = 0;
	front = NULL;
	back = NULL;

	Node<T>* curr = ll.front;

	while (curr != NULL) {
		InsertBack(curr->data);
		curr = curr->next;
	}
}

template <typename T>
LinkedList<T>::~LinkedList() {
	DeleteList();
}

template <typename T>
void LinkedList<T>::DeleteList() {
	Node<T>* temp;
	while (front != NULL) {
		temp = front->next;
		delete front;
		front = temp;
	}
}


template <typename T>
int LinkedList<T>::Size() const {
	return size;
}

template <typename T>
bool LinkedList<T>::IsEmpty() const {
	return (front == NULL);
}

template <typename T>
bool LinkedList<T>::Contains(T item) const {
	if (IsEmpty()) {
		return false;
	}

	Node<T>* curr = front;
	
	while (curr != NULL) {
		if (curr->data == item) {
			return true;
			break;
		}

		else {
			curr = curr->next;
		}
	}
	return false;
}


template <typename T>
T LinkedList<T>::ElementAt(int p) const {
	if (p < 0 || p >= Size()) {
		throw std::out_of_range ("Index doesn't exist in linked list.");
	}

	Node<T>* curr = front;
	int i = 0;

	while (i != p) {
		curr = curr->next;
		i++;
	}

	return curr->data;
}

template <typename T>
void LinkedList<T>::InsertFront(T item){
	if (front == NULL) {
		Node<T>* curr = new Node<T>(item);
		front = curr;
		back = curr;
		size++;
		return;
	}

	else {
		Node<T>* curr = new Node<T>(item);
		front->prev = curr;
		curr->next = front;
		front = curr;
		size++;
	}	
}

template <typename T>
void LinkedList<T>::InsertBack(T item){
	if (front == NULL) {
		Node<T>* curr = new Node<T>(item);
		back = curr;
		front = curr;
		size++;
		return;
	}

	else {
		Node<T>* curr = new Node<T>(item);
		back->next = curr;
		curr->prev = back;
		back = curr;
		size++;
		return;
	}
}

template <typename T>
void LinkedList<T>::InsertAt(T item, int p){
	if (p < 0 || p > Size()) {
		throw std::out_of_range ("Index doesn't exist in linked list.");
	}

	else if (p == 0) {
		InsertFront(item);
	}

	else if (p == Size()) {
		InsertBack(item);
	}

	else {

	Node<T>* newNode = new Node<T>(item);
	Node<T>* before = front;
	Node<T>* after = back;
	int i = 0;

	while (i != p-1) {
		before = before->next;
		i++;
	}

	int j = Size() - 1; 

		while (j != p) {
			after = after->prev;
			j--;
		}

	newNode->next = after;
	newNode->prev = before;
	before->next = newNode;
	after->prev = newNode;
	size++;
}
}

template <typename T>
T LinkedList<T>::RemoveAt(int p){
	int end = Size() - 1;
	if (p >= Size() || p < 0) {
		throw std::out_of_range("Index doesn't exist in this list.");
	}
	else if (Size() == 1) {
		T value = front->data;
		delete front;
		front = NULL;
		size--;
		return value;
	}

	else if (p == 0) {
		Node<T>* afterCurr = front->next;
		afterCurr->prev = NULL;
		T value = front->data;
		delete front;
		size--;
		front = afterCurr;
		return value;
	}

	else if (p == end) {
		Node<T>* temp1 = back->prev;
		temp1->next = NULL;
		T value = back->data;
		delete back;
		size--;
		back = temp1;
		return value;
	}

	else {
		int i = 0;
		Node<T>* temp2 = front;
		Node<T>* curr = back;
		Node<T>* after;
		while (i != p-1) {
			temp2 = temp2->next;
			i++;
		}

		while (end != p) {
			after = curr;
			curr = curr->prev;
			end--;
		}

		T value = curr->data;
	    temp2->next = curr->next;
	    after->prev = curr->prev;
	    delete curr;
	    size--;
	    return value;
	}
}

template <typename T>
void LinkedList<T>::Append(const LinkedList& ll){
	Node<T>* appendList = ll.front;

	while (appendList != NULL) {
		InsertBack(appendList->data);
		appendList = appendList->next;
	}
}

template <typename T>
void LinkedList<T>::RemoveDuplicates(){
	Node<T>* outerTemp = back;
	int outerEnd = Size() - 1;

	while (outerTemp != NULL) {
		Node<T>* innerTemp = outerTemp->prev;
		T value = outerTemp->data;
		int innerEnd = outerEnd - 1;

		while (innerTemp != NULL) {
			if (innerTemp->data == value) {
				innerTemp = innerTemp->prev;
				RemoveAt(innerEnd);
				innerEnd--;
				outerEnd--;
			}

			else {
			innerTemp = innerTemp->prev;
			innerEnd--;
		}
	}

	outerTemp = outerTemp->prev;
	outerEnd--;
}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
	if (this != &ll) {
		DeleteList();
		CopyList(ll);
	}
	return *this;
}

#endif
