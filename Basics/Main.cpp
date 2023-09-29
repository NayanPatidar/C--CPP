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

		cout << " | | " << endl;
		cout << " | | " << endl;
		cout << " | | " << endl;
		initializeBoard();
		do {
			playerX();
			if (checkWinner('X')) {
				std::cout << "Player X wins!\n";
				break;
			}
			playerO();
			if (checkWinner('O')) {
				std::cout << "Player 0 wins!\n";
				break;
			}
		} while (true);
	}

	void playerX() {
		int x, y;
		cout << "Player X - It's your turn ! ->\n";
		cin >> x;
		cin >> y;
		// Check for input position ...
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j < 2) {
					if (i == x && j == y) {
						arr[i][j] = 'X';
						cout << arr[i][j] << "|";
					}
					else {
						cout << arr[i][j] << "|";
					}
				}
				else {
					if (i == x && j == y) {
						arr[i][j] = 'X';
						cout << arr[i][j] << "|";
					}
					else {
						cout << arr[i][j] ;
					}
				}
			}
			cout << endl;
		}
	}

	void playerO() {
		int x, y;
		cout << "Player O - It's your turn ! ->\n";
		cin >> x;
		cin >> y;
		// Check for input position ...
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j < 2) {
					if (i == x && j == y) {
						arr[i][j] = 'O';
						cout << arr[i][j] << "|";
					}
					else {
						cout << arr[i][j] << "|";
					}
				}
				else {
					if (i == x && j == y) {
						arr[i][j] = 'O';
						cout << arr[i][j] ;
					}
					else {
						cout << arr[i][j];
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

	bool checkWinner(char player) {
		for (int i = 0; i < 3; i++) {
			if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player)
				return true;  // Check rows
			if (arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)
				return true;  // Check columns
		}

		if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
			return true;  // Check main diagonal
		if (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
			return true;  // Check anti-diagonal

		return false;
	}
};