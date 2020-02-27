#include "StdAfx.h"
#include "BaseBill.h"
#include<iostream>

BaseBill::BaseBill(void)
{
	number="";
	balanse=0;
}

BaseBill::BaseBill(int balanse, std::string number)
{
	this->number=number;
	this->balanse=balanse;
}

void BaseBill::AddBalanse(int balanse)
{
	this->balanse+=balanse;
}
bool BaseBill::DecreaseBalanse(int balanse)
{
	std::cout<<"BaseBill::DecreaseBalanse\n";
	if (this->balanse<balanse)
	{
		std::cout<<"You don't have enough money\n";
		return false;
	}
	this->balanse-=balanse;
	std::cout<<"You have enough money\n";
}