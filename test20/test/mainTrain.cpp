#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Q1.h"
#include "Q2.h"
using namespace std;


// test for quiestion 1
void testQ1(){

	// test1
	SnakesNladders2 snd;
    snd.addGlue(3,5);
	SnakesNladders2::iterator it=snd.getIterator();

	if(*it!=0)
		cout<<"new iterator should return index 0 (-10)"<<endl;
	++it; // 1
	++it; // 2
	++it; // 3
    
    // 5 times ++ should stay on 3...
	++it; // 3
	++it; // 3
	++it; // 3
	++it; // 3
	++it; // 3
	if(*it!=3)
		cout<<"wrong value returned for iterator on glue (-10)"<<endl;

	++it; // 4

	if(*it!=4)
		cout<<"wrong value returned for iterator passing glue (-10)"<<endl;

	// test2
	SnakesNladders2 snd2;
    snd2.addLadder(3,10);
    snd2.addGlue(3,5);
	it=snd2.getIterator();

    ++it; // 1
    ++it; // 2
    ++it; // 3-->10

	if(*it!=10)
		cout<<"wrong value returned for iterator with no glue (-10)"<<endl;

	// test3
	SnakesNladders2 snd3;
    snd3.addLadder(3,10);
    snd3.addGlue(10,3);
	it=snd3.getIterator();

    ++it; // 1
    ++it; // 2
    ++it; // 3-->10
    
    ++it; // 10
    ++it; // 10
    ++it; // 10

	if(*it!=10)
		cout<<"wrong value returned for iterator passing glue (-10)"<<endl;

    ++it; // 11

	if(*it!=11)
		cout<<"wrong value returned for iterator on glue (-10)"<<endl;


}

// test for quiestion 2
void testQ2(){
    srand (time(NULL));

    // test1 set & get 20 points
    SpreadSheet s;
    for(int i=0;i<10;i++){
        float x=rand()%100;
        char c[2];
        c[0] = 'A' + rand()%5;
        c[1] = '1' + rand()%5;
        s.set(c,x);
        if(s.get(c)!=x)
            cout<<"wrong value for cell (-2)"<<endl;
    }

    // test 2 applyFunc 10 points
    SpreadSheet s2;
    float x=rand()%100;
    char c[2];
    c[0] = 'B' + rand()%4;
    c[1] = '1' + rand()%5;
    s2.set(c,x);    
    s2.applyFunc(c,[](float x){return x*2;},"A1");
    if(s2.get("A1")!=x*2)
        cout<<"wrong value for cell after applyFunc (-5)"<<endl;

    
    s2.applyFunc(c,[](float x){return x*x;},"A2");
    if(s2.get("A2")!=x*x)
        cout<<"wrong value for cell after applyFunc (-5)"<<endl;

    
    // test 3 setFunc 20 points
    SpreadSheet s3;
    x=rand()%100;
	char c3[2];
    c3[0] = 'B' + rand()%4;
    c3[1] = '1' + rand()%5;
    s3.onChange(c3,[](float x){return x*2;},"A1");
    if(s3.get("A1")!=0)
        cout<<"wrong value for cell for onChange before change (-5)"<<endl;
    
    s3.set(c3,x);    
    if(s3.get("A1")!=x*2)
        cout<<"wrong value for cell for onChange after change (-5)"<<endl;

    x=rand()%100;
	char c4[2];
    c4[0] = 'B' + rand()%4;
    c4[1] = '1' + rand()%5;
    s3.onChange(c4,[](float x){return x*x;},"A4");
    if(s3.get("A4")!=0)
        cout<<"wrong value for cell for onChange before change (-5)"<<endl;
    
    s3.set(c4,x);    
    if(s3.get("A4")!=x*x)
        cout<<"wrong value for cell for onChange after change (-5)"<<endl;
}



int main(){
	testQ1();
    testQ2();
	cout<<"done"<<endl;

	return 0;
}


