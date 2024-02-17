#include <iostream>
#include <list>

using namespace std;

template <class T,class comparator>
class PriorityQueue{
    list<T> queue;
    comparator comp;
    
    public:

    void push(const T& t){
        typename list<T>::iterator it=queue.begin();
        while(it!=queue.end() && comp(*it,t)<0) it++;
        queue.insert(it,t);
    }
    
    T poll(){
        T t=*queue.begin();
        queue.pop_front();
        return t;
    }
    
    template<class func>
    void forEach(func f){
        typename list<T>::iterator it=queue.begin();
        while(it!=queue.end()){
            f(*it);
            it++;  
        } 
    }
    
};


