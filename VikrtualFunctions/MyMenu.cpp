#include "StdAfx.h"
#include "MyMenu.h"
#include<iostream>

MyMenu::MyMenu(void)
{
	menuItems[0]=std::string("1. Show items\n");
	menuItems[1]=std::string("2. Add item\n");
	menuItems[2]=std::string("3. Update item\n");
	menuItems[3]=std::string("4. Delete item\n");
	menuItems[4]=std::string("5. Save items\n");
	menuItems[5]=std::string("6. Find item\n");
	menuItems[6]=std::string("7. Exit\n");
	length=7;
}

void MyMenu::ShowMenu()
{
	system("cls");
	for (int i=0;i<length;i++)
		std::cout<<menuItems[i];
}

int MyMenu::ChoiseItem()
{
	int choise;
	std::cout<<"Enter your choise\n";
	std::cin>>choise;
	while(choise<1 || choise>length)
	{
		std::cout<<"You choise must be in range 1..7\n";
		std::cin>>choise;
	}
	return choise;
}

MyMenu::~MyMenu(void)
{
}
