
#ifndef SRC_OBJECTS_H_
#define SRC_OBJECTS_H_

class Object{
public:
	const int id;
	Object(int id):id(id){}
	virtual ~Object(){}
};

class Student:public Object{
public:
	Student(int id):Object(id){}
	virtual ~Student(){};
};

class Orange:public Object{
public:
	Orange(int id):Object(id){}
	virtual ~Orange(){};
};

class Phone:public Object{
public:
	Phone(int id):Object(id){}
	virtual ~Phone(){};
};



#endif /* SRC_OBJECTS_H_ */
