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
	virtual bool DecreaseBalanse(int balanse);
	std::string GetNumber() const{return number;};
	int GetBalanse() const {return balanse;}
	void SetNumber(std::string number){this->number=number;};
	void SetBalanse(int balanse){this->balanse=balanse;};
};

