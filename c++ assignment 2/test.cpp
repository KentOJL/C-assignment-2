#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <array>
#include <cstring>
#include <cctype>
#include <regex>
using namespace std;
const int MAX_PRODUCTS = 100;


int main()
{
	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	double temp_price, R_prod_price_list[MAX_PRODUCTS];
	int prod_id, i = 0;
	char con;
	bool del = true, ask = true;

	do
	{
		/*display_stock();*/
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
			/*stock_manage();*/
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
			/*stock_manage();*/
		}
		else
		{
			cout << "Error: file could not be opened for writing." << endl;
			cout << "Please go check the file and you will be return to stock management page.\n";
			/*stock_manage();*/
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
	return 0;
}

//std::array<int, 100> func()
//{
//	std::array<int, 100> f_array;
//
//		for (int i = 0; i < 100; i++)
//		{
//			f_array[i] = i;
//		}
//
//	return f_array;
//}
	//std::array<int, 100> arr;
	//arr = func();

	//cout << "the last num is: " << arr.back();
//
////Function to get ID
//std::array<int, 100> get_id()
//{
//	std::array<int, 100> f_array;
//	string prod_name_list[100];
//	std::array<double, 100> prod_price_list;
//	std::array<int, 100> prod_quant_list;
//
//	//	string prod_name_list[100];
////	static int prod_id_list[100], prod_quant_list[100];
////	double prod_price_list[100];
//
//	ifstream infile;
//	infile.open("stock.txt");
//
//	while (!infile.eof())
//	{
//		for (int i = 0; i < 100; i++)
//		{
//			infile >> f_array[i];
//			getline(infile, prod_name_list[i]);
//			infile >> prod_price_list[i];
//			infile >> prod_quant_list[i];
//		}
//	}
//	infile.close();
//	return std::array<int, 100> {f_array};
//	//for (int i = 0; i < 100; i++)
//	//{
//	//	f_array[i] = i;
//	//}
//	
//}
/*
int file_size()
{
	ifstream infile;
	infile.open("stock.txt");

	string a[1000];

	while (getline(infile , a[])
}
*/
//int main()
//{
	//string prod_name_list[100];
	//string prod_id_list[100], prod_quant_list[100];
	//string prod_price_list[100];

	//int temp_id, temp_quant, R_prod_id_list[100], R_prod_quant_list[100];
	//double temp_price, R_prod_price_list[100];

	//int new_prod_quant, new_prod_id;
	//int counter = 0, i = 0;
	//double new_prod_price = 0;
	//string new_prod_name;

	//bool boolean = true, con = true;
	//char cont_add;
	//while (boolean == true)
	//{
	//	cout << "\nPlease enter the new product name(In Capital Letter): ";
	//	cin >> new_prod_name;
	//	cout << "\nPLease enter the new product price: ";
	//	cin >> new_prod_price;
	//	cout << "\nPlease enter the new product quantity: ";
	//	cin >> new_prod_quant;


	//	//std::array<int, 100> arr;
	//	//int* ptr_id;// pointer to hold id array address
	///*	arr = get_id();
	//	new_prod_id = arr.back() + 1;*/

	//	fstream inFile;
	//	inFile.open("stock.txt", ios::in);
	//	if(inFile.is_open())
	//	{
	//		while (!inFile.eof())
	//		{
	//			getline(inFile, prod_id_list[i]);
	//			getline(inFile, prod_name_list[i]);
	//			getline(inFile, prod_price_list[i]);
	//			getline(inFile, prod_quant_list[i]);
	//			i++;
	//			counter++;
	//		}
	//	}
	//	else
	//		cout << "File not open" << endl;

	//	new_prod_id = counter + 1;
	//	inFile.close();

	//	for (int i = 0; i < counter; i++)
	//	{
	//		temp_id = stoi(prod_id_list[i]);
	//		R_prod_id_list[i] = temp_id;
	//		temp_price = stod(prod_price_list[i]);
	//		R_prod_price_list[i] = temp_price;
	//		temp_quant = stoi(prod_quant_list[i]);
	//		R_prod_quant_list[i] = temp_quant;
	//	}

	//	ofstream outFile;
	//	outFile.open("stock.txt", ios::app);
	//	outFile << endl;
	//	outFile << new_prod_id << endl;
	//	outFile << new_prod_name << endl;
	//	outFile << new_prod_price << endl;
	//	outFile << new_prod_quant;
	//	outFile.close();

	//	cout << "New Product is added." << endl;
	//	cout << "\n Do you want to continue(Y/N): \n";
	//	cin >> cont_add;

	//	while (toupper(cont_add) != 'Y' && toupper(cont_add) != 'N')
	//	{
	//		cout << "\nInvalid Input!!!\n";
	//		cout << "Please enter 'Y' or 'N' ONLY\n";
	//		cin >> cont_add;
	//	}

	//	//while (con == true)
	//	//{

	//	//	if (toupper(cont_add) != 'Y' && toupper(cont_add) != 'N')
	//	//	{
	//	//		cout << "\nInvalid Input!!!\n";
	//	//		cout << "Please enter 'Y' or 'N' ONLY\n";
	//	//		con = true;
	//	//	}

	//	//	else
	//	//		con = false;
	//	//}

	//	if (toupper(cont_add) == 'Y')
	//		boolean = true;

	//	else
	//		boolean = false;
	//}
	//cout << "\nreturn to menu\n";

//display function
	//ifstream inFile;
	//inFile.open("stock.txt");
	//string prod_name , prod_id, prod_quant , prod_price;
	//

	//cout << endl;
	//cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
	//cout << "**********************************************************************" << endl;

	//while (!inFile.eof())
	//{
	//	//inFile >> prod_id;
	//	//getline(inFile, prod_name);
	//	//inFile >> prod_price;
	//	//inFile >> prod_quant;
	//	getline(inFile, prod_id);
	//	getline(inFile, prod_name);
	//	getline(inFile, prod_price);
	//	getline(inFile, prod_quant);
	//	cout << "\n" << prod_id << ".\t\t " << prod_name << "\t\t ";
	//	cout << fixed << setprecision(2) << prod_price << "\t\t " << prod_quant << endl;
	//}

	//inFile.close();


//Old del product function
	//string prod_name_list[100] , prod_id_list[100] , prod_quant_list[100] , prod_price_list[100];
	////static int prod_id_list[100], prod_quant_list[100];
	////double prod_price_list[100];

	//int prod_id ,i = 0;
	//char con;
	//int temp_id, temp_quant, R_prod_id_list[100], R_prod_quant_list[100];
	//double temp_price, R_prod_price_list[100];
	////display_stock();
	//cout << "\nPlease enter the Product ID you want to DELETE: ";
	//cin >> prod_id;

	//fstream File;
	//File.open("stock.txt", ios::in | ios::out);

	////	File.open("stock.txt", ios::in);
	//if(File.is_open())
	//{
	//	while (!File.eof())
	//	{
	//		getline(File, prod_id_list[i]);
	//		getline(File, prod_name_list[i]);
	//		getline(File, prod_price_list[i]);
	//		getline(File, prod_quant_list[i]);
	//		i++;
	//	}
	//}
	//else
	//	cout << "File not open" << endl;

	//int j = sizeof(prod_id_list);

	//for (int z = 0; z < j; z++)
	//{
	//	temp_id = stoi(prod_id_list[z]);
	//	R_prod_id_list[z] = temp_id;
	//	temp_price = stod(prod_price_list[z]);
	//	R_prod_price_list[z] = temp_price;
	//	temp_quant = stoi(prod_quant_list[z]);
	//	R_prod_quant_list[z] = temp_quant;
	//}

	////std::array<int, 100> prod_id_list;
	////string prod_name_list[100];
	////std::array<double, 100> prod_price_list;
	////std::array<int, 100> prod_quant_list;

	////std::array<int, 100> arr;
	////arr = get_id();
	////int j = sizeof(arr);

	////while (!File.eof())
	////{
	////	for (int i = 0; i < 100; i++)
	////	{	
	////		File >> prod_id_list[i];
	////		getline(File, prod_name_list[i]);
	////		File >> prod_price_list[i];
	////		File >> prod_quant_list[i];
	////	}
	////	File.ignore();
	////}

	//if (prod_id > j || prod_id <= 0)
	//{
	//	cout << "\nSorry ther is no this ID in the inventory system. :(" << endl;
	//	//stock_manage();
	//	cout << "return to menu";
	//}

	//else
	//{
	//	cout << "Do you sure want to delete this Item(ID:" << prod_id << ") Y/N: ";
	//	cin >> con;

	//	if (toupper(con) == 'Y')
	//	{
	//		//while (!File.eof())
	//		//{
	//		//	for (int i = 0; i != prod_id - 1; i++)
	//		//	{
	//		//		File >> prod_id_list[i];
	//		//		getline(File, prod_name_list[i]);
	//		//		File >> prod_price_list[i];
	//		//		File >> prod_quant_list[i];
	//		//		continue;
	//		//	}
	//		//}

	//		for (int num = 0; num < j ; num++)
	//		{
	//			if (R_prod_id_list[num] > prod_id)
	//			{
	//				R_prod_id_list[num] = R_prod_id_list[num] - 1;
	//			}
	//		}

	//		for (int no = 0; no < j - 1; no++)
	//		{
	//			File << prod_id_list[no] << endl;
	//			File << prod_name_list[no] << endl;
	//			File << fixed << setprecision(2) << prod_price_list[no] << endl;
	//			File << prod_quant_list[no] << endl;
	//		}

	//	}

	//	else if (toupper(con) == 'N')
	//		//stock_manage();
	//		cout << "return to menu";

	//	else
	//	{
	//		cout << "\nInvalid Input!!! return back to stock management page.\n";
	//		//stock_manage();
	//	}

	//}


	//File.close();



////Old restock code
//	string prod_id_list[100], prod_name_list[100], prod_price_list[100], prod_quant_list[100];
//	int temp_id, temp_quant, R_prod_id_list[100], R_prod_quant_list[100];
//	string prod_name, temp_name, R_prod_name_list[100];
//	double temp_price, R_prod_price_list[100];
//
//	bool del = true, ask = true;
//	int restock_quant, prod_id , i = 0;
//	char con_restock;
//	/*display_stock();*/
//
//	fstream File;
//	File.open("stock.txt", ios::in | ios::out);
//
//	if (File.is_open())
//	{
//		while (!File.eof())
//		{
//			getline(File, prod_id_list[i]);
//			getline(File, prod_name_list[i]);
//			getline(File, prod_price_list[i]);
//			getline(File, prod_quant_list[i]);
//			i++;
//		}
//	}
//	else
//		cout << "File not open" << endl;
//		
//	int j = sizeof(prod_id_list) / sizeof(prod_id_list[0]);
//		
//	for (int z = 0; z < j; z++)
//	{
//		temp_id = stoi(prod_id_list[z]);
//		R_prod_id_list[z] = temp_id;
//		temp_name = prod_name_list[z];
//		R_prod_name_list[z] = temp_name;
//		temp_price = stod(prod_price_list[z]);
//		R_prod_price_list[z] = temp_price;
//		temp_quant = stoi(prod_quant_list[z]);
//		R_prod_quant_list[z] = temp_quant;
//	}
//		
//	File.close();
//
//	while (del == true)
//	{
//		cout << "\nPLease enter the product ID which you want to restock: ";
//		cin >> prod_id;
//		cout << "\nPlease enter the quantity of the product you want to restock: ";
//		cin >> restock_quant;
//
//		//std::array<int, 100> arr;
//		//arr = get_id();
//		//int j = sizeof(arr);
//
//		for (int z = 0; z < j; z++)
//		{
//			if (R_prod_id_list[z] == prod_id)
//			{
//				R_prod_quant_list[z] = R_prod_quant_list[z] + restock_quant;
//			}
//		}
//
//		File.open("stock.txt", ios::out | ios::trunc);
//		
//		if (File.is_open())
//		{
//			for (int z = 0; z < j ; z++)
//			{
//				temp_name = R_prod_name_list[z];
//				File << R_prod_id_list[z] << endl;
//				File << temp_name << endl;
//				File << fixed << setprecision(2) << R_prod_price_list[z] << endl;
//				File << R_prod_quant_list[z] << endl;
//			}
//			File.close();
//			cout << "Stock of Product " << prod_id << " has been restock successfully." << endl;
//		}
//		else
//		{
//			cout << "Error: file could not be opened for writing." << endl;
//		}
//
//		while (ask == true)
//		{
//			cout << "Do you want to continue restock?(Y/N): ";
//			cin >> con_restock;
//
//			if (toupper(con_restock) != 'Y' || toupper(con_restock) != 'N')
//			{
//				cout << "\nPlease enter Y and N ONLY";
//				ask = true;
//			}
//
//			else
//				ask = false;
//		}
//
//		if (toupper(con_restock) == 'Y')
//			del = true;
//
//		else
//			del = false;
//	}
	//string prod_name_list[100];
	//static int prod_id_list[100], prod_quant_list[100];
	//double prod_price_list[100];
	//bool j = true, ask = true;
	//char con_name;
	//int prod_id;
	//display_stock();
	//fstream File;
	//File.open("stock.txt", ios::in | ios::out);
	//std::array<int, 100> arr;
	//arr = get_id();
	//int z = sizeof(arr);

//rename function
	//string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
	//int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
	//string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
	//double temp_price, R_prod_price_list[MAX_PRODUCTS];

	//bool rename = true, ask = true;
	//int prod_id, i = 0;
	//char con_name;
	//string new_name;
	//ifstream inFile;
	//ofstream outFile;
	//inFile.open("stock.txt");
	//if (inFile.fail())
	//{
	//	cout << "Error: file could not be opened for reading." << endl;
	//	return 0;
	//}

	//while (!inFile.eof())
	//{
	//	getline(inFile, prod_id_list[i]);
	//	getline(inFile, prod_name_list[i]);
	//	getline(inFile, prod_price_list[i]);
	//	getline(inFile, prod_quant_list[i]);
	//	i++;
	//}
	//inFile.close();

	//int j = i;

	//for (int z = 0; z < j; z++)
	//{
	//	temp_id = stoi(prod_id_list[z]);
	//	R_prod_id_list[z] = temp_id;
	//	temp_name = prod_name_list[z];
	//	R_prod_name_list[z] = temp_name;
	//	temp_price = stod(prod_price_list[z]);
	//	R_prod_price_list[z] = temp_price;
	//	temp_quant = stoi(prod_quant_list[z]);
	//	R_prod_quant_list[z] = temp_quant;
	//}


	//while (rename == true)
	//{
	//	cout << "\nPLease enter the product ID which you want to change its name: ";
	//	cin >> prod_id;
	//	cout << "\nPlease enter the new name(Capital Letter ONLY): ";
	//	cin.ignore();
	//	getline(cin, new_name);

	//	for (int z = 0; z < j; z++)
	//	{
	//		if (R_prod_id_list[z] == prod_id)
	//		{
	//			R_prod_name_list[z] = new_name;
	//		}
	//	}

	//	outFile.open("stock.txt");
	//	if (outFile.fail())
	//	{
	//		cout << "Error: file could not be opened for writing." << endl;
	//		return 0;
	//	}

	//	for (int z = 0; z < j; z++)
	//	{
	//		temp_name = R_prod_name_list[z];
	//		outFile << R_prod_id_list[z] << endl;
	//		outFile << temp_name << endl;
	//		outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
	//		if (z == j - 1) {
	//			outFile << R_prod_quant_list[z];
	//		}
	//		else {
	//			outFile << R_prod_quant_list[z] << endl;
	//		}
	//	}
	//	outFile.close();
	//	cout << "Name of Product " << prod_id << " has been rename successfully." << endl;

	//	while (ask == true)
	//	{
	//		cout << "Do you want to continue restocking? (Y/N): ";
	//		cin >> con_name;
	//		
	//		if (toupper(con_name) != 'Y' && toupper(con_name) != 'N')
	//		{
	//			cout << "\nPlease enter Y and N ONLY" << endl;
	//			ask = true;
	//		}
	//		else
	//		{
	//			ask = false;
	//		}
	//	}
	//		
	//	if (toupper(con_name) == 'Y')
	//	{
	//		rename = true;
	//	}
	//	else
	//		rename = false;
	//}

	////menu();

////update cost function
//	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
//	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
//	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
//	double temp_price, R_prod_price_list[MAX_PRODUCTS];
//
//	bool cost = true, ask = true;
//	char con_price;
//	int prod_id , i = 0;
//	double new_price;
//	//display_stock();
//
//	ifstream inFile;
//	ofstream outFile;
//	inFile.open("stock.txt");
//	if (inFile.fail())
//	{
//		cout << "Error: file could not be opened for reading." << endl;
//		cout << "Return to main menu\n";
//		/*menu();*/
//	}
//
//	while (!inFile.eof())
//	{
//		getline(inFile, prod_id_list[i]);
//		getline(inFile, prod_name_list[i]);
//		getline(inFile, prod_price_list[i]);
//		getline(inFile, prod_quant_list[i]);
//		i++;
//	}
//	inFile.close();
//
//	int j = i;
//
//	for (int z = 0; z < j; z++)
//	{
//		temp_id = stoi(prod_id_list[z]);
//		R_prod_id_list[z] = temp_id;
//		temp_name = prod_name_list[z];
//		R_prod_name_list[z] = temp_name;
//		temp_price = stod(prod_price_list[z]);
//		R_prod_price_list[z] = temp_price;
//		temp_quant = stoi(prod_quant_list[z]);
//		R_prod_quant_list[z] = temp_quant;
//	}
//
//
//	while (cost == true)
//	{
//		cout << "\nPLease enter the product ID which you want to change its cost: ";
//		cin >> prod_id;
//		cout << "\nPlease enter the new cost: RM";
//		cin >> new_price;
//
//
//		for (int z = 0; z < j; z++)
//		{
//			if (R_prod_id_list[z] == prod_id)
//			{
//				R_prod_price_list[z] = new_price;
//			}
//		}
//
//		outFile.open("stock.txt");
//		if (outFile.fail())
//		{
//			cout << "Error: file could not be opened for writing." << endl;
//			/*menu();*/
//		}
//
//		for (int z = 0; z < j; z++)
//		{
//			temp_name = R_prod_name_list[z];
//			outFile << R_prod_id_list[z] << endl;
//			outFile << temp_name << endl;
//			outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
//			if (z == j - 1) {
//				outFile << R_prod_quant_list[z];
//			}
//			else {
//				outFile << R_prod_quant_list[z] << endl;
//			}
//		}
//		outFile.close();
//		cout << "New cost of Product " << prod_id << " has been updated successfully." << endl;
//
//		while (ask = true)
//		{
//			cout << "Do you want to continue update new cost?(Y/N): ";
//			cin >> con_price;
//
//			if (toupper(con_price) != 'Y' && toupper(con_price) != 'N')
//			{
//				cout << "\nPlease enter Y and N ONLY" << endl;
//				ask = true;
//			}
//
//			else
//				ask = false;
//		}
//
//		if (toupper(con_price) == 'Y')
//			cost = true;
//
//		else
//			cost = false;
//	}

////check out function
//	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
//	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
//	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
//	double temp_price, R_prod_price_list[MAX_PRODUCTS];
//
//	bool del = true, ask = true;
//	int stock_quant, prod_id, i = 0;
//	char con_out;
//	//display_stock();
//
//	ifstream inFile;
//	ofstream outFile;
//	inFile.open("stock.txt");
//	if (inFile.fail())
//	{
//		cout << "Error: file could not be opened for reading." << endl;
//		cout << "Return to main menu\n";
//		/*menu();*/
//	}
//
//	while (!inFile.eof())
//	{
//		getline(inFile, prod_id_list[i]);
//		getline(inFile, prod_name_list[i]);
//		getline(inFile, prod_price_list[i]);
//		getline(inFile, prod_quant_list[i]);
//		i++;
//	}
//	inFile.close();
//
//	int j = i;
//
//	for (int z = 0; z < j; z++)
//	{
//		temp_id = stoi(prod_id_list[z]);
//		R_prod_id_list[z] = temp_id;
//		temp_name = prod_name_list[z];
//		R_prod_name_list[z] = temp_name;
//		temp_price = stod(prod_price_list[z]);
//		R_prod_price_list[z] = temp_price;
//		temp_quant = stoi(prod_quant_list[z]);
//		R_prod_quant_list[z] = temp_quant;
//	}
//	while (del == true)
//	{
//		cout << "\nPLease enter the product ID which you want to check out: ";
//		cin >> prod_id;
//		cout << "\nPlease enter the quantity of the product you want to check out: ";
//		cin >> stock_quant;
//
//		bool valid_input = false;
//
//		// loop through the product list to find the matching product id
//		for (int z = 0; z < j; z++)
//		{
//			if (R_prod_id_list[z] == prod_id)
//			{
//				if (R_prod_quant_list[z] >= stock_quant)
//				{
//					R_prod_quant_list[z] = R_prod_quant_list[z] - stock_quant;
//					valid_input = true; // set valid_input to true if the input is valid
//				}
//				else
//				{
//					cout << "Sorry you can only check out " << R_prod_quant_list[z] << " of the stock.";
//					break; // break out of the loop if the input is invalid
//				}
//			}
//		}
//
//		if (valid_input) // if the input is valid, write to the file and ask if the user wants to continue
//		{
//			// write the updated stock to the file
//			outFile.open("stock.txt");
//			if (outFile.fail())
//			{
//				cout << "Error: file could not be opened for writing." << endl;
//				cout << "Please go check the file and you will be return to stock management page.\n";
//				/*stock_manage();*/
//			}
//
//			for (int z = 0; z < j; z++)
//			{
//				temp_name = R_prod_name_list[z];
//				outFile << R_prod_id_list[z] << endl;
//				outFile << temp_name << endl;
//				outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
//				if (z == j - 1) {
//					outFile << R_prod_quant_list[z];
//				}
//				else {
//					outFile << R_prod_quant_list[z] << endl;
//				}
//				cout << "\nThe new quantity of the stock is updated.\n";
//			}
//
//			outFile.close();
//			cout << "Stock of Product " << prod_id << " has been check out successfully." << endl;
//
//			while (ask = true)
//			{
//				cout << "Do you want to continue to check out the stock?(Y/N): ";
//				cin >> con_out;
//
//				if (toupper(con_out) != 'Y' && toupper(con_out) != 'N')
//				{
//					cout << "\nPlease enter Y and N ONLY" << endl;
//					ask = true;
//				}
//
//				else
//					ask = false;
//			}
//
//			if (toupper(con_out) == 'Y')
//				del = true;
//
//			else
//				del = false;
//		}
//		// if the input is invalid, loop back to the question part to ask again
//		else
//		{
//			cout << "\nInvalid input. Please try again.\n";
//		}
//	}
//
//	char yes;
//	cout << " Press Any Key to return to menu\n";
//	cin >> yes;
//	system("cls");
//
//	return 0;
//}
//
//void display_stock()
//{
//	ifstream inFile;
//	inFile.open("stock.txt");
//	int prod_id, prod_quant;
//	string prod_name;
//	double prod_price;
//
//	cout << endl;
//	cout << "ID\t\t Name\t\t Cost\t\t Quantity\n";
//	cout << '*' * 50 << endl;
//
//	while (!inFile.eof())
//	{
//		inFile >> prod_id;
//		getline(inFile, prod_name);
//		inFile >> prod_price;
//		inFile >> prod_quant;
//		cout << "\n" << prod_id << ".\t\t " << prod_name << "\t\t ";
//		cout << fixed << setprecision(2) << prod_price << "\t\t " << prod_quant << endl;
//	}
//
//	inFile.close();
//}

//void delete_product();
//void delete_product()
//{
//	string prod_id_list[100], prod_name_list[100], prod_price_list[100], prod_quant_list[100];
//	int prod_id, i = 0;
//	char con;
//	int temp_id, temp_quant, R_prod_id_list[100], R_prod_quant_list[100];
//	string prod_name, temp_name, R_prod_name_list[100];
//	double temp_price, R_prod_price_list[100];
//
//	//display_stock();
//	cout << "\nPlease enter the Product ID you want to DELETE: ";
//	cin >> prod_id;
//
//	fstream File;
//	File.open("stock.txt", ios::in | ios::out);
//
//	if (File.is_open())
//	{
//		while (!File.eof())
//		{
//			getline(File, prod_id_list[i]);
//			getline(File, prod_name_list[i]);
//			getline(File, prod_price_list[i]);
//			getline(File, prod_quant_list[i]);
//			i++;
//		}
//	}
//	else
//		cout << "File not open" << endl;
//
//	int j = sizeof(prod_id_list) / sizeof(prod_id_list[0]);
//
//	for (int z = 0; z < j; z++)
//	{
//		temp_id = stoi(prod_id_list[z]);
//		R_prod_id_list[z] = temp_id;
//		temp_name = prod_name_list[z];
//		R_prod_name_list[z] = temp_name;
//		temp_price = stod(prod_price_list[z]);
//		R_prod_price_list[z] = temp_price;
//		temp_quant = stoi(prod_quant_list[z]);
//		R_prod_quant_list[z] = temp_quant;
//	}
//
//	File.close();
//
//	// Deleting the product from the arrays
//	int del_index = -1;
//	for (int z = 0; z < j; z++)
//	{
//		if (R_prod_id_list[z] == prod_id)
//		{
//			del_index = z;
//			break;
//		}
//	}
//
//	if (del_index == -1)
//	{
//		cout << "Product not found!" << endl;
//	}
//
//	for (int z = del_index; z < j - 1; z++)
//	{
//		R_prod_id_list[z] = R_prod_id_list[z + 1];
//		R_prod_name_list[z] = R_prod_name_list[z + 1];
//		R_prod_price_list[z] = R_prod_price_list[z + 1];
//		R_prod_quant_list[z] = R_prod_quant_list[z + 1];
//	}
//
//	// Writing the updated stock to the file
//	File.open("stock.txt", ios::out | ios::trunc);
//
//	if (File.is_open())
//	{
//		for (int z = 0; z < j - 1; z++)
//		{
//			temp_name = R_prod_name_list[z];
//			File << R_prod_id_list[z] << endl;
//			File << temp_name << endl;
//			File << fixed << setprecision(2) << R_prod_price_list[z] << endl;
//			File << R_prod_quant_list[z] << endl;
//		}
//		File.close();
//		cout << "Product " << prod_id << " deleted successfully." << endl;
//	}
//	else
//	{
//		cout << "Error: file could not be opened for writing." << endl;
//	}
//}

//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string prod_id_list[100], prod_name_list[100], prod_price_list[100], prod_quant_list[100];
//	int prod_id, i = 0;
//	char con;
//	int temp_id, temp_quant, R_prod_id_list[100], R_prod_quant_list[100];
//	string prod_name, temp_name, R_prod_name_list[100];
//	double temp_price, R_prod_price_list[100];
//
//	//display_stock();
//	cout << "\nPlease enter the Product ID you want to DELETE: ";
//	cin >> prod_id;
//
//	fstream File;
//	File.open("stock.txt", ios::in | ios::out);
//
//	if (File.is_open())
//	{
//		while (!File.eof())
//		{
//			getline(File, prod_id_list[i]);
//			getline(File, prod_name_list[i]);
//			getline(File, prod_price_list[i]);
//			getline(File, prod_quant_list[i]);
//			i++;
//		}
//	}
//	else
//		cout << "File not open" << endl;
//
//	int j = sizeof(prod_id_list) / sizeof(prod_id_list[0]);
//
//	for (int z = 0; z < j; z++)
//	{
//		temp_id = stoi(prod_id_list[z]);
//		R_prod_id_list[z] = temp_id;
//		temp_name = prod_name_list[z];
//		R_prod_name_list[z] = temp_name;
//		temp_price = stod(prod_price_list[z]);
//		R_prod_price_list[z] = temp_price;
//		temp_quant = stoi(prod_quant_list[z]);
//		R_prod_quant_list[z] = temp_quant;
//	}
//
//	File.close();
//
//	// Deleting the product from the arrays
//	int del_index = -1;
//	for (int z = 0; z < j; z++)
//	{
//		if (R_prod_id_list[z] == prod_id)
//		{
//			del_index = z;
//			break;
//		}
//	}
//
//	if (del_index == -1)
//	{
//		cout << "Product not found!" << endl;
//		return 0;
//	}
//
//	for (int z = del_index; z < j - 1; z++)
//	{
//		R_prod_id_list[z] = R_prod_id_list[z + 1];
//		R_prod_name_list[z] = R_prod_name_list[z + 1];
//		R_prod_price_list[z] = R_prod_price_list[z + 1];
//		R_prod_quant_list[z] = R_prod_quant_list[z + 1];
//	}
//
//	// Writing the updated stock to the file
//	File.open("stock.txt", ios::out | ios::trunc);
//
//	if (File.is_open())
//	{
		//for (int z = 0; z < j - 1; z++)
		//{
		//	temp_name = R_prod_name_list[z];
		//	File << R_prod_id_list[z] << endl;
		//	File << temp_name << endl;
		//	File << fixed << setprecision(2) << R_prod_price_list[z] << endl;
		//	if (z == j - 2) 
		//	{
		//		File << R_prod_quant_list[z];
		//	}
		//	else 
		//	{
		//		File << R_prod_quant_list[z] << endl;
		//	}
		//}
//		File.close();
//		cout << "Product " << prod_id << " deleted successfully." << endl;
//	}
//	else
//	{
//		cout << "Error: file could not be opened for writing." << endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <string>
//
//using namespace std;
//
//const int MAX_PRODUCTS = 100;
//
//int main()
//{
//	string prod_id_list[MAX_PRODUCTS], prod_name_list[MAX_PRODUCTS], prod_price_list[MAX_PRODUCTS], prod_quant_list[MAX_PRODUCTS];
//	int temp_id, temp_quant, R_prod_id_list[MAX_PRODUCTS], R_prod_quant_list[MAX_PRODUCTS];
//	string prod_name, temp_name, R_prod_name_list[MAX_PRODUCTS];
//	double temp_price, R_prod_price_list[MAX_PRODUCTS];
//
//	bool del = true, ask = true;
//	int restock_quant, prod_id, i = 0;
//	char con_restock;
//
//	ifstream inFile;
//	ofstream outFile;
//	inFile.open("stock.txt");
//	if (inFile.fail())
//	{
//		cout << "Error: file could not be opened for reading." << endl;
//		return 0;
//	}
//
//	while (!inFile.eof())
//	{
//		getline(inFile, prod_id_list[i]);
//		getline(inFile, prod_name_list[i]);
//		getline(inFile, prod_price_list[i]);
//		getline(inFile, prod_quant_list[i]);
//		i++;
//	}
//	inFile.close();
//
//	int j = i;
//
//	for (int z = 0; z < j; z++)
//	{
//		temp_id = stoi(prod_id_list[z]);
//		R_prod_id_list[z] = temp_id;
//		temp_name = prod_name_list[z];
//		R_prod_name_list[z] = temp_name;
//		temp_price = stod(prod_price_list[z]);
//		R_prod_price_list[z] = temp_price;
//		temp_quant = stoi(prod_quant_list[z]);
//		R_prod_quant_list[z] = temp_quant;
//	}
//
//	while (del == true)
//	{
//		cout << "\nPlease enter the product ID which you want to restock: ";
//		cin >> prod_id;
//		cout << "\nPlease enter the quantity of the product you want to restock: ";
//		cin >> restock_quant;
//
//		for (int z = 0; z < j; z++)
//		{
//			if (R_prod_id_list[z] == prod_id)
//			{
//				R_prod_quant_list[z] = R_prod_quant_list[z] + restock_quant;
//			}
//		}
//
//		outFile.open("stock.txt");
//		if (outFile.fail())
//		{
//			cout << "Error: file could not be opened for writing." << endl;
//			return 0;
//		}
//
//		for (int z = 0; z < j; z++)
//		{
//			temp_name = R_prod_name_list[z];
//			outFile << R_prod_id_list[z] << endl;
//			outFile << temp_name << endl;
//			outFile << fixed << setprecision(2) << R_prod_price_list[z] << endl;
//			if (z == j - 1) {
//				outFile << R_prod_quant_list[z];
//			}
//			else {
//				outFile << R_prod_quant_list[z] << endl;
//			}
//		}
//		outFile.close();
//		cout << "Stock of Product " << prod_id << " has been restocked successfully." << endl;
//
//		while (ask == true)
//		{
//			cout << "Do you want to continue restocking? (Y/N): ";
//			cin >> con_restock;
//
//			if (toupper(con_restock) != 'Y' && toupper(con_restock) != 'N')
//			{
//				cout << "\nPlease enter Y and N ONLY" << endl;
//				ask = true;
//			}
//			else
//			{
//				ask = false;
//			}
//		}
//
//		if (toupper(con_restock) == 'Y')
//		{
//			del = true;
//		}
//		else
//			del = false;
//	}
//	return 0;
//} 



