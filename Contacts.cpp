#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Contacts.h"

using namespace std;


char menu()
{
	char choise; 

	cout << endl << string(25, '=') << endl;

	cout << "WELCOME TO YOU'R CONTACTS" << endl;

	cout << string(25, '=') << endl << endl;

	cout << "Press 'A' to View all contacts" << endl;

	cout << "Press 'B' to Add a new contact" << endl;

	cout << "Press 'C' to Change(Edit) a contact" << endl;

	cout << "Press 'D' to Delete a contact" << endl;

	cout << "Press 'S' to Search for a contact" << endl;

	cout << "Press 'E' to Exit" << endl << endl;

	do
	{
		cout << "Enter your choice: " ;
		cin >> choise;
		choise = toupper(choise);
	}while(choise != 'A' && choise != 'B' && choise != 'C' && choise != 'D'
			&& choise != 'S' && choise != 'E');
	system("CLS");

	return choise;
}






char viewAll()
{
	string temp;

	ifstream fin;

	fin.open("contacts.txt");

	if(!fin)
	{
		ofstream fout;
		fout.open("contacts.txt");
		fout.close();
		fin.open("contacts.txt");
	}

	if(!fin)
	{
		cout << "Error opening the file" << endl;
		exit(1);
	}

	while (!fin.eof())
	{
		getline(fin, temp);
		cout << temp << endl;
	}
	fin.close();
	cout << "Press 'R' to go back to the main menu: ";
	char back;
	cin >> back;
	back = toupper(back);
	system("CLS");

	return back;

}





char addNew(person people)
{
	fstream fout("contacts.txt", ios::app);
	

	cout << "Enter the name : ";
	cin >> people.name;
	cout << "Enter the phone : ";
	cin >> people.number;

	fout << "Name : " << people.name << endl;
	fout << "phone number : " << people.number << endl;

	cout << "Add successful" << endl;
	fout.close();

	cout << "Press 'R' to go back to the main menu: ";
	char back;
	cin >> back;
	back = toupper(back);
	system("CLS");

	return back;

}


char edit(person people)
{
	string find;
	string line;

	cout << "Enter the name to be updated : ";
  cin >> find;
  find = "Name : " + find; // when searching to add the name
  cout << "Enter the new name : ";
  cin >> people.name;
  cout << "Enter the phone number : ";
  cin >> people.number;




    ifstream fin; //for reading records
    fin.open("contacts.txt");

    ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line))
    {
      if (line != find )
        temp << line << endl;
      else
      {
      	getline(fin, line); // to skip the next line
      	temp << "Name : " << people.name << endl;
      	temp <<"phone number : " << people.number << endl;

      }
    }

   
    fin.close();
    temp.close();

    remove("contacts.txt");

    rename("temp.txt", "contacts.txt");

    cout << "Press 'R' to go back to the main menu: ";
	char back;
	cin >> back;
	back = toupper(back);
	system("CLS");

	return back;
}




char remove()
{
	string find;
	string line;

	cout << "Enter the name to be deleted : ";
  cin >> find;
  find = "Name : " + find; // when searching to add the name


  ifstream fin; //for reading records
    fin.open("contacts.txt");

    ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line))
    {
      if (line != find )
        temp << line << endl;
      else
      {
      	getline(fin, line); // to skip the next line
	    }
		}

		fin.close();
    temp.close();

    remove("contacts.txt");

    rename("temp.txt", "contacts.txt");

    cout << "Press 'R' to go back to the main menu: ";
	char back;
	cin >> back;
	back = toupper(back);
	system("CLS");

	return back;  
}




char search()
{
	string name, line ;
	bool notfoud = true;
	cout << "Enter the name you want to search : ";
	cin >> name;
	name = "Name : " + name;

	ifstream fin;
	fin.open("contacts.txt");

	if (!fin)
	{
		cout << "The file is empty" << endl;
	}


	while (!fin.eof())
	{
		getline(fin , line);
		if (name == line )
		{
			cout << name << endl;
			getline(fin , line);
			cout << line << endl;
			notfoud = false;
		}
	}

	if (notfoud)
		cout << "The name could not be found check the spelling and capitalization" << endl;

	 cout << "Press 'R' to go back to the main menu: ";
	char back;
	cin >> back;
	back = toupper(back);
	system("CLS");

	return back;

}