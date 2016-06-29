#include "Node.h"
#define DEFAULT_QUEUE 100
#define INIT_POSITION 1

class MyQueue {
private:
	int tail;
	Node::Node ** queue;

	void bubbleDown(int bubblePosition){
		if(bubblePosition > tail) return;

		int leftChildPosition = bubblePosition * 2;
		int rightChildPosition = leftChildPosition + 1;
		int largerChildPosition = 0;

		while(leftChildPosition <= tail) {
			int bubblePriority = queue[bubblePosition]->getPriority();
			int leftChildPriority = queue[leftChildPosition]->getPriority();

			if(rightChildPosition > tail) {

				if(bubblePriority < leftChildPriority)
					swapNodes(bubblePosition, leftChildPosition);

				bubblePosition = leftChildPosition;
			}

			rightChildPosition = bubblePosition * 2 + 1;
			leftChildPosition = bubblePosition * 2;
		}
	}

	void bubbleUp(int bubblePosition){
		if(bubblePosition < INIT_POSITION) return;
		Node::Node * bubbleNode = queue[bubblePosition];
		Node::Node * parentNode = 0;
		int parentPosition = bubblePosition/2;

		while(parentPosition >= INIT_POSITION) {
			parentNode = queue[parentPosition];

			if(parentNode->getPriority() < bubbleNode->getPriority())
				swapNodes(bubblePosition, parentPosition);

			bubblePosition = parentPosition;
			parentPosition = bubblePosition/2;
		}
	}

	Node::Node * getLast() {
		return queue[tail];
	}

	int getLargerChildPosition(int parentPosition) {
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
	MyQueue(int size): tail(0) {
		queue = new Node::Node[size];
	}

	MyQueue(): tail(0) {
		queue = new Node::Node[DEFAULT_QUEUE];
	}


	void push(Node::Node * newNode) {

	}

	Node::Node * pop(){
		if(tail <= INIT_POSITION) return 0;

		Node::Node * poppedNode = queue[INIT_POSITION];

		queue[INIT_POSITION] = queue[tail];

		delete(queue[tail]);
		queue[tail] = 0;

		if(tail > INIT_POSITION)
			tail--;

		bubbleDown(INIT_POSITION);

		return poppedNode;
	}

	Node::Node * top(){
		return queue[INIT_POSITION];
	}
};

