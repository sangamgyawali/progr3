#pragma once
#include <string>

using namespace std;
class Node {
public:
	Node *left;
	Node *right;
	Node() {
		left= right = nullptr;
	}
	string data="";
};
class bst
	
{
	Node* root;

public:
	string name;
	bst();
	Node* Insert(Node* root, std::string data);
	bool found(Node* root, std::string data);
	Node* del(Node* root, std::string data);
	Node* FindMin(Node* root);
	//bst(Node * root, std::string data);
	void inDisplay(Node* root);
	void preDisplay(Node* root);
	void postDisplay(Node* root);
	void load();
	void allFunctions(string input1, string input2, int input3, string input4, string input5);
	Node* Find(Node* root, string data);
	
	
};

