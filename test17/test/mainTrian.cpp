#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "round_list.h"
#include "objects.h"
#include "set.h"

using namespace std;

//-------------------------------------------------- QUESTION 1 ----------------------------
void test1a(){

	int a[6]={rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};

	RoundList<int> rl;

	rl.push_front(a[2]);
	rl.push_front(a[1]);
	rl.push_front(a[0]);
	rl.push_back(a[3]);
	rl.push_back(a[4]);
	rl.push_back(a[5]);

	// list should be a[0],a[1],a[2],a[3],a[4],a[5]

	list<int> itemsList=rl.getItemsList();
	if(itemsList.size()!=6)
		cout<<"wrong inner list size (-6)"<<endl;
	else{
		int i=0;
		for(int x : itemsList){
			if(x!=a[i])
				cout<<"wrong item in list (-1)"<<endl;
			i++;
		}
	}
}

void test1b(){

	int a[6]={rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};

	list<int> l;
	for(int x: a)
		l.push_back(x);

	RoundList<int> rl(l);

	// list should be a[0],a[1],a[2],a[3],a[4],a[5]

	RoundList<int>::iterator it(&rl); // points to the beginning of the round list
									  // instead of the student's implementation of begin()

	if(*it!=a[0])
		cout<<"problem in the round list iterator's op* (-5)"<<endl;
	++it;
	++it;
	if(*it!=a[2])
		cout<<"problem in the round list iterator's op++ or op* (-5)"<<endl;
	--it;
	if(*it!=a[1])
		cout<<"problem in the round list iterator's op-- or op* (-5)"<<endl;

	RoundList<int>::iterator begin(&rl); // should point to the beginning of the round list
	if(!(begin!=it))
		cout<<"problem in the round list iterator's op!= (-2)"<<endl;

	--it;

	if(begin!=it)
		cout<<"problem in the round list iterator's op!= (-3)"<<endl;

	--it;
	if(*it!=a[5])
		cout<<"problem in roundness of op-- or problem in op* (-5)"<<endl;

	++it;
	if(*it!=a[0])
		cout<<"problem in roundness of op++ or problem in op* (-5)"<<endl;

}

void test1c(){

	int a[6]={rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};

	list<int> l;
	for(int x: a)
		l.push_back(x);

	RoundList<int> rl(l);

	// list should be a[0],a[1],a[2],a[3],a[4],a[5]

	RoundList<int>::iterator it=rl.begin();
	if(*it!=a[0])
		cout<<"problem in begin method or the iterator's op* (-6)"<<endl;
}

struct Sum{
	int sum=0;
	void operator()(int x){
		sum+=x;
	}
};

void test1d(){

	int a[6]={rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100};

	int sum=0;
	list<int> l;
	for(int x: a){
		l.push_back(x);
		sum+=x;
	}

	RoundList<int> rl(l);

	// list should be a[0],a[1],a[2],a[3],a[4],a[5]

	Sum s;
	s=rl.for_each(s);
	if(s.sum!=sum)
		cout<<"problem in the result of for_each (-8)"<<endl;

}

////-------------------------------------------------- QUESTION 2 ----------------------------
//
void test2a(){
	Student s(1);
	Orange o(2);
	Phone p1(3);
	Phone p2(4);
	Phone p3(5);


	Set phones(345);
	bool b=true;
	b&=phones.add(p1);
	b&=phones.add(p2);
	b&=phones.add(p3);
	if(!b)
		cout<<"problem in adding new objects to the set (-2)"<<endl;
	if(phones.add(p1) || phones.add(p2) || phones.add(p3))
		cout<<"you cannot add existing elements to the set (-3)"<<endl;

	Set objects(2345);
	if(!objects.add(phones))
		cout<<"problem adding a set into a set (-5)"<<endl;
	objects.add(o);

	Set bigSet(12345345);
	b=true;
	b&=bigSet.add(s);
	b&=bigSet.add(objects);
	b&=bigSet.add(phones);

	if(!b)
		cout<<"problem adding sets into a big set (-5)"<<endl;
}

void test2b(){
	Student s(1);
	Orange o(2);
	Phone p1(3);
	Phone p2(4);
	Phone p3(5);


	Set phones(345);
	phones.add(p1);
	phones.add(p2);
	phones.add(p3);

	Set objects(2345);
	objects.add(phones);
	objects.add(o);

	Set bigSet(12345345);
	bigSet.add(s);
	bigSet.add(objects);
	bigSet.add(phones);

	if(!phones.contains(3) || !phones.contains(4) || !phones.contains(5))
		cout<<"problem with contains method (-5)"<<endl;

	phones.remove(3);
	bigSet.remove(1);
	if(bigSet.contains(1) || phones.contains(3))
		cout<<"problem with remove method or contains method (-5)"<<endl;

}


void test2c(){
	Student s(1);
	Orange o(2);
	Phone p1(3);
	Phone p2(4);
	Phone p3(5);


	Set phones(345);
	phones.add(p1);
	phones.add(p2);
	phones.add(p3);

	Set objects(2345);
	objects.add(phones);
	objects.add(o);

	Set bigSet(12345345);
	bigSet.add(s);
	bigSet.add(objects);
	bigSet.add(phones);

	if(phones.size()!=3 || objects.size()!=2 || bigSet.size()!=3)
		cout<<"problem with size method (-5)"<<endl;

	if(phones.deepSize()!=3)
		cout<<"problem with deepSize method for a simple set (-5)"<<endl;

	if(objects.deepSize()!=5)
		cout<<"problem with deepSize method for a deep set (-5)"<<endl;

	if(bigSet.deepSize()!=11)
		cout<<"problem with deepSize method for a deep set (-10)"<<endl;

}


int main(){
	srand(time(NULL));
	
    // question 1
	test1a();
    test1b();
    test1c();
    test1d();

    // question 2
    test2a();
    test2b();
    test2c();

	cout<<"done"<<endl;
	return 0;
}