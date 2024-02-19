

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
	class iterator {
	public:
		Node<T>* iter;
		iterator(Node<T>* it): iter(it){}
		const iterator& operator++()
		{
			iter = iter->next;
			return *this;
		}
		bool operator==(iterator iterComp)
		{
			return iter == iterComp.iter;
		}
		bool operator!=(iterator iterComp)
		{
			return iter != iterComp.iter;
		}
		const T& operator*()
		{
			return (* iter).value;
		}

	};
	iterator begin()
	{
		return iterator(this);
	}
	iterator end()
	{
		return nullptr;
	}
	// continue the implementation to make for_each work on Node

};


#endif /* SRC_NODE_H_ */
