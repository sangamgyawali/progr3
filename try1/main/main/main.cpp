/*
Student Name: Sangam Gyawali
Student NetID: sg2126
Compiler Used: Microsoft Visual Studio
Program Description:
This program accepts a file from the user and executes the fuctions mentioned in the file to insert/remove/find/create in order to create a binary search tree.
the tree contents can be searched and modified by the user.
*/
#include "pch.h"
#include <iostream>
#include "bst.h"
#include<istream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include <vector>
void allFunctions(string input1, string input2, string input3, string input4, string input5, vector<bst> &container);
int main()
{
	bst binSrch1;
	vector <bst> container;
	string input1, input2, input3, input4, input5;
	/*binSrch1.name = "clos";
	Node *root = NULL;
	std::string arr[10] = { "ahey","kdnfjsdnc","csdnjndc","lcsdjnc","encjnc","csdnjndc","mndcn","hsndcsnc","ihbf ","jijfjn" };
	for (int i = 0; i < 10; i++) {
		binSrch1.Insert(arr[i], 6);
		if (i == 3)
			binSrch1.del(arr[i]);
		//if (i == 5)
		//	binSrch1.del(arr[i]);
	}
	binSrch1.inDisplay();
	cout << endl;
	binSrch1.postDisplay();
	cout << endl;
	binSrch1.preDisplay();*/

	// upon the create command
	// check your list to see if the name exists already .. if it does then fail
	// otherwise create an instance of the BST with the given name
	//    bst x;
	//    x.name = name;
	// the push it into the container
	//    container.push_back(x);
	string   str;
	
	do {
		cout << "enter the command: ";
		getline(cin, str);
		stringstream ss(str);
		getline(ss, input1, ' ');
		getline(ss, input2, ' ');
		getline(ss, input3, ' ');
		getline(ss, input4, ' ');
		getline(ss, input5, ' ');

		if (input1 == "load") {
			string fileName = input2;
			fstream inFile;
			inFile.open(fileName);

			if (!inFile.is_open()) {
				cout << "File not found \n";
				break;
			}
			else {
				
				
				cout << "file " << input2 << " loaded.\n";
				while (getline(inFile, str)) {
					stringstream ss(str);
					getline(ss, input1, ' ');
					getline(ss, input2, ' ');
					getline(ss, input3, ' ');
					getline(ss, input4, ' ');
					getline(ss, input5, ' ');
					//cout << input1<<"  " << input2<< " " << input3 <<" "<< input4 <<" "<< input5 << endl<<endl;
					allFunctions(input1, input2, input3, input4, input5, container);
					cout << endl;
				}
			}
			inFile.close();
		}
		else {
			
			allFunctions(input1, input2, input3, input4, input5, container);
		}
	} while (input1 != "exit");
}


void allFunctions(string input1, string input2, string input3, string input4, string input5, vector<bst> &container)
{
	if (input1 == "display" && (input3 == "in" || input3 == "pre" || input3 == "post")) {                         // PRE POST IN Order Dispaly
		bst cont;
		int cnt = 0;
		for (int i = 0; i < container.size(); i++)
		{
			if (input2 == container[i].name) {
				cnt++;
				cont = container[i];
			}
		}
		if (cnt == 0) { cout << "closet " << input2 << " not found\n"; }
		else {
			cout << endl;
			if (input3 == "in") {
				cout << cont.name<<" Inordered BST:  \n";
				cont.inDisplay();
			}
			if (input3 == "pre")
			{
				cout <<cont.name<< " preordered BST:  \n";
				cont.preDisplay();
			}
			if (input3 == "post")
			{
				cout << cont.name <<" postordered BST:  \n";
				cont.postDisplay();
			}
		}
	}

	else if (input1 == "create")															//create Closet
	{
		int clos = 0;
		for (int i = 0; i < container.size(); i++)
		{
			if (input2 == container[i].name)
			{
				clos++;
			}
		}
		if (clos == 0) {
			bst closet1;
			closet1.name = input2;
			try {
				container.push_back(closet1);
				cout << input2 << " Closet Created\n";
			}
			catch (...)
			{
				cout << "failed to create a container named " << input2 << endl;
			}
		}
		else
			cout << input2 << " is already a closet \n";
	}
	else if (input1 == "destroy")                                                           //Delete closet
	{
		for (int i = 0; i < container.size(); i++)
		{
			if (input2 == container[i].name)
			{
				container.erase(container.begin() + i);
				cout << input2 << "  destroyed!!\n";
			}
			else
				cout << " closet not found\n";
		}
	}
	else if (input1 == "remove" && input3 == "from") {                                              // Remove item from closet
		int clos = 0;
		int cnt = 0;
		for (int i = 0; i < container.size(); i++)
		{
			if (input4 == container[i].name)
			{
				clos++;
				if (container[i].name ==input4)
				{
					container[i].del(input2);
					cnt++;
				}
			}

		}
		if (clos == 0) { cout << input4 << " not found\n"; }
		else if (cnt == 0) { cout << input2 << " not found\n"; }
		else { cout << input2 << " removed from " << input4 << endl; }
	}
	else if (input1 == "remove") {                                                                 // remove item from all closet
		int cnt = 0;
		for (int i = 0; i < container.size(); i++)
		{
				container[i].del(input2);
				cnt++;
		}
		if (cnt == 0)
			cout << input2 << " not found!!! \n";
		else
			cout << input2 << " removed\n";
	}
	else if (input1 == "find") {																		// find item and count in all closet
		int cnt = 0;
		for (int i = 0; i < container.size(); i++) {
			if (container[i].data() == input2) {
				cout << "there are " << container[i].count() << " of " << input2 << "in" << container[i].name;
				cnt = container[i].count() + cnt;
			}
		}
		if (cnt == 0)
			cout << input2 << " not found";
		else
      	cout << "total number of " << input2 << " is: " << cnt << endl;
	}
	else if (input1 == "find" && input3 == "in") {                                                                // find item and count in specific closet
		int cnt = 0;
		for (int i = 0; i < container.size(); i++) {
			if (container[i].name == input4) {
				if (container[i].data() == input2) {
					cout << "there are " << container[i].count() << " of " << input2 << " in " << container[i].name << endl;
					cnt = container[i].count() + cnt;
				}
			}
		}
		if (cnt == 0)
			cout << input2 << " not found\n";
		else
			cout << "total number of " << input2 << " is: " << cnt << endl;
	}
	else if (input1 == "insert" && input4 == "into")                                                       // insert item into specific closet
	{
	    int index;
		int clos = 0;
		for (int i = 0; i < container.size(); i++) {
			if (container[i].name == input5) {
				cout << "innserted: "<<input2 <<" into " << container[i].name << endl;
				clos++;
				index = i;
			}
		}
			if (clos == 0) { cout << input5 << " closet not found\n"; }
			else
				try {
				container[index].Insert(input2, stoi(input3));
			}
			catch (...)
			{
			};
	}
	else
	cout << "command unidentified\n";
}