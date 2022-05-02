#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee()
{
	id_number = 0;
	salary = 0;
	year_started = 0;
}

Employee::Employee(std::string newName, int newID, std::string newAddress, double newSalary, int newYearsWorked)
{
	name = newName;
	id_number = newID;
	address = newAddress;
	salary = newSalary;
	year_started = newYearsWorked;
}

void Employee::output(ostream& fout)
{
	if (&fout == &cout)
	{
		fout << "Name: " << name << endl;
		fout << "ID number: " << id_number << endl;
		fout << "Address: " << address << endl;
		fout << "Salary: " << salary << endl;
		fout << "Years worked at company: " << year_started << endl;
	}
	else {
		fout << name << endl;
		fout << id_number << endl;
		fout << address << endl;
		fout << salary << endl;
		fout << year_started << endl;
	}
}

void Employee::input(istream& fin)
{
	if (&fin == &cin)
	{
		if (fin.peek() == '\n')fin.ignore();
		cout << "Name: ";
		getline(fin, name);
		cout << "Enter Id Number ";
		fin >> id_number;
		cout << "Enter address: ";
		if (fin.peek() == '\n')fin.ignore();
		getline(fin, address);
		cout << "Enter salary: ";
		fin >> salary;
		cout << "Enter the number of years the employee has worked for the company: ";
		fin >> year_started;
	}
	else {
		if (fin.peek() == '\n')fin.ignore();
		getline(fin, name);
		if (fin.peek() == '\n')fin.ignore();
		fin >> id_number;
		if (fin.peek() == '\n')fin.ignore();
		getline(fin, address);
		fin >> salary;
		fin >> year_started;
	}

}

ostream& operator <<(ostream& fout, Employee& temp)
{
	temp.output(fout);
	return fout;
}

istream& operator >>(istream& fin, Employee& temp)
{
	temp.input(fin);
	return fin;
}