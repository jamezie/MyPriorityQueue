#include "Node.h"

class MyQueue {
private:
	Node::Node * top;

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

	void bubbleDown(Node::Node * bubbleNode, Node::Node * queuePosition) {

	}

public:
	MyQueue(): top(0){}

	Node::Node * peek() {
		return top;
	}

	void pushBack(Node * newNode) {

	}

	void popBack(){
		if(!top) // Empty Queue
			return;

		Node::Node * currTop = top;
		Node::Node * currLeft = top->getLeft();
		Node::Node * currRight = top->getRight();

		// Only top exists in Queue
		if((currLeft == 0) && (currRight == 0)) {
			delete(top);
			return;
		}

		// Top is smallest element
		if(currLeft == 0) {
			top = currTop->getRight();
			top->setParent(0);

			deleteNode(currTop);
			return;
		}

		Node::Node * lowestNode = getLowest();
	}

	void deleteNode(Node * delNode) {
		delNode->setParent(0);
		delNode->setLeft(0);
		delNode->setRight(0);
		delete(delNode);
	}


};
