#include "Node.h"

class MyQueue {
private:
	Node::Node * top;
	Node::Node * last;

	Node::Node * getLowest() {
		if(!top) return 0;
		Node::Node * currLow = top;
		Node::Node * currLeft = currLow->getLeft();

		while(currLeft) {
			currLow = currLeft;
			currLeft = currLow->getLeft();
		}

		return currLow;
	}

	void bubbleDown(Node::Node * bubbleNode) {
		if(!bubbleNode)
			return;

		Node::Node * left = bubbleNode->getLeft();
		Node::Node * right = bubbleNode->getRight();

		if(left && bubbleNode->isLowerPriorityThan(left))
			Node::swapNodes(bubbleNode, left);
		else
			Node::swapNodes(bubbleNode, right);
	}

	void bubbleUp(Node::Node * bubbleNode) {
		if(!bubbleNode) return;
		Node::Node * parent = bubbleNode->getParent();

		while(parent) {
			if(parent->isLowerPriorityThan(bubbleNode)) {
				Node::swapNodes(bubbleNode, parent);
				bubbleNode->pointToMe();
				parent->pointToMe();

				parent = bubbleNode->getParent();
			} else {
				bubbleNode = parent;
				parent = parent->getParent();
			}
		}
	}

public:
	MyQueue(): top(0), last(0){}

	Node::Node * peek() {
		return top;
	}

	void pop(Node * newNode) {
		Node::Node * queuePosition = top;

		while(queuePosition) {
			if(newNode->isLowerPriorityThan(queuePosition)) {
				queuePosition = queuePosition->getLeft();
			} else {
				Node::swapNodes(newNode, queuePosition);
				newNode->pointToMe();
				queuePosition->pointToMe();
				queuePosition = newNode->
			}
		}



	}

	void insert(Node * newNode){
		if(!last) {
			top = newNode;
			last = getNewLast();
			return;
		}

		Node::Node * lastParent = last->getParent();

		if(lastParent)
			lastParent->incChildren();

		newNode->setParent(last->getParent());
		bubbleUp(newNode);

		last = getNewLast();
	}

	void deleteNode(Node * delNode) {
		delNode->nullToMe();
		delNode->setParent(0);
		delNode->setLeft(0);
		delNode->setRight(0);
		delete(delNode);
	}

	Node::Node * getNewLast(){
		return 0;
	}
};
