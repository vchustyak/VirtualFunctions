#pragma once
#include "abstractrepository.h"
class FileRepository :
	public AbstractRepository
{
	private:
		BaseBill** pBills;
		int length;
		int count;
		int GetElementIndex(BaseBill* pBill);
public:
	FileRepository(void);
	FileRepository(int length);
	FileRepository(BaseBill* pBill);
	~FileRepository(void);
	BaseBill** Bills() override;
	BaseBill* GetBillByNumber(std::string number) override;
	void AddBill(const BaseBill& pBill)  override;
	void UpdateBill(std::string number, const BaseBill& pBill) override;
	void DeleteBill(std::string number) override;
	void SaveBills() override;
};

