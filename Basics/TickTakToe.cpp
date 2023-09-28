#include <iostream>

using namespace std;

class TikTacToe {


public:
	void start() {
		boxCreation();
	}

private:
	char(*arr)[3] = new char[3][3];;
	bool wonX, wonY;

	void boxCreation() { 

		cout << " | | |" << endl;
		cout << " | | |" << endl;
		cout << " | | |" << endl;
		initializeBoard();
		do {
			playerX();
			//checkWinner();
			playerO();
			//checkWinner();
		} while (true);
	}

	void playerX() {
		int x, y;
		cout << "Player X - It's your turn ! ->";
		cin >> x;
		cin >> y;
		// Check for input position ...
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j < 2) {
					if (i == x && j == y) {
						arr[i][j] = 'X';
						cout << "X|";
					}
					else {
						cout << " |";
					}
				}
				else {
					if (i == x && j == y) {
						arr[i][j] = 'X';
						cout << "X";
					}
					else {
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}

	void playerO() {
		int x, y;
		cout << "Player O - It's your turn ! ->";
		cin >> x;
		cin >> y;
		// Check for input position ...
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j < 2) {
					if (i == x && j == y) {
						arr[i][j] = 'O';
						cout << "O|";
					}
					else  {
						cout << " |";
					}
				}
				else {
					if (i == x && j == y) {
						arr[i][j] = 'O';
						cout << "O";
					}
					else {
						cout << " ";
					}
				}
			}
			cout << endl;
		}
	}

	void initializeBoard() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = ' ';
			}
		}
	}
};