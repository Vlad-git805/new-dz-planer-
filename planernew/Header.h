#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");

struct Event
{
	string category;
	string title;
	string description;
	string day;
	int hour;
	int level_of_importance;
};

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(int text, int background);
void CoutEvent(Event *event, int i);
void EventList(Event *event, int siz);
void EventAdd(string *&category, Event *&event, int siz, int value, int &siz2, bool &a);
void CategoryList(string *category, int &siz2);
void eventsByCategory(string *category, Event *event, int siz, int &siz2);
void sortEvents(int count, Event *event, int siz);
