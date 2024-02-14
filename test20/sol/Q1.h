
#ifndef SRC_Q1_H_
#define SRC_Q1_H_

#include "snl.h"

class SnakesNladders2: public SnakesNladders{


public:


	// implement
	void addGlue(int index, int stickness){
		if(data[index]==0){
			data[index]= -stickness;
		}
	}

	// implement
	class iterator{
		int glued;
		SnakesNladders2* snd;
		SnakesNladders::iterator it;
	public:
		iterator(SnakesNladders2* snd):it(snd){
			this->snd=snd;
			glued=0;
		}

		int operator*(){
			return *it;
		}

		void operator++(){
			if(snd->data[*it]<0 && glued< -snd->data[*it]){
				glued++;
			}else{
				glued=0;
				++it;
			}
		}
	};

	// implement
	iterator getIterator(){
		return iterator(this);
	}

	
};



#endif /* SRC_Q1_H_ */
