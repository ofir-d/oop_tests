
#ifndef FUNCTIONALSORTEDLIST_H_
#define FUNCTIONALSORTEDLIST_H_

#include "SortedList.h"

class FunctionalSortedList:public SortedList{
public:

	FunctionalSortedList(list<int>& ts):SortedList(ts){}
	
	template<typename funci>
	int countIf(funci f)
	{
		int sum = 0;
		for (auto var : data)
		{
			if (f(var))
			{
				sum++;
			}
		}
		return sum;
	}
	
	template<typename funci>
	int fold(int identity, funci f)
	{
		int result = identity;
		for (auto var : data)
		{
			result = f(result, var);
		}
		return result;
	}
	// implement fold


};


#endif /* FUNCTIONALSORTEDLIST_H_ */


/*
 examples:

	FunctionalSortedList sl; // for instance 10, 12, 20
	
	//...

	sl.countIf([](int i){return i%2==0;}) // = 3
	
	sl.fold(0,[](int x,int y){return x+y;}) // = (((0 + 10) + 12) + 20) = 42
	
	sl.fold(1,[](int x,int y){return x*y;}) // = (((1 * 10) * 12) * 20) = 2400
	
*/