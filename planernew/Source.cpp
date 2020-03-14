#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{
	int siz2 = 0;
	bool a = true;

	int siz = 0;
	Event *event = new Event[siz]; //масив для подій
	string *category = new string[siz2]; //масив для категорій
	int menu;
	do
	{
		SetColor(White, Black);
		cout << " \t Menu" << endl;
		cout << " 1 - Event list" << endl;
		cout << " 2 - Add 1 event" << endl;
		cout << " 3 - Show all available categories" << endl;
		cout << " 4 - Putput of events by category " << endl;
		cout << " 5 - Sort the event by importance:  1 - from 3 to 1;  "
			 << "2 - from 1 to 3" << endl;
		cout << " 7 - exit" << endl;
		cin >> menu;
		CLEAR
		switch (menu)
		{
		case 1:
		{
			cout << "Event list:" << endl;
			EventList(event, siz);
		}
		break;
		case 2:
		{
			cout << "Add event" << endl;
			int value = 1;
			EventAdd(category, event, siz, value, siz2, a);

			siz++;
		}
		break;
		case 3:
		{
			cout << "Show all category:" << endl;
			CategoryList(category, siz2);
		}
		break;
		case 4:
		{
			cout << "Output of events by category " << endl;
			eventsByCategory(category, event, siz, siz2);
		}
		break;
		case 5:
		{
			cout << "Sort the event by importance:  1 - from 3 to 1;  "
				 <<"2 - from 1 to 3" << endl;
			int count;
			cin >> count;
			sortEvents(count, event, siz);
		}
		break;
		case 7:
			break;
		default:
			break;
		}
	} while (menu != 7);

	delete[]event;
	delete[]category;
	system("pause");
	return 0;
}

