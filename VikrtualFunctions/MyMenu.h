#pragma once
#include<string>
class MyMenu
{
private:
	std::string menuItems[7];
	int length;
public:
	MyMenu(void);
	void ShowMenu();
	int ChoiseItem();
	~MyMenu(void);
};

