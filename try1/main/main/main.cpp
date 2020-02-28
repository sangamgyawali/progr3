// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "bst.h"
#include <vector>

int main()
{
	bst binSrch1;
	vector <bst> container;
	
	
	
	string input1,  input2, input3,  input4, input5;
	binSrch1.name = "closet";
	Node *root = NULL;
	std::string arr[10] = { "ahey","kdnfjsdnc","csdnjndc","lcsdjnc","encjnc","fjscnjdnc","mndcn","hsndcsnc","ihbf ","jijfjn" };
	for (int i = 0; i < 10; i++)
	binSrch1.Insert(arr[i],6);

	binSrch1.inDisplay();
	cout << endl;
	binSrch1.postDisplay();
	cout << endl;
	binSrch1.preDisplay();

	// upon the create command
	// check your list to see if the name exists already .. if it does then fail
	// otherwise create an instance of the BST with the given name
	//    bst x;
	//    x.name = name;
	// the push it into the container
	//    container.push_back(x);
	Node *root = NULL;
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
		if (cnt == 0) { cout << "closet" << input2 << "not found"; }
		else {
			cout << endl;
			if (input3 == "in") {
				cout << "Inordered BST:  \n";
				cont.inDisplay();
			}
			if (input3 == "pre")
			{
				cout << "preordered BST:  \n";
				cont.preDisplay();
			}

			if (input3 == "post")
			{
				cout << "postordered BST:  \n";
				cont.postDisplay();
			}

		}
	}

	else if (input1 == "create")															//create Closet
	{
		/*for (int i = 0; i < cars.size(); i++)
		{
			if (searchName == cars[i].Name)
			{
				cout << cars[i]; //overloaded  operator<<}
			}*/
		bst closet1;

		closet1.name = input2;
		
		try {
			container.push_back(closet1);
		}
		catch (...)
		{
			cout << "failed to create a container named " << input2 << endl;
		}

	}
	else if (input1 == "destroy")                                                           //Delete closet
	{
		for (int i = 0; i < container.size(); i++)
		{
			if (input2 == container[i].name)
			{

				container.erase[i];
			}
			else
				cout << "closet not found";
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
				if (container[i].found(input2))
				{
					container[i].del(input2);
					cnt++;
				}
			}
			
		}
		if (clos == 0) { cout << input4 << " not found\n"; }
		if (cnt == 0) { cout << input2 << " not found\n"; }
	}
	else if (input1 == "remove") {                                                                 // remove item from all closet
		int cnt = 0;
		for (int i = 0; i < container.size(); i++)
		{
			if (container[i].found(input2))
			{
				container[i].del(input2);
				cnt++;
			}
		}
		if (cnt == 0)
			cout << input2 << " not found!!! \n";
	}
	else if (input1 == "find") {																		// find item and count in all closet
		int cnt = 0;
		for (int i = 0; i < container.size(); i++){
			
		if (container[i].found(input2)) {

			cout <<"there are"<<container[i].count_item<<" of " <<input2 << "in"<< container[i].name;
				cnt = container[i].count_item + cnt;
		}
		}
		if (cnt == 0)
			cout << input2 << " not found";
		else
			cout << "total number of " << input2 << " is: " << cnt;

	}
	else if (input1 == "find" && input3 == "in") {                                                                // find item and count in specific closet
		int cnt = 0;
		for (int i = 0; i < container.size(); i++) {

			if (container[i].name== input4){
				if (container[i].found(input2)) {

					cout << "there are" << container[i].count_item << " of " << input2 << "in" << container[i].name;
					cnt = container[i].count_item + cnt;
				}
			}
		}
		if (cnt == 0)
			cout << input2 << " not found";
		else
			cout << "total number of " << input2 << " is: " << cnt;

	}
	
	else if (input1 == "insert" && input4 == "into")                                                       // insert item into specific closet
    {
	int clos = 0;
	for (int i = 0; i < container.size(); i++) {

		if (container[i].name == input5) {
			clos++;
			container[i].Insert(input2, stoi(input3));
		}
		if (clos == 0) { cout << input5 << "closet not found\n"; }
	}
	
	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file