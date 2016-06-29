#include "Node.h"
#define DEFAULT_QUEUE 100
#define INIT_POSITION 1

class MyQueue {
private:
	int tail;
	Node::Node * queue;

	void bubbleDown(){

	}

	void bubbleUp(int bubblePosition){
		if(bubblePosition < 1) return;
		Node::Node * bubbleNode = queue[bubblePosition];

		int parentPosition = bubblePosition/2;
		if(parentPosition < 1) return;

		Node::Node * parentNode = queue[parentPosition];

		if(parentNode->getPriority() < bubbleNode->getPriority()) {
			swapNodes(bubblePosition, parentPosition);
			bubbleUp(parentPosition);
		}
	}

	Node::Node * getLast() {
		return queue[tail];
	}

	Node::Node * getLargerChild() {
		return 0;
	}

	void swapNodes(int position1, int position2) {
		Node::Node * node1 = queue[position1];
		Node::Node * node2 = queue[position2];

		if(!(node1 && node2))
			return;

		queue[position2] = node1;
		queue[position1] = node2;
	}

public:
	MyQueue(int size): tail(INIT_POSITION) {
		queue = new Node::Node[size];
	}

	MyQueue(): tail(INIT_POSITION) {
		queue = new Node::Node[DEFAULT_QUEUE];
	}


	void push(Node::Node * newNode) {

	}

	Node::Node * pop(){
		Node::Node * poppedNode = queue[INIT_POSITION];

		return poppedNode;
	}

	Node::Node * top(){
		return queue[INIT_POSITION];
	}
};

