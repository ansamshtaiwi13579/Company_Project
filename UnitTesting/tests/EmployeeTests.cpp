/*
 * Employeetests.cpp
 *
 *  Created on: 14 Feb 2022
 *      Author: user
 */

#include "gtest/gtest.h"
#include "Employee.hpp"



  class EmployeeTest : public ::testing::Test {};

  Employee employee("e1", 1000, HR);

  TEST_F(EmployeeTest, checkSalaryEmployee) {
	  ASSERT_EQ(1000,employee.getSalary());

	  employee.setSalary(2000);
	  ASSERT_EQ(2000,employee.getSalary());
  }


  TEST_F(EmployeeTest, checkNameEmployee) {
	  ASSERT_EQ("e1",employee.getName());

	  employee.setName("e2");
	  ASSERT_EQ("e2",employee.getName());
  }


  TEST_F(EmployeeTest, checkRoleEmployee) {
	  ASSERT_EQ(HR,employee.getRole());

	  employee.setRole(Dev);
	  ASSERT_EQ(Dev,employee.getRole());
  }


  TEST_F(EmployeeTest, checkNumOfDepEmployee) {
	  ASSERT_EQ(0,employee.getNumOfDep());

	  employee.setNumOfDep(2);
	  ASSERT_EQ(2,employee.getNumOfDep());

	  employee.incEmp();
	  ASSERT_EQ(3,employee.getNumOfDep());
  }


  TEST_F(EmployeeTest, checkDepOfEmployee) {
	  set <Department*> depSet;
	  ASSERT_EQ(depSet,employee.getEmpDep());

	  Department d1("d1");
	  employee.setEmpDep(&d1);
	  depSet.insert(&d1);
	  ASSERT_EQ(depSet,employee.getEmpDep());


  }








