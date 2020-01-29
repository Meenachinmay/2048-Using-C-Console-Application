#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;


int board[4][4];
int dirLine[] = {1,0,-1,0};
int dirCol[] = {0,1,0,-1};

pair<int, int> generateUnoccupiedPosition() {
	int occupied = 1, line, column;
	while (occupied) {
		line = rand() % 4;
		column = rand() % 4;

		if (board[line][column] == 0) {
			occupied = 0;
		}
	}
	return make_pair(line, column);
}

void newGame() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = 0;
}

void printUI() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 0)
				cout << " ";
			else
				cout << board[i][j];
		cout << "\n";
	}
	cout << "n: new game, w: up, s: down, a: left, d: right, q: quit \n";
}

void applyMove(int direction) {

}

int main() {
	
	srand(time(0));
	char commandToDir[128];
	commandToDir['s'] = 0;
	commandToDir['d'] = 1;
	commandToDir['w'] = 2;
	commandToDir['a'] = 3;
	newGame();
	while (true) {
		printUI();

		char command;
		cin >> command;

		if (command == 'n')
			newGame();
		else if (command == 'q')
			break;
		else {
			int currentDirection = commandToDir[command];
			cout << currentDirection << endl;
			applyMove(currentDirection);
		}
	}

	return 0;
}