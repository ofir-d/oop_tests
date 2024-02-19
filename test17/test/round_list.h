
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
	const RoundList<T>& push_front(T data)
	{
		items.push_front(data);
		return *this;
	}
	// implement push_front() and push_back() methods
	const RoundList<T>& push_back(T data)
	{
		items.push_back(data);
		return *this;
	}

	// implement inner class iterator
	class iterator{
		RoundList<T>* rl; 				// pointer to a round list object
		typename list<T>::iterator it;	// a regular iterator of list<T>
	public:
		iterator(RoundList<T>* rl):rl(rl),it(rl->items.begin()){}

		iterator& operator++()
		{
			auto temp = ++it;
			if (temp == rl->items.end())
			{
				it = rl->items.begin();
				return *this;
			}
			return *this;
		}

		iterator operator++(int)
		{
			auto temp = it;
			if (it == rl->items.end())
			{
				it = rl->items.begin();
				return temp;
			}
			it++;
			return temp;
		}

		iterator& operator--()
		{
			if (it == rl->items.begin())
			{
				it = rl->items.end();
			}
			it--;
			return *this;
		}

		iterator operator--(int)
		{
			auto temp = it;
			if (it == rl->items.begin())
			{
				it = rl->items.end();
				return temp;
			}
			it--;
			return temp;
		}

		bool operator!=(const iterator& iter)
		{
			return it != iter.it;
		}
		bool operator==(const iterator& iter) 
		{
			return it == iter.it;
		}
		T& operator* ()
		{
			return *it;
		}

		// continue the implementation...

	};

	// implement begin() & for_each() methods
	iterator begin()
	{
		return iterator(this);
	}

	template<typename func_obj>
	func_obj for_each(func_obj func)
	{
		for (T item : items)
		{
			func(item);
		}
		return func;
	}
};



#endif /* SRC_ROUNDLIST_H_ */
