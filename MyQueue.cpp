#include "Node.h"
#define DEFAULT_QUEUE 100
#define INIT_POSITION 1

class MyQueue {
private:
	int tail;
	Node::Node * queue;

	void bubbleDown(){

		}

	void bubbleUp(){

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
		return queue[INIT_POSITION];
	}

	Node::Node * getLast() {
		return queue[tail];
	}

	Node::Node * top(){
		return queue[1];
	}
};

