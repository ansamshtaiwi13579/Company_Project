/*
 * DepartmentTests.cpp
 *
 *  Created on: 15 Feb 2022
 *      Author: user
 */

#include "gtest/gtest.h"
#include "Department.hpp"


  class DepartmentTest : public ::testing::Test {};

  Department department("d1");

  TEST_F(DepartmentTest, checkNameDepartment) {
	  ASSERT_EQ("d1",department.getName());
  }

  set <Employee*> setEmp;
  Employee emp1("e1", 1000, HR);
  Employee emp2("e2", 2000, Dev);

  TEST_F(DepartmentTest, checkAddEmployees) {
	  ASSERT_EQ(setEmp,department.getEmployees());

	  department.addEmployee(&emp1);
	  department.addEmployee(&emp2);
	  setEmp.insert(&emp1);
	  setEmp.insert(&emp2);
	  ASSERT_EQ(setEmp,department.getEmployees());
  }

  TEST_F(DepartmentTest, checkDeleteEmployees) {
	  department.deleteEmployee(&emp1);
	  setEmp.erase(&emp1);
	  ASSERT_EQ(setEmp,department.getEmployees());

	  department.deleteEmployee(nullptr);
	  ASSERT_EQ(setEmp,department.getEmployees());
  }

  set <Department*> setSubDep;
  Department subDep1("subDep1");
  Department subDep2("subDep2");

  TEST_F(DepartmentTest, checkAddSubDepartment){
	  ASSERT_EQ(setSubDep,department.getSubDepartments());

	  department.addSubDepartment(&subDep1);
	  department.addSubDepartment(&subDep2);
	  setSubDep.insert(&subDep1);
	  setSubDep.insert(&subDep2);
	  ASSERT_EQ(setSubDep,department.getSubDepartments());
  }

  TEST_F(DepartmentTest, checkDeleteSubDepartment){
	  department.deleteSubDepartment(&subDep2);
	  setSubDep.erase(&subDep2);
	  ASSERT_EQ(setSubDep,department.getSubDepartments());

	  department.deleteSubDepartment(nullptr);
	  ASSERT_EQ(setSubDep,department.getSubDepartments());
  }

  TEST_F(DepartmentTest, checkFoundSubDepartment){
	  ASSERT_TRUE(department.hasSubDep(&subDep1));
	  ASSERT_FALSE(department.hasSubDep(&subDep2));
  }

  TEST_F(DepartmentTest, checkCountOfDepartment){
	  ASSERT_EQ(0,department.getNumOfDep());

	  department.setNumOfDep(2);
	  ASSERT_EQ(2,department.getNumOfDep());
  }











