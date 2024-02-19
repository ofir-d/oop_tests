#include "SortedList.h"
#include <algorithm>


	// IMPLEMENT THE FOLLOWING:
	
	void SortedList::add(int t)
	{
		list<int> newList;
		bool found = false;
		for (auto var : data)
		{
			if (var > t && !found)
			{
				found = true;
				newList.push_back(t);
			}
			newList.push_back(var);
		}
		if (!found)
		{
			newList.push_back(t);
		}
		data = newList;

		/*auto prev = data.begin();
		if (prev == data.end())
		{
			data.push_front(t);
			return;
		}
		auto temp = ++data.begin();
		while (prev != data.end()) 
		{
			if (temp == data.end())
			{
				data.push_back(t);
				return;
			}
			if (*temp > t)
			{
				data.insert(prev, t);
				return;
			}
			++prev;
			++temp;
		} 
		data.push_front(t);*/
	}

	int SortedList::max(){
		return data.back();
	}

	int SortedList::min(){
		return data.front();
	}

	bool SortedList::contains(int x){
		auto iter = find(data.begin(), data.end(), x);
		if (iter != data.end())
		{
			return true;
		}
		return false;
	}



