// VikrtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BaseBill.h"
#include "AdvansedBill.h"


int _tmain(int argc, _TCHAR* argv[])
{
	BaseBill bill(1000
		, std::string("1234 3456 1234 56768"));

	bill.DecreaseBalanse(500);
	bill.DecreaseBalanse(600);
	return 0;
}

