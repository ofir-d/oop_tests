
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SortedList.h"
#include "FunctionalSortedList.h"
#include "q2.h"

using namespace std;

// un-comment each test as you answer the test

// --------------------------------------- 1.a
void test1a(){
	SortedList sl;
	for(size_t i=0;i<10;i++)
		sl.add(rand()%100 +1 );

	if(!sl.isSorted())
		cout<<"your list is not sorted after add (-10)"<<endl;
}


 //--------------------------------------- 1.b
void test1b(){

	list<int> l;

	int x=rand()%100 +1;
	int max=x,min=x;
	for(size_t i=0;i<10;i++){
		l.push_back(x);
		if(x>max)
			max=x;
		if(x<min)
			min=x;

		x=rand()%100 +1;
	}
	l.sort();

	SortedList sl(l);

	if(sl.max()!=max)
		cout<<"wrong max value returned (-5)"<<endl;

	if(sl.min()!=min)
		cout<<"wrong min value returned (-5)"<<endl;

}



// --------------------------------------- 1.c
void test1c(){
	list<int> l;
	int x;
	int y=rand()%100 +1;
	int z=rand()%10;
	for(int i=0;i<10;i++){
		do{
			x=rand()%100 +1;
		}while(x==y);

		l.push_back(x);

		if(i==z)
			z=x;
	}
	l.sort();

	SortedList sl(l);

	if(!sl.contains(z))
		cout<<"the list should contain the value (-5)"<<endl;

	if(sl.contains(y))
		cout<<"the list should not contain the value (-5)"<<endl;

}



// --------------------------------------- 1.d
void test1d(){
	list<int> l;
	int x,count0=0,count1=0;
	for(int i=0;i<10;i++){
		x=rand()%100 +1;
		l.push_back(x);

		if(x%2==0)
			count0++;

		if(x>50)
			count1++;
	}
	l.sort();

	FunctionalSortedList sl(l);

	if(sl.countIf([](int i){return i%2==0;}) !=count0)
		cout<<"problem with count if (-5)"<<endl;

	if(sl.countIf([](int i){return i>50;}) !=count1)
		cout<<"another problem with count if (-5)"<<endl;

}



// --------------------------------------- 1.e
void test1e(){
	list<int> l;
	int x,sum=0,p=1;
	for(int i=0;i<10;i++){
		x=rand()%100 +1;
		l.push_back(x);
		sum+=x;
		p*=x;
	}
	l.sort();

	FunctionalSortedList sl(l);

	if(sl.fold(0,[](int x,int y){return x+y;}) != sum)
		cout<<"problem with fold (-5)"<<endl;

	if(sl.fold(1,[](int x,int y){return x*y;}) != p)
		cout<<"another problem with fold (-5)"<<endl;

}



// --------------------------------------- 2.a
void test2a(){
	Developer d(123, 1);
	Engineer e(321, 'A');

	// the following lines must compile
	SoftwareEngineer se(d,e,3.3f);
	Employee* ep=&se;
	Developer* dp=&se;
	Engineer* enp=&se;

	if(se.getID()!=123 || ep->getID()!=123 || dp->getID()!=123 || enp->getID()!=123)
		cout<<"wrong id for software engineer (-5)"<<endl;
}



// --------------------------------------- 2.b
void test2b(){
	Counter s;
	s.developers=0;
	s.engineers=0;
	s.softwareDevelopers=0;

	Employee** emps=new Employee*[20];
	for(size_t i=0;i<20;i++){
		int x=rand()%3;
		if(x==0){
			emps[i]=new Developer(1,1);
			s.developers++;
		}
		else
			if(x==1){
				emps[i]=new Engineer(1,'A');
				s.engineers++;
			}
			else{
				emps[i]=new SoftwareEngineer(Developer(1,1),Engineer(1,'A'),3.3);
				s.softwareDevelopers++;
				s.developers++;
				s.engineers++;
			}

	}

	Counter r = countEmployees(emps,20);

	if(r.developers!=s.developers)
		cout<<"wrong count of developers (-5)"<<endl;

	if(r.engineers!=s.engineers)
		cout<<"wrong count of engineers (-5)"<<endl;

	if(r.softwareDevelopers!=s.softwareDevelopers)
		cout<<"wrong count of software developers (-5)"<<endl;

	for(size_t i=0;i<20;i++)
		delete emps[i];

	delete [] emps;

}


// --------------------------------------- 2.c
void test2c(){
	Employee* e1=new Employee(rand()%10);
	save("e1",e1);
	Employee* s1 = load("e1");
	if(s1->id!=e1->id)
		cout<<"problem with save or load Employee (-5)"<<endl;

	delete e1;
	delete s1;

	Engineer* e2=new Engineer(rand()%10,'A'+(char)(rand()%10));
	save("e2",e2);
	Engineer* s2 = dynamic_cast<Engineer*>(load("e2"));
	if(s2==nullptr || s2->id!=e2->id || s2->degree!=e2->degree)
		cout<<"problem with save or load Engineer (-5)"<<endl;

	delete e2;
	delete s2;

	Developer* e3=new Developer(rand()%10,rand()%100);
	save("e3",e3);
	Developer* s3 = dynamic_cast<Developer*>(load("e3"));
	if(s3==nullptr || s3->id!=e3->id || s3->level!=e3->level)
		cout<<"problem with save or load Developer (-5)"<<endl;

	delete e3;
	delete s3;

	Developer d(rand()%10,rand()%100);
	Engineer e(rand()%10,'A'+(char)(rand()%10));
	SoftwareEngineer* e4=new SoftwareEngineer(d,e,rand()%200);

	save("e4",e4);
	SoftwareEngineer* s4 = dynamic_cast<SoftwareEngineer*>(load("e4"));
	if(s4==nullptr || s4->id!=e4->id || s4->level!=e4->level || s4->degree!=e4->degree || s4->experience!=e4->experience)
		cout<<"problem with save or load SoftwareEngineer (-5)"<<endl;

	delete e4;
	delete s4;

}



// un-comment each test as you answer the test
int main(){
	srand(time(NULL));

// question 1

	test1a();
	test1b();
	test1c();
	test1d();
	test1e();

// question 2

	test2a();
	test2b();
	test2c();

	cout<<"done"<<endl;
	return 0;
}
