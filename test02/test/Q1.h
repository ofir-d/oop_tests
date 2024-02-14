#include <list>
#include <iostream>
using namespace std;

template<class E>
class MySet{
	list<E> lst;
public:
	void add(E e){
		for (auto i = lst.begin(); i != lst.end(); i++)
		{
			if (*i == e)
			{
				return;
			}
		}
		lst.push_back(e);
	}

	template<typename func>
	int countIf(func f){
		int sum = 0;
		for (auto i = lst.begin(); i != lst.end(); i++)
		{
			if (f(*i))
			{
				sum++;
			}
		}
		return sum;
	}

	template<typename func>
	MySet<E> splitIf(func f){
		MySet removedItems = MySet();
		typename list<E>::iterator iter = lst.begin();
		while (iter != lst.end())
		{
			if (f(*iter))
			{
				E value = *iter;
				iter = lst.erase(iter);
				removedItems.add(value);
			}
			else {
				iter++;
			}
		}
		return removedItems;
	}

	int size(){ return lst.size(); }
};

// tests the API for Q1
void testQ1API(){
	MySet<int> ms1;
	// adds each number from 1 to 10 twise!
	for (int i = 1; i < 11; i++){
		ms1.add(i);
		ms1.add(i); // this should not be allowed in
	}
	cout << ms1.size() << endl; // should be 10
	// count the number of even ints inside ms1
	cout << ms1.countIf([](int x){return x % 2 == 0; }) << endl; // should be 5
	// split the ints that are bigger than 3
	MySet<int> ms2 = ms1.splitIf([](int x){return x>3; });
	cout << ms1.size() << endl; // should be 3 (the numbers 1,2,3)
	cout << ms2.size() << endl; // should be 7 (the numbers 4,5,6,7,8,9,10)
}