
#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Stream{
	vector<T> items;
public:

	void push(T t){
		items.push_back(t);
	}

	vector<T> get(){return items;}


	Stream<T> distinct(){
		Stream<T> r;
		for(T t : items){
			auto it=find(r.items.begin(),r.items.end(),t);
			if(it==r.items.end())
				r.push(t);
		}
		return r;
	}

	template<class Predicate>
	Stream<T> filter(Predicate p){
		Stream<T> r;
		for(T t : items){
			if(p(t))
				r.push(t);
		}
		return r;
	}



	template <class consumer>
	void forEach(consumer c){
		for(T t : items)
			c(t);
	}

	template <class binop>
	T reduce(T id, binop bin){
		T result=id;
		for(T t : items){
			result=bin(result,t);
		}
		return result;
	}

	template<class Predicate>
	bool allMatch(Predicate p){
		bool b=true;
		for(T t: items){
			b&=p(t);
		}
		return b;
	}

	template<class Predicate>
	bool anyMatch(Predicate p){
		bool b=false;
		for(T t: items){
			b|=p(t);
			if(b)
				break;
		}
		return b;
	}

};


#endif /* SRC_Q2_H_ */
