#include "StdAfx.h"
#include "FileRepository.h"
#include<exception>
#include<iostream>
#include<fstream>

FileRepository::FileRepository(void)
{
	pBills=NULL;
	length=0;
	count=0;
}

FileRepository::FileRepository(int length)
{
	pBills=new BaseBill*[length];
	this->count=0;
	this->length=length;
}

FileRepository::FileRepository(BaseBill* pBill)
{
	pBills=new BaseBill*[10];
	pBills[0]=new BaseBill(pBill->GetBalanse(),pBill->GetNumber());
	this->count=1;
	this->length=10;
}

FileRepository::~FileRepository(void)
{
	if (pBills!=NULL)
		for (int i=0;i<count;i++)
			delete pBills[i];
	delete [] pBills;
}

BaseBill** FileRepository::Bills() 
{
	if (pBills!=NULL)
		return pBills;
	std::ifstream fInput("bills.txt");
	if (!fInput.is_open())
		return NULL;
	std::string buff;
	std::string delimiter=": ";
	count=length=0;
	while(getline(fInput,buff))
	{
		std::size_t index=buff.find(delimiter);
		char strBalanse[50];
		buff.copy(strBalanse,buff.length()-index-2,index+2);
		int balanse=atoi(strBalanse);
		
		char number[20];
		buff.copy(number,index,0);
		BaseBill bill(balanse,std::string(number));
		AddBill(bill);
	}
}

BaseBill* FileRepository::GetBillByNumber(std::string number)
{
	if (count==0)
		return NULL;
	for (int i=0;i<count;i++)
		if (pBills[i]->GetNumber()==number)
			return pBills[i];
	return NULL;
}

void FileRepository::AddBill(const BaseBill& pBill)
{
	if (count<length)
	{
		if (pBills[count-1]!=NULL)
			throw new char*("Error in adding element\n");
		pBills[count-1]=new BaseBill(pBill.GetBalanse(), pBill.GetNumber());
		count++;
		return;
	}
	BaseBill** pTmpBills=pBills;
	pBills=new BaseBill*[2*length+1];
	for (int i=0;i<count;i++)
	{
		pBills[i]=new BaseBill(pTmpBills[i]->GetBalanse(),pTmpBills[i]->GetNumber());
	}
	pBills[count]=new BaseBill(pBill.GetBalanse(), pBill.GetNumber());
	count++;
}

void FileRepository::UpdateBill(std::string oldNumber, const BaseBill& pNewBill)
{
	BaseBill* pBill=GetBillByNumber(oldNumber);
	if (pBill!=NULL)
	{	
		pBill->SetNumber(pNewBill.GetNumber());
		pBill->SetBalanse(pNewBill.GetBalanse());
	}
}

void FileRepository::DeleteBill(std::string number)
{
	BaseBill* pBill=GetBillByNumber(number);
	if (pBill==NULL)
		return;
	int index=GetElementIndex(pBill);
	delete pBill;
	for (int i=index;i<count-1;i++)
		pBills[i]=pBills[i+1];
	delete pBills[count-1];
	count--;
}

int FileRepository::GetElementIndex(BaseBill* pBill)
{
	for (int i=0;i<count;i++)
		if (pBills[i]->GetNumber()==pBill->GetNumber())
			return i;
	return -1;
}

void FileRepository::SaveBills() 
{
	std::ofstream fOutput("bills.txt");
	if (!fOutput.is_open())
		throw new const char*("Error inf writing file");
	for (int i=0;i<count;i++)
	{
		fOutput<<pBills[i]->GetNumber()<<": "<<pBills[i]->GetBalanse()<<"\n";
	}
}