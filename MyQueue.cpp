#include <array>

class MyQueue {
private:
	int tail;
	Array queue;

	void bubbleDown(Node::Node * bubbleNode) {
	}

	void bubbleUp(Node::Node * bubbleNode) {
	}

public:
	MyQueue(): tail(0);

	int peek() {
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
