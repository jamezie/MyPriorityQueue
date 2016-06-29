#include <array>

class MyQueue {
private:
	int tail;
	Array queue;

<<<<<<< HEAD
	void bubbleDown(Node::Node * bubbleNode) {
	}

	void bubbleUp(Node::Node * bubbleNode) {
=======
	void bubbleDown(Node::Node * bubbleNode, Node::Node * queuePosition) {

>>>>>>> parent of 1df7eec... Add nullToMe, pointToMe, isLowerPriorityThan, swapNodes, popBack, deleteNode, bubbleDown
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

<<<<<<< HEAD
		if(lastParent)
			lastParent->incChildren();

		newNode->setParent(last->getParent());
		bubbleUp(newNode);

		last = getNewLast();
=======
			deleteNode(currTop);
			return;
		}

		Node::Node * lowestNode = getLowest();
>>>>>>> parent of 1df7eec... Add nullToMe, pointToMe, isLowerPriorityThan, swapNodes, popBack, deleteNode, bubbleDown
	}

	void deleteNode(Node * delNode) {
		delNode->setParent(0);
		delNode->setLeft(0);
		delNode->setRight(0);
		delete(delNode);
	}

<<<<<<< HEAD
	Node::Node * getNewLast(){
		return 0;
	}
=======

>>>>>>> parent of 1df7eec... Add nullToMe, pointToMe, isLowerPriorityThan, swapNodes, popBack, deleteNode, bubbleDown
};
