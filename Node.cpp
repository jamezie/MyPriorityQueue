/*
 * Node.cpp
 *
 *  Created on: Jun 27, 2016
 *      Author: James
 */
#include "Node.h"

Node::Node(): value(), priority(-1), parent(0), left(0), right(0){}
Node::Node(int v): value(v), priority(-1), parent(0), left(0), right(0){}

Node::Node * getLeft(){
	return Node::left;
}

void Node::setLeft(Node * l) {
	Node::left = l;
}

Node::Node * Node::getRight(){
	return Node::right;
}

void Node::setRight(Node * r){
	right = r;
}

Node::Node * Node::getParent(){
	return Node::parent;
}

void Node::setParent(Node * p){
	Node::parent = p;
}

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

void static Node::swapNodes(Node * node1, Node * node2){
	if(!node1 || (!node2)) {
		return;
	}

	Node::Node * tempParent = node1->getParent();
	Node::Node * tempLeft = node1->getLeft();
	Node::Node * tempRight = node1->getRight();

	node1->setParent(node2->getParent());
	node1->setLeft(node2->getLeft());
	node1->setRight(node2->getRight());

	node2->setParent(tempParent);
	node2->setLeft(tempLeft);
	node2->setRight(tempRight);
}




