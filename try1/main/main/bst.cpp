#include "pch.h"
#include "bst.h"
#include <iostream>
#include<istream>
#include<string>
#include <vector>
#include<fstream>
#include<sstream>
#include <map>
#include<algorithm>

using namespace std;

bst::bst() //constructor
{
	

}

//insert function
Node* bst::Insert(Node* root, string data)
{ 
	if (!root)
	{
		Node* new_node = new Node();
		new_node->data = data;
		return new_node;
	}
	if (data > root->data)
	{
		root->right = Insert(root->right, data);
	}
	else
	
		root->left = Insert(root->left, data);
		return root;
}
bool bst::found(Node* root, string data)
{
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
	{
		return found(root->left, data);
	}
	else
	{
		return found(root->right, data);
	}
}

Node* bst::del(Node* root, string data) {
	if (root == NULL)
		cout << "Emply Container \n";
	else if (data < root->data)
		del(root->left, data);
	else if (data > root->data)
		root->right = del(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}

		else if (root->left == NULL)
		{
			Node* temp = new Node();
			temp = root;
			root = root->right;
			delete temp;

		}
		else if (root->right == NULL)
		{
			Node* temp = new Node();
			temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			Node* temp = new Node();
			temp = FindMin(root->right);
			root->data = temp->data;
			root->right = del(root ->right, temp->data);
		}
	}
	return root;



}

Node * bst::FindMin(Node * root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}


void bst::inDisplay(Node* root)
{
	if (!root)
		return;
	inDisplay(root->left);
	cout << root->data << endl;
	inDisplay(root->right);
}

void bst::postDisplay(Node* root)
{
	if (root == NULL)
		return;

	postDisplay(root->left);
	postDisplay(root->right);
	cout << root->data << endl;
}
void bst::preDisplay( Node* root)
{
	if (root == NULL)
		return;

	cout << root->data << endl;

	preDisplay(root->left);
	preDisplay(root->right);
}

void bst::load() {
	int count;
	string str, input1, input2, input3, input4, input5;
	Node *root = NULL;




	// implementing functions
	while (input1 != "exit") {
		if (input1 == "load") {
			string fileName = input2;
			fstream inFile;
			inFile.open(fileName);

			if (!inFile.is_open()) {
				cout << "File not found ";
			}
			else {
				while (getline(inFile, str)) {
					stringstream ss(str);
					getline(ss, input1, ' ');
					getline(ss, input2, ' ');
					getline(ss, input3, ' ');
					getline(ss, input4, ' ');
					getline(ss, input5, ' ');
					try {
						count = stoi(input3);
					}
					catch (...) {
						cout << "count level conversion failure" << endl;
					}

					allFunctions(input1, input2, input3, input4, input5);
				}
				inFile.close();

			}
		}
		else {
			cout << "Command Unidentified, refer to the top" << endl;
		}
		recurFunc(input1, input2, input3, input4, input5);
	}
}
Node * bst::Find(Node * root, string data)
{
	if (root == NULL || root->data == data)
		return root;

	 
	if (root->data < data)
		return Find(root->right, data);

	// Key is smaller than root's key 
	return Find(root->left, data);
}

void bst::allFunctions(string input1, string input2, string input3, string input4, string input5) {
	typedef map<string, bst> bstMap;
	bstMap container;
	Node *root = NULL;
	if (input1 == "display" && input3 == "in" ) {
		cout << "\nInordered BST: \n" << endl;
		inDisplay(root);
		cout << endl;
	}
	else if (input1 == "display" && input3 == "pre") {
		cout << "\n preordered BST: \n";
			preDisplay(root);
			cout << endl;
	}
	else if (input1 == "display"  && input3 == "post")
	{
		cout << "Post ordered BST: \n";
		postDisplay(root);
		cout << endl;
	}
	else if (input1 == "create")
	{
		try {
			
			container[input2];
		}
		catch(...)
		{
			cout << "failed to create a container named " << input2 << endl;
		}
		
	}
	else if (input1 == "destroy")
	{    
		try {
			container.erase(input2);
			cout << input2 << " erased ";
		}
		catch (...)
		{
			cout << "failed!!\n";
		}
	}
	//****************To  do: Here and below**************
	else if (input1 == "find") {
		if (!found(root, input2) {
			cout << input2 << " has not been found" << endl;
		}
		else {
			cout << input2 << " Not found! " << endl;
		}
	}
	else if (input1 == "remove") {

		remove(input2);
	}
	else if (input1 == "insert") {
		if (input4 == "after") {
			insertAfter(input2, input3, input5);
		}
		else if (input4 == "before") {
			insertBefore(input2, input3, input5);
		}
		else {
			insert(input2, input3);
		}
	}
}