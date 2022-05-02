#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <fstream>
using namespace std;
class Employee
{
public:
	Employee();
	Employee(std::string newName, int newID, std::string newAddress, double newSalary, int newYearsWorked);
	//accesors
	std::string get_name()const { return name; }
	int get_id_number()const { return id_number; }
	std::string get_address()const { return address; }
	double get_salary()const { return salary; }
	int get_years_started()const { return year_started; }
	void output(std::ostream& fout);
	void input(std::istream& fin);
private:
	std::string name;
	int id_number;
	std::string address;
	double salary;
	int year_started;
};
std::ostream& operator <<(std::ostream& fout, Employee& temp);
std::istream& operator >>(std::istream& fin, Employee& temp);
#endif

