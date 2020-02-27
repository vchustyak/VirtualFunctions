#include "StdAfx.h"
#include "AdvansedBill.h"

AdvansedBill::AdvansedBill(void)
{
	suma=0;
}

AdvansedBill::AdvansedBill(std::string number, 
	int balanse, int suma):BaseBill(balanse,number)
{
	this->suma=suma;
};

