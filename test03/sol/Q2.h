#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

class MusicalInstrument{
    int numOfStrings;
    protected:
    char id[2];
    public:
    MusicalInstrument(int num):numOfStrings(num){}
    int getNumOfStrings(){ return numOfStrings;}
    
    void saveType(ofstream& out){
        out.write(id,2);
    }
    void save(ofstream& out){
        out.write((char*)&numOfStrings,sizeof(numOfStrings));
        saveMe(out);
    }
    
    void load(ifstream& in){
        in.read((char*)&numOfStrings,sizeof(numOfStrings));
        loadMe(in);
    }
    
    void virtual saveMe(ofstream& out)=0;
    void virtual loadMe(ifstream& in)=0;
    
    virtual ~MusicalInstrument(){}
};

class Guitar: public virtual MusicalInstrument{
    double highestPitch;
    public:
    Guitar():MusicalInstrument(6){
        id[0]='G';
        id[1]='u';
        highestPitch=329.63;
    }
    
    void virtual saveMe(ofstream& out){
        out.write((char*)&highestPitch,sizeof(highestPitch));
    }
    
    void virtual loadMe(ifstream& in){
        in.read((char*)&highestPitch,sizeof(highestPitch));
    }
    
};

class Harp: public virtual MusicalInstrument{
    bool deep;
    public:
    Harp():MusicalInstrument(256){
        id[0]='H';
        id[1]='a';
        deep=true;
    }
    
    void virtual saveMe(ofstream& out){
        out.write((char*)&deep,sizeof(deep));
    }
    
    void virtual loadMe(ifstream& in){
        in.read((char*)&deep,sizeof(deep));
    }
    
};

class HarpGuitar: public Guitar, public Harp{
    public:
    HarpGuitar():MusicalInstrument(12){
        id[0]='H';
        id[1]='g';
    }
    
    void virtual saveMe(ofstream& out){
       Guitar::saveMe(out);
       Harp::saveMe(out);
    }
    void virtual loadMe(ifstream& in){
       Guitar::loadMe(in);
       Harp::loadMe(in);
    }
    
};

template<class T>
int countType(MusicalInstrument** array,int size){
    int count=0;
    for(int i=0;i<size;i++)
        if(typeid(*array[i])==typeid(T))
            count++;
    return count;
}

template<class T>
int countTypesOf(MusicalInstrument** array,int size){
    int count=0;
    for(int i=0;i<size;i++){
        T* t=dynamic_cast<T*>(array[i]);
        if(t) count++;
    }
    return count;
}

void saveInstruments(ofstream& out, MusicalInstrument** array,int size){
    out.write((char*)&size,sizeof(size));
    for(int i=0;i<size;i++){
        array[i]->saveType(out);
        array[i]->save(out);
    }
}

void loadInstruments(ifstream& in,MusicalInstrument** & array, int & size){
    in.read((char*)&size,sizeof(size));
    array=new MusicalInstrument*[size];
    char id[2];
    for(int i=0;i<size;i++){
        in.read(id,2);
        if(id[0]=='G' && id[1]=='u')
            array[i]=new Guitar();
        if(id[0]=='H' && id[1]=='a')
            array[i]=new Harp();
        if(id[0]=='H' && id[1]=='g')
            array[i]=new HarpGuitar();
            
        array[i]->load(in);
    }
}


