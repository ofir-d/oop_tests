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

class BinaryExpression:public Expression{
	protected:
	Expression *left, *right;
public:
	BinaryExpression(Expression *leftExp, Expression *rightExp){
		left = leftExp;
		right = rightExp;
	}

	virtual ~BinaryExpression(){
		delete left;
		delete right;
	}
};

class Plus :public BinaryExpression{
public:
	Plus(Expression *leftExp, Expression *rightExp) :BinaryExpression(leftExp, rightExp){}

	virtual double calculate(){
		return left->calculate() + right->calculate();
	}
};

class Minus :public BinaryExpression{
public:
	Minus(Expression *leftExp, Expression *rightExp) :BinaryExpression(leftExp, rightExp){}

	virtual double calculate(){
		return left->calculate() - right->calculate();
	}
};

class Mul :public BinaryExpression{
public:
	Mul(Expression *leftExp, Expression *rightExp) :BinaryExpression(leftExp, rightExp){}

	virtual double calculate(){
		return left->calculate() * right->calculate();
	}
};

class Div :public BinaryExpression{
public:
	Div(Expression *leftExp, Expression *rightExp) :BinaryExpression(leftExp, rightExp){}

	virtual double calculate(){
		return left->calculate() / right->calculate();
	}
};

// ------------------------- TEST API - YOU ARE NOT ALLOWED TO CHANGE THIS... ----------------
void testQ2API(){
	// 5+3*(8-4/2) = 23
	Expression* e = new Plus(new Num(5), new Mul(new Num(3), new Minus(new Num(8), new Div(new Num(4), new Num(2)))));
	cout << e->calculate() << endl; // 23
	delete e; // frees the entire expression
}