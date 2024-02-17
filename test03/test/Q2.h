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
        out.write(id, 2);
    }
    void save(ofstream& out){
        out.write((char*)&numOfStrings, 4);
        saveMe(out);
    }
    
    void load(ifstream& in){
        in.read((char*)&numOfStrings, 4);
        loadMe(in);
    }
    
    void virtual saveMe(ofstream& out)=0;
    void virtual loadMe(ifstream& in)=0;
    
    virtual ~MusicalInstrument(){}
};

class Guitar : virtual public MusicalInstrument{
    double highestPitch;
    public:
    Guitar() : MusicalInstrument(6)
    {
        id[0] = 'G';
        id[1] = 'u';
        highestPitch = 329.63;
    }
   
    void virtual saveMe(ofstream& out){
        out.write((char *)&highestPitch,sizeof(double));
    }
    
    void virtual loadMe(ifstream& in){
        in.read((char*)&highestPitch, sizeof(double));
    }
    
};

class Harp: virtual public MusicalInstrument{
    bool deep;
    public:
    Harp() : MusicalInstrument(256)
    {
        id[0] = 'h';
        deep = true;
    }

    void virtual saveMe(ofstream& out){
        out.write((char*)&deep, sizeof(deep));
    }
    
    void virtual loadMe(ifstream& in){
        in.read((char*)&deep, sizeof(deep));
    }
    
};

class HarpGuitar: public Guitar, public Harp{
    public:
    HarpGuitar(): MusicalInstrument(12), Guitar(), Harp() 
    {
        id[0] = 'x';
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

template<typename T>
int countType(MusicalInstrument** array,int size){
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (typeid(*array[i]) == typeid(T))
        {
            sum++;
        }
    }
    return sum;
}

template<typename T>
int countTypesOf(MusicalInstrument** array,int size){
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        T* converted = dynamic_cast<T*>(array[i]);
        if (converted)
        {
            sum++;
        }
    }
    return sum;
}

void saveInstruments(ofstream& out, MusicalInstrument** array,int size){
    out.write((char*)&size, sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        array[i]->saveType(out);
        array[i]->save(out);
    }
}


void loadInstruments(ifstream& in,MusicalInstrument** &array, int & size){
    in.read((char*)&size, sizeof(size));
    array = new MusicalInstrument*[size];
    char id[2];
    for (size_t i = 0; i < size; i++)
    {
        in.read(id, 2);
        switch (id[0])
        {
        case 'h':
            array[i] = new Harp();
            break;
        case 'G':
            array[i] = new Guitar();
            break;
        case 'x':
            array[i] = new HarpGuitar();
            break;
        default:
            break;
        }
        array[i]->load(in);
    }
}


