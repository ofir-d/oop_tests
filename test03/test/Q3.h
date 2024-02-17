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
    list<Delegate*> delegates;
public:
    Event() {}
    const Event& operator+=(Delegate *del)
    {
        delegates.push_back(del);
        return *this;
    }
    const Event& operator()()
    {
        for (auto i = delegates.begin(); i != delegates.end(); i++)
        {
            (**i)();
        }
        return *this;
    }
};



