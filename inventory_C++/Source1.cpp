#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <array>
#include <cstring>
using namespace std;

//declare variables
string new_prod_name;
char prod_name_list[100][30];
static int prod_id_list[100][5] , prod_quant_list[100][5];
int new_prod_price, new_prod_id;
double prod_price_list[100][5];
int new_prod_quant;



//menu function
void menu();
void menu()
{
	int menu_num;
	cout << "\t   MMMMM     MMMMM     EEEEEEEEE  NNNNNN       NNN  UUU    UUU\n";
	cout << "\t  MMMMMMM   MMMMMMM    EEEEEEEEE  NNN NNN      NNN  UUU    UUU\n";
	cout << "\tMMM      MMM      MMM  EEE        NNN  NNN     NNN  UUU    UUU\n";
	cout << "\tMMM      MMM      MMM  EEEEEEEEE  NNN   NNN    NNN  UUU    UUU\n";
	cout << "\tMMM      MMM      MMM  EEEEEEEEE  NNN    NNN   NNN  UUU    UUU\n";
	cout << "\tMMM      MMM      MMM  EEE        NNN     NNN  NNN  UUU    UUU\n";
	cout << "\tMMM      MMM      MMM  EEEEEEEEE  NNN      NNN NNN  UUUUUUUUUU\n";
	cout << "\tMMM      MMM      MMM  EEEEEEEEE  NNN       NNNNNN  UUUUUUUUUU\n";
	cout << endl;
	cout << "**************************************************************";
	cout << "**************************************************************";
	cout << endl;
	cout << "1. Display Stock\n\n";
	cout << "2. Stock Management\n\n";
	cout << "3. Check Insufficient stock\n\n";
	cout << "4. Exit Program\n\n";
	
	cout << "Please enter your choice here(1-4): ";
	cin >> menu_num;
	// not yet done
	switch (menu_num)
	{
	case 1: {
		system("cls");
		display_stock();
		break;
	}
	case 2: {
		system("cls");
		stock_manage();//not yet done stock management
		break;
	}
	case 3: {
		system("cls");
		Insuff_stock();//not yet done bills management
		break;
	}
	case 4: {
		system("cls");
		cout << endl;
		cout << "\t\tBBBBBBBB   YYY    YYY  EEEEEEEEE\n";
		cout << "\t\tBBBB  BBB  YYY    YYY  EEEEEEEEE\n";
		cout << "\t\tBBBB   BBB YYY    YYY  EEE      \n";
		cout << "\t\tBBBB  BBB  YYY    YYY  EEE      \n";
		cout << "\t\tBBBBBBBB     YYYYYY    EEEEEEEEE\n";
		cout << "\t\tBBBB  BBB     YYYY     EEE      \n";
		cout << "\t\tBBBB   BBB    YYYY     EEE      \n";
		cout << "\t\tBBBB  BBB     YYYY     EEEEEEEEE\n";
		cout << "\t\tBBBBBBBB      YYYY     EEEEEEEEE\n";
		break;
	}
	default:
	{
		system("cls");
		cout << endl;
		cout << "EEEEEEEEE RRRRRRRR	  RRRRRRRR	 OOOOOOOOO RRRRRRRR	\n";
		cout << "EEEEEEEEE RRR   RRR  RRR   RRR  OOOOOOOOO RRR   RRR	\n";
		cout << "EEE	   RRR    RRR RRR    RRR OOO   OOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR  RRRR  RRR  RRRR  OOO   OOO RRR  RRRR	\n";
		cout << "EEEEEEEEE RRRRRRRR	  RRRRRRRR   OOO   OOO RRRRRRRR	\n";
		cout << "EEE	   RRR    RRR RRR    RRR OOO   OOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR    RRR RRR    RRR OOOOOOOOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR    RRR RRR    RRR OOOOOOOOO RRR    RRR\n";
		cout << endl;
		cout << "Error Code 101: Invalid Input Number!!!\n";
		menu();
	}
	}
}



//not yet done stock_management function
void stock_manage();
void stock_manage()
{
	int stock_num;
	cout << "\n1. Add new Products\n";
	cout << "2. Delete Products\n";
	cout << "3. Update Products Quantity\n";
	cout << "4. Update Products Price\n";
	cout << "5. Update Products Name\n";
	cout << "6. Search Products\n";
	cout << "7. Return to menu\n\n";
	
	cout << "Please enter your selection(1-5): ";
	cin >> stock_num;
	cout << endl;

	if (stock_num == 1)
	{
		system("cls");
		addproducts();
	}

	else if (stock_num == 2)
	{
		system("cls");
		delproducts();//not done
	}

	else if (stock_num == 3)
	{
		system("cls");
		update_quantity();//not done
	}

	else if (stock_num == 4)
	{
		system("cls");
		update_price();//not done
	}

	else if (stock_num == 5)
	{
		system("cls");
		update_name();
	}

	else if (stock_num == 6)
	{
		system("cls");
		search_item();
	}

	else if (stock_num == 7)
	{
		system("cls");
		menu();
	}

	else
	{
		system("cls");
		cout << endl;
		cout << "EEEEEEEEE RRRRRRRR	  RRRRRRRR	 OOOOOOOOO RRRRRRRR	\n";
		cout << "EEEEEEEEE RRR   RRR  RRR   RRR  OOOOOOOOO RRR   RRR	\n";
		cout << "EEE	   RRR    RRR RRR    RRR OOO   OOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR  RRRR  RRR  RRRR  OOO   OOO RRR  RRRR	\n";
		cout << "EEEEEEEEE RRRRRRRR	  RRRRRRRR   OOO   OOO RRRRRRRR	\n";
		cout << "EEE	   RRR    RRR RRR    RRR OOO   OOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR    RRR RRR    RRR OOOOOOOOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR    RRR RRR    RRR OOOOOOOOO RRR    RRR\n";
		cout << endl;
		cout << "Error Code 101: Invalid Input Number!!!\n";
		stock_manage();

	}

}



//Add New product function
void addproducts();
void addproducts()
{
	bool boolean = true , con = true;
	char cont_add;
	while (boolean = true) 
	{
		cout << "\nPlease enter the new product name: ";
		cin >> new_prod_name;
		cout << "\nPLease enter the new product price: ";
		cin >> new_prod_price;
		cout << "\nPlease enter the new product quantity: ";
		cin >> new_prod_quant;
		int* ptr_id;// pointer to hold id array address
		ptr_id = getid();
		new_prod_id = ptr_id.back() + 1;

		ofstream outFile;
		outFile.open("stock.txt", ios:app);

		outFile << new_prod_id << endl;
		outFile << new_prod_name << endl;
		outFile << new_prod_price << endl;
		outFile << new_prod_quant << endl;
		outFile.close();

		cout << "New Product is added." << endl;
		cout << "\n Do you want to continue(Y/N): \n";
		cin >> cont_add;

		while (con == true)
		{
			if (toupper(cont_add) != 'Y' && toupper(cont_add) != 'N')
			{
				cout << "\nInvalid Input!!!\n";
				cout << "Please enter 'Y' or 'N' ONLY\n";
				return con = true;
			}

			else
				return con = false;
		}

		if (toupper(cont_add) == 'Y')
				return boolean = true;

		else
				return boolean = false;
	}

	menu();
}



//function to get id list
int* getid();
int* getid()
{
	ifstream inFile;
	inFile.open("stock.txt");

	while (!inFile.eof())
	{
		inFile >> prod_id_list;
		getline(inFile,prod_name_list);
		inFile >> prod_price_list;
		inFile >> prod_quant_list;
	}
	inFile.close();
	return prod_id;
}



//Delete Product function not done
void delproducts();
void delproducts()
{
	int prod_id;
	display_stock();
	cout << "\nPlease enter the Product ID you want to DELETE: ";
	cin >> prod_id;
	
	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	while (!File.eof())
	{
		for (int i = 0; i != prod_id - 1; i++)
		{
			File >> prod_id_list;
			getline(File, prod_name_list);
			File >> prod_price_list;
			File >> prod_quant_list;
			continue;
		}
	}

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		if (prod_id_list[i] > prod_id)
		{
			prod_id_list[i] = prod_id_list[i] - 1;
		}
	}

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		File << prod_id_list[i] << endl;
		File << prod_name_list[i] << endl;
		File << fixed << setprecision(2) << prod_price_list[i] << endl;
		File << prod_quant_list[i] << endl;
	}

	File.close();
}



//Display Item Function
void display_stock();
void display_stock()
{
	ifstream inFile;
	inFile.open("stock.txt");
	int prod_id , prod_quant;
	string prod_name;
	double prod_price;

	while (!inFile.eof())
	{
		inFile >> prod_id;
		getline(inFile, prod_name);
		inFile >> prod_price;
		inFile >> prod_quant;
		cout << endl;
		cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
		cout << "*" * 50 << endl;
		cout << prod_id << ".\t\t " << prod_name << "\t\t ";
		cout << fixed << showpoint() << setprecision(2) << prod_price << "\t\t " << prod_quant << endl;
	}

	inFile.close();
}



//Restock function
void update_quant();
void update_quant()
{
	int restock_quant, prod_id;
	display_stock();

	cout << "\nPLease enter the product ID which you want to restock: ";
	cin >> prod_id;
	cout << "\nPlease enter the quantity of the product you want to restock: ";
	cin >> restock_quant;

	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	while (!File.eof())
	{
		File >> prod_id_list;
		getline(File, prod_name_list);
		File >> prod_price_list;
		File >> prod_quant_list;
	}

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		if (prod_id_list[i] == prod_id - 1)
		{
			prod_quant_list[i] = prod_quant_list[i] + restock_quant;
		}
	}

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		File << prod_id_list[i] << endl;
		File << prod_name_list[i] << endl;
		File << fixed << setprecision(2) << prod_price_list[i] << endl;
		File << prod_quant_list[i] << endl;
	}

	File.close();
}


//Update new cost function
void update_price();
void update_price()
{
	int prod_id;
	double new_price;
	display_stock();

	cout << "\nPLease enter the product ID which you want to change its cost: ";
	cin >> prod_id;
	cout << "\nPlease enter the new cost: RM";
	cin >> new_price;

	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	while (!File.eof())
	{
		File >> prod_id_list;
		getline(File, prod_name_list);
		File >> prod_price_list;
		File >> prod_quant_list;
	}

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		if (prod_id_list[i] == prod_id - 1)
		{
			strcpy(prod_priceList[i], new_price);
		}
	}

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		File << prod_id_list[i] << endl;
		File << prod_name_list[i] << endl;
		File << fixed << setprecision(2)<< prod_price_list[i] << endl;
		File << prod_quant_list[i] << endl;
	}

	File.close();

}


//Update Name function
void update_name();
void update_name()
{

}