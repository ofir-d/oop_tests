
#ifndef SRC_SNL_H_
#define SRC_SNL_H_


class SnakesNladders{
protected:
	int data[100];

public:

	SnakesNladders(){
		for(int i=0;i<100;i++)
			data[i]=0;
	}

	void addLadder(int from, int to){
		if(from>=0 && from<to && to<100){
			data[from]=to;
		}
	}
	void addSnake(int from, int to){
		if(from<100 && from>to && to>=0){
			data[from]=to;
		}
	}

	class iterator{
		int index;
		SnakesNladders* snd;
	public:
		iterator(SnakesNladders* snd){
			index=0;
			this->snd=snd;
		}

		int operator*(){
			return index;
		}

		void operator++(){
			if(index<99)
				index++;
			while(snd->data[index]>0){
				index=snd->data[index];
			}
		}
	};

	iterator getIterator(){
		return iterator(this);
	}

};



#endif /* SRC_SNL_H_ */
