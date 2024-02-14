#include <iostream>
using namespace std;

class Expression{
public: 
	virtual double calculate()=0;
	virtual ~Expression(){}
};

class Num :public Expression{
	int num;
public:
	Num(int anum) :num(anum){}
	virtual double calculate(){	return num;}

};

class BinaryExpression : public Num {
	protected:
	double left, right;
public:
	BinaryExpression(Num *leftExp, Num *rightExp): Num(0), left(0), right(0) {
		left = (leftExp->calculate());
		right = (rightExp->calculate());
	}

	virtual ~BinaryExpression(){
		//...
	}
};

class Plus : public BinaryExpression{
public:
	Plus(Num* leftExp, Num* rightExp): BinaryExpression(leftExp, rightExp) {}
	virtual double calculate()
	{
		return (this->left) + (this->right);
	}

};
class Minus : public BinaryExpression {
public:
	Minus(Num* leftExp, Num* rightExp) : BinaryExpression(leftExp, rightExp) {}
	virtual double calculate()
	{
		return (this->left) - (this->right);
	}
};
class Mul : public BinaryExpression {
public:
	Mul(Num* leftExp, Num* rightExp) : BinaryExpression(leftExp, rightExp) {}
	virtual double calculate()
	{
		return (this->left) * (this->right);
	}
};
class Div : public BinaryExpression {
public:
	Div(Num* leftExp, Num* rightExp) : BinaryExpression(leftExp, rightExp) {}
	virtual double calculate()
	{
		return (this->left) / (this->right);
	}
};

// ------------------------- TEST API - YOU ARE NOT ALLOWED TO CHANGE THIS... ----------------
void testQ2API(){
	// 5+3*(8-4/2) = 23
	Expression* e = new Plus(new Num(5), new Mul(new Num(3), new Minus(new Num(8), new Div(new Num(4), new Num(2)))));
	cout << e->calculate() << endl; // 23
	delete e; // frees the entire expression
}