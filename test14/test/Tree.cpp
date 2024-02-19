
#include "Tree.h"
void emptyy(stack<Tree*>& st)
{
	int size = st.size();
	for (size_t i = 0; i < size; i++)
	{
		st.pop();
	}
}
void Tree::iterator::UpdateCreateStack(Tree* tr)
{
	if (tr == nullptr)
	{
		return;
	}
	if (tr->children.size() == 0)
	{
		treeStack2.push(tr);
		return;
	}
	UpdateCreateStack(tr->children.front());
	treeStack2.push(tr);
}

Tree::iterator::iterator(Tree* tree) : level(0), current(tree), head(tree), father(nullptr)
{
	emptyy(treeStack2);
	UpdateCreateStack(tree);
}

void Tree::operator+=(int id)
{
	children.push_back(new Tree(id));
}
Tree& Tree::iterator::operator*()
{
	return *current;
}
void Tree::iterator::up(int steps)
{
	emptyy(treeStack2);
	UpdateCreateStack(head);
	int hops = level - steps;
	int newLevel = 0;
	stack<Tree*> temp;
	for (size_t i = 0; i < hops; i++)
	{
		Tree* tempo = treeStack2.top();
		temp.push(tempo);
		treeStack2.pop();
		newLevel++;
	}
	current = treeStack2.top();
	level = newLevel;
	for (size_t i = 0; i < hops; i++)
	{
		Tree* tempo = temp.top();
		treeStack2.push(tempo);
		temp.pop();
	}
}
void Tree::iterator::UpdateStack()
{
	emptyy(treeStack2);
	stack<Tree*> tempStack;
	UpdateCreateStack(current);
	int head_level = 0;
	Tree* head_iter =  head;
	for (size_t i = 0; i < level; i++)
	{
		tempStack.push(head_iter);
		head_iter = head_iter->children.front();
	}
	for (size_t i = 0; i < level; i++)
	{
		treeStack2.push(tempStack.top());
		tempStack.pop();
	}
}
void Tree::iterator::down()
{
	UpdateStack();
	vector<Tree*> childs = current->children;
	if (childs.size() != 0)
	{
		father = current;
		current = childs.front();
		level++;

	}
}

void Tree::iterator::operator++()
{
	if (!father)
	{
		return;
	}
	UpdateStack();
	Tree* current_temp = current;
	vector<Tree*>current_level = father->children;
	for (auto iter = current_level.begin(); iter != current_level.end(); iter++)
	{
		if (current_temp == *iter)
		{
			auto next = ++iter;
			if (next == current_level.end())
			{
				current = current_temp;
				break;
			}
			current = *next;
			break;
		}
	}
	UpdateStack();
}

void Tree::iterator::operator--()
{
	emptyy(treeStack2);
	UpdateCreateStack(head);
	Tree* current_temp = current;
	stack<Tree*> temp;
	for (size_t i = 0; i < level; i++)
	{
		Tree* tempo = treeStack2.top();
		temp.push(tempo);
		treeStack2.pop();
	}
	current = treeStack2.top();
	up(1);
	vector<Tree*>current_level = current->children;
	for (auto iter = current_level.begin(); iter != current_level.end(); iter++)
	{
		if (current_temp == *iter)
		{
			auto next = --iter;
			if (next == current_level.end())
			{
				current = current_temp;
				level++;
				break;
			}
			current = *next;
			level++;
			break;
		}
	}
	emptyy(treeStack2);
	UpdateCreateStack(current);
	for (size_t i = 0; i < level; i++)
	{
		Tree* tempo = temp.top();
		treeStack2.push(tempo);
		temp.pop();
	}
}
