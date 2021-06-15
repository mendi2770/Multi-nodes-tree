/*
Shimon Dyskin && Mendi Ben-Ezra 
Course Name: Data Structures 2
Exercise 1
Description: Forums of discussions and responses based on trees and lists
(This is the treeList.cpp file)
*/

#include "treeList.h"

treeList::~treeList() // deallocate tree
{
	clearAllTrees();
}

void treeList::clearAllTrees()    //clear all of the trees
{
	while (!tList.empty())			//as long there is still a tree in the list
	{
		Tree* temp = tList.front(); //		take the first tree
		temp->clear();				// clear the sub tree
		tList.pop_front(); // pop destroys the pointers
	}
}

void treeList::clearOneTree(Tree::Node* rootCurrent)  //delete one tree
{
	for (list<Tree*>::iterator it = tList.begin(); it != tList.end(); it++)	//loop itarator the tree to delete
	{
		if ((*it)->root == rootCurrent)			//if we found the tree
		{
			(*it)->clear();						//call the function clear to delete the all tree
			return;
		}
	}
}

void treeList::addNewTree(string val) {			//add a new tree
	Tree* t = new Tree(val);					//allocate place for the new tree
	tList.push_back(t);							//place the tree in the list
}

bool treeList::addResponse(string title, string father, string son)			//add a new respone 
{
	for (list<Tree*>::iterator it = tList.begin(); it != tList.end(); it++)
	{
		if ((*it)->root->getContent() == title)		//if the tree we wnat to responed on is found
		{
			return (*it)->addResp(father, son);		//call the function add resp for adding the new respon
		}
	}
	return false; // Reached the end of the list of trees without finding the title
}

bool treeList::delResponse(string title, string val) {		//delete respon
	bool flag = (title == val);
	for (list<Tree*>::iterator it = tList.begin(); it != tList.end(); it++)
	{
		if ((*it)->root->getContent() == title)
		{
			if (flag) // If found the title and it equals the value to delete
			{
				(*it)->delSubTree(title); // Delets the subtree
				tList.erase(it); // Erases the tree from the list
				return true;
			}
			else // If the title isn't the value to delete
			{
				return (*it)->delSubTree(val);
			}
		}
	}
	return false; // Reached the end of the list of trees without finding the title
}

void treeList::printAllTrees()			//print all tree
{
	int i = 1;							//variable to check the level of the tree(for the 3 indention)
	for (list<Tree*>::reverse_iterator it = tList.rbegin(); it != tList.rend(); it++, i++)
	{
		cout << "Tree #" << i << endl;			//the indention
		(*it)->print((*it)->root);				//call function print ro print the current tree
		cout << endl;
	}
}

void treeList::printOneTree(string title)		//function for print a single tree
{
	for (list<Tree*>::iterator it = tList.begin(); it != tList.end(); it++)
	{
		if ((*it)->root->getContent() == title)		//in case we found the tree for printing
		{
			(*it)->print((*it)->root);				//call function print ro print the current tree
			return;
		}
	}
}

void treeList::printSubTree(string title, string val)		//printing sub tree
{
	for (list<Tree*>::iterator it = tList.begin(); it != tList.end(); it++)
	{
		if ((*it)->root->getContent() == title)			//in case we found the tree 
		{
			Tree::Node* temp = (*it)->find(val);		//finding the node we want to print from
			if (temp != NULL)
			{
				(*it)->printFromNode(val);			//print from this node
				(*it)->printToNode(val);			//print the track to the node
				cout << endl;
			}
		}
	}
}

bool treeList::searchAndPrint(string val)			//search and print
{
	bool flag = false;				//in case we didn't found the tree
	for (list<Tree*>::reverse_iterator it = tList.rbegin(); it != tList.rend(); it++)
	{
		Tree::Node* temp = (*it)->find(val);		//in case we found the tree
		if (temp != NULL)
		{
			(*it)->printFromNode(val);
			(*it)->printToNode(val);
			cout << endl;
			flag = true;						//returning true because we found the tree 
		}
	}
	return flag;
}
