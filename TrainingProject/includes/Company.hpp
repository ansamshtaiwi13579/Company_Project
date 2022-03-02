#ifndef H_COMPANY_H_
#define H_COMPANY_H_
#pragma once
#include <set>
#include <list>
#include <map>
#include <thread>
#include <algorithm>
#include "../includes/Department.hpp"
#include "../includes/Ceo.hpp"
#include <iostream>
using namespace std;
class Employee;
class Department;


class Company{
private:
	Company(){}
	Company(Ceo c, string name);
	set <Employee*> allEmps;
	set <Department*> allDeps;
	set <Department*> departments;
	string compName;
	Ceo ceo;
	static Company* company;
	map <int, set<Employee*>> hashMap;
	bool depLoop = false;
	int countOfLoops = 0;

public:
	static Company* getInstance(Ceo* c, string* com);
	string companyName();
	Ceo companyCEO();
	void setDepLoop(bool loop);
	bool getDepLoop();
	bool hasMainDep(Department* dep);
	set <Employee*> getAllEmps();
	set <Department*> getAllDeps();
	set <Department*> getMainDeps();
	map <int, set<Employee*>> getSalaryMap();
	void getDepEmps(set <Employee*> &emps, Department* dep);

	void addEmployee(Employee* emp, Department* dep);
	void deleteEmp(Employee* emp, Department* dep);
	void addDepartment(Department* dep);
	void addSubDep(Department* sub, Department* sup);
	void deleteDep(Department* subDep, Department* supDep);
	void deleteDep(Department* dep);
	void printAllEmps();



};

#endif






















