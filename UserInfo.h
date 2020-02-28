#include<string>
#include<fstream>
#include<iostream>
using namespace std;

#ifndef UserInfo_h
#define UserInfo_h

class UserInfo
{
public:
	string userName;
	string password;
	
	friend bool operator<(const UserInfo &, const UserInfo &);		//overloads <
	friend bool operator==(const UserInfo &, const UserInfo &);		//overloads ==
	friend istream& operator >>(istream &, UserInfo &);				//overloads istream
	friend ostream& operator <<(ostream &, UserInfo &);				//overloads ostream
};

//only the usernames of the objects are compared. The tree is sorted by usernames, not passwords.
bool operator<(const UserInfo & one, const UserInfo & two)
{
	return one.userName < two.userName;
}

//like the <, only the usernames are compared
bool operator==(const UserInfo & one, const UserInfo & two)
{
	return one.userName == two.userName;
}

//input the members of the class
istream& operator >>(istream & input, UserInfo & x)
{
	input >> x.userName >> x.password;
	return input;
}

//output the members of the class separated by a space
ostream& operator <<(ostream & output, UserInfo & x)
{
	output << x.userName << '\t' << x.password << endl;
	return output;
}

#endif
