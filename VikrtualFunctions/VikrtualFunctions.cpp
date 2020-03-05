// VikrtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BaseBill.h"
#include "AdvansedBill.h"
#include "MyMenu.h"
#include "AbstractRepository.h"
#include "FileRepository.h"

void ShowItems(const AbstractRepository* repository);
void AddItem(AbstractRepository* repository, BaseBill& bill); 
void UpdateItem(AbstractRepository* repository, BaseBill& oldBill,
	BaseBill newBill);
void DeleteItem(AbstractRepository* repository, BaseBill& bill);
void SaveItems(AbstractRepository* repository);
BaseBill* FindItem(AbstractRepository* repository, BaseBill& bill);

int _tmain(int argc, _TCHAR* argv[])
{
	MyMenu menu;
	AbstractRepository* pRepository=new FileRepository();
	bool isSaved=true;
	int choise;
	do
	{
		menu.ShowMenu();
		choise=menu.ChoiseItem();
		switch(choise)
		{
		case 1:
			ShowItems(pRepository);
		break;
		case 2:
			std::string number;
			int balanse;
			std::cout<<"Enter bill number\n";
			getline(std::cin,number);
			std::cout<<"Enter bill balanse\n";
			std::cin>>balanse;
			BaseBill bill(balanse,number);
			AddItem(pRepository,bill);
			isSaved=false;
		break;
		case 3:
			std::string number;
			std::cout<<"Enter search number";
			getline(std::cin,number);

			int balanse;
			std::cout<<"Enter bill balanse\n";
			std::cin>>balanse;

			BaseBill oldBill(0,number);
			BaseBill newBill(balanse,number);
			UpdateItem(pRepository,oldBill,newBill);
			isSaved=false;
		break;
		case 4:
			std::string number;
			std::cout<<"enter deleted bill number\n";
			getline(std::cin,number);
			BaseBill bill(0,number);
			DeleteItem(pRepository,bill);
			isSaved=false;
		break;
		case 5:
			SaveItems(pRepository);
			isSaved=true;
		break;
		case 6:
			std::cout<<"Enter search number\n";
			std::string number;
			getline(std::cin,number);
			BaseBill bill(0,number);
			BaseBill* pSearchedBill=FindItem(pRepository,bill);
			if (pSearchedBill!=NULL)
				std::cout<<"Number "<<pSearchedBill->GetNumber()<<
				" balanse "<<pSearchedBill->GetNumber()<<"\n";
			else
				std::cout<<"Bill with number "<<number<<"is not exists\n";
		break;
		case 7:
			if (!isSaved)
				SaveItems(pRepository);
			if (pRepository!=NULL)
				delete pRepository;
		break;
	}
	while(choise==7);
	return 0;
}

