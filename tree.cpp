/*
Shimon Dyskin && Mendi Ben-Ezra 
Course Name: Data Structures 2
Exercise 1
Description: Forums of discussions and responses based on trees and lists
(This is the tree.cpp file)
*/

#include "tree.h"

// Delete routine: //

void Tree::clear()
{
	if (!root->responses.empty()) // If there are any responses call to the clear by list method with the responses parameter
		clearByList(root->responses);
	delete root; // After deleting the responses we need to deallocate the root
}

void Tree::clearByList(list<Node*> &resp) 
{
	while (!resp.empty()) //  While there are responses
	{
		if (!resp.front()->responses.empty())
			clearByList(resp.front()->responses); // If the front organ has responses, check them by recurssion
		Node* temp = resp.front(); // Store the pointer to the first organ
		resp.pop_front(); // else, or after deleting the responses (returning from the recurssion), delete the organ
		delete temp; // Delete the allocated object
	}
}

// Print node routine:
void Tree::print(Node* nd)
{
	if (nd != NULL) // If there is a node
	{
		cout << nd->getContent() << endl;	  // Print the node content
		if (!nd->responses.empty())			  // If the node has any responses call to the print by list method with the responses parameter and the level needed for the indentation
			printByList(nd->responses, 1);	  // At first the level sent is 1  
	}
}

void Tree::printByList(list<Node*> &resp, int level) 
{
	for (list<Node*>::iterator itNode = resp.begin(); itNode != resp.end(); itNode++) // The iterator will run through the list
	{
		for (int i = 0; i < level; i++)					// The indentation proccess (based on the level information)
			cout << "   ";
		cout << (*itNode)->getContent() << endl;		// Print node's content
		if (!((*itNode)->responses.empty()))			// If there are responses to the node call the print by list function with the responses list, increasing the level by 1
			printByList((*itNode)->responses, level + 1); 
	}
}

// Find node routine: //
Tree::Node* Tree::find(string title)
{
	if (title == root->content)					// If the title we are searching for is in the root - return the root
		return root;
	if (!(root->responses.empty()))				// Else, if the root has responses - call the find by list function to search the title there, and return the node if found (or NULL)
		return findByList(root->responses, title);
	return NULL;								// If reached here, it means didn't find, so return NULL
}

Tree::Node* Tree::findByList(list<Node*> &resp, string title)
{
	for (list<Node*>::iterator itNode = resp.begin(); itNode != resp.end(); itNode++) // The iterator will run through the list
	{
		if (title == (*itNode)->content)							// If found, return the node* pointer
			return *itNode;
		if (!((*itNode)->responses.empty()))						// Else, if the node has responses
		{
			Node* temp = findByList((*itNode)->responses, title);	// Call the find by list function
			if (temp != NULL)										// If isn't NULL, return the node found
				return temp;
		}
	}
	return NULL; // Return NULL if search to the end of the list of nodes and didn't fins
}

// Add response method:
bool Tree::addResp(string father, string son)
{
	Node* ptr = find(father);				// The father being found by the find function
	if (ptr == NULL)						// If didn't find, return false
		return false;
	Node* newResp = new Node(son);			// Else, allocate memory for the new node
	ptr->responses.push_back(newResp);		// And push back the new response to the list of father's responses
	return true;							// And finally return true
}

// Delete sub tree routine:
bool Tree::delSubTree(string title)
{
	if (title == root->getContent())					 // It the root is the one we search to delete
	{
		clearByList(root->responses);					// Clear the responses
		delete root;									// Delete the allocated tree
		return true;									// 'Success'
	}
	else if (!(root->responses.empty()))				// Else, if the root isn't the title to delete, check if there are responses
		return delSubTreeByList(root->responses, title); // Check to delete in the responses
	return false;										// to print 'ERROR'
}

bool Tree::delSubTreeByList(list<Node*> &resp, string title)
{
	for (list<Node*>::iterator itNode = resp.begin(); itNode != resp.end(); itNode++)	// Run through the list
	{
		if ((*itNode)->content == title) // If the title to delete found
		{
			clearByList((*itNode)->responses);											// Clear the responses of the deleted node
			resp.erase(itNode);															// Erase the pointer to the node frome the list (calls the destructor)
			return true;
		}
		else if (!(*itNode)->responses.empty() && delSubTreeByList((*itNode)->responses, title)) // Else, if the node has sons, check if the title to delete is there
			return true;																// If found (and deleted with the sub tree), return true
	}
	return false; // In case didn't find the title
}

// Print to node routine. This method uses queue to store the route //
void Tree::printToNode(string title)
{
	if (root->getContent() == title) // If we found the title to delete
	{
		return;	// No need to print it
	}
	if (!root->responses.empty()) // Else, if there are responses
	{
		if (printToNodeByList(root->responses, title)) // Call the print by responses method, if true, then print
			cout << "=>" << root->getContent() << endl; // Print the current father of the found title
	}
}

bool Tree::printToNodeByList(list<Node*> &resp, string title) 
{
	for (list<Node*>::iterator itNode = resp.begin(); itNode != resp.end(); itNode++) // Run through the list
	{
		if ((*itNode)->content == title) // If we found the title to delete
		{
			cout << (*itNode)->getContent(); // Print the content
			return true;
		}
		else if (!(*itNode)->responses.empty()) // Else, check through the responses if there are
		{
			if (printToNodeByList((*itNode)->responses, title)) // If returned from recurrsion with true, print the father
			{
				cout << "=>" << (*itNode)->getContent();
				return true; // Return true to print the father of the father
			}
			else // Else, means didn't find
				return false;
		}
	}
	return false; // In case didn't find the title
}

// Print from node (subtree) routine: //
void Tree::printFromNode(string title)
{
	Node* ptr = find(title); // Gets the node found
	print(ptr);				// Sends the node to print the sub-tree from the node
}