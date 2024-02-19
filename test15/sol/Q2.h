
#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <list>
#include <fstream>
#include "employee.h"
using namespace std;

void saveEmps(const char* fileName,list<Employee*> emps){
	ofstream out(fileName);
	int size=emps.size();
	out.write((char*)&size,sizeof(int));
	for(auto it=emps.begin();it!=emps.end();++it){
		Manager* m=dynamic_cast<Manager*>(*it);
		if(m){
			out.write("M",1);
			char level=m->getLevel();
			out.write(&level,1);
		}
		else
			out.write("E",1);
		double id=(*it)->getID();
		out.write((char*)&id,sizeof(double));
		int len=strlen((*it)->getName());
		out.write((char*)&(len),sizeof(int));
		out.write((*it)->getName(),len);
	}
	out.close();
}

list<Employee*> loadEmps(const char* fileName){
	list<Employee*> l;
	ifstream in(fileName);
	int size;
	in.read((char*)&size,sizeof(int));
	int i=0;
	while(i++<size){
		char c,level;
		in.read(&c,1);
		if(c=='M'){
			in.read(&level,1);
		}
		double id;
		in.read((char*)&id,sizeof(double));
		int len;
		in.read((char*)&len,sizeof(int));

		char* name=new char[len+1];
		in.read(name,len);
		name[len]='\0';


		Employee* e;
		if(c=='M')
			e=new Manager(name,id,level);
		else
			e=new Employee(name,id);
		l.push_back(e);
	}
	in.close();
	return l;
}


#endif /* SRC_Q2_H_ */
