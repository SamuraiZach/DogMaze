/*
 * Board.cpp
 *
 *  Created on: Feb 26, 2022
 *      Author: zachb
 */

#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board(char diff, bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	mydog.name = name;
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	while (keepPlaying) {
		cout << "Welcome to Dog and the Evil Forest" << endl;
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		endx = rand() % size;
		endy = size-1;
		mydog.x = startx;
		mydog.y = starty + 1;
		string board[size][size];
		boardConfig();
		addFood();
		addTraps();
		printBoard();
		playGame();
		cout << "Play again? " << endl;
		string s = "no";
		cin>>s;
		if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
			keepPlaying = true;
			mydog.reset();
		}
		else{
			cout <<"Thanks for playing!" << endl;
			keepPlaying = false;
		}
	}
}
void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
		printBoard();
	}
}

void Board::addFood() {
/* (5 pts) code for the addFood method goes here
*/
	int easyDiff = 30;
	int mediumDiff = 20;
	int hardDiff = 15;
	if(level == 'e'){
		for(int i = 0; i < easyDiff; i++){
			int row = rand() % 19 + 1;
			int col = rand() % 19 + 1;
			if(board[row][col] == ' ' && board[row][col] != '*'){
				board[row][col] = 'F';
			}
		}
	}else if(level == 'm'){
		for(int i = 0; i < mediumDiff; i++){
			int row = rand() % 19 + 1;
			int col = rand() % 19 + 1;
			if(board[row][col] == ' ' && board[row][col] != '*'){
				board[row][col] = 'F';
			}
		}
	}else if(level == 'h'){
		for(int i = 0; i < hardDiff; i++){
			int row = rand() % 19 + 1;
			int col = rand() % 19 + 1;
			if(board[row][col] == ' ' && board[row][col] != '*'){
				board[row][col] = 'F';
			}
		}
	}

}
void Board::addTraps() {
/* (5 pts) code for the addTraps method goes here
*/
	int easyDiff = 10;
	int mediumDiff = 15;
	int hardDiff = 25;
	if(level == 'e'){
		for(int i = 0; i < easyDiff; i++){
			int row = rand() % 19 + 1;
			int col = rand() % 19 + 1;
			if(board[row][col] == ' ' && board[row][col] != '*'){
				board[row][col] = 'T';
			}
		}
	}else if(level == 'm'){
		for(int i = 0; i < mediumDiff; i++){
			int row = rand() % 19 + 1;
			int col = rand() % 19 + 1;
			if(board[row][col] == ' ' && board[row][col] != '*'){
				board[row][col] = 'T';
			}
		}
	}else if(level == 'h'){
		for(int i = 0; i < hardDiff; i++){
			int row = rand() % 19 + 1;
			int col = rand() % 19 + 1;
			if(board[row][col] == ' ' && board[row][col] != '*'){
				board[row][col] = 'T';
			}
		}
	}
}
void Board::boardConfig() {
/* (8 pts) code for the boardConfig method goes here
*/
	int rowx = startx;
	int coly = starty;
	int rowEnd = endx;
	int colEnd = endy;
	for(int i = 0; i <size; i++){
		for(int j = 0; j < size; j++){
			board[i][j] = ' ';
		}
	}
	if(level == 'e'){
		int easyDiff = size*5;
		for(int i = 0; i < easyDiff; i++){
			if(rand()%2 == 0){
				if(board[rand() % 19 + 1][rand() % 19+1] != '*'){
					int coly = rand() % 19+1;
					if(coly%2 == 0){
						board[rand() % size + 1][coly]= '|';
					}
				}
			}else{
				int colx = rand() % size + 2;
				int coly = rand() % size + 2;
				if(colx%2 != 0 && coly%2 != 0){
					board[coly][colx] = '_';
				}
			}
		}
	}else if(level == 'm'){
		int mediumDiff = size*13;
		for(int i = 0; i < mediumDiff; i++){
			if(rand()%2 == 0){
				if(board[rand() % 19 + 1][rand() % 19+1] != '*'){
					int coly = rand() % 19+1;
					if(coly%2 == 0){
						board[rand() % 19 + 1][coly]= '|';
					}
				}
			}else{
				int colx = rand() % size + 2;
				int coly = rand() % size + 2;
				if(colx%2 != 0 && coly%2 != 0){
					board[coly][colx] = '_';
				}
			}
		}
	}else{
		int hardDiff = size*15;
		for(int i = 0; i < hardDiff; i++){
			if(rand()%2 == 0){
				if(board[rand() % 19 + 1][rand() % 19+1] != '*'){
					int coly = rand() % 19+1;
					if(coly%2 == 0){
						board[rand() % 19 + 1][coly]= '|';
					}
				}
			}else{
				int colx = rand() % size + 2;
				int coly = rand() % size + 2;
				if(colx%2 != 0 && coly%2 != 0){
					board[coly][colx] = '_';
				}
			}
		}
	}
	for(int row = 0; row < size; row++){
		for(int col = 0; col < size; col++){
			if(row == 0 || row == size-1){
				board[row][col] = '*';
			}else if((col == 0 &&  (row > 0 && row < size - 1)) ||(col == size - 1 && (row > 0 && row < size - 1))){
				board[row][col] = '*';
			}
		}
	}
	board[rowx][coly+ 1] = 'D';
	board[rowx][coly] = '>';
	board[rowEnd][colEnd] = '>';
	board[rowEnd][colEnd - 1] = 'E';
}
void Board::printBoard() {
/* (8 pts) code for the printBoard method goes here
*/
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<" "<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}
bool Board::moveDog(char c) {
/* (12 pts) code for the moveDog method goes here
*/
	bool alive = true;
	bool playing = true;
	string s;
	if(c == 'u'){
		if(board[mydog.x - 1][mydog.y] != '*'){
			if(board[mydog.x-1][mydog.y] == '|' || board[mydog.x-1][mydog.y] == '_'){
				cout<<"Do you wish do break down the wall? (y/n)"<<endl;
				cin>>s;
				if(s == "y" && mydog.strength > 6){
					alive = mydog.changeStrength(-1*(6));
					cout<<"Activates rage to destroy the wall yet hurting itself in the process."<<endl;
					board[mydog.x - 1][mydog.y] = 'D';
					board[mydog.x][mydog.y] = ' ';
					mydog.x = mydog.x - 1;
				}else if(s == "n"){
					alive = mydog.changeStrength(-1*(1));
					cout<<"Cowardice lowers strength and morale."<<endl;
				}else if(s == "y" && mydog.strength < 6){
					cout<<"You are too weak to even attempt to break a wall."<<endl;
				}
			}else if(board[mydog.x - 1][mydog.y] == 'F'){
				alive = mydog.changeStrength((rand()%17+2));
				board[mydog.x - 1][mydog.y] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.x = mydog.x - 1;
				cout<<"Finally, food. After wandering your strength replenishes."<<endl;
			}else if(board[mydog.x - 1][mydog.y] == 'T'){
				alive = mydog.changeStrength(-1*(rand()%17+2));
				board[mydog.x - 1][mydog.y] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.x = mydog.x - 1;
				cout<<"Dog yelps. As a trap has been sprung therefore mutilating your health."<<endl;
			}else if(board[mydog.x - 1][mydog.y] == 'E'){
				board[mydog.x][mydog.y] = ' ';
				mydog.won();
				playing = false;
				return playing;
			}else{
				board[mydog.x - 1][mydog.y] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.x = mydog.x - 1;
				alive = mydog.changeStrength(-1*(2));
			}
		}else{
			cout << "Boundaries restrict you." << endl;
		}
	}else if(c == 'd'){
		if(board[mydog.x + 1][mydog.y] != '*'){
			if(board[mydog.x+1][mydog.y] == '|' || board[mydog.x+1][mydog.y] == '_'){
				cout<<"Do you wish do break down the wall? (y/n)"<<endl;
				cin>>s;
				if(s == "y" && mydog.strength > 6){
					alive = mydog.changeStrength(-1*(6));
					cout<<"Activates rage to destroy the wall yet hurting itself in the process."<<endl;
					board[mydog.x + 1][mydog.y] = 'D';
					board[mydog.x][mydog.y] = ' ';
					mydog.x = mydog.x + 1;
				}else if(s == "n"){
					alive = mydog.changeStrength(-1*(1));
					cout<<"Cowardice lowers strength and morale."<<endl;
				}else if(s == "y" && mydog.strength < 6){
					cout<<"You are too weak to even attempt to break a wall."<<endl;
				}
			}else if(board[mydog.x + 1][mydog.y] == 'F'){
				alive = mydog.changeStrength((rand()%17+2));
				board[mydog.x + 1][mydog.y] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.x = mydog.x + 1;
				cout<<"Finally, food. After wandering your strength replenishes."<<endl;
			}else if(board[mydog.x + 1][mydog.y] == 'T'){
				alive = mydog.changeStrength(-1*(rand()%17+2));
				board[mydog.x + 1][mydog.y] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.x = mydog.x + 1;
				cout<<"Dog yelps. As a trap has been sprung therefore mutilating your health."<<endl;
			}else if(board[mydog.x + 1][mydog.y] == 'E'){
				board[mydog.x][mydog.y] = ' ';
				mydog.won();
				playing = false;
				return playing;
			}else{
				board[mydog.x + 1][mydog.y] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.x = mydog.x + 1;
				alive = mydog.changeStrength(-1*(2));
			}
		}else{
			cout << "Boundaries restrict you." << endl;
		}
	}else if(c == 'l'){
		if(board[mydog.x][mydog.y - 1] != '*'){
			if(board[mydog.x][mydog.y - 1] == '|' || board[mydog.x][mydog.y - 1] == '_'){
				cout<<"Do you wish do break down the wall? (y/n)"<<endl;
				cin>>s;
				if(s == "y" && mydog.strength > 6){
					alive = mydog.changeStrength(-1*(6));
					cout<<"Activates rage to destroy the wall yet hurting itself in the process."<<endl;
					board[mydog.x][mydog.y - 1] = 'D';
					board[mydog.x][mydog.y] = ' ';
					mydog.y = mydog.y - 1;
				}else if(s == "n"){
					alive = mydog.changeStrength(-1*(1));
					cout<<"Cowardice lowers strength and morale."<<endl;
				}else if(s == "y" && mydog.strength < 6){
					cout<<"You are too weak to even attempt to break a wall."<<endl;
				}
			}else if(board[mydog.x][mydog.y - 1] == 'F'){
				alive = mydog.changeStrength((rand()%17+2));
				board[mydog.x][mydog.y - 1] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.y = mydog.y - 1;
				cout<<"Finally, food. After wandering your strength replenishes."<<endl;
			}else if(board[mydog.x][mydog.y - 1] == 'T'){
				alive = mydog.changeStrength(-1*(rand()%17+2));
				board[mydog.x][mydog.y - 1] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.y = mydog.y - 1;
				cout<<"Dog yelps. As a trap has been sprung therefore mutilating your health."<<endl;
			}else{
				board[mydog.x][mydog.y - 1] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.y = mydog.y - 1;
				alive = mydog.changeStrength(-1*(2));
			}
		}else{
			cout << "Boundaries restrict you." << endl;
		}
	}else if(c == 'r'){
		if(board[mydog.x][mydog.y + 1] != '*'){
			if(board[mydog.x][mydog.y + 1] == '|' || board[mydog.x][mydog.y + 1] == '_'){
				cout<<"Do you wish do break down the wall? (y/n)"<<endl;
				cin>>s;
				if(s == "y" && mydog.strength > 6){
					alive = mydog.changeStrength(-1*(6));
					cout<<"Activates rage to destroy the wall yet hurting itself in the process."<<endl;
					board[mydog.x][mydog.y + 1] = 'D';
					board[mydog.x][mydog.y] = ' ';
					mydog.y = mydog.y + 1;
				}else if(s == "n"){
					alive = mydog.changeStrength(-1*(1));
					cout<<"Cowardice lowers strength and morale."<<endl;
				}else if(s == "y" && mydog.strength < 6){
					cout<<"You are too weak to even attempt to break a wall."<<endl;
				}
			}else if(board[mydog.x][mydog.y + 1] == 'F'){
				alive = mydog.changeStrength((rand()%17+2));
				board[mydog.x][mydog.y + 1] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.y = mydog.y + 1;
				cout<<"Finally, food. After wandering your strength replenishes."<<endl;
			}else if(board[mydog.x][mydog.y + 1] == 'T'){
				alive = mydog.changeStrength(-1*(rand()%17+2));
				board[mydog.x][mydog.y + 1] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.y = mydog.y + 1;
				cout<<"Dog yelps. As a trap has been sprung therefore mutilating your health."<<endl;
			}else if(board[mydog.x][mydog.y + 1] == 'E'){
				board[mydog.x][mydog.y] = ' ';
				mydog.won();
				playing = false;
				return playing;
			}else{
				board[mydog.x][mydog.y + 1] = 'D';
				board[mydog.x][mydog.y] = ' ';
				mydog.y = mydog.y + 1;
				alive = mydog.changeStrength(-1*(2));
			}
		}else{
			cout << "Boundaries restrict you." << endl;
		}
	}
	mydog.printDog();
	return alive;
}
