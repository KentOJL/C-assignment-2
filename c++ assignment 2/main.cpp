#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;
const int MAX_PRODUCTS = 100;

void menu();
void exit();
void error_input();
void stock_manage();
void addproducts();
void delproducts();
void display_stock();
void update_quant();
void update_price();
void update_name();
void stock_out();
void search_item();
void insuff_stock();


//menu function
void menu()
{
	int menu_num;
	cout << "\033[35m";
	cout << "\t\t   MMMMM     MMMMM     EEEEEEEEE  NNNNNN       NNN  UUU    UUU\n";
	cout << "\t\t  MMMMMMM   MMMMMMM    EEEEEEEEE  NNN NNN      NNN  UUU    UUU\n";
	cout << "\t\tMMM      MMM      MMM  EEE        NNN  NNN     NNN  UUU    UUU\n";
	cout << "\t\tMMM      MMM      MMM  EEEEEEEEE  NNN   NNN    NNN  UUU    UUU\n";
	cout << "\t\tMMM      MMM      MMM  EEEEEEEEE  NNN    NNN   NNN  UUU    UUU\n";
	cout << "\t\tMMM      MMM      MMM  EEE        NNN     NNN  NNN  UUU    UUU\n";
	cout << "\t\tMMM      MMM      MMM  EEEEEEEEE  NNN      NNN NNN  UUUUUUUUUU\n";
	cout << "\t\tMMM      MMM      MMM  EEEEEEEEE  NNN       NNNNNN  UUUUUUUUUU\n";
	cout << "\t\t**************************************************************\n";
	cout << "\t\t**************************************************************\n";
	cout << "\033[0m\033[39m" << endl;
	cout << endl;
	


	// Output the text
	cout << "\033[35m\033[48;2;251;163;142m";
	cout << "1. Display Stock\n\n";
	cout << "2. Stock Management\n\n";
	cout << "3. Check Insufficient stock\n\n";
	cout << "4. Exit Program\n\n";
	cout << "\033[0m";
	cout << endl;
	bool is_valid_input = false;
	do {
		// Prompt the user to enter their choice
		cout << "\033[35m\033[48;2;251;163;142m";
		cout << "Please enter your choice here(1-4): ";
		cin >> menu_num;
		cout << "\033[0m";

		switch (menu_num)
		{
		case 1:
			system("cls");
			display_stock();
			is_valid_input = true;
			break;

		case 2:
			system("cls");
			stock_manage();
			is_valid_input = true;
			break;

		case 3:
			system("cls");
			insuff_stock();
			is_valid_input = true;
			break;

		case 4:
			system("cls");
			exit();
			is_valid_input = true;
			break;

		default:
			// Output error message
			error_input();
			is_valid_input = false;
			break;
		}
		cout << endl; // Add a line break for clarity
	} while (menu_num < 1 || menu_num > 4 || !is_valid_input);
}





void exit()
{
	cout << "\033[38;2;255;255;102m";
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
	cout << "\033[0m"; // Reset the color to default

}





void error_input()
{
	cout << "\033[1;31m"; // Set text color to red and bold
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
	cout << "\033[0m"; // Reset text color to default
	cout << "\033[1;31m"; // Set text color to red and bold
	cout << "Error Code 101: Invalid Input Number!!!\n";
	cout << "\033[0m"; // Reset text color to default
}





//stock_management function

void stock_manage()
{
	int stock_num;
	while (true) {
		cout << "\033[38;2;255;255;102m";
		cout << "\n STOCK MANAGEMENT\n";
		cout << "****************************\n";
		cout << "\033[0m"; // Reset the color to default
		cout << endl;
		cout << "\n1. Add new Products\n";
		cout << "2. Delete Products\n";
		cout << "3. Restock Products\n";
		cout << "4. Check Out Products Stock\n";
		cout << "5. Update Products Price\n";
		cout << "6. Rename Products \n";
		cout << "7. Search Products\n";
		cout << "8. Return to menu\n\n";

		cout << "Please enter your selection (1-8): ";
		cin >> stock_num;
		cout << endl;

		if (stock_num >= 1 && stock_num <= 8) {
			break;
		}

		error_input();
	}

	switch (stock_num) {
	case 1:
		system("cls");
		addproducts();
		break;
	case 2:
		system("cls");
		delproducts();
		break;
	case 3:
		system("cls");
		update_quant();
		break;
	case 4:
		system("cls");
		stock_out();
		break;
	case 5:
		system("cls");
		update_price();
		break;
	case 6:
		system("cls");
		update_name();
		break;
	case 7:
		system("cls");
		search_item();
		break;
	case 8:
		system("cls");
		menu();
		break;
	default:
		system("cls");
		error_input();
		stock_manage();
		break;
	}
}




//Add New product function

void addproducts()
{
	string prod_name_list[100];
	string prod_id_list[100], prod_quant_list[100];
	string prod_price_list[100];

	int temp_id, temp_quant, R_prod_id_list[100], R_prod_quant_list[100];
	double temp_price, R_prod_price_list[100];

	int new_prod_quant, new_prod_id;
	int counter = 0, i = 0;
	double new_prod_price = 0;
	string new_prod_name;

	bool boolean = true, con = true;
	char cont_add;
	while (boolean == true)
	{
		cout << "\nPlease enter the new product name(In Capital Letter): ";
		cin >> new_prod_name;
		cout << "\nPLease enter the new product price: ";
		cin >> new_prod_price;
		cout << "\nPlease enter the new product quantity: ";
		cin >> new_prod_quant;

		fstream inFile;
		inFile.open("stock.txt", ios::in);
		if (inFile.is_open())
		{
			while (!inFile.eof())
			{
				getline(inFile, prod_id_list[i]);
				getline(inFile, prod_name_list[i]);
				getline(inFile, prod_price_list[i]);
				getline(inFile, prod_quant_list[i]);
				i++;
				counter++;
			}
		}
		else
			cout << "File not open" << endl;

		new_prod_id = counter + 1;
		inFile.close();

		for (int i = 0; i < counter; i++)
		{
			temp_id = stoi(prod_id_list[i]);
			R_prod_id_list[i] = temp_id;
			temp_price = stod(prod_price_list[i]);
			R_prod_price_list[i] = temp_price;
			temp_quant = stoi(prod_quant_list[i]);
			R_prod_quant_list[i] = temp_quant;
		}

		ofstream outFile;
		outFile.open("stock.txt", ios::app);
		outFile << endl;
		outFile << new_prod_id << endl;
		outFile << new_prod_name << endl;
		outFile << new_prod_price << endl;
		outFile << new_prod_quant;
		outFile.close();

		cout << "New Product is added." << endl;
		cout << "\n Do you want to continue(Y/N): \n";
		cin >> cont_add;

		while (toupper(cont_add) != 'Y' && toupper(cont_add) != 'N')
		{
			cout << "\nInvalid Input!!!\n";
			cout << "Please enter 'Y' or 'N' ONLY\n";
			cin >> cont_add;
		}

		if (toupper(cont_add) == 'Y')
			boolean = true;

		else
			boolean = false;
	}
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}




//Delete Product function

void delproducts()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];
	int prod_id, i = 0;
	char con;
	bool del = true , ask = true;

	do
	{
		display_stock();
		cout << "\nPlease enter the Product ID you want to DELETE: ";
		cin >> prod_id;

		fstream File;
		File.open("stock.txt", ios::in | ios::out);

		if (File.is_open())
		{
			while (!File.eof())
			{
				getline(File, prod_id_list[i]);
				getline(File, prod_name_list[i]);
				getline(File, prod_price_list[i]);
				getline(File, prod_quant_list[i]);
				i++;
			}
		}
		else
		{
			cout << "File not open" << endl;
			cout << "Please go check the file and you will be return to stock management page.\n";
			stock_manage();
		}
		

		int j = i;

		for (int z = 0; z < j; z++)
		{
			temp_id = stoi(prod_id_list[z]);
			R_prod_id_list[z] = temp_id;
			temp_name = prod_name_list[z];
			R_prod_name_list[z] = temp_name;
			temp_price = stod(prod_price_list[z]);
			R_prod_price_list[z] = temp_price;
			temp_quant = stoi(prod_quant_list[z]);
			R_prod_quant_list[z] = temp_quant;
		}

		File.close();

		// Deleting the product from the arrays
		int del_index = -1;
		for (int z = 0; z < j; z++)
		{
			if (R_prod_id_list[z] == prod_id)
			{
				del_index = z;
				break;
			}
		}

		if (del_index == -1)
		{
			cout << "Product not found!" << endl;
		}

		for (int z = del_index; z < j - 1; z++)
		{
			R_prod_id_list[z] = R_prod_id_list[z + 1];
			R_prod_name_list[z] = R_prod_name_list[z + 1];
			R_prod_price_list[z] = R_prod_price_list[z + 1];
			R_prod_quant_list[z] = R_prod_quant_list[z + 1];
		}

		// Writing the updated stock to the file
		File.open("stock.txt", ios::out | ios::trunc);

		if (File.is_open())
		{
			for (int z = 0; z < j - 1; z++)
			{
				temp_name = R_prod_name_list[z];
				File << R_prod_id_list[z] << endl;
				File << temp_name << endl;
				File << fixed << setprecision(2) << R_prod_price_list[z] << endl;
				if (z == j - 2)
				{
					File << R_prod_quant_list[z];
				}
				else
				{
					File << R_prod_quant_list[z] << endl;
				}
			}
			File.close();
			cout << "Product " << prod_id << " deleted successfully." << endl;
			cout << "Return to menu\n";
			stock_manage();
		}
		else
		{
			cout << "Error: file could not be opened for writing." << endl;
			cout << "Please go check the file and you will be return to stock management page.\n";
			stock_manage();
		}

		while (ask == true)
		{
			cout << "Do you want to continue delete products? (Y/N): ";
			cin >> con;

			if (toupper(con) != 'Y' && toupper(con) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY" << endl;
				ask = true;
			}
			else
			{
				ask = false;
			}
		}

		if (toupper(con) == 'Y')
		{
			del = true;
		}
		else
			del = false;

	} while (del == true);

	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}




//Display Item Function

void display_stock()
{
	ifstream inFile;
	inFile.open("stock.txt");
	string prod_name, prod_id, prod_quant, prod_price;


	cout << endl;
	cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
	cout << "**********************************************************************" << endl;

	while (!inFile.eof())
	{
		//inFile >> prod_id;
		//getline(inFile, prod_name);
		//inFile >> prod_price;
		//inFile >> prod_quant;
		getline(inFile, prod_id);
		getline(inFile, prod_name);
		getline(inFile, prod_price);
		getline(inFile, prod_quant);
		cout << "\n" << prod_id << ".\t\t " << prod_name << "\t\t ";
		cout << fixed << setprecision(2) << prod_price << "\t\t " << prod_quant << endl;
	}

	inFile.close();
}




//Restock function

void update_quant()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];

	bool del = true, ask = true;
	int restock_quant, prod_id, i = 0;
	char con_restock;

	display_stock();

	ifstream inFile;
	ofstream outFile;
	inFile.open("stock.txt");
	if (inFile.fail())
	{
		cout << "Error: file could not be opened for reading." << endl;
		cout << "Return to main menu\n";
		menu();
	}

	while (!inFile.eof())
	{
		getline(inFile, prod_id_list[i]);
		getline(inFile, prod_name_list[i]);
		getline(inFile, prod_price_list[i]);
		getline(inFile, prod_quant_list[i]);
		i++;
	}
	inFile.close();

	int j = i;

	for (int z = 0; z < j; z++)
	{
		temp_id = stoi(prod_id_list[z]);
		R_prod_id_list[z] = temp_id;
		temp_name = prod_name_list[z];
		R_prod_name_list[z] = temp_name;
		temp_price = stod(prod_price_list[z]);
		R_prod_price_list[z] = temp_price;
		temp_quant = stoi(prod_quant_list[z]);
		R_prod_quant_list[z] = temp_quant;
	}

	while (del == true)
	{
		cout << "\nPlease enter the product ID which you want to restock: ";
		cin >> prod_id;
		cout << "\nPlease enter the quantity of the product you want to restock: ";
		cin >> restock_quant;

		for (int z = 0; z < j; z++)
		{
			if (R_prod_id_list[z] == prod_id)
			{
				R_prod_quant_list[z] = R_prod_quant_list[z] + restock_quant;
			}
		}

		outFile.open("stock.txt");
		if (outFile.fail())
		{
			cout << "Error: file could not be opened for writing." << endl;
			cout << "Please go check the file and you will be return to stock management page.\n";
			stock_manage();
		}

		for (int z = 0; z < j; z++)
		{
			temp_name = R_prod_name_list[z];
			outFile << R_prod_id_list[z] << endl;
			outFile << temp_name << endl;
			outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
			if (z == j - 1) {
				outFile << R_prod_quant_list[z];
			}
			else {
				outFile << R_prod_quant_list[z] << endl;
			}
		}
		outFile.close();
		cout << "Stock of Product " << prod_id << " has been restocked successfully." << endl;

		while (ask == true)
		{
			cout << "Do you want to continue restocking? (Y/N): ";
			cin >> con_restock;

			if (toupper(con_restock) != 'Y' && toupper(con_restock) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY" << endl;
				ask = true;
			}
			else
			{
				ask = false;
			}
		}

		if (toupper(con_restock) == 'Y')
		{
			del = true;
		}
		else
			del = false;
	}
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}





//Update new cost function

void update_price()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];

	bool cost = true, ask = true;
	char con_price;
	int prod_id, i = 0;
	double new_price;
	display_stock();

	ifstream inFile;
	ofstream outFile;
	inFile.open("stock.txt");
	if (inFile.fail())
	{
		cout << "Error: file could not be opened for reading." << endl;
		cout << "Please go check the file and you will be return to stock management page.\n";
		stock_manage();
	}

	while (!inFile.eof())
	{
		getline(inFile, prod_id_list[i]);
		getline(inFile, prod_name_list[i]);
		getline(inFile, prod_price_list[i]);
		getline(inFile, prod_quant_list[i]);
		i++;
	}
	inFile.close();

	int j = i;

	for (int z = 0; z < j; z++)
	{
		temp_id = stoi(prod_id_list[z]);
		R_prod_id_list[z] = temp_id;
		temp_name = prod_name_list[z];
		R_prod_name_list[z] = temp_name;
		temp_price = stod(prod_price_list[z]);
		R_prod_price_list[z] = temp_price;
		temp_quant = stoi(prod_quant_list[z]);
		R_prod_quant_list[z] = temp_quant;
	}


	while (cost == true)
	{
		cout << "\nPLease enter the product ID which you want to change its cost: ";
		cin >> prod_id;
		cout << "\nPlease enter the new cost: RM";
		cin >> new_price;


		for (int z = 0; z < j; z++)
		{
			if (R_prod_id_list[z] == prod_id)
			{
				R_prod_price_list[z] = new_price;
			}
		}

		outFile.open("stock.txt");
		if (outFile.fail())
		{
			cout << "Error: file could not be opened for writing." << endl;
			cout << "Please go check the file and you will be return to stock management page.\n";
			stock_manage();
		}

		for (int z = 0; z < j; z++)
		{
			temp_name = R_prod_name_list[z];
			outFile << R_prod_id_list[z] << endl;
			outFile << temp_name << endl;
			outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
			if (z == j - 1) {
				outFile << R_prod_quant_list[z];
			}
			else {
				outFile << R_prod_quant_list[z] << endl;
			}
		}
		outFile.close();
		cout << "New cost of Product " << prod_id << " has been updated successfully." << endl;

		while (ask == true)
		{
			cout << "Do you want to continue update new cost?(Y/N): ";
			cin >> con_price;

			if (toupper(con_price) != 'Y' && toupper(con_price) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY" << endl;
				ask = true;
			}

			else
				ask = false;
		}

		if (toupper(con_price) == 'Y')
			cost = true;

		else
			cost = false;
	}
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}





//Update Name function
void update_name()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];

	bool rename = true, ask = true;
	int prod_id, i = 0;
	char con_name;
	string new_name;
	ifstream inFile;
	ofstream outFile;

	display_stock();

	inFile.open("stock.txt");
	if (inFile.fail())
	{
		cout << "Error: file could not be opened for reading." << endl;
		cout << "Please go check the file and you will be return to stock management page.\n";
		stock_manage();
	}

	while (!inFile.eof())
	{
		getline(inFile, prod_id_list[i]);
		getline(inFile, prod_name_list[i]);
		getline(inFile, prod_price_list[i]);
		getline(inFile, prod_quant_list[i]);
		i++;
	}
	inFile.close();

	int j = i;

	for (int z = 0; z < j; z++)
	{
		temp_id = stoi(prod_id_list[z]);
		R_prod_id_list[z] = temp_id;
		temp_name = prod_name_list[z];
		R_prod_name_list[z] = temp_name;
		temp_price = stod(prod_price_list[z]);
		R_prod_price_list[z] = temp_price;
		temp_quant = stoi(prod_quant_list[z]);
		R_prod_quant_list[z] = temp_quant;
	}


	while (rename == true)
	{
		cout << "\nPLease enter the product ID which you want to change its name: ";
		cin >> prod_id;
		cout << "\nPlease enter the new name(Capital Letter ONLY): ";
		cin.ignore();
		getline(cin, new_name);

		for (int z = 0; z < j; z++)
		{
			if (R_prod_id_list[z] == prod_id)
			{
				R_prod_name_list[z] = new_name;
			}
		}

		outFile.open("stock.txt");
		if (outFile.fail())
		{
			cout << "Error: file could not be opened for writing." << endl;
			cout << "Please go check the file and you will be return to stock management page.\n";
			stock_manage();
		}

		for (int z = 0; z < j; z++)
		{
			temp_name = R_prod_name_list[z];
			outFile << R_prod_id_list[z] << endl;
			outFile << temp_name << endl;
			outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
			if (z == j - 1) {
				outFile << R_prod_quant_list[z];
			}
			else {
				outFile << R_prod_quant_list[z] << endl;
			}
		}
		outFile.close();
		cout << "Name of Product " << prod_id << " has been rename successfully." << endl;

		while (ask == true)
		{
			cout << "Do you want to continue renaming? (Y/N): ";
			cin >> con_name;

			if (toupper(con_name) != 'Y' && toupper(con_name) != 'N')
			{
				cout << "\nPlease enter Y and N ONLY" << endl;
				ask = true;
			}
			else
			{
				ask = false;
			}
		}

		if (toupper(con_name) == 'Y')
		{
			rename = true;
		}
		else
			rename = false;
	}
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}




//search product function

void search_item()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];
	int choice , i = 0;

	ifstream inFile;
	inFile.open("stock.txt");
	if (inFile.fail())
	{
		cout << "Error: file could not be opened for reading." << endl;
		cout << "Return to main menu\n";
		menu();
	}

	while (!inFile.eof())
	{
		getline(inFile, prod_id_list[i]);
		getline(inFile, prod_name_list[i]);
		getline(inFile, prod_price_list[i]);
		getline(inFile, prod_quant_list[i]);
		i++;
	}
	inFile.close();

	int j = i;

	for (int z = 0; z < j; z++)
	{
		temp_id = stoi(prod_id_list[z]);
		R_prod_id_list[z] = temp_id;
		temp_name = prod_name_list[z];
		R_prod_name_list[z] = temp_name;
		temp_price = stod(prod_price_list[z]);
		R_prod_price_list[z] = temp_price;
		temp_quant = stoi(prod_quant_list[z]);
		R_prod_quant_list[z] = temp_quant;
	}

	system("cls");
	cout << "\nHellooo what product do you want to search.\n";
	cout << "Press 1 if you want to search by ID.\n";
	cout << "Press 2 if you want to search by NAME\n";
	cout << endl;
	cout << "Please enter your choice: ";
	cin >> choice;
	cin.ignore();

	if (choice == 1)
	{
		int prod_id;
		system("cls");
		cout << "\nPlease key in the ID: ";
		cin >> prod_id;
		cin.ignore();

		cout << endl;
		cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
		cout << "**********************************************************************" << endl;


		bool found = false;
		for (int z = 0; z < j; z++)
		{
			if (R_prod_id_list[z] == prod_id)
			{
				cout << R_prod_id_list[z] << ".\t\t " << R_prod_name_list[z] << "\t\t ";
				cout << fixed << setprecision(2) << "RM" << R_prod_price_list[z] << "\t\t " << R_prod_quant_list[z] << endl;
				found = true;
			}
		}
		if (!found)
		{
			cout << "\n Sorry NO such product in the inventory.\n";
			cout << "Return to the stock management page" << endl;
			stock_manage();
		}
	}

	else if (choice == 2)
	{

		system("cls");
		string prod_name;
		cout << "\nPlease key in the NAME(In Capital Letter): ";
		getline(cin, prod_name);
		cin.ignore();

		cout << endl;
		cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
		cout << "**********************************************************************" << endl;

		bool found = false;
		for (int z = 0; z < j; z++)
		{
			if (R_prod_name_list[z] == prod_name)
			{
				cout << R_prod_id_list[z] << ".\t\t " << R_prod_name_list[z] << "\t\t ";
				cout << fixed << setprecision(2) << "RM" << R_prod_price_list[z] << "\t\t " << R_prod_quant_list[z] << endl;
				found = true;
			}
		}
		if (!found)
		{
			cout << "\n Sorry NO such product in the inventory.\n";
			cout << "Return to the stock management page" << endl;
			stock_manage();
		}

	}

	else
	{
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
		cout << endl;
		cout << "return to stock management page.\n";
		stock_manage();

	}

	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}





void stock_out()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];

	bool del = true, ask = true;
	int stock_quant, prod_id, i = 0;
	char con_out;
	display_stock();

	ifstream inFile;
	ofstream outFile;
	inFile.open("stock.txt");
	if (inFile.fail())
	{
		cout << "Error: file could not be opened for reading." << endl;
		cout << "Return to main menu\n";
		menu();
	}

	while (!inFile.eof())
	{
		getline(inFile, prod_id_list[i]);
		getline(inFile, prod_name_list[i]);
		getline(inFile, prod_price_list[i]);
		getline(inFile, prod_quant_list[i]);
		i++;
	}
	inFile.close();

	int j = i;

	for (int z = 0; z < j; z++)
	{
		temp_id = stoi(prod_id_list[z]);
		R_prod_id_list[z] = temp_id;
		temp_name = prod_name_list[z];
		R_prod_name_list[z] = temp_name;
		temp_price = stod(prod_price_list[z]);
		R_prod_price_list[z] = temp_price;
		temp_quant = stoi(prod_quant_list[z]);
		R_prod_quant_list[z] = temp_quant;
	}
	while (del == true)
	{
		bool valid_input = false; // initialize valid_input to false

		while (!valid_input) // loop while valid_input is false
		{
			cout << "\nPlease enter the product ID which you want to check out: ";
			cin >> prod_id;
			cout << "\nPlease enter the quantity of the product you want to check out: ";
			cin >> stock_quant;

			// loop through the product list to find the matching product id
			for (int z = 0; z < j; z++)
			{
				if (R_prod_id_list[z] == prod_id)
				{
					if (R_prod_quant_list[z] >= stock_quant)
					{
						R_prod_quant_list[z] = R_prod_quant_list[z] - stock_quant;
						valid_input = true; // set valid_input to true if the input is valid
					}
					else
					{
						cout << "Sorry, you can only check out " << R_prod_quant_list[z] << " of the stock.\n";
						break; // break out of the loop if the input is invalid
					}
				}
			}

			if (!valid_input) // if the input is invalid, loop back to the question part to ask again
			{
				cout << "\nInvalid input. Please try again.\n";
			}
		}


		if (valid_input) // if the input is valid, write to the file and ask if the user wants to continue
		{
			// write the updated stock to the file
			outFile.open("stock.txt");
			if (outFile.fail())
			{
				cout << "Error: file could not be opened for writing." << endl;
				cout << "Please go check the file and you will be return to stock management page.\n";
				stock_manage();
			}

			for (int z = 0; z < j; z++)
			{
				temp_name = R_prod_name_list[z];
				outFile << R_prod_id_list[z] << endl;
				outFile << temp_name << endl;
				outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
				if (z == j - 1) {
					outFile << R_prod_quant_list[z];
				}
				else {
					outFile << R_prod_quant_list[z] << endl;
				}
			}

			outFile.close();
			cout << "Stock of Product " << prod_id << " has been check out successfully." << endl;

			while (ask == true)
			{
				cout << "Do you want to continue to check out the stock?(Y/N): ";
				cin >> con_out;

				if (toupper(con_out) != 'Y' && toupper(con_out) != 'N')
				{
					cout << "\nPlease enter Y and N ONLY" << endl;
					ask = true;
				}

				else
					ask = false;
			}

			if (toupper(con_out) == 'Y')
				del = true;

			else
				del = false;
		}
		// if the input is invalid, loop back to the question part to ask again
		else
		{
			cout << "\nInvalid input. Please try again.\n";
		}
	}
	char yes;
	cout << " Press Any Key to return to menu\n";
	cin >> yes;
	system("cls");
	menu();
}






void insuff_stock()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];

	int i = 0;
	int count = 0;
	const int insuff_num = 20;

	ifstream inFile;
	inFile.open("stock.txt");
	if (inFile.fail())
	{
		cout << "Error: file could not be opened for reading." << endl;
		cout << "Return to main menu\n";
		menu();
	}

	while (!inFile.eof())
	{
		getline(inFile, prod_id_list[i]);
		getline(inFile, prod_name_list[i]);
		getline(inFile, prod_price_list[i]);
		getline(inFile, prod_quant_list[i]);
		i++;
	}
	inFile.close();

	int j = i;

	for (int z = 0; z < j; z++)
	{
		temp_id = stoi(prod_id_list[z]);
		R_prod_id_list[z] = temp_id;
		temp_name = prod_name_list[z];
		R_prod_name_list[z] = temp_name;
		temp_price = stod(prod_price_list[z]);
		R_prod_price_list[z] = temp_price;
		temp_quant = stoi(prod_quant_list[z]);
		R_prod_quant_list[z] = temp_quant;
	}

	system("cls");
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||\n";
	cout << "||| Products with INSUFFICIENT stock |||\n";
	cout << "||||||||||||||||||||||||||||||||||||||||\n";
	cout << endl;
	cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
	cout << "**********************************************************************" << endl;

	for (int z = 0; z < j; z++)
	{
		if (R_prod_quant_list[z] <= insuff_num)
		{
			cout << R_prod_id_list[z] << ".\t\t " << R_prod_name_list[z] << "\t\t ";
			cout << fixed << setprecision(2) << "RM" << R_prod_price_list[z] << "\t\t " << R_prod_quant_list[z] << endl;
			count += 1;
		}

	}

	if (count > 0)
	{
		cout << "\nPlease order the stock ASAP!!!\n";
	}

	else
		cout << "\nThe stock all is sufficient. :)\n";

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
