#include "Contacts.h"

using namespace std;





int main()
{
	char looper;

	person people;

	do
	{
		char choise = menu();

		if (choise == 'E')
			return 0;

		switch(choise)
		{
			case 'A': looper = viewAll();
				break;
			case 'B': looper = addNew(people);
				break;
			case 'C': looper = edit(people);
				break;
			case 'D': looper = remove();
				break;
			case 'S': looper = search();
			  break;
		}

	}while(looper == 'R');




	return 0;
}