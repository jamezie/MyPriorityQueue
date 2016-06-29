#include "Node.h"
#define DEFAULT_LENGTH 100
#define INIT_POSITION 1

class MyQueue {
private:
	int tail;
	int length;
	Node::Node ** queue;

	void bubbleDown(int bubblePosition){
		if(bubblePosition > tail) return;

		int leftChildPosition;
		int rightChildPosition;

		while(hasLeftChild(bubblePosition)) {
			int largerChildPosition =
				getLargerChildPosition(bubblePosition);

			if(queue[bubblePosition] < queue[largerChildPosition])
				swapNodes(bubblePosition, largerChildPosition);

			bubblePosition = largerChildPosition;
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

	int getLargerChildPosition(int parent) {
		int right = getRightChildPosition(parent);
		int left = getLeftChildPosition(parent);

		if(right > tail) return left;
		if(queue[left]->getPriority() < queue[right]->getPriority())
			return right;

		return left;
	}

	void swapNodes(int position1, int position2) {
		Node::Node * node1 = queue[position1];
		Node::Node * node2 = queue[position2];

		if(!(node1 && node2))
			return;

		queue[position2] = node1;
		queue[position1] = node2;
	}

	bool hasRightChild(int parentPosition) {
		if((parentPosition * 2 + 1) <= tail)
			return true;

		return false;
	}

	bool hasLeftChild(int parentPosition) {
		if((parentPosition * 2 ) <= tail)
			return true;

		return false;
	}

	int getRightChildPosition(int parent) {
		return (parent * 2 + 1);
	}

	int getLeftChildPosition(int parent) {
		return (parent * 2);
	}

public:
	MyQueue(int size): tail(0) {
		length = size;
		queue = new Node::Node[length];
	}

	MyQueue(): tail(0) {
		length = DEFAULT_LENGTH;
		queue = new Node::Node[DEFAULT_LENGTH];
	}


	void push(Node::Node * newNode) {
		if(tail >= (length-2)) return;

		tail++;
		queue[tail] = newNode;

		bubbleUp(tail);
	}

	Node::Node * pop(){
		if(tail < INIT_POSITION) return 0;

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

