/*
Shimon Dyskin && Mendi Ben-Ezra 
Course Name: Data Structures 2
Exercise 1
Description: Forums of discussions and responses based on trees and lists
(This is the treeList.h file)
*/

#ifndef TREELIST_H
#define TREELIST_H

#include <iostream>
#include <list>
#include <string>
#include "tree.h"
using namespace std;

class treeList
{
private:
	list<Tree*> tList;
public:
	treeList() { } // Default ctor
	~treeList(); // Dtor
	// Clear methods:
	void clearAllTrees();
	void clearOneTree(Tree::Node* rootCurrent);
	// Add methods:
	void addNewTree(std::string val);
	bool addResponse(string title, string father, string son);
	// Delete response method:
	bool delResponse(string title, string val);
	// Different print methods:
	void printAllTrees();
	void printOneTree(string title);
	void printSubTree(string title, string val);
	bool searchAndPrint(string val);
};
#endif
