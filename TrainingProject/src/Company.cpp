

#include "../includes/Company.hpp"
#include <iostream>
using namespace std;



Company::Company(Ceo c, string name){ ceo = c; compName = name; }
string Company::companyName(){
	return compName;
}
Ceo Company::companyCEO(){
	return ceo;
}

void Company::setDepLoop(bool loop){
	depLoop = loop;
}

bool Company::getDepLoop(){
	return depLoop;
}

bool Company::hasMainDep(Department* dep){
	auto findDep = find(departments.begin(), departments.end(), dep);
	if(findDep != departments.end()){
		return true;
	}
	return false;
}

set <Employee*> Company::getAllEmps(){
	return allEmps;
}

set <Department*> Company::getAllDeps(){
	return allDeps;
}

set <Department*> Company::getMainDeps(){
	return departments;
}

map <int, set<Employee*>> Company::getSalaryMap(){
	return hashMap;
}

void Company::getDepEmps(set <Employee*> &emps, Department* dep){
//	emps.
//	for(Department* subDep: dep->getSubDepartments()){
//
//	}
}


void Company::addEmployee(Employee* emp, Department* dep){

	if(emp == nullptr){//1
		return;
	}

	if(dep != nullptr){
		if(emp->hasDep(dep)){//2
			cout<<emp->getName()<<" is already in "<<dep->getName()<<endl;
			return;
		}
		else{//3
			emp->incEmp();
			emp->setEmpDep(dep);
			dep->addEmployee(emp);
		}
	}//4

	allEmps.insert(emp);

	int sal = emp->getSalary();//5
	if(hashMap.count(sal)==0){
		set<Employee*> hashSet;
		hashSet.insert(emp);
		hashMap[sal] =hashSet;
	}
	else{
		hashMap.at(sal).insert(emp);
	}

}



void Company::deleteEmp(Employee* emp, Department* dep){
	if(emp==nullptr){//1
		cout<<"Null Pointer"<<endl;
		return;
	}

	if(emp->getNumOfDep()==0 && dep==nullptr){//2
		allEmps.erase(emp);
		int sal = emp->getSalary();
		hashMap.at(sal).erase(emp);
		return;
	}

	if(dep==nullptr){//3
		cout<<"Null Pointer"<<endl;
		return;
	}

	if(dep->deleteEmployee(emp)){//4
		int num = emp->getNumOfDep();
		if(num >=1){
			emp->setNumOfDep(num-1);
			emp->deleteDep(dep);
		}
		if(num==1){//5
			allEmps.erase(emp);
			int sal = emp->getSalary();
			hashMap.at(sal).erase(emp);
		}
	}//6
	return;
}

void Company::addDepartment(Department* dep){
	if(dep == nullptr){//1
		return;
	}
	auto fd = find(allDeps.begin(), allDeps.end(), dep);
	if(fd!=allDeps.end()){//2
		depLoop = true;
	}//3

	int num = dep->getNumOfDep();
	dep->setNumOfDep(num+1);
	departments.insert(dep);
	allDeps.insert(dep);
}


void Company::addSubDep(Department* sub, Department* sup){

	if(sub==nullptr || sup==nullptr){//1
		return;
	}
	if(sup->hasSubDep(sub)){//2
		cout<<"Sub department "<<sub->getName()<<" is already found in Department "<<sup->getName()<<endl;
		return;
	}
	else{//3
		auto fd = find(allDeps.begin(), allDeps.end(), sub);
		if(fd!=allDeps.end()){
			depLoop = true;
			countOfLoops++;
		}//4
		int num = sub->getNumOfDep();
		sub->setNumOfDep(num+1);
		sup->addSubDepartment(sub);
		allDeps.insert(sub);
	}

}


void Company::deleteDep(Department* subDep, Department* supDep){
	if(subDep==nullptr || supDep==nullptr){//1
		cout<<"Null Dep"<<endl;
		return;
	}
		if(!supDep->hasSubDep(subDep)){//2
			cout<<"Department does not found in Super"<<endl;
			return;
		}
		int num;
		num = subDep->getNumOfDep();

		if(num >=1){//3
			subDep->setNumOfDep(num-1);
			supDep->deleteSubDepartment(subDep);
			cout<<subDep->getName()<<" is deleted from "<<supDep->getName()<<endl;
		}
		if(num>1){
			countOfLoops--;
			if(countOfLoops==0){
				depLoop = false;
			}
		}
		if(num==1){//4
			set <Employee*> empSet = subDep->getEmployees();

			for(Employee* e: empSet){
				cout<<e->getName()<<endl;
				deleteEmp(e, subDep);
			}
		}

		for(Department* sub: subDep->getSubDepartments()){
			cout<<endl;
			deleteDep(sub, subDep);
		}
		if(num > 1){
			return;
		}
		allDeps.erase(subDep);
		return;


}

void Company::deleteDep(Department* dep){
	if(dep == nullptr){
		return;
	}

	auto findDep = find(departments.begin(), departments.end(), dep);
	if(findDep == departments.end()){
		return;
	}

	int num;
	num = dep->getNumOfDep();

	if(num >=1){//3
		dep->setNumOfDep(num-1);
		departments.erase(dep);
		cout<<dep->getName()<<" is deleted"<<endl;
	}
	if(num>1){
		countOfLoops--;
		if(countOfLoops==0){
			depLoop = false;
		}
	}
	if(num==1){//4
		set <Employee*> empSet = dep->getEmployees();

		for(Employee* e: empSet){
			cout<<e->getName()<<endl;
			deleteEmp(e, dep);
		}
	}

	for(Department* sub: dep->getSubDepartments()){
		cout<<endl;
		deleteDep(sub, dep);
	}
	if(num > 1){
		return;
	}
	allDeps.erase(dep);
	return;
}




void Company::printAllEmps(){
	cout<<endl<<"All Employees : ";
	for(Employee* i: allEmps){
		cout<<i->getName()<<","<<i->getNumOfDep()<<","<<i->getSalary()<<"  ";
	}
	cout<<endl<<"Multiple Department Employees : ";
	for(Employee* i: allEmps){
		if(i->getNumOfDep()>1){
			cout<<i->getName()<<" ";
		}
	}
	cout<<endl<<"Employees as Salary : ";
	for(auto k: hashMap){
		cout<<endl;
		cout<<k.first<<" : ";
		set<Employee*> soe = k.second;
		for(Employee* e : soe){
			cout<<e->getName()<<" ";
		}
	}
	cout<<endl<<"All Departments : ";
	for(Department* i: allDeps){
		cout<<i->getName()<<","<<i->getNumOfDep()<<" ";
	}
	cout<<endl<<"Department loop : ";
	if(depLoop){
		cout<<"is found";
	}
	else{
		cout<<"is not found";
	}
	cout<<endl<<"Floating Employees : ";
	for(Employee* e: allEmps){
		if(e->getNumOfDep()==0){
			cout<<e->getName()<<" ";
		}
	}

	cout<<endl;
}

Company* Company::company = nullptr;
Company* Company::getInstance (Ceo* ceo, string* com){
	if(company == nullptr){
		company = new Company(*ceo, *com);
	}
	return company;
}


















