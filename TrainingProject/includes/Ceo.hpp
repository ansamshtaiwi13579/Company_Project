#pragma once
#include "../includes/Person.hpp"
#include <iostream>
using namespace std;

class Ceo:public Person{
public:
	string name;
	Ceo();
	Ceo(string nm);
	void setName(string nam);
	string getName();
};
