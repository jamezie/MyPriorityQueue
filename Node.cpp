/*
 * Node.cpp
 *
 *  Created on: Jun 27, 2016
 *      Author: James
 */
#include "Node.h"

int Node::getPriority(){
	return Node::priority;
}

void Node::setPriority(int p){
	Node::priority = p;
}

int Node::getValue(){
	return Node::value;
}

void Node::setValue(int v) {
	Node::value = v;
}
