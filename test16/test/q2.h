
#ifndef Q2_H_
#define Q2_H_


#include <typeinfo>
#include <fstream>
#include "employees.h"

using namespace std;


// implement
class SoftwareEngineer: public Engineer, public Developer{
public:
	const float experience;
	SoftwareEngineer(Developer dev, Engineer eng, float exp): Employee(dev.getID()), Developer(dev.getID(), dev.level), Engineer(eng.getID(), eng.degree), experience(exp){}
};


Counter countEmployees(Employee** emps,int size){

	Counter c = {};
	for (size_t i = 0; i < size; i++)
	{
		if (typeid(*emps[i]) == typeid(Developer))
		{
			c.developers++;
		}
		if (typeid(*emps[i]) == typeid(Engineer))
		{
			c.engineers++;
		}
		if (typeid(*emps[i]) == typeid(SoftwareEngineer))
		{
			c.developers++;
			c.engineers++;
			c.softwareDevelopers++;
		}
	}
	return c;
}



// implement
void save(const char* fileName, Employee* e){ 
	fstream f;
	f.open(fileName, ios::binary | ios::out);
	int id = e->id;
	f.write((char*)&id, sizeof(id));
	if (typeid(*e) == typeid(Employee))
	{
		char arr[2];
		arr[0] = 'Y';
		arr[1] = '\0';
		f.write(arr, 1);
		f.write((char*)&id, sizeof(id));
	}
	Engineer* eng = dynamic_cast<Engineer*>(e);
	if (typeid(*e) == typeid(Engineer))
	{
		char arr[2];
		arr[0] = 'E';
		arr[1] = '\0';
		f.write(arr, 1);
		f.write((char*)&eng->degree, sizeof(eng->degree));
	}
	Developer* dev = dynamic_cast<Developer*>(e);
	if (typeid(*e) == typeid(Developer))
	{
		char arr[2];
		arr[0] = 'D';
		arr[1] = '\0';
		f.write(arr, 1);
		f.write((char*)&dev->level, sizeof(dev->level));
	}
	SoftwareEngineer* se = dynamic_cast<SoftwareEngineer*>(e);
	if (typeid(*e) == typeid(SoftwareEngineer))
	{
		char arr[2];
		arr[0] = 'X';
		arr[1] = '\0';
		f.write(arr, 1);
		f.write((char*)&eng->degree, sizeof(eng->degree));
		f.write((char*)&dev->level, sizeof(dev->level));
		f.write((char*)&se->experience, sizeof(se->experience));
	}
	f.close();
}

// implement
Employee* load(const char*fileName){
	char type{};
	int id{};
	fstream f;
	f.open(fileName, ios::binary | ios::in);
	f.read((char*)&id, sizeof(id));
	f.read(&type, sizeof(type));
	if (type == 'E')
	{
		char degree{};
		f.read(&degree, sizeof(degree));
		return new Engineer(id, degree);
	}
	if (type == 'D')
	{
		unsigned int level{};
		f.read((char*)&level, sizeof(level));
		return new Developer(id, level);
	}
	if (type == 'X')
	{
		char degree{};
		unsigned int level{};
		float exp{};
		f.read(&degree, sizeof(degree));
		f.read((char*)&level, sizeof(level));
		f.read((char*)&exp, sizeof(exp));
		return new SoftwareEngineer(Developer(id, level), Engineer(id, degree), exp);
	}
	f.close();
	return new Employee(id);
}


#endif /* Q2_H_ */
