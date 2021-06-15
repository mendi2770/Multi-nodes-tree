/*
Shimon Dyskin 310468558 && Mendi Ben-Ezra 311140933
Course Name: Data Structures 2
Exercise 1
Description: Forums of discussions and responses based on trees and lists
(This is the tree-main.cpp file)
*/

#include <iostream>
#include <list>
#include <string>
#include "treeList.h"

using namespace std;
int main()
{
	treeList tl;							//create tree of list
	string title, father, val, son;			//strings for the sobjects
	char ch;
	cout << "\nDISCUSSION TREE\n";
	cout << "Choose one of the following:" << endl;
	cout << "n: New discussion tree" << endl;
	cout << "s: Add a new response" << endl;
	cout << "d: Delete a sub-discussion" << endl;
	cout << "p: Print all discussion trees" << endl;
	cout << "r: Print a sub-tree" << endl;
	cout << "w: Search a string in all discussion trees" << endl;
	cout << "e: exit:" << endl;
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'n':		//add a new discussion (new tree)
			cout << "enter the discussion title (with no space) "; cin >> val; tl.addNewTree(val); break;
		case 's':		//Add a new response(sub tree)
			cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter the last message (with no space) "; cin >> father;
			cout << "enter the new respond "; cin >> son;
			if (tl.addResponse(title, father, son)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'd':		//Delete a sub-discussion(sub tree, or the all tree)
			cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter string of subtree to delete (with no space) "; cin >> val;
			if (tl.delResponse(title, val)) cout << "success\n"; else cout << "ERROR\n"; break;
		case 'p':		//Print all discussion trees
			tl.printAllTrees();  break;
		case 'r':		//Print a sub-tree(print from a specific node)
			cout << "enter the discussion title (with no space) "; cin >> title;
			cout << "enter the last message (with no space) "; cin >> val;
			tl.printSubTree(title, val); break;
		case 'w':	//Search a string in all discussion trees, and then print the tree and the track
			cout << "enter a string (with no space) "; cin >> val;
			if (!tl.searchAndPrint(val)) cout << "\nERROR\n" << endl;  break;
		case 'e':		//exit from the program
			cout << "bye "; break;
		default:
			cout << "ERROR\n";  break;		//in case of illegal input
		}
	} while (ch != 'e');
}

/*
DISCUSSION TREE
Choose one of the following:
n: New discussion tree
s: Add a new response
d: Delete a sub-discussion
p: Print all discussion trees
r: Print a sub-tree
w: Search a string in all discussion trees
e: exit:
n
enter the discussion title (with no space) saba
n
enter the discussion title (with no space) savta
s
enter the discussion title (with no space) saba
enter the last message (with no space) saba
enter the new respond aba
success
s
enter the discussion title (with no space) saba
enter the last message (with no space) aba
enter the new respond ben
success
n
enter the discussion title (with no space) doda
s
enter the discussion title (with no space) saba
enter the last message (with no space) saba
enter the new respond ach
success
p
Tree #1
doda

Tree #2
savta

Tree #3
saba
   aba
	  ben
   ach

s
enter the discussion title (with no space) savta
enter the last message (with no space) savta
enter the new respond bat
success
s
enter the discussion title (with no space) doda
enter the last message (with no space) doda
enter the new respond batdoda
success
p
Tree #1
doda
   batdoda

Tree #2
savta
   bat

Tree #3
saba
   aba
	  ben
   ach

w
enter a string (with no space) saba
saba
   aba
	  ben
   ach

r
enter the discussion title (with no space) saba
enter the last message (with no space) ben
ben
ben=>aba=>saba

d
enter the discussion title (with no space) doda
enter string of subtree to delete (with no space) doda
success
p
Tree #1
savta
   bat

Tree #2
saba
   aba
	  ben
   ach

e
bye
*/
