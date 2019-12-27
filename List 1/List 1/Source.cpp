#include "Headers.h"

const int i_value_added_to_offset = 5;

void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int ***pi2DimTable,int iSizeX,int iSizeY);
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX);

bool b_fill_2_dim_table(int*** pi2DimTable, int iSizeX, int iSizeY);
bool b_show_2_dim_table(int*** pi2DimTable, int iSizeX, int iSizeY);
bool b_positive_number(int number);
void v_wrong_parameters_warning();
void v_deleted_pointer_warning();
void v_alloc_2_dim_warning();
void v_success();

int main()
{	
	bool run = true;
	int** pi_2_dim_table = NULL;
	int choice = -1;
	int dim_1_size = -1;
	int dim_2_x_size = -1;
	int dim_2_y_size = -1;

	while (run)
	{
		cout << endl << "Welcome! What you want to do?: " << endl;
		cout << "1. Allocate,show and deallocate 1 dimensional table" << endl;
		cout << "2. Allocate 2 dimensional table" << endl;
		cout << "3. Deallocate 2 dimensional table" << endl;
		cout << "4. Fill 2 dimensional table with offset+5 for every row" << endl;
		cout << "5. Show 2 dimensional table" << endl;
		cout << "0. Exit program" << endl;

		cin >> choice;
		
		switch (choice)
		{
			case 1:
			{
				cout << "What size should table has?: ";
				cin >> dim_1_size;
				v_alloc_table_add_5(dim_1_size);
				v_success();
			}break;

			case 2:
			{
				cout << "What X size should table has?: ";
				cin >> dim_2_x_size;
				cout << "What Y size should table has?: ";
				cin >> dim_2_y_size;
				if (!b_alloc_table_2_dim(&pi_2_dim_table, dim_2_x_size, dim_2_y_size))
				{
					v_alloc_2_dim_warning();
				}
				else
				{
					v_success();
				}
			}break;

			case 3:
			{
				if (!b_dealloc_table_2_dim(&pi_2_dim_table, dim_2_x_size))
				{
					v_deleted_pointer_warning();
				}
				else
				{
					v_success();
				}
			}break;

			case 4:
			{
				if (!b_fill_2_dim_table(&pi_2_dim_table, dim_2_x_size, dim_2_y_size))
				{
					v_deleted_pointer_warning();
				}
				else
				{
					v_success();
				}
			}break;

			case 5:
			{
				if (!b_show_2_dim_table(&pi_2_dim_table, dim_2_x_size, dim_2_y_size))
				{
					v_deleted_pointer_warning();
				}
				else
				{
					v_success();
				}
			}break;

			case 0:
			{
				run = false;
			}break;

			default:
			{
				cout << "Wrong option has been used! try again!";
			}break;
		}
	}
}//int main()


void v_alloc_table_add_5(int iSize)
{
	if (b_positive_number(iSize))
	{
		int* pi_table = new int[iSize];	//pointer in v_alloc_table_add_5
		for (int ii = 0; ii < iSize; ii++)
		{
			pi_table[ii] = ii + i_value_added_to_offset;
		}
		for(int ii = 0; ii < iSize; ii++)
		{
			cout << pi_table[ii] << " ";
		}
		cout << endl;
		delete[] pi_table;	//deleting pointer in v_alloc_table_add_5
	}
	else
	{
		v_wrong_parameters_warning();
	}
}//void v_alloc_table_add_5(int iSize)

bool b_alloc_table_2_dim(int*** pi2DimTable, int iSizeX, int iSizeY)
{
	if (b_positive_number(iSizeX) && b_positive_number(iSizeY) && !*pi2DimTable)
	{
		*pi2DimTable = new int*[iSizeX]; //pointer in b_alloc_table_2_dim //pointers in b_alloc_table_2_dim
		for (int ii = 0; ii < iSizeX; ii++)
		{
			(*pi2DimTable)[ii] = new int[iSizeY];
		}
		return true;
	}
	else
	{
		return false;
	}

}//bool b_alloc_table_2_dim

bool b_dealloc_table_2_dim(int*** pi2DimTable, int iSizeX)
{
	if (!*pi2DimTable)
	{
		return false;
	}
	else
	{
		for (int ii = 0; ii < iSizeX; ii++)
		{
			delete (*pi2DimTable)[ii];
		}
		delete *pi2DimTable;
		*pi2DimTable = NULL;
	}

}//bool b_dealloc_table_2_dim(int*** piTable, int iSizeX)


bool b_fill_2_dim_table(int*** pi2DimTable, int iSizeX, int iSizeY)
{
	if (*pi2DimTable)
	{
		for (int ii = 0; ii < iSizeX; ii++)
		{
			for (int ii2 = 0; ii2 < iSizeY; ii2++)
			{
				(*pi2DimTable)[ii][ii2] = ii + i_value_added_to_offset;
			}
		}
		return true;
	}
	return false;

}//void v_fill_2_dim_table

bool b_show_2_dim_table(int*** pi2DimTable, int iSizeX, int iSizeY)
{
	if (*pi2DimTable)
	{
		for (int ii = 0; ii < iSizeX; ii++)
		{
			for (int ii2 = 0; ii2 < iSizeY; ii2++)
			{
				cout << (*pi2DimTable)[ii][ii2] << " ";
			}
			cout << endl;
		}
		return true;
	}
	return false;
}// void v_show_2_dim_table(int*** pi2DimTable, int iSizeX, int iSizeY)



bool b_positive_number(int number)
{
	return 0 < number;
}//bool b_positive_number(int number)


void v_wrong_parameters_warning()
{
	cout << endl << "Wrong parameter/parameters. Function will skip its mechanics!" << endl;
}//void v_wrong_parameters_warning()

void v_deleted_pointer_warning()
{
	cout << endl << "Pointer is deleted. Function will not make its mechanics!" << endl;
}//void v_deleted_pointer_warning()

void v_alloc_2_dim_warning()
{
	cout << endl << "Wrong parameters or pointer is already used." << endl;
}//void v_alloc_2_dim_warning()

void v_success()
{
	cout << endl << "Function made its job correctly!" << endl;
}//void v_alloc_2_dim_warning()