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
	int value;
	int priority;

public:
	Node(): value(0), priority(0) {}
	Node(int val): value(val), priority(0) {}
	Node(int val, int pri): value(val), priority(pri) {}

	int getPriority();
	int getValue();

	void setPriority(int p);
	void setValue(int v);
};
#endif /* NODE_H_ */
