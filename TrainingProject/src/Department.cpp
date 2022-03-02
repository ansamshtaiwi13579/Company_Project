
#include <list>
#include "../includes/Department.hpp"
#include <iostream>
using namespace std;

Department::Department(string nm){
	name = nm;
}
void Department::addEmployee(Employee* e){
	employees.insert(e);
}
bool Department::deleteEmployee(Employee* emp){
	if(emp == nullptr){
		cout<<"Employee is NULL"<<endl;
		return false;
	}

	auto findEmp = find(employees.begin(), employees.end(), emp);
	if(findEmp != employees.end()){
		employees.erase(emp);
		return true;
	}
	cout<<"Employee does not found"<<endl;
	return false;
}
void Department::addSubDepartment(Department* d){
	subDepartments.insert(d);
}
void Department::deleteSubDepartment(Department* dep){
	if(dep == nullptr){
		cout<<"Employee is NULL"<<endl;
		return;
	}

	auto findSubDep = find(subDepartments.begin(), subDepartments.end(), dep);
	if(findSubDep != subDepartments.end()){
		subDepartments.erase(dep);
		return;
	}
	cout<<"Employee does not found"<<endl;
	return;
}
set <Employee*> Department::getEmployees(){
	return employees;
}
set <Department*> Department::getSubDepartments(){
	return subDepartments;
}
string Department::getName(){
	return name;
}
bool Department::hasSubDep(Department* subDep){
	auto findSubDep = find(subDepartments.begin(), subDepartments.end(), subDep);
	if(findSubDep != subDepartments.end()){
		return true;
	}
	return false;
}

void Department::setNumOfDep(int num){
	numOfDep = num;
}

int Department::getNumOfDep(){
	return numOfDep;
}

bool Department::hasEmp(Employee* emp){
	auto findEmp = find(employees.begin(), employees.end(), emp);
	if(findEmp != employees.end()){
		return true;
	}
	return false;
}

//Overloading operator
bool Department::operator== (const Department& d) const{
	if(name == d.name){
		return true;
	}
	return false;
}

bool Department::operator<(const Department& d) const {
	return name<d.name;
}





















