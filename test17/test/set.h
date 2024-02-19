#ifndef SRC_SET_H_
#define SRC_SET_H_

#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;

#include "objects.h"

class Set : public Object {
	vector<Object*> group;
public:
	Set(int id) :Object(id) {}
	bool add(Object& obj);
	Set& remove(int idRemove);
	bool contains(int idCheck);
	int size();
	int deepSize();
};
bool Set::contains(int idCheck)
{
	for (Object* element : group)
	{
		if (element->id == idCheck)
		{
			return true;
		}
	}
	return false;
}
bool Set::add(Object& obj)
{
	if (contains(obj.id))
	{
		return false;
	}
	group.push_back(&obj);
	return true;
}

Set& Set::remove(int idRemove)
{
	for (auto iter = group.begin(); iter != group.end(); iter++)
	{
		if ((*iter)->id == idRemove)
		{
			iter = group.erase(iter);
			return *this;
		}
	}
	return *this;
}
int Set::size()
{
	return group.size();
}
int Set::deepSize()
{
	int sum = 0;
	for (Object* obj : group)
	{
		sum++;
		Set* newSet = newSet = dynamic_cast<Set*>(obj);
		if (newSet)
		{
			sum += newSet->deepSize();
		}
	}
	return sum;
}
// implement class Set
// and the following methods:
// , size() , deepSize() 




#endif /* SRC_SET_H_ */
