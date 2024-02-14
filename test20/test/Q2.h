#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <vector>
#include <map>
#include <string.h>
using namespace std;

// F2F is a type for a function pointer
// that takes a float as an argument, and returns a float
typedef float(*F2F)(float);
class MyFunctionObject {
	F2F function_pointer;
	const char* destination;
public:
	MyFunctionObject() : function_pointer(nullptr), destination(nullptr){}
	MyFunctionObject(F2F func, const char* dest) : function_pointer(func), destination(dest){}
	F2F getFunc() { return function_pointer; }
	const char* getDest() { return destination; }
};

class SpreadSheet{
	
	map<char, float*> table;
	map<char, map<float, MyFunctionObject>> function_table;
public:
	SpreadSheet()
	{
		for (char col = 'A'; col <= 'E'; ++col) {
			float *x = new float[5];
			for (int i = 0; i < 5; i++)
				x[i] = 0;
			table[col] = x;
		}
	}
	~SpreadSheet()
	{
		/*for (const auto& entry : table) {
			delete[] entry.second;
		}
		table.clear();*/
	}

	void set(const char* index, float data)
	{
		table[index[0]][std::atoi(index + 1)] = data;
		const char* dest_index = function_table[index[0]][std::atoi(index + 1)].getDest();
		if (dest_index != nullptr)
		{
			set(dest_index, function_table[index[0]][std::atoi(index + 1)].getFunc()(data));
		}
	}

	float get(const char* index)
	{
		auto y = index[0];
		auto d = index[1];
		auto x = (table[index[0]])[std::atoi(index + 1)];
		return x;
	}

	void applyFunc(const char* index_src, F2F function, const char* index_out)
	{
		set(index_out, function(table[index_src[0]][std::atoi(index_src + 1)]));
	}
	void onChange(const char* index_src, F2F function, const char* index_out)
	{
		function_table[index_src[0]][std::atoi(index_src + 1)] = MyFunctionObject(function, index_out);
	}
};


#endif /* SRC_Q2_H_ */