
#ifndef H_EMPLOYEE_H_
#define H_EMPLOYEE_H_
#pragma once
#include <iostream>
#include <set>
#include "../includes/Person.hpp"
#include "../includes/Department.hpp"
using namespace std;
class Department;

enum Role {CEO, DevMng, Lead, Dev, HR};
class Employee: public Person{
private:
	set <Department*> empDeps;
	int salary;
	Role role;
	int numOfDep = 0;
public:
	Employee(string empNm, int sal, Role rol);
	void setName(string nm);
	void setSalary(int sal);
	void setRole(Role rol);
	string getName();
	int getSalary();
	Role getRole();
	int getNumOfDep();
	void setNumOfDep(int num);
	void incEmp();

	void setEmpDep(Department* dep);
	set <Department*> getEmpDep();
	bool hasDep(Department* dep);
	void deleteDep(Department* dep);

	//Overloading operator
	bool operator== (const Employee& e) const;
	bool operator<(const Employee &emp) const ;

};

#endif




















