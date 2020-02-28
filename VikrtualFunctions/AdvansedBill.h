#pragma once
#include "basebill.h"
#include<iostream>
class AdvansedBill :
	public BaseBill
{
protected:
	int suma;
public:
	AdvansedBill(void);
	AdvansedBill(std::string number, int balanse,
		int suma);
	bool DecreaseBalanse(int balanse) override
	{
		std::cout<<"AdvansedBill::DecreaseBalanse\n";
		if (balanse>this->balanse+suma)
		{
			std::cout<<"You don't have enough money\n";
			return false;
		}
		if (balanse>this->balanse)
		{
			std::cout<<"You borg is "<<
				balanse-this->balanse<<"\n";
			return true;
		}
		return BaseBill::DecreaseBalanse(balanse);
	}
	
};

