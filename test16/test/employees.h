

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

// DON'T CHANGE - NOT FOR SUBMIT

class Employee{
public:
	const int id;
	Employee(int id):id(id){}
	int getID(){return  id;}
	virtual ~Employee(){};
};

class Engineer : public virtual Employee{
public:
	const char degree;
	Engineer(int id, char degree):Employee(id),degree(degree){}
};

class Developer : public virtual Employee{
public:
	const unsigned int level;
	Developer(int id, unsigned int level):Employee(id),level(level){}
};


struct Counter{
	int engineers;
	int developers;
	int softwareDevelopers;
};

#endif /* EMPLOYEES_H_ */
