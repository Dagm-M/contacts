#ifndef CONTACTS_H_INCLUDED
#define CONTACTS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


struct person
{
	string name;
	string number;
};


char menu();
char viewAll();
char addNew(person);
char edit(person);
char remove();
char search();

#endif