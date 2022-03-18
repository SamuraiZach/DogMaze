/*
 * Dog.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: zachb
 */


#include "Dog.hpp"
#include <iostream>
using namespace std;

Dog::Dog(string n){
	name = n;
	strength = 50;
	x = 0;
	y = 0;
}
Dog::Dog(){
	name = "fido";
	strength = 50;
	x = 0;
	y = 0;
}
bool Dog::changeStrength(int amt){
	bool live = true;
	strength += amt;
	if(strength < 0){
		die();
		live = false;
		return live;
	}
	return live;
}
void Dog::die(){
	cout << "The dog, fiendish animal, crumbles under the weight of its escape. Never to be remembered." << endl;
}
void Dog::printDog(){
	cout << "Name: " << name << " Strength: " << strength << endl;
}
void Dog::won(){
	cout << "Curelty and adversaries left in the maze. "<<name<<" gets to live another day with every step out continuing to look forward rather than regret in trauma." << endl;
}
void Dog::reset(){
	strength = 50;
	x = 0;
	y = 0;
}
