// VikrtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BaseBill.h"
#include "AdvansedBill.h"


int _tmain(int argc, _TCHAR* argv[])
{
	AdvansedBill bill("3456 1234 7890 3456", 1000, 500);
	BaseBill* pBill = &bill;
	pBill->DecreaseBalanse(500);
	pBill->DecreaseBalanse(600);
	return 0;
}

