
#ifndef SRC_Q2_H_
#define SRC_Q2_H_
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <list>
#include <fstream>
#include "employee.h"
using namespace std;

void saveEmps(const char* fileName,list<Employee*> emps)
{
	fstream f;
	char type{};
	int len{};
	const char* name;
	double id{};
	f.open(fileName, ios::binary | ios::out);
	int size = emps.size();
	f.write((char*)&size, sizeof(size));
	for (Employee* emp : emps)
	{
		if (typeid(*emp) == typeid(Employee))
		{
			type = 'E';
			f.write((char*)&type, 1);
		}
		else
		{
			type = 'M';
			f.write((char*)&type, 1);
		}
		id = emp->getID();
		f.write((char*)&id, sizeof(id));
		name = emp->getName();
		len = strlen(name);
		f.write((char*)&len, sizeof(len));
		f.write(name, len);
		Manager* man = dynamic_cast<Manager*>(emp);
		if (man)
		{
			char level = man->getLevel();
			f.write((char*)&level, sizeof(level));
		}
	}
	f.close();
}

Employee* loadEmploy(fstream& f)
{
	int nameSize{};
	double id{};
	f.read((char*)&id, sizeof(id));
	f.read((char*)&nameSize, sizeof(nameSize));
	char* name = new char[nameSize + 1];
	f.read(name, nameSize);
	name[nameSize] = '\0';
	return new Employee(name, id);

}

Manager* loadManager(fstream& f)
{
	char level{};
	Employee* emp_part = loadEmploy(f);
	f.read(&level, sizeof(level));
	return new Manager(emp_part->getName(), emp_part->getID(), level);

}

list<Employee*> loadEmps(const char* fileName){
	list<Employee*> l;
	fstream f;
	int listLen{};
	char type[1];
	f.open(fileName, ios::in | ios::binary);
	f.read((char *)&listLen, sizeof(listLen));
	for (size_t i = 0; i < listLen; i++)
	{
		f.read(type, sizeof(type));
		switch (type[0])
		{
		case 'E':
			l.push_back(loadEmploy(f));
			break;
		case 'M':
			l.push_back(loadManager(f));
			break;
		default:
			break;
		}
	}
	f.close();
	return l;
}


#endif /* SRC_Q2_H_ */
