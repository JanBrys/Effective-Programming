#include "CTable.h"

CTable::CTable()
{
	i_length = NSIntegers::const_i_default_table_len;
	vSetName(NSStrings::const_s_default_name);
	pi_table = new int[NSIntegers::const_i_default_table_len];	//pi_table allocated
	vPrintUsage(NSStrings::const_s_default_constructor);

}//CTable::CTable()

CTable::CTable(string sName, int iTableLen)
{
	i_length = iTableLen;
	vSetName(sName);
	pi_table = new int[iTableLen]; //pi_table allocated
	vPrintUsage(NSStrings::const_s_parametrized_constructor);

}//CTable::CTable(string sName, int iTableLen)

CTable::CTable(CTable& pcOther)
{	
	i_length = pcOther.i_length;
	pi_table = new int[i_length]; //pi_table allocated
	vSetName(pcOther.s_name + NSStrings::const_s_copied_name_extension);
	vCopyTable(*pcOther.pi_table); 
	vPrintUsage(NSStrings::const_s_copy_constructor);

}//CTable::CTable(CTable& pcOther)

CTable::~CTable()
{
	delete pi_table;
	vPrintUsage(NSStrings::const_s_destructor);

}//CTable::~CTable()

void CTable::vSetName(string sName)
{
	s_name = sName;
}//void CTable::vSetName(string sName)

bool CTable::bSetNewSize(int iTableLen)
{
	if (!pi_table)
	{
		return false;
	}
	else
	{
		//int value = iTableLen - i_length;
		int* pi_temp_table = new int[i_length]; //allocated pi_temp_table
		memcpy(pi_temp_table, pi_table, i_length*4);
		delete[] pi_table;
		pi_table = NULL;
		i_length =iTableLen;
		pi_table = new int[i_length];
		memcpy(pi_table, pi_temp_table, i_length*4);
		delete[] pi_temp_table; //deallocating pi_temp_table
		
		/*if (value > 0)
		{
			vFillPartOfTable(value, i_length);
		}*/
		return true;

	}

}//bool CTable::bSetNewSize(int iTableLen)

CTable* CTable::pcClone()
{
	return new CTable(*this);

}//CTable* CTable::pcClone()

void CTable::vPrintUsage(string s_usage)
{
	cout << "\"" << s_usage << " " << "`" << s_name << "`\"" << endl;

}//void CTable::vPrintUsage(string s_usage)

void CTable::vCopyTable(int& i_table)
{
	memcpy(pi_table, &i_table, i_length*sizeof(pi_table));

}//void CTable::vCopyTable(int** i_table)

void CTable::vAlreadyUsedMemory()
{
	cout << endl << "Memory is already used!" << endl;
}//void CTable::vAlreadyUsedMemory()


int CTable::iGetSize()
{
	return i_length;
}//int CTable::iGetSize()

void CTable::vFillPartOfTable(int iStartIndex,int iLastIndex)
{
	for (int ii = iStartIndex; ii < iLastIndex+1; ii++)
	{
		pi_table[ii] = ii;
	}
}//void CTable::vFillPartOfTable(int iStartIndex,int iLastIndex)

void CTable::vFillDefault()
{
	for (int ii = 0; ii < i_length; ii++)
	{
		pi_table[ii] = 0;
	}
}//void CTable::vFillDefault()

void CTable::vShowTable()
{
	for (int ii = 0; ii < i_length; ii++)
	{
		cout << pi_table[ii] << " ";
	}
	cout << endl;
}//void CTable::vShowTable()

