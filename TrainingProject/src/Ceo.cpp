#include "../includes/Ceo.hpp"
#include <iostream>
using namespace std;

Ceo::Ceo(string nm){
	name = nm;
}
Ceo::Ceo(){}
void Ceo::setName(string nm){
	name = nm;
}
string Ceo::getName(){
	return name;
}
