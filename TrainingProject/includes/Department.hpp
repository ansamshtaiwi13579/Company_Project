#ifndef H_DEPARTMENT_H_
#define H_DEPARTMENT_H_

#pragma once
#include <list>
#include "../includes/Employee.hpp"
#include "../includes/Company.hpp"
#include <iostream>
using namespace std;
class Employee;

class Department{
private:
	string name;
	set <Employee*> employees;
	set <Department*> subDepartments;
	int numOfDep = 0;
public:
	Department(string nm);
	void addEmployee(Employee* e);
	bool deleteEmployee(Employee* emp);
	void addSubDepartment(Department* d);
	void deleteSubDepartment(Department* d);
	set <Employee*> getEmployees();
	set <Department*> getSubDepartments();
	string getName();
	bool hasSubDep(Department* subDep);
	void setNumOfDep(int num);
	int getNumOfDep();
	bool hasEmp(Employee* emp);

	//Overloading operator
	bool operator== (const Department& d) const;
	bool operator<(const Department& d) const ;
};

#endif



















