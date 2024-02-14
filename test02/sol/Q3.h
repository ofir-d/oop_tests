#include <iostream>
#include <typeinfo>

using namespace std;

class A{
public:
	virtual void print() = 0;
};

class B : public A{
public:
	virtual void print(){ cout << "B" << endl; }
};

class C : public B{
public:
	virtual void print(){ cout << "C" << endl; }
};

class D : public B{
public:
	virtual void print(){ cout << "D" << endl; }
};

class E : public A{
public:
	virtual void print(){ cout << "E" << endl; }
};


// count how many B objects are in arr
int countBs(A** arr, int size){
	int count = 0;
	for (int i = 0; i < size; i++){
		if (typeid(*arr[i]) == typeid(B))
			count++;
	}
	return count;
}

int countTypeOfBs(A** arr, int size){
	int count = 0;
	for (int i = 0; i < size; i++){
		B* b = dynamic_cast<B*>(arr[i]);
		if (b)
			count++;
	}
	return count;
}

void testQ3API(){
	A** arr = new A*[7];
	arr[0] = new B();
	arr[1] = new C();
	arr[2] = new E();
	arr[3] = new B();
	arr[4] = new D();
	arr[5] = new C();
	arr[6] = new E();

	cout << countBs(arr, 7) << endl; // should be 2
	cout << countTypeOfBs(arr, 7) << endl; // should be 5

	for (int i = 0; i < 7; i++)
		delete arr[i];
	delete arr;
}