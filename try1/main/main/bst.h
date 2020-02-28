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
	int count_item=0;
};
class bst
	
{
private:
	Node* root;
	bool Insert(Node*& root, std::string data, int count);
	bool found(Node*& root, std::string data);
	bool del(Node*& root, std::string data);
	Node* FindMin(Node* root);
	//bst(Node * root, std::string data);
	void inDisplay(Node*& root);
	void preDisplay(Node*& root);
	void postDisplay(Node*& root);
public:
	string name;
	int count_item;
	bst();
	bool Insert(std::string data, int count) { return Insert(root, data, count); }
	bool found(std::string data) { return found(root, data); }
	bool del( std::string data){ return del(root, data); }
	void inDisplay() { inDisplay(root); }
	void preDisplay() { preDisplay(root); }
	void postDisplay() { postDisplay(root); }
	void allFunctions(string input1, string input2, int input3, string input4, string input5);	
};