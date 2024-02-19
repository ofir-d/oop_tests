
#ifndef SRC_ROUNDLIST_H_
#define SRC_ROUNDLIST_H_

#include<list>

using namespace std;

template<class T>
class RoundList{
	list<T> items;
public:

	RoundList(){}
	RoundList(list<T>& items){
		this->items.insert(this->items.begin(),items.begin(),items.end());
	}
	list<T> getItemsList(){ return items;}

	//--------------- START HERE ---------------------

	// implement push_front() and push_back() methods

	void push_front(const T& t){
		items.push_front(t);
	}

	void push_back(const T& t){
		items.push_back(t);
	}

	// implement inner class iterator
	class iterator{
		RoundList<T>* rl; 				// pointer to a round list object
		typename list<T>::iterator it;	// a regular iterator of list<T>
	public:
		iterator(RoundList<T>* rl):rl(rl),it(rl->items.begin()){}

		// continue the implementation...
		iterator(RoundList<T>* rl,typename list<T>::iterator it):rl(rl),it(it){}

		void operator++(){
			++it;
			if(it==rl->items.end())
				it=rl->items.begin();
		}
		void operator--(){
			if(it==rl->items.begin())
				it=rl->items.end();
			--it;
		}

		T operator*(){
			return *it;
		}

		bool operator!=(RoundList<T>::iterator other){
			return it!=other.it;
		}

	};

	// implement begin() & for_each() methods

	iterator begin(){
		return iterator(this,items.begin());
	}


	template<class func>
	func for_each(func f){
		for(T t : items)
			f(t);
		return f;
	}
};



#endif /* SRC_ROUNDLIST_H_ */
