
#ifndef Q2_H_
#define Q2_H_


#include <typeinfo>
#include <fstream>
#include "employees.h"

using namespace std;

class SoftwareEngineer:public Developer, public Engineer{
public:
	const float experience;
	SoftwareEngineer(const Developer& dev, const Engineer& en,float exp):Employee(dev),Developer(dev),Engineer(en),experience(exp){}
};


Counter countEmployees(Employee** emps,int size){

	Counter c;
	c.developers=0;
	c.engineers=0;
	c.softwareDevelopers=0;

	for(int i=0;i<size;i++){
		if(dynamic_cast<Developer*>(emps[i]))
			c.developers++;
		if(dynamic_cast<Engineer*>(emps[i]))
			c.engineers++;
		if(typeid(*emps[i])==typeid(SoftwareEngineer))
			c.softwareDevelopers++;

	}

	return c;
}



void save(const char* fileName, Employee* e){ // save the Employee to a file
	ofstream out(fileName);

	char type=typeid(*e).name()[2];
	out<<type<<endl;

	out<<e->id<<endl;

	Engineer* en = dynamic_cast<Engineer*>(e);
	Developer* d = dynamic_cast<Developer*>(e);
	SoftwareEngineer* s = dynamic_cast<SoftwareEngineer*>(e);

	if(en) out<<en->degree<<endl;
	if(d) out<<d->level<<endl;
	if(s) out<<s->experience<<endl;

	out.close();
}

Employee* load(const char*fileName){
	Employee* e;

	ifstream in(fileName);

	char type;
	in>>type;
	int id;
	in>>id;

	switch(type){
	case 'm': // 8Employee
		e=new Employee(id);
		break;
	case 'n': // 8Engineer
		char deg;
		in>>deg;
		e=new Engineer(id,deg);
		break;
	case 'e': // 9Developer
		unsigned int level;
		in>>level;
		e=new Developer(id,level);
		break;
	case 'S': // 16SoftwareEngineer
		float exp;
		in>>deg;
		in>>level;
		in>>exp;
		e=new SoftwareEngineer(Developer(id,level),Engineer(id,deg),exp);
	}

	return e;
}


#endif /* Q2_H_ */
