/*
Shimon Dyskin && Mendi Ben-Ezra 
Course Name: Data Structures 2
Exercise 1
Description:  Forums of discussions and responses based on trees and lists
(This is the tree.h file)
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Tree
{
public:

	class Node
	{
	public:
		string content;
		list<Node*> responses;

		// Ctor:
		Node() : content("/0") { }
		Node(string con) : content(con) {}
		Node(string con, list<Node*> res) : content(con), responses(res) {}
		~Node() { for (list<Node*>::iterator it = responses.begin(); it != responses.end(); it++) delete* it;};
		// Getters and setters:
		string getContent() { return content; }
		void setContent(string str) { content = str; };
	};

public:
	Node* root;

	// Ctors:
	Tree() { root = NULL; } // initialize tree
	Tree(string title) { root = new Node(title);}

	// Clearing methods:
	~Tree() { delete root; root = NULL;}
	void clear();
	void clearByList(list<Node*> &resp);
	// print discussion function:
	void print(Node* root);
	void printByList(list<Node*> &resp, int level);
	// find a response function:
	Node* find(string title);
	Node* findByList(list<Node*> &resp, string title);
	// add response function:
	bool addResp(string father, string son);
	// delete sub tree function:
	bool delSubTree(string title);
	bool delSubTreeByList(list<Node*> &resp, string title);
	// print to node methods:
	void printToNode(string title);
	bool printToNodeByList(list<Node*> &resp, string title);
	// print from node function:
	void printFromNode(string title);

};

#endif
