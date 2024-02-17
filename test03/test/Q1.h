#include <iostream>
#include <list>

using namespace std;

template<typename T, typename func>
class PriorityQueue{
    list<T> queue;
    func funcition;
    public:

    void push(const T& t){
        if (queue.size() == 0)
        {
            queue.insert(queue.begin(), t);
            return;
        }
        for (auto i = queue.begin(); i != queue.end(); i++)
        {
            if (funcition((*i), t) >= 0)
            {
                queue.insert(i, t);
                return;
            }
        }
    }
	
    T poll(){
        T data = *queue.begin();
        queue.pop_front();
        return data;
    }
    
    template<typename fi>
    void forEach(const fi& funci){
        for (auto i = queue.begin(); i != queue.end(); i++)
        {
            funci(*i);
        }
    }
    
};


