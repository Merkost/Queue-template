#pragma once
#include<iostream>
using namespace std;

class Tourist
{
private:
	string first_name, second_name, third_name, country;
	short day;
public:
	Tourist();
	Tourist(string f, string s, string t, string c, short d);
	string getf() { return first_name; }
	string gets() { return second_name; }
	string gett() { return third_name; }
	string getc() { return country; }
	short getd() { return day; }


};
