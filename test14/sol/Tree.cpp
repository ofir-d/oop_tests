
#include "Tree.h"

// implement
void Tree::operator+=(int id) {
	Tree* tree=new Tree(id);
	children.push_back(tree);
}


// implement here the iterator methods

Tree::iterator::iterator(Tree* tree){
	treeStack.push(tree);
	current=tree;
	child=0;
}


void Tree::iterator::up(int steps){
	for(int i=0;i<steps && treeStack.size()>1 ;i++)
		treeStack.pop();
	current=treeStack.top();
}


void Tree::iterator::down(){
	if(current->children.size()>0){
		treeStack.push(current->children[0]);
		child=0;
		current=treeStack.top();
	}
}


Tree& Tree::iterator::operator*(){
	return *current;
}


void Tree::iterator::operator++(){
	if(treeStack.size()>1){
		up(1);
		if(current->children.size()>child+1)
			treeStack.push(current->children[++child]);
		else
			treeStack.push(current->children[child]);
		current=treeStack.top();
	}
}

void Tree::iterator::operator--(){
	if(treeStack.size()>1){
		up(1);
		if(child>0)
			treeStack.push(current->children[--child]);
		current=treeStack.top();
	}
}

