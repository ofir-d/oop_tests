
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

	

	Stream<T> distinct() {
		Stream newStream = Stream();
		for (auto iter = items.begin(); iter != items.end(); iter++)
		{
			if (!newStream.anyMatch([&](T value) {return value == *iter;}))
			{
				newStream.push(*iter);
			}
		}
		return newStream;
	}
	
	template<typename func_obj>
	Stream<T> filter(func_obj predicate)
	{
		Stream newStream = Stream();
		for (auto iter = items.begin(); iter != items.end(); iter++)
		{
			if (predicate(*iter))
			{
				newStream.push(*iter);
			}
		}
		return newStream;
	}
	
	template<typename func_obj>
	void forEach(func_obj func)
	{
		for (auto iter = items.begin(); iter != items.end(); iter++)
		{
			func(*iter);
		}
	}
	
	template<typename func_obj>
	T reduce(T id, func_obj func)
	{
		T result = id;
		for (auto iter = items.begin(); iter != items.end(); iter++)
		{
			result  = func( result ,*iter);
		}
		return result;
	}
	
	template<typename func_obj>
	bool allMatch(func_obj func)
	{
		for (auto iter = items.begin(); iter != items.end(); iter++)
		{
			if (!func(*iter))
			{
				return false;
			}
		}
		return true;
	}
	
	template<typename func_obj>
	bool anyMatch(func_obj func)
	{
		for (auto iter = items.begin(); iter != items.end() ; iter++)
		{
			if (func(*iter))
			{
				return true;
			}
		}
		return false;
	}

};


#endif /* SRC_Q2_H_ */
