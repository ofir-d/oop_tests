#include "SortedList.h"
#include <algorithm>


	void SortedList::add(int t){ // adds t to the list at its sorted position
		auto it=data.begin();
		while(it!=data.end() && t>*it) it++;
		data.insert(it,t);
	}

	int SortedList::max(){
		return *(--data.end());
	}

	int SortedList::min(){
		return *(data.begin());
	}

	bool SortedList::contains(int x){
		for(int y : data)
			if(x==y)
				return true;
		return false;
	}



