#pragma once
#include "Constants.h"


class CTable
{
public:


	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable& pcOther);
	CTable(CTable& pcLeft, CTable& pcRight);
	~CTable();

	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

	void vPrintUsage(string sUsage);
	void vCopyTable(int& iTable);
	void vAlreadyUsedMemory();

	int iGetSize();

	void vFillPartOfTable(int iStartIndex, int iLastIndex);

	void vFillDefault();

	void vShowTable();

	void vSetValueAt(int iOffset, int iNewVal);

	CTable operator+(CTable& pcOther);
private:
	string s_name;
	int* pi_table = NULL;
	int i_length = 0;
};

