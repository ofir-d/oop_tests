
#ifndef FUNCTIONALSORTEDLIST_H_
#define FUNCTIONALSORTEDLIST_H_

#include "SortedList.h"

class FunctionalSortedList:public SortedList{
public:

	FunctionalSortedList(list<int>& ts):SortedList(ts){}

	template<class predicate>
	int countIf(predicate p){
		int count=0;
		for(int x : data)
			if(p(x))
				count++;
		return count;
	}

	template<class binOperator>
	int fold(int identity,binOperator op){
		int r=identity;
		for(int x : data)
			r=op(r,x);
		return r;
	}


};


#endif /* FUNCTIONALSORTEDLIST_H_ */
