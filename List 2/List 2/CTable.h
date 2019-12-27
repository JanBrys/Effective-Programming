#pragma once
#include "Constants.h"


class CTable
{
public:
	string s_name;
	int* pi_table = NULL;
	int i_length = 0;

	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();

	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

	void vPrintUsage(string s_usage);
	void vCopyTable(int& i_table);
	void vAlreadyUsedMemory();

	int iGetSize();

	void vFillPartOfTable(int iStartIndex,int iLastIndex);

	void vFillDefault();

	void vShowTable();


};

