#include "CTable.h"

void v_mod_tab(CTable cTab, int iNewSize);
void v_mod_tab(CTable* pcTab, int iNewSize);

int main()
{
	cout << "Welcome in a program! Full run thorugh the program is scripted. Enjoy!" << endl << endl;
	cout << endl << "order of showing tables: 1 - default 2 - parametrized 3 - copy 4 - pointer" << endl;

	cout << "Initalizing of default static constructor." << endl;
	CTable def;
	cout <<endl << "Initalizing of parametrized static constructor." << endl;
	CTable param("parametrized", 10);
	cout << endl << "Initalizing of copy static constructor. Parametrized constructor will be copied  " << endl;
	CTable copy(param);
	cout << endl << "Setting up size of param constructor to 15 (was 10)" << endl;
	param.bSetNewSize(15);
	cout << endl << "Filling all tables (0 in all indexes)" << endl;
	def.vFillDefault();
	param.vFillDefault();
	copy.vFillDefault();
	
	cout << endl << "Showing all tables." << endl;
	def.vShowTable();
	param.vShowTable();
	copy.vShowTable();
	cout << endl << "Filling part of param table (first 5 indexes; values will be set as offset)" << endl;
	param.vFillPartOfTable(0,5);
	cout << endl << "Showing all tables " << endl;
	def.vShowTable();
	param.vShowTable();
	copy.vShowTable();
	cout << "Initalizing of default dynamic constructor." << endl;
	CTable* point;
	cout << endl << "point constructor = param.pcClone()" << endl;
	point = param.pcClone();
	cout << endl << "Showing all tables " << endl;
	def.vShowTable();
	param.vShowTable();
	copy.vShowTable();
	point->vShowTable();
	cout << endl << "Setting up size of point constructor to 20(was param's)" << endl;
 	point->bSetNewSize(20);

	cout << endl << "Showing all tables " << endl;
	def.vShowTable();
	param.vShowTable();
	copy.vShowTable();
	point->vShowTable();
	cout << endl << "Getting size of  point destructor" << endl;
	cout << point->iGetSize() << endl;
	cout << endl << "Let the games begin. I want to change table size to 2. first of all default table then working of void v_mod_tab(CTable cTab, int iNewSize) and showing table again " << endl << endl;
	def.vShowTable();
	v_mod_tab(def,2);
	def.vShowTable();
	cout << endl << "Nice. Next step -  I want to change table size to 2. first of all default table then working of void v_mod_tab(CTable* cTab, int iNewSize) and showing table again " << endl << endl;
	def.vShowTable();
	v_mod_tab(&def,2);
	def.vShowTable();
	cout << endl << "Program came to the end. Now destructors take their jobs (in order):" << endl;
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