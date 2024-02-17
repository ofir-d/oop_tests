


#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <typeinfo>
#include "Q1.h"
#include "Q2.h"
using namespace std;


// test for quiestion 1
void testQ1(){

	// simple test
	SnakesNladders snd;
	snd.addLadder(2,50);
	snd.addSnake(51,40);
	SnakesNladders::iterator it=snd.getIterator();

	if(*it!=0)
		cout<<"new iterator should return index 0 (-10)"<<endl;
	++it; // 1
	++it; // 2 --> 50
	++it;// 51 --> 40
	if(*it!=40)
		cout<<"wrong value returned for iterator (-10)"<<endl;

	// medium test
	SnakesNladders snd2;
	snd2.addLadder(1,30);
	snd2.addLadder(30,45);
	snd2.addSnake(45,29);
	snd2.addSnake(29,10);
	snd2.addLadder(10,50);

	it=snd2.getIterator();
	++it; // 1-->30-->45-->29-->10-->50
	if(*it!=50)
		cout<<"wrong value returned for iterator medium test (-10)"<<endl;

	// loops test
	if(snd2.hasLoops())
		cout<<"wrong answer for hasLoops (-5)"<<endl;

	snd2.addSnake(50,1);
	if(!snd2.hasLoops())
		cout<<"wrong answer for hasLoops (-5)"<<endl;

	SnakesNladders snd3;
	snd3.addLadder(2,10);
	snd3.addLadder(10,31);
	snd3.addSnake(31,9);

	if(snd3.hasLoops())
		cout<<"wrong answer for hasLoops (-5)"<<endl;

	snd3.addLadder(5,40);
	snd3.addLadder(40,80);
	snd3.addSnake(80,19);
	snd3.addSnake(19,5);
	if(!snd3.hasLoops())
		cout<<"wrong answer for hasLoops (-5)"<<endl;
}

bool eqp(Point* p1, Point* p2){
    return p1->x==p2->x && p1->y==p2->y;
}

bool eql(Line* l1, Line*l2){
    return eqp(&(l1->from),&(l2->from)) && eqp(&(l1->to),&(l2->to));
}

bool eqa(Area* a1, Area* a2){
    return eql(&(a1->l1),&(a1->l1)) && eql(&(a1->l2),&(a2->l2));
}

bool equals(Shape* s1, Shape*s2){
    if(typeid(*s1)==typeid(Point))
        return eqp((Point*)s1,(Point*)s2);
    if(typeid(*s1)==typeid(Line))
        return eql((Line*)s1,(Line*)s2);
    
    return eqa((Area*)s1,(Area*)s2);    
}

// test for quiestion 2
void testQ2(){
    srand (time(NULL));
    int x1=rand() % 10 + 1;
    int y1=rand() % 10 + 1;
    int x2=rand() % 10 + 1;
    int y2=rand() % 10 + 1;
    int x3=rand() % 10 + 1;
    int y3=rand() % 10 + 1;
    int x4=rand() % 10 + 1;
    int y4=rand() % 10 + 1;
    
    Point p1(x1,y1);
    Point p2(x2,y2);
    Point p3(x3,y3);
    Point p4(x4,y4);

    Line l1(p1,p2);
    Line l2(p3,p4);

    Area a(l1,l2);

    Shape** shapes=new Shape*[5];
    shapes[0]=&p1;
    shapes[1]=&p2;
    shapes[2]=&l1;
    shapes[3]=&l2;
    shapes[4]=&a;

    save(shapes,5,"shapes.bin");
    Shape** shapes2 = load("shapes.bin");

    if (shapes2==nullptr){
        cout<<"load method returned NULL (-50)"<<endl;
    }else{
        for(int i=0;i<5;i++){
            if(typeid(*shapes[i]) != typeid(*shapes2[i]))
                cout<<"wrong type of object loaded (-10)"<<endl;
            else{
                if(!equals(shapes[i],shapes2[i]))
                    cout<<"wrong content of object loaded (-5)"<<endl;
            }
        }
    }

    delete[] shapes;
    for(int i=0;i<5;i++)
        delete shapes2[i];
    delete[] shapes2;
}


int main(){
	testQ1();
    testQ2();
	cout<<"done"<<endl;
	return 0;
}


