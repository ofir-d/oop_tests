

#ifndef SRC_TREE_H_
#define SRC_TREE_H_

#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Tree {
	int id;
	vector<Tree*> children;
public:
	int getID(){ return id;}
	Tree(int id):id(id){};
	virtual ~Tree(){ // free the tree and all subtrees
		for_each(children.begin(),children.end(),[](Tree* t){delete t;});
	}
	// implement in cpp file
	void operator+=(int id); // add a tree with root id to the children

	class iterator{
		/*******************************************/
		// you may add data members here
		// HINT: you need a stack
		stack<Tree*> treeStack2;
		Tree* head;
		Tree* current;
		Tree* father;
		int level;
		/*******************************************/
	public:
		// implement the following methods in the cpp file
		
		iterator(Tree* tree);
		Tree& operator*(); // returns the current T the iterator points at
		void up(int steps); // goes up the tree number of steps
		void down(); // goes down one step and points to the first child
		void operator++(); // goes to the next child
		void operator--(); // goes to the previous child
		void UpdateCreateStack(Tree* tr);
		void UpdateStack();
	};

	iterator getIterator(){
		return iterator(this);
	}
};

#endif /* SRC_TREE_H_ */
