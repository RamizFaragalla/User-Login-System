//Lab 6 | Ramiz Faragalla

#include<iostream>
#include<string>
#include"UserInfo.h"
#include<fstream>
#include"BST.h"
using namespace std;

int main()
{
	ifstream inFile;			
	inFile.open("input.txt");	//opening file
	BST<UserInfo> tree;			//creating the tree

	//fill up the tree from the input file
	UserInfo temp;
	inFile >> temp;
	while (!inFile.eof())
	{
		tree.insert(temp);
		inFile >> temp;
	} 

	//user input to check if usernames and passwords are valid
	//0 0 means to stop taking in values
	cout << "Enter the usernames and passwords separated by a space.\nEnter 0 0 to stop.\n\n";

	UserInfo other;
	cin >> temp;
	while (temp.userName != "0")
	{

		if (tree.search(temp, other))				//if item is found, other will be changed since it's passed by reference
		{
			if (other.password == temp.password)	//check if password is correct
				cout << "Username and password are correct!\n\n";

			else
				cout << "Ivalid password.\n\n";
		}

		else										//username is incorrect
			cout << "Invalid username.\n\n";

		cin >> temp;
	}
	cout << endl;

	tree.inorder(cout);		//print the three in alphabetical order

	cout << endl;
	inFile.close();			//close the file
	system("PAUSE");
	return 0;
}