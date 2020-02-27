#pragma once
#include<string>
class BaseBill
{
protected:
	int balanse;
	std::string number;
public:
	BaseBill(void);
	BaseBill(int balanse,std::string number);
	void AddBalanse(int balanse);
	bool DecreaseBalanse(int balanse);
	
};

