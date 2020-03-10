#pragma once
#include "BaseBill.h"
#include<cstring>
class AbstractRepository
{
public:
	virtual BaseBill** Bills()=0;
	virtual BaseBill* GetBillByNumber(std::string number)=0;
	virtual void AddBill(const BaseBill& bill)=0;
	virtual void UpdateBill(std::string oldNumber,
		const BaseBill& bill)=0;
	virtual void DeleteBill(std::string number)=0;
	virtual void SaveBills()=0;
};

