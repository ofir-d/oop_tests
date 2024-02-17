#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <fstream>
#include <typeinfo>
using namespace std;
    

class Shape{
public:
    virtual ~Shape(){}
};

class Point{
};

class Line{
};

class Area{

};

void save(Shape** shapes, int size, const char* fileName){
}

Shape** load(const char* fileName){
}

#endif /* SRC_Q2_H_ */