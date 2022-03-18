/*
 * MainGame.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: zachb
 */

#include "Board.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	srand(time(NULL));
	Board board('m',"fido", true);
	return 0;
}


