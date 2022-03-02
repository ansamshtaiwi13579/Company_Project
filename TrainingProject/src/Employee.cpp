#include <iostream>
#include "../includes/Employee.hpp"
using namespace std;


Employee::Employee(string empNm, int sal, Role rol){
	name = empNm;
	salary = sal;
	role = rol;
}
void Employee:: setName(string nm){
	name = nm;
}
void Employee::setSalary(int sal){
	salary = sal;
}
void Employee::setRole(Role rol){
	role = rol;
}
string Employee::getName(){
	return name;
}
int Employee::getSalary(){
	return salary;
}
Role Employee::getRole(){
	return role;
}
void Employee::incEmp(){
	numOfDep++;
}
int Employee::getNumOfDep(){
	return numOfDep;
}
void Employee::setNumOfDep(int num){
	numOfDep = num;
}
void Employee::setEmpDep(Department* dep){
	empDeps.insert(dep);
}
set <Department*> Employee::getEmpDep(){
	return empDeps;
}
bool Employee::hasDep(Department* dep){
	auto findDep = find(empDeps.begin(), empDeps.end(), dep);
	if(findDep != empDeps.end()){
		return true;
	}
	return false;
}
void Employee::deleteDep(Department* dep){
	empDeps.erase(dep);
}



//Overloading operator
bool Employee::operator== (const Employee& e) const{
	if(name==e.name){
		return true;
	}
	return false;
}

bool Employee::operator<(const Employee &emp) const {
	return name < emp.name;
}


















