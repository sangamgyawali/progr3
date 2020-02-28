#include "pch.h"
#include "bst.h"
#include <iostream>
#include<istream>
#include<string>
#include<fstream>
#include<sstream>
#include <map>
#include<algorithm>

using namespace std;

bst::bst() //constructor
{
	

}

//insert function
bool bst::Insert(Node*& root, string data, int count)
{ 
	if (!root)
	{
		root = new Node();
		root->data = data;
		root->count_item;
		return true;
	}
	if (data > root->data)
	{
		return Insert(root->right, data, count);
	}
	if (data < root->data)
	{
		return Insert(root->left, data,count);
	}
	root->count_item += count;
		return false;
	
}


bool bst::del(Node*& root, string data) {
	if (root == NULL)
		return false;
	else if (data < root->data)
		return del(root->left, data);
	else if (data > root->data)
		return del(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			return true;
		}

		else if (root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			root = temp;
			return true;

		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			delete temp;
			root = temp;
			return true;
		}
		else
		{// need the source citation here
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->count_item = temp->count_item;
			return del(root ->right, temp->data);
		}
	}
	return true;



}

Node * bst::FindMin(Node * root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}


void bst::inDisplay(Node*& root)
{
	if (!root)
		return;
	inDisplay(root->left);
	cout << root->data << endl;
	inDisplay(root->right);
}

void bst::postDisplay(Node*& root)
{
	
	if (root == NULL)
		return;

	postDisplay(root->left);
	postDisplay(root->right);
	cout << root->data << endl;
}
void bst::preDisplay( Node*& root)
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

bool bst::found(Node*& root, string data)
{
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
	{
		root = root->left;
		return found(root, data);
	}
	else
	{
		root = root->right;
		return found(root, data);
	}
}

