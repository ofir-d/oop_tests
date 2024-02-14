#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

// F2F is a type for a function pointer
// that takes a float as an argument, and returns a float
typedef float(*F2F)(float);

class SpreadSheet{

    float data[5][5];
    vector<const char*> inputCells;    
    vector<const char*> outputCells;    
    vector<F2F> functions;

    public:
    SpreadSheet(){
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++){
                data[i][j]=0;
            }
    }

    void set(const char* cell,float val){
        int i=cell[0]-'A';
        int j=cell[1]-'1';
        data[i][j]=val;

        for(int k=0;k<inputCells.size();k++){
            if(strcmp(inputCells[k],cell)==0){
                applyFunc(cell,functions[k],outputCells[k]);                
                break;
            }
        }

    }

    float get(const char* cell){
        int i=cell[0]-'A';
        int j=cell[1]-'1';
        return data[i][j];
    }
    
    void applyFunc(const char* inputCell,F2F f, const char* outputCell){
        set(outputCell,f(get(inputCell)));
    }

    // a generic posible solution
    // template<class func>
    // void applyFunc(const char* inputCell,func f, const char* outputCell){
    //     set(outputCell,f(get(inputCell)));
    // }
    
    void onChange(const char* inputCell,F2F f, const char* outputCell){
        inputCells.push_back(inputCell);
        functions.push_back(f);
        outputCells.push_back(outputCell);
    }


};


#endif /* SRC_Q2_H_ */