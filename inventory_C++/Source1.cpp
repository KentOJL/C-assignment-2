#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <array>
#include <cstring>
#include <cctype>
using namespace std;

////declare variables
//string new_prod_name;
//char prod_name_list[100][30];
//static int prod_id_list[100][5] , prod_quant_list[100][5];
//double prod_price_list[100][5];
//int new_prod_quant;
//int new_prod_price, new_prod_id;


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
	cout << "\t****************************************************************\n";
	cout << "\t****************************************************************\n";
	cout << endl;
	cout << "1. Display Stock\n\n";
	cout << "2. Stock Management\n\n";
	cout << "3. Check Insufficient stock\n\n";
	cout << "4. Exit Program\n\n";
	
	cout << "Please enter your choice here(1-4): ";
	cin >> menu_num;
	
	switch (menu_num)
	{
	case 1: {
		system("cls");
		display_stock();
		break;
	}
	case 2: {
		system("cls");
		stock_manage();
		break;
	}
	case 3: {
		system("cls");
		insuff_stock();
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
		cout << "EEEEEEEEE RRRRRRRR   RRRRRRRR   OOOOOOOOO RRRRRRRR\n";
		cout << "EEEEEEEEE RRR   RRR  RRR   RRR  OOOOOOOOO RRR   RRR\n";
		cout << "EEE       RRR    RRR RRR    RRR OOO   OOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR  RRRR  RRR  RRRR  OOO   OOO RRR  RRRR\n";
		cout << "EEEEEEEEE RRRRRRRR   RRRRRRRR   OOO   OOO RRRRRRRR \n";
		cout << "EEE       RRR    RRR RRR    RRR OOO   OOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR    RRR RRR    RRR OOOOOOOOO RRR    RRR\n";
		cout << "EEEEEEEEE RRR    RRR RRR    RRR OOOOOOOOO RRR    RRR\n";
		cout << endl;
		cout << "Error Code 101: Invalid Input Number!!!\n";
		menu();
		break;
	}
	}
}



//stock_management function
void stock_manage();
void stock_manage()
{
	int stock_num;
	cout << "\n1. Add new Products\n";
	cout << "2. Delete Products\n";
	cout << "3. Restock Products\n";
	cout << "4. Check Out Products Stock\n";
	cout << "5. Update Products Price\n";
	cout << "6. Update Products Name\n";
	cout << "7. Search Products\n";
	cout << "8. Return to menu\n\n";
	
	cout << "Please enter your selection(1-8): ";
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
		delproducts();
	}

	else if (stock_num == 3)
	{
		system("cls");
		update_quant();
	}

	else if (stock_num == 4)
	{
		system("cls");
		stock_out();
	}

	else if (stock_num == 5)
	{
		system("cls");
		update_price();
	}

	else if (stock_num == 6)
	{
		system("cls");
		update_name();
	}

	else if (stock_num == 7)
	{
		system("cls");
		search_item();
	}

	else if (stock_num == 8)
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
	char prod_name_list[100][30];
	static int prod_id_list[100][5], prod_quant_list[100][5];
	double prod_price_list[100][5];

	int new_prod_quant;
	int new_prod_price, new_prod_id;
	string new_prod_name;

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

		std::array<int, 100> arr;
		//int* ptr_id;// pointer to hold id array address
		arr = get_id();
		new_prod_id = arr.back() + 1;

		ofstream outFile;
		outFile.open("stock.txt", ios::app);

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
				con = true;
			}

			else
				con = false;
		}

		if (toupper(cont_add) == 'Y')
				boolean = true;

		else
				boolean = false;
	}

	stock_manage();
}


//Function to get ID
std::array<int, 100> get_id()
{
	std::array<int, 100> f_array;
	string prod_name_list[100];
	std::array<double, 100> prod_price_list;
	std::array<int, 100> prod_quant_list;

	ifstream infile;
	infile.open("stock.txt");

	while (!infile.eof())
	{
		for (int i = 0; i < 100; i++)
		{
			infile >> f_array[i];
			getline(infile , prod_name_list[i]);
			infile >> prod_price_list[i];
			infile >> prod_quant_list[i];
		}
		infile.ignore();
	}

	for (int i = 0; i < 100; i++)
	{
		f_array[i] = i;
	}

	return f_array;
}


//// Old function to get id list
//int* getid();
//int* getid()
//{
//	char prod_name_list[100][30];
//	static int prod_id_list[100][5], prod_quant_list[100][5];
//	double prod_price_list[100][5];
//
//	ifstream inFile;
//	inFile.open("stock.txt");
//
//	while (!inFile.eof())
//	{
//		inFile >> prod_id_list;
//		getline(inFile , prod_name_list);
//		inFile >> prod_price_list;
//		inFile >> prod_quant_list;
//	}
//	inFile.close();
//	return prod_id_list;
//}



//Delete Product function
void delproducts();
void delproducts()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	int prod_id;
	char con;
	display_stock();
	cout << "\nPlease enter the Product ID you want to DELETE: ";
	cin >> prod_id;
	
	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	//std::array<int, 100> prod_id_list;
	//string prod_name_list[100];
	//std::array<double, 100> prod_price_list;
	//std::array<int, 100> prod_quant_list;

	std::array<int, 100> arr;
	arr = get_id();
	int j = sizeof(arr);

	//while (!File.eof())
	//{
	//	for (int i = 0; i < 100; i++)
	//	{	
	//		File >> prod_id_list[i];
	//		getline(File, prod_name_list[i]);
	//		File >> prod_price_list[i];
	//		File >> prod_quant_list[i];
	//	}
	//	File.ignore();
	//}


	if (prod_id > j || prod_id <= 0)
	{
		cout << "\nSorry ther is no this ID in the inventory system. :(" << endl;
		stock_manage();
	}

	else
	{	cout << "Do you sure want to delete this Item(ID:" << prod_id <<") Y/N: ";
		cin >> con;

		if (toupper(con) == 'Y')
		{
			while (!File.eof())
			{
				for (int i = 0; i != prod_id - 1; i++)
				{
					File >> prod_id_list[i];
					getline(File, prod_name_list[i]);
					File >> prod_price_list[i];
					File >> prod_quant_list[i];
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

		}

		else if (toupper(con) == 'N')
			stock_manage();

		else
		{
			cout << "\nInvalid Input!!! return back to stock management page.\n";
			stock_manage();
		}

	}


	File.close();
	stock_manage();
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
		cout << '*' *50 << endl;
		cout << prod_id << ".\t\t " << prod_name << "\t\t ";
		cout << fixed << setprecision(2) << prod_price << "\t\t " << prod_quant << endl;
	}

	inFile.close();
}



//Restock function
void update_quant();
void update_quant()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	bool j = true , ask = true;
	int restock_quant, prod_id;
	char con_restock;
	display_stock();

	fstream File;
	File.open("stock.txt", ios::in | ios::out);



	while (j == true) 
	{	cout << "\nPLease enter the product ID which you want to restock: ";
		cin >> prod_id;
		cout << "\nPlease enter the quantity of the product you want to restock: ";
		cin >> restock_quant;

		std::array<int, 100> arr;
		arr = get_id();
		int j = sizeof(arr);

		while (!File.eof())
		{
			for (int i = 0; i < j; i++)
			{
				File >> prod_id_list[i];
				getline(File, prod_name_list[i]);
				File >> prod_price_list[i];
				File >> prod_quant_list[i];
			}
		}

		for (int i = 0; i < j ; i++)
		{
			if (prod_id_list[i] == prod_id)
			{
				prod_quant_list[i] = prod_quant_list[i] + restock_quant;
			}
		}

		for (int i = 0; i < j ; i++)
		{
			File << prod_id_list[i] << endl;
			File << prod_name_list[i] << endl;
			File << fixed << setprecision(2) << prod_price_list[i] << endl;
			File << prod_quant_list[i] << endl;
		}

		cout << "\nNew stock is added into the inventory.\n";

		while (ask == true)
		{
			cout << "Do you want to continue restock?(Y/N): ";
			cin >> con_restock;

			if (toupper(con_restock) != 'Y' || toupper(con_restock) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY";
				ask = true;
			}

			else
				ask = false;
		}

		if (toupper(con_restock) == 'Y')
			j = true;

		else
			j = false;
	}

	File.close();
	menu();
}


//Update new cost function
void update_price();
void update_price()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	bool j = true, ask = true;
	char con_price;
	int prod_id;
	double new_price;
	display_stock();

	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	std::array<int, 100> arr;
	arr = get_id();
	int z = sizeof(arr);


	while (j == true)
	{
		cout << "\nPLease enter the product ID which you want to change its cost: ";
		cin >> prod_id;
		cout << "\nPlease enter the new cost: RM";
		cin >> new_price;


		while (!File.eof())
		{
			for (int i = 0; i < j; i++)
			{
				File >> prod_id_list[i];
				getline(File, prod_name_list[i]);
				File >> prod_price_list[i];
				File >> prod_quant_list[i];
			}
		}

		for (int i = 0; i < sizeof(prod_id_list); i++)
		{
			if (prod_id_list[i] == prod_id - 1)
			{
				prod_price_list[i] = new_price;
			}
		}

		for (int i = 0; i < sizeof(prod_id_list); i++)
		{
			File << prod_id_list[i] << endl;
			File << prod_name_list[i] << endl;
			File << fixed << setprecision(2) << prod_price_list[i] << endl;
			File << prod_quant_list[i] << endl;
		}

		cout << "\nNew Cost is added.\n";

		while (ask = true)
		{
			cout << "Do you want to continue update new cost?(Y/N): ";
			cin >> con_price;

			if (toupper(con_price) != 'Y' || toupper(con_price) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY";
				ask = true;
			}

			else
				ask = false;
		}

		if (toupper(con_price) == 'Y')
			j = true;

		else
			j = false;
	}

	File.close();
	menu();
}


//Update Name function
void update_name();
void update_name()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	int prod_id;
	bool j = true, ask = true;
	char con_name;
	string new_name;
	display_stock();

	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	std::array<int, 100> arr;
	arr = get_id();
	int z = sizeof(arr);

	while (j == true)
	{
		cout << "\nPLease enter the product ID which you want to change its name: ";
		cin >> prod_id;
		cout << "\nPlease enter the new name(In Capital Latter): ";
		getline(cin, new_name);


		while (!File.eof())
		{
			for (int i = 0; i < z; i++)
			{
				File >> prod_id_list[i];
				getline(File, prod_name_list[i]);
				File >> prod_price_list[i];
				File >> prod_quant_list[i];
			}
		}

		for (int i = 0; i < z; i++)
		{
			if (i == prod_id - 1)
			{
				prod_name_list[i] = new_name;
			}
		}

		for (int i = 0; i < z; i++)
		{
			File << prod_id_list[i] << endl;
			File << prod_name_list[i] << endl;
			File << fixed << setprecision(2) << prod_price_list[i] << endl;
			File << prod_quant_list[i] << endl;
		}

		cout << "\nNew Name is added.\n";

		while (ask = true)
		{
			cout << "Do you want to continue to update new name(Y/N): ";
			cin >> con_name;

			if (toupper(con_name) != 'Y' || toupper(con_name) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY";
				ask = true;
			}

			else
				ask = false;
		}
		
		if (toupper(con_name) == 'Y')
			j = true;

		else
			j = false;
	}


	File.close();
	menu();
}


//search product function
void search_item();
void search_item()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	int choice;

	system("cls");
	cout << "\nHellooo what product do you want to search.\n";
	cout << "Press 1 if you want to search by ID.\n";
	cout << "Press 2 if you want to search by NAME\n";
	cout << endl;
	cout << "Please enter your choice: ";
	cin >> choice;

	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	std::array<int, 100> arr;
	arr = get_id();
	int j = sizeof(arr);

	while (!File.eof())
	{
		for (int i = 0; i < j; i++)
		{
			File >> prod_id_list[i];
			getline(File, prod_name_list[i]);
			File >> prod_price_list[i];
			File >> prod_quant_list[i];
		}
	}

	if (choice == 1)
	{
		while (!File.eof())
		{
			for (int i = 0; i < j; i++)
			{
				File >> prod_id_list[i];
				getline(File, prod_name_list[i]);
				File >> prod_price_list[i];
				File >> prod_quant_list[i];
			}
		}

		int prod_id;
		system("cls");
		cout << "\nPlease key in the ID: ";
		cin >> prod_id;

		for (int i = 0 ; i < j ; i++)
		{
			if (i == prod_id - 1)
			{
				cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
				cout << '*' * 50 << endl;
				cout << prod_id << ".\t\t " << prod_name_list[i] << "\t\t ";
				cout << fixed << setprecision(2) << "RM" << prod_price_list[i] << "\t\t " << prod_quant_list[i] << endl;
			}

			else
			{
				cout << " Sorry NO such product in the inventory.";
				stock_manage();
			}
		}
	}

	if (choice == 2)
	{
		while (!File.eof())
		{
			for (int i = 0; i < j; i++)
			{
				File >> prod_id_list[i];
				getline(File, prod_name_list[i]);
				File >> prod_price_list[i];
				File >> prod_quant_list[i];
			}
		}


		string prod_name;
		system("cls");
		cout << "\nPlease key in the NAME(In Capital Letter): ";
		getline(cin, prod_name);


		for (int i = 0; i < j ; i++)
		{
			if (prod_name_list[i] == prod_name)
			{
				cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
				cout << '*' * 50 << endl;
				cout << prod_id_list[i] << ".\t\t " << prod_name_list[i] << "\t\t ";
				cout << fixed << setprecision(2) << "RM" << prod_price_list[i] << "\t\t " << prod_quant_list[i] << endl;
			}

			else
			{
				cout << " Sorry NO such product in the inventory.";
				stock_manage();
			}
		}

	}

	File.close();

	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}

void stock_out();
void stock_out()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	int stock_quant, prod_id;
	bool j = true, ask = true;
	char con_out;
	display_stock();

	fstream File;
	File.open("stock.txt", ios::in | ios::out);

	std::array<int, 100> arr;
	arr = get_id();
	int z = sizeof(arr);

	while (j == true)
	{
		cout << "\nPLease enter the product ID which you want to check out: ";
		cin >> prod_id;
		cout << "\nPlease enter the quantity of the product you want to check out: ";
		cin >> stock_quant;

		//fstream File;
		//File.open("stock.txt", ios::in | ios::out);

		while (!File.eof())
		{
			for (int i = 0; i < z; i++)
			{
				File >> prod_id_list[i];
				getline(File, prod_name_list[i]);
				File >> prod_price_list[i];
				File >> prod_quant_list[i];
			}
		}

		for (int i = 0; i < z ; i++)
		{
			if (i == prod_id - 1)
			{
				if (prod_quant_list[i] >= stock_quant)
				{
					prod_quant_list[i] = prod_quant_list[i] - stock_quant;
				}

				else
				{
					cout << "Sorry you can only check out " << prod_quant_list[i] << " of the stock.";
				}
			}
		}

		for (int i = 0; i < sizeof(prod_id_list); i++)
		{
			File << prod_id_list[i] << endl;
			File << prod_name_list[i] << endl;
			File << fixed << setprecision(2) << prod_price_list[i] << endl;
			File << prod_quant_list[i] << endl;
		}

		cout << "\nThe new quantity of the stock is updated.\n";

		while (ask = true)
		{
			cout << "Do you want to continue to check out the stock?(Y/N): ";
			cin >> con_out;

			if (toupper(con_out) != 'Y' || toupper(con_out) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY";
				ask = true;
			}

			else
				ask = false;
		}

		if (toupper(con_out) == 'Y')
			j = true;

		else
			j = false;
	}

	File.close();
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}

void insuff_stock();
void insuff_stock()
{
	string prod_name_list[100];
	static int prod_id_list[100], prod_quant_list[100];
	double prod_price_list[100];

	int j;
	system("cls");
	ifstream inFile;
	inFile.open("stock.txt");

	std::array<int, 100> arr;
	arr = get_id();
	int j = sizeof(arr);

	while (!inFile.eof())
	{
		for (int i = 0; i < j; i++)
		{
			inFile >> prod_id_list[i];
			getline(inFile, prod_name_list[i]);
			inFile >> prod_price_list[i];
			inFile >> prod_quant_list[i];
		}
	}

	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||\n";
	cout << "||| Products with INSUFFICIENT stock |||\n";
	cout << "||||||||||||||||||||||||||||||||||||||||\n";
	cout << endl;
	cout << "ID \t\t Name \t\t Cost \t\t Quantity\n";

	for (int i = 0; i < sizeof(prod_id_list); i++)
	{
		if (prod_quant_list[i] <= 20)
		{
			cout << "\n" << prod_id_list[i] << "|\t\t " << prod_name_list[i] << "|\t\t " << prod_price_list[i] << "|\t\t" << prod_quant_list[i];
			j += 1;
		}

	}

	if (j > 0)
	{
		cout << "\nPlease order the stock ASAP!!!\n";
	}

	else
		cout << "\nThe stock all is sufficient. :)\n";

	inFile.close();
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}

int main()
{
	char yes;
	system("cls");
	cout << " BlaBlaBla Fruits Store Inventory Management System program\n";
	cout << " Press Any Key to Proceed\n";
	cin >> yes;
	system("cls");
	menu();

	return 0;
}


