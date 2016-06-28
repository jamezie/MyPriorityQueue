/*
 * Node.h
 *
 *  Created on: Jun 27, 2016
 *      Author: James
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
private:
	Node * parent;
	Node * left;
	Node * right;
	int priority;
	int value;

public:
	Node();
	Node(int value);

	Node * getLeft();
	Node * getRight();
	Node * getParent();
	int getPriority();
	int getValue();

	void setLeft(Node * l);
	void setRight(Node * r);
	void setParent(Node * p);
	void setPriority(int p);
	void setValue(int v);

	void static swapNodes(Node * node1, Node * node2);
};
#endif /* NODE_H_ */
