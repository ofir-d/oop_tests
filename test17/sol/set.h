#ifndef SRC_SET_H_
#define SRC_SET_H_

#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;

#include "objects.h"

// implement class Set

class Set:public Object{
	vector<Object*> objects;
public:
	Set(int id):Object(id){}

	bool add(Object& o){

		for(Object* oi : objects)
			if(oi->id==o.id)
				return false;
		objects.push_back(&o);
		return true;
	}

	void remove(int id){
		remove_if(objects.begin(),objects.end(),[&id](Object* o){return o->id==id;});
	}

	bool contains(int id){
		bool b=false;
		for(Object* oi : objects)
			if(oi->id==id)
				return true;
		return b;
	}

	int size(){
		return objects.size();
	}

	int deepSize(){
		int size=0;
		for(Object* oi : objects){
			size+=1;
			Set* s=dynamic_cast<Set*>(oi);
			if(s)
				size+=s->deepSize();
		}
		return size;
	}
};



#endif /* SRC_SET_H_ */
