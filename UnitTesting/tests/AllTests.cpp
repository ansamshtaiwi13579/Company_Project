/*
 * AllTests.cpp
 *
 *  Created on: 14 Feb 2022
 *      Author: user
 */

#include "gtest/gtest.h"

#include "EmployeeTests.cpp"
#include "DepartmentTests.cpp"
#include "CompanyTests.cpp"

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


