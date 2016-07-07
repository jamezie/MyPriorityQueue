/*
 * Node.h
 *
 *  Created on: Jun 27, 2016
 *      Author: James
 */

#ifndef NODE_H_
#define NODE_H_

template <class T> class Node {
private:
	T value;
	int priority;

public:
	Node<T>(): value(0), priority(0) {}
	//Node<T>(T val): value(val), priority(0) {}
	Node<T>(T val, int pri): value(val), priority(pri) {}

	int getPriority();
	T getValue();

	void setPriority(int p);
	void setValue(T v);
};
#endif /* NODE_H_ */
