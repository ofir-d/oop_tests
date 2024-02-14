#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

void test1(){
	MySet<double> ms1;
	// adds each number from 1 to 10 twise!
	for (int i = 1; i < 21; i++){
		ms1.add(i);
		ms1.add(i); // this should not be allowed in
		ms1.add(i); // this should not be allowed in
	}
	if(ms1.size()!=20)
		cout<<"problem in the add method of MySet (-10)"<< endl;
	// count the number of even ints inside ms1
}

void test2(){
	Expression* e = new Plus(new Num(5), new Num(2));
	if (e->calculate()!=7)
		cout<<"problem with plus (-5)"<< endl; 
	delete e;
	e = new Minus(new Num(5), new Num(2));
	if (e->calculate() != 3)
		cout << "problem with minus (-5)" << endl;
	delete e;

}

class F : public A{
public:
	virtual void print(){ cout << "F" << endl; }
};



void test3(){
	A** arr = new A*[8];
	arr[0] = new F();
	arr[1] = new B();
	arr[2] = new E();
	arr[3] = new F();
	arr[4] = new D();
	arr[5] = new C();
	arr[6] = new E();
	arr[7] = new F();

	if(countBs(arr, 8)!=1)
		cout << "problem with countBs implementation (-15)"<< endl; // should be 3
	if(countTypeOfBs(arr, 8)!=3)
		cout << "problem with countTypeOfBs implementation (-15)" << endl;// should be 6

	for (int i = 0; i < 8; i++)
		delete arr[i];
	delete arr;
}


int main(){
	//testQ1API();
	//testQ2API();
	testQ3API();
	
	//test1();
	//test2();
	test3();
	cout << "done" << endl;
	return 0;
}