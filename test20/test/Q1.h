
#ifndef SRC_Q1_H_
#define SRC_Q1_H_

#include "snl.h"

class SnakesNladders2: public SnakesNladders{
	int glue[100];

public:

	SnakesNladders2() {
		for (int i = 0; i < 100; i++)
			glue[i] = 0;
	}

	void addGlue(int tile, int glue_strenght) {
		if (tile < 0 || tile >= 100)
			return;
		if (data[tile] != 0)
			return;

		glue[tile] = glue_strenght;
	}
	class iterator {
		int index;
		SnakesNladders2* snl;
	public:
		iterator(SnakesNladders2* snl) {
			index = 0;
			this->snl = snl;
		}

		int operator*() {
			return index;
		}

		void operator++() {
			if (snl->glue[index] == 0)
			{
				if (index < 99)
					index++;
				while (snl->data[index] > 0) {
					index = snl->data[index];
				}
			}
			else
			{
				snl->glue[index]--;
			}
		}
	};

	iterator getIterator() {
		return iterator(this);
	}
	
};



#endif /* SRC_Q1_H_ */
