#include "CTable.h"

void v_mod_tab(CTable cTab, int iNewSize);
void v_mod_tab(CTable* pcTab, int iNewSize);

int main()
{
	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	for (int ii = 0; ii < 6; ii++)
	{
		c_tab_0.vSetValueAt(ii, ii + 1);
	}
	for (int ii = 0; ii < 4; ii++)
	{
		c_tab_1.vSetValueAt(ii, 50 + ii + 1);
	}
	cout << endl << "Tables before using = operator" << endl;
	c_tab_0.vShowTable();
	c_tab_1.vShowTable();
	//c_tab_0 = c_tab_1; IT WORKS
	cout << endl << "Tables after using = operator" << endl;
	c_tab_0.vShowTable();
	c_tab_1.vShowTable();
	c_tab_1.vSetValueAt(2, 123);
	cout << endl << "Tables after using c_tab_1.vSetValueAt(2, 123) " << endl;
	c_tab_0.vShowTable();
	c_tab_1.vShowTable();
	cout << endl << "Concatenation of 2 tables" << endl;
	//CTable c_tab_3 = c_tab_0 + c_tab_1; IT DOESNT WORK AT ALL (NO SUITABLE COPY CONSTRUCTOR)
	CTable c_tab_3;
	c_tab_3 = c_tab_0 + c_tab_1;
	c_tab_3.vShowTable();

}


void v_mod_tab(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);
	cout << "Table inside void v_mod_tab(CTable cTab) after changed 1st element: " << endl;
	cTab.vShowTable();
}//void v_mod_tab(CTable cTab)
void v_mod_tab(CTable* pcTab, int iNewSize)
{
	pcTab->bSetNewSize(iNewSize);
}//void v_mod_tab(CTable* pcTab)

/*
	Line 31 makes c_tab_0 being the same like c_tab_1 (same adress, so when the program ends it wants to use same destructor twice and delete 1 pointer 2 times. But something strange is happening. dunno why.
	When i delete constructor program works but there is a fatal error (MEMORY LEAK OFC).

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0.vShowTable();
	c_tab_1.vShowTable();
	c_tab_0 = c_tab_1;
	c_tab_0.vShowTable();
	c_tab_1.vShowTable();

*/