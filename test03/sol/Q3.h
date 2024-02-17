#include <iostream>
#include <list>

using namespace std;


class Delegate{
    public:
    virtual void operator()(){
        cout<<"default implementation"<<endl;
    };
    virtual ~Delegate(){}
};

class Event{
    list<Delegate*> actions;
    public:
    
    Event& operator+=(Delegate* d){
        actions.push_back(d);
        return *this;
    }
    
    void operator()(){
         list<Delegate*>::iterator it=actions.begin();
         while(it!=actions.end()){
             Delegate* d=*it;
             (*d)();
             it++;
         }
    }
};

