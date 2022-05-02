#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
#include "database.h"
using namespace std;

int menu();
int main()
{
	Database database;
	Employee emp;
	string filename;
	cout << "Enter name of file (No file extension): ";
	getline(cin, filename);
	filename + ".txt";
	ifstream fin(filename.c_str());
	if(!fin.fail())
	{
		database.load(fin);
		fin.close();
		int choice;
		while(choice!=8)
		{
			choice = menu();
			switch (choice)
			{
				case 1:{
					cin >> emp;
					database.add(emp);
					break;
				}
				case 2:{
					system("cls");
					string name;
					cout << "Enter name of employee to find: ";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					database.search(name);
					break;
				}
				case 3:{
					system ("cls");
					int id;
					cout << "Enter Employee ID number: ";
					cin >> id;
					database.search_id(id);
					break;
				}
				case 4:{
					system("cls");
					cout << "All the employees in the database!" << endl;
					database.display_all();
					break;
				}
				case 5:{
					system("cls");
					string name;
					cout << "Enter employee that has been sacked: ";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					database.remove(name);
					break;
				}
				case 6:{
					system("cls");
					database.sort_salary();
					cout << "Employees sorted by salary." << endl;
					database.display_all();
					break;
				}
				case 7:{
					system("cls");
					database.sort_name();
					cout << "Employees sorted by first name." << endl; 
					database.display_all();
					break;
				}
				case 8:{
					break;
				}
				default:{
					system("cls");
					cout << "Not a valid input dummy!" << endl;
					break;
				}
			}
		}
		ofstream fout(filename.c_str());
		if(!fout.fail())
		{
			database.save(fout);
		}
		else{
			cout << "File could not open!" << endl;
		}
		fout.close();
		cout << "Thank you for using the ItalyHorse45 Database System! COME AGAIN SOON!" << endl;
	}
	else{
		cout << "File does not exist, creating new file!" << endl;
		ofstream new_file(filename.c_str());
		new_file.close();
		main();
	}
	return 0;
}
int menu()
{
	int choice;
	cout << "1. Add new_employee." << endl;
	cout << "2. Search for employee by name." << endl;
	cout << "3. Searh for employee by ID number." << endl;
	cout << "4. Display all current employees." << endl;
	cout << "5. Remove employee from database." << endl;
	cout << "6. Sort Employees by salary. (Richest first)" << endl;
	cout << "7. Sort Employees by First Name." << endl;
	cout << "8. Quit" << endl;
	cin >> choice;
	return choice;
}
