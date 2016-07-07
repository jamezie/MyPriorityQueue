/*
 * Node.cpp
 *
 *  Created on: Jun 27, 2016
 *      Author: James
 */
#include "Node.h"

template <class T> int Node<T>::getPriority(){
	return Node<T>::priority;
}

template <class T> void Node<T>::setPriority(int p){
	Node<T>::priority = p;
}

template <class T> T Node<T>::getValue(){
	return Node<T>::value;
}

template <class T> void Node<T>::setValue(T v) {
	Node<T>::value = v;
}

template class Node<int>;
