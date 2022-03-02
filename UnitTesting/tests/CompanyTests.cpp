/*
 * CompanyTests.cpp
 *
 *  Created on: 16 Feb 2022
 *      Author: user
 */

#include "gtest/gtest.h"
#include "Company.hpp"


  class CompanyTest : public ::testing::Test {};
	Ceo ceo("Tareq"); string com = "Exalt";
	 Company *company = Company::getInstance(&ceo, &com);

  TEST_F(CompanyTest, CheckCompanyName) {
	  ASSERT_EQ("Exalt",company->companyName());
  }

  TEST_F(CompanyTest, CheckCeoName) {
  	  ASSERT_EQ("Tareq",company->companyCEO().name);
  }

  Employee employee1("e1", 1000, HR);
  Employee employee2("e2", 2000, Dev);
  Employee employee3("e3", 3000, DevMng);
  Employee employee4("e4", 1000, HR);
  Employee employee5("e5", 2000, Dev);
  Employee employee6("e6", 3000, DevMng);
  Employee employee7("e7", 4000, Lead);
  Employee floatEmp("float", 1500, Dev);

  Department dep1("d1");
  Department dep2("d2");

  Department dep11("d11");
  Department dep12("d12");
  Department dep21("d21");
  Department dep111("d111");

  set <Employee*> allEmployees;
  set <Department*> alldepartments;
  set <Department*> mainDepartments;
  map <int, set<Employee*>> salaryMap;

  bool depLoop = false;

  TEST_F(CompanyTest, AddEmployee) {
  	ASSERT_EQ(allEmployees, company->getAllEmps());

  	company->addEmployee(&employee1, &dep1);//3 normal insertion
  	allEmployees.insert(&employee1);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee1.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(1000));
  	ASSERT_EQ(1, (int)company->getSalaryMap().at(1000).size());
  	ASSERT_TRUE(employee1.hasDep(&dep1));
  	ASSERT_TRUE(dep1.hasEmp(&employee1));

  	company->addEmployee(&employee1, &dep1);//2 insert subDep that found in the super
  	ASSERT_EQ(allEmployees, company->getAllEmps());

  	company->addEmployee(nullptr, &dep1);//1 null Employee
  	ASSERT_EQ(allEmployees, company->getAllEmps());

  	company->addEmployee(&floatEmp, nullptr);//4 null department ==> float Employee
  	allEmployees.insert(&floatEmp);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(0, floatEmp.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(1500));
  	ASSERT_EQ(1, (int)company->getSalaryMap().at(1500).size());

  	company->addEmployee(&employee2, &dep2);
  	allEmployees.insert(&employee2);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee2.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(2000));
  	ASSERT_EQ(1, (int)company->getSalaryMap().at(2000).size());
  	ASSERT_TRUE(employee2.hasDep(&dep2));
  	ASSERT_TRUE(dep2.hasEmp(&employee2));

  	company->addEmployee(&employee3, &dep12);
  	allEmployees.insert(&employee3);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee3.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(3000));
  	ASSERT_EQ(1, (int)company->getSalaryMap().at(3000).size());
  	ASSERT_TRUE(employee3.hasDep(&dep12));
  	ASSERT_TRUE(dep12.hasEmp(&employee3));

  	company->addEmployee(&employee1, &dep12);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(2, employee1.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(1000));
  	ASSERT_EQ(1, (int)company->getSalaryMap().at(1000).size());
  	ASSERT_TRUE(employee1.hasDep(&dep12) && employee1.hasDep(&dep1));
  	ASSERT_TRUE(dep12.hasEmp(&employee1));

  	company->addEmployee(&employee4, &dep21);
  	allEmployees.insert(&employee4);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee4.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(1000));// the count function returns 0 or 1 only!
  	ASSERT_EQ(2, (int)company->getSalaryMap().at(1000).size());
  	ASSERT_TRUE(employee4.hasDep(&dep21));
  	ASSERT_TRUE(dep21.hasEmp(&employee4));

  	company->addEmployee(&employee5, &dep21);
  	allEmployees.insert(&employee5);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee5.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(2000));
  	ASSERT_EQ(2, (int)company->getSalaryMap().at(2000).size());
  	ASSERT_TRUE(employee5.hasDep(&dep21));
  	ASSERT_TRUE(dep21.hasEmp(&employee5));

  	company->addEmployee(&employee6, &dep111);
  	allEmployees.insert(&employee6);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee6.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(3000));
  	ASSERT_EQ(2, (int)company->getSalaryMap().at(3000).size());
  	ASSERT_TRUE(employee6.hasDep(&dep111));
  	ASSERT_TRUE(dep111.hasEmp(&employee6));

  	company->addEmployee(&employee7, &dep1);
  	allEmployees.insert(&employee7);
  	ASSERT_EQ(allEmployees, company->getAllEmps());
  	ASSERT_EQ(1, employee7.getNumOfDep());
  	ASSERT_EQ(1, (int)company->getSalaryMap().count(4000));
  	ASSERT_EQ(1, (int)company->getSalaryMap().at(4000).size());
  	ASSERT_TRUE(employee7.hasDep(&dep1));
  	ASSERT_TRUE(dep1.hasEmp(&employee7));

  }



  TEST_F(CompanyTest, AddMainDepartment) {
	  company->addDepartment(nullptr); //1 null department

	  company->addDepartment(&dep1);//3 normal department insertion
	  alldepartments.insert(&dep1);
	  mainDepartments.insert(&dep1);
	  ASSERT_EQ(1, dep1.getNumOfDep());
	  ASSERT_TRUE(company->hasMainDep(&dep1));
	  ASSERT_FALSE(company->getDepLoop());

	  company->addDepartment(&dep2);
	  alldepartments.insert(&dep2);
	  mainDepartments.insert(&dep2);
	  ASSERT_EQ(1, dep2.getNumOfDep());
	  ASSERT_TRUE(company->hasMainDep(&dep2));
	  ASSERT_FALSE(company->getDepLoop());

	  ASSERT_EQ(alldepartments, company->getAllDeps());
  }

  TEST_F(CompanyTest, AddSubDepartemnt) {
	  company->addSubDep(nullptr, nullptr);//1 null subDep or super

	  company->addSubDep(&dep111, &dep11);//4 normal insertion
	  alldepartments.insert(&dep111);
	  ASSERT_EQ(1, dep111.getNumOfDep());
	  ASSERT_TRUE(dep11.hasSubDep(&dep111));
	  ASSERT_FALSE(company->getDepLoop());

	  company->addSubDep(&dep111, &dep11);//2 subDep found in super
	  ASSERT_EQ(1, dep111.getNumOfDep());
	  ASSERT_TRUE(dep11.hasSubDep(&dep111));
	  ASSERT_FALSE(company->getDepLoop());

	  company->addSubDep(&dep111, &dep2);//3 loop department
	  ASSERT_EQ(2, dep111.getNumOfDep());
	  ASSERT_TRUE(dep11.hasSubDep(&dep111));
	  ASSERT_TRUE(company->getDepLoop());

	  company->addSubDep(&dep11, &dep1);
	  alldepartments.insert(&dep11);

	  company->addSubDep(&dep12, &dep1);
	  alldepartments.insert(&dep12);

	  company->addSubDep(&dep21, &dep2);
	  alldepartments.insert(&dep21);

	  ASSERT_EQ(alldepartments, company->getAllDeps());
	  company->printAllEmps();
  }




  TEST_F(CompanyTest, DeleteEmployee) {
	  company->deleteEmp(nullptr, &dep1);//1 null employee
	  ASSERT_EQ(allEmployees, company->getAllEmps());

	  company->deleteEmp(&employee1, nullptr);//3 null department and nonfloat Employee
	  ASSERT_EQ(allEmployees, company->getAllEmps());

	  company->deleteEmp(&employee1, &dep2);//6 is not found
	  ASSERT_EQ(allEmployees, company->getAllEmps());

	  company->deleteEmp(&employee1, &dep1);//4 multi department
	  ASSERT_EQ(allEmployees, company->getAllEmps());
	  ASSERT_EQ(1, employee1.getNumOfDep());
	  ASSERT_EQ(1, (int)company->getSalaryMap().count(1000));
	  ASSERT_EQ(2, (int)company->getSalaryMap().at(1000).size());
	  ASSERT_FALSE(employee1.hasDep(&dep1));
	  ASSERT_FALSE(dep1.hasEmp(&employee1));

	  company->deleteEmp(&floatEmp, nullptr);//2 null deparement and float employee
	  allEmployees.erase(&floatEmp);
	  ASSERT_EQ(allEmployees, company->getAllEmps());
	  ASSERT_EQ(0, floatEmp.getNumOfDep());
	  ASSERT_EQ(1, (int)company->getSalaryMap().count(1500));
	  ASSERT_EQ(0, (int)company->getSalaryMap().at(1500).size());

	  company->deleteEmp(&employee4, &dep21);//5 normal deletion
	  allEmployees.erase(&employee4);
	  ASSERT_EQ(allEmployees, company->getAllEmps());
	  ASSERT_EQ(0, employee4.getNumOfDep());
	  ASSERT_EQ(1, (int)company->getSalaryMap().count(1000));
	  ASSERT_EQ(1, (int)company->getSalaryMap().at(1000).size());
	  ASSERT_FALSE(employee4.hasDep(&dep21));
	  ASSERT_FALSE(dep21.hasEmp(&employee4));
  }


  TEST_F(CompanyTest, deleteDepartemnt) {
	  company->deleteDep(&dep21, &dep2);
	  alldepartments.erase(&dep21);
	  allEmployees.erase(&employee5);
	  ASSERT_EQ(0, dep21.getNumOfDep());
	  ASSERT_FALSE(dep2.hasSubDep(&dep21));
	  ASSERT_TRUE(company->getDepLoop());
	  ASSERT_FALSE(dep21.hasEmp(&employee5));
	  ASSERT_FALSE(employee5.hasDep(&dep21));

	  company->deleteDep(&dep11, &dep1);
	  alldepartments.erase(&dep11);
	  ASSERT_EQ(0, dep11.getNumOfDep());
	  ASSERT_FALSE(dep1.hasSubDep(&dep11));
	  ASSERT_EQ(1, dep111.getNumOfDep());
	  ASSERT_FALSE(dep11.hasSubDep(&dep111));
	  ASSERT_FALSE(company->getDepLoop());
	  ASSERT_TRUE(dep111.hasEmp(&employee6));
	  ASSERT_TRUE(employee6.hasDep(&dep111));

	  ASSERT_EQ(allEmployees, company->getAllEmps());
	  ASSERT_EQ(alldepartments, company->getAllDeps());
  }

  TEST_F(CompanyTest, deleteMainDepartemnt) {
	  company->deleteDep(&dep2);
	  alldepartments.erase(&dep2);
	  mainDepartments.erase(&dep2);
	  allEmployees.erase(&employee2);
	  ASSERT_EQ(0, dep2.getNumOfDep());
	  ASSERT_FALSE(dep2.hasEmp(&employee2));
	  ASSERT_FALSE(employee2.hasDep(&dep2));

	  alldepartments.erase(&dep111);
	  allEmployees.erase(&employee6);
	  ASSERT_EQ(0, dep111.getNumOfDep());
	  ASSERT_FALSE(dep2.hasSubDep(&dep111));
	  ASSERT_FALSE(company->getDepLoop());
	  ASSERT_FALSE(dep111.hasEmp(&employee6));
	  ASSERT_FALSE(employee6.hasDep(&dep111));

	  ASSERT_EQ(allEmployees, company->getAllEmps());
	  ASSERT_EQ(alldepartments, company->getAllDeps());
	  ASSERT_EQ(mainDepartments, company->getMainDeps());

  }









