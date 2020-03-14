#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Header.h"

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void CoutEvent(Event *event, int i)
{
	cout << event[i].category << "\t" <<
		event[i].title << "\t" <<
		event[i].description << "\t" <<
		event[i].day << "\t" <<
		event[i].hour << "\t" <<
		event[i].level_of_importance << endl;

}

void EventList(Event *event, int siz)
{
	for (int i = 0; i < siz; i++)
	{
		if (event[i].level_of_importance == 1)
		{
			SetColor(Green, Black);
			CoutEvent(event, i);
		}
		if (event[i].level_of_importance == 2)
		{
			SetColor(Magenta, Black);
			CoutEvent(event, i);
		}
		if (event[i].level_of_importance == 3)
		{
			SetColor(Red, Black);
			CoutEvent(event, i);
		}
	}
	SetColor(White, Black);
	PAUSE
	CLEAR
}

void EventAdd(string *&category, Event *&event, int siz, int value, int &siz2, bool &a)
{
	Event *newevent = new Event[siz + value];
	string *newcategory = new string[siz2 + value];
	for (int i = 0; i < siz; i++)
	{
		newevent[i].category = event[i].category;
		if (i < siz2)
		{
			newcategory[i] = category[i];
		}
		newevent[i].title = event[i].title;
		newevent[i].description = event[i].description;
		newevent[i].day = event[i].day;
		newevent[i].hour = event[i].hour;
		newevent[i].level_of_importance = event[i].level_of_importance;
	}
	cout << "Enter Enter category" << endl;
	cin.ignore();
	getline(cin, newevent[siz].category);
	a = true;
	for (int i = 0; i < siz2; i++)
	{
		if (newevent[siz].category != newcategory[i])
		{
			continue;
		}
		else
		{
			a = false;
			break;
		}
	}
	if (a == true)
	{
		siz2++;
	}
	int b = siz2 - 1;
	if (a != false)
	{
		newcategory[b] = newevent[siz].category;
	}

	cout << "Enter title" << endl;
	getline(cin, newevent[siz].title);
	cout << "Enter description" << endl;
	getline(cin, newevent[siz].description);
	cout << "Enter day" << endl;
	cin >> newevent[siz].day;
	cout << "Enter hour" << endl;
	cin >> newevent[siz].hour;
	cout << "Enter level of importance (1 - 3)" << endl;
	cin >> newevent[siz].level_of_importance;
	delete[]event;
	delete[]category;
	category = newcategory;
	event = newevent;
	SetColor(White, Black);
	PAUSE
	CLEAR
}

void CategoryList(string *category, int &siz2)
{
	for (int i = 0; i < siz2; i++)
	{
		cout << category[i] << endl;
	}
	SetColor(White, Black);
	PAUSE
	CLEAR
}

void eventsByCategory(string *category, Event *event, int siz, int &siz2)
{
	cout << "Category: \t";
	for (int i = 0; i < siz2; i++)
	{
		cout << category[i] << "\t";
	}
	cout << endl;
	cout << "Enter the category you want to display events for" << endl;
	string count;
	cin.ignore();
	getline(cin, count);
	for (int i = 0; i < siz; i++)
	{
		if (event[i].category == count)
		{
			if (event[i].level_of_importance == 1)
			{
				SetColor(Green, Black);
				CoutEvent(event, i);
			}
			if (event[i].level_of_importance == 2)
			{
				SetColor(Magenta, Black);
				CoutEvent(event, i);
			}
			if (event[i].level_of_importance == 3)
			{
				SetColor(Red, Black);
				CoutEvent(event, i);
				/*cout << event[i].category << "\t" <<
					event[i].title << "\t" <<
					event[i].description << "\t" <<
					event[i].day << "\t" <<
					event[i].hour << "\t" <<
					event[i].level_of_importance << endl;*/
			}
		}
	}
	SetColor(White, Black);
	PAUSE
	CLEAR
}

void sortEvents(int count, Event *event, int siz)
{
	if (count == 1)
	{
		cout << "Sort the event by importance: from 3 to 1" << endl;
		for (int i = 0; i < siz; i++)
		{
			if (event[i].level_of_importance == 3)
			{
				SetColor(Red, Black);
				CoutEvent(event, i);
			}
		}
		for (int i = 0; i < siz; i++)
		{
			if (event[i].level_of_importance == 2)
			{
				SetColor(Magenta, Black);
				CoutEvent(event, i);
			}
		}
		for (int i = 0; i < siz; i++)
		{
			if (event[i].level_of_importance == 1)
			{
				SetColor(Green, Black);
				CoutEvent(event, i);
			}
		}
		SetColor(White, Black);
		PAUSE
		CLEAR
	}
	else if (count == 2)
	{
		cout << "Sort the event by importance: from 1 to 3" << endl;
		for (int i = 0; i < siz; i++)
		{
			if (event[i].level_of_importance == 1)
			{
				SetColor(Green, Black);
				CoutEvent(event, i);
			}
		}
		for (int i = 0; i < siz; i++)
		{
			if (event[i].level_of_importance == 2)
			{
				SetColor(Magenta, Black);
				CoutEvent(event, i);
			}
		}
		for (int i = 0; i < siz; i++)
		{
			if (event[i].level_of_importance == 3)
			{
				SetColor(Red, Black);
				CoutEvent(event, i);
			}
		}
		SetColor(White, Black);
		PAUSE
		CLEAR
	}
}
