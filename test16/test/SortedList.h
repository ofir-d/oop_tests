
#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

// DON'T CHANGE - NOT FOR SUBMIT

#include <iostream>
#include <list>
using namespace std;

class SortedList{

protected:
	list<int> data;

public:

	SortedList(){}

	SortedList(list<int>& ts){
		data=ts;
	}

	bool isSorted(){
		bool sorted=true;
		auto it=data.begin();
		auto next=data.begin();
		next++;
		while(next!=data.end()){
			if(*next < *it){
				sorted=false;
				break;
			}
			next++;
			it++;
		}
		return sorted;
	}

	void add(int t);


	int max();
	int min();

	bool contains(int x);


};



#endif /* SORTEDLIST_H_ */
