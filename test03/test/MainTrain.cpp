#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

struct TestComparator{
    int operator()(double a, double b){
        return b-a;
    }
};

void test1(){
	PriorityQueue<double,TestComparator> queue;
	for(double i=0;i<100;i++)
		queue.push(i);
	
    queue.forEach([](double i){
        if((int)i%10==0)
            cout<<i<<" ";
    }); 
    cout<<endl; // should output: "90 80 70 60 50 40 30 20 10 0 "
	
	if(queue.poll()!=99)
		cout<<"wrong prioritization for first value (-10)"<<endl;
	for(int j=0;j<50;j++)
		queue.poll();
	if(queue.poll()!=48)
		cout<<"wrong prioritization for middle value (-5)"<<endl;
	for(int j=0;j<47;j++)
		queue.poll();
	if(queue.poll()!=0)
		cout<<"wrong prioritization for last value (-5)"<<endl;
	

}


void test2(){
    MusicalInstrument** instruments=new MusicalInstrument*[3];
    instruments[0]=new Guitar();
    instruments[1]=new Harp();
    instruments[2]=new HarpGuitar();
    
    if(instruments[0]->getNumOfStrings()!=6)
        cout<<"wrong implementation of Guitar (-3)"<<endl;
    if(instruments[1]->getNumOfStrings()!=256)
        cout<<"wrong implementation of Harp (-3)"<<endl;
    if(instruments[2]->getNumOfStrings()!=12)
        cout<<"wrong implementation of HarpGuitar (-4)"<<endl;
    

    if(countType<Guitar>(instruments,3)!=1)
        cout<<"wrong implementation of countType (-5)"<<endl;
    if(countTypesOf<Guitar>(instruments,3)!=2)
        cout<<"wrong implementation of countTypesOf (-5)"<<endl;
    
    ofstream out("database.db");
    saveInstruments(out,instruments,3);
    out.close();
    
    ifstream in("database.db");
    int size2;
    MusicalInstrument** instruments2;
    loadInstruments(in,instruments2,size2);
    in.close();
    
    if(size2!=3)
        cout<<"wrong number of loaded items (-15)"<<endl;
    else {
        for(int i=0;i<size2;i++)
            if(instruments2[i]->getNumOfStrings()!=instruments[i]->getNumOfStrings())
                cout<<"loaded item does not equal to saved item (-5)"<<endl;
    }

    for(int i=0;i<3;i++){
        delete instruments[i];
        delete instruments2[i];
    }
        
    delete[] instruments;
    delete[] instruments2;
    // no segmentation faults...
}

int sum;

class Action1:public Delegate{
    public:
    virtual void operator()(){
        sum+=5;
    };
};

class Action2:public Delegate{
    public:
    virtual void operator()(){
        sum+=10;
    };
};

void test3(){
    sum=0;
    Event e;
    Action1* a1=new Action1();
    Action2* a2=new Action2();
    e+=a1;
    e();
    if(sum!=5)
      cout<<"not executing an action (-10)"<<endl;
    sum=0;
    e+=a2;
    e();
    if(sum!=15)
      cout<<"not executing two actions (-10)"<<endl;
    e+=a1;
    sum=0;
    e();
    if(sum!=20)
      cout<<"not executing three actions (-15)"<<endl;
        

    delete a1;
    delete a2;
}


int main(){
	test1();
	test2();
	test3();
	cout << "done" << endl;
	return 0;
}