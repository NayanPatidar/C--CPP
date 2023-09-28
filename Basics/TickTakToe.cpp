#include <iostream>

using namespace std;

class TikTacToe {


public:
	void start() {
		boxCreation();
	}

private:
	char(*arr)[3];
	bool wonX, wonY;

	void boxCreation() {
		arr = new char[3][3];

		cout << " | | " << endl;
		cout << " | | " << endl;
		cout << " | | " << endl;

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
				if (i == x && j == y) {
					arr[i][j] = 'X|';
					cout << arr[i][j];
				}
				else {
					arr[i][j] = ' |';
					cout << arr[i][j];
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
				if (i == x && j == y) {
					arr[i][j] = 'O|';
					cout << arr[i][j];
				}
				else {
					arr[i][j] = ' |';
					cout << arr[i][j];
				}
			}
			cout << endl;
		}
	}

	
};