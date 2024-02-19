/*
 * node.h
 *
 *  Created on: Feb 23, 2021
 *      Author: Eli
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

template<class T>
class Node{
	Node<T>* next;
	T value;
public:
	Node(T t){
		value = t;
		next=nullptr; // this is NULL for pointers
	}

	void setNext(Node<T>* next){
		this->next=next;
	}

	// continue the implementation

	class iterator{
		Node<T>* current;
	public:

		iterator(Node<T>* current):current(current){}

		void operator++(){
			if(current!=nullptr)
				current=current->next;
		}

		bool operator!=(iterator it){
			return current!=it.current;
		}

		T operator*(){
			return current->value;
		}
	};

	iterator begin(){
		return iterator(this);
	}

	iterator end(){
		return iterator(nullptr);
	}
};


#endif /* SRC_NODE_H_ */
