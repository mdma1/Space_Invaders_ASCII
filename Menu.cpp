#include "Headers.h"

int openMainMenu()
{
	string str[4] = { "Play", "High Scores", "Help", "Exit" };

	setColor(10, 0);
	setPosition(5, 6);
	cout << "> " << str[0];
	setColor(15, 0);

	setPosition(7, 7);
	cout << str[1];

	setPosition(7, 8);
	cout << str[2];

	setPosition(7, 9);
	cout << str[3];

	setPosition(27, 32);

	bool decision = false;
	int choice = 0;

	while (!decision) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'w':
				if (choice != 0) choice--;
				break;
			case 's':
				if (choice != 3) choice++;
				break;
			case 13:
				decision = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				setPosition(5, 6 + i);
				cout << "  " << str[i];
			}

			setColor(10, 0);
			setPosition(5, 6 + choice);
			cout << "> " << str[choice];
			setColor(15, 0);

			setPosition(27, 32);
		}
	}

	return choice;
}

int openPauseMenu()
{
	string str[2] = { "Resume", "Quit" };
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 19; j++) {
			setPosition(18 + j, 10 + i);
			cout << " ";
		}
	}

	for (int i = 0; i < 19; i++) {
		setPosition(18 + i, 9);
		cout << (char)196;
	}
	for (int i = 0; i < 4; i++) {
		setPosition(17, 10 + i);
		cout << (char)179;
	}
	for (int i = 0; i < 4; i++) {
		setPosition(37, 10 + i);
		cout << (char)179;
	}
	for (int i = 0; i < 19; i++) {
		setPosition(18 + i, 14);
		cout << (char)196;
	}
	setPosition(17, 9);
	cout << (char)218;
	setPosition(37, 9);
	cout << (char)191;
	setPosition(17, 14);
	cout << (char)192;
	setPosition(37, 14);
	cout << (char)217;

	setPosition(25, 10);
	cout << "PAUSE";

	setColor(10, 0);
	setPosition(21, 12);
	cout << str[0];
	setColor(15, 0);

	setPosition(29, 12);
	cout << str[1];

	setPosition(27, 32);

	bool decision = false;
	int choice = 0;

	while (!decision) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				if (choice != 0) choice--;
				break;
			case 'd':
				if (choice != 1) choice++;
				break;
			case 13:
				decision = true;
				break;
			case 27:
				choice = 0;
				decision = true;
				break;
			}

			for (int i = 0; i < 2; i++) {
				setPosition(21 + i * 8, 12);
				cout << str[i];
			}

			setColor(10, 0);
			setPosition(21 + choice * 8, 12);
			cout << str[choice];
			setColor(15, 0);

			setPosition(27, 32);
		}
	}

	return choice;
}

void closePauseMenu(vector < Alien >& aliens, Bullet& playerBullet, Bullet& alienBullet)
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 21; j++) {
			setPosition(17 + j, 9 + i);
			cout << " ";
		}
	}

	vector < Alien > ::iterator alienIterator;
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		if (alienIterator->isAlive) {
			setPosition(alienIterator->pos.x, alienIterator->pos.y);
			cout << (char)201 << (char)254 << (char)187;
		}
	}

	if (playerBullet.fire) {
		setPosition(playerBullet.pos.x, playerBullet.pos.y);
		cout << "|";
	}

	if (alienBullet.fire) {
		setPosition(alienBullet.pos.x, alienBullet.pos.y);
		cout << "|";
	}

	for (int i = 3; i > 0; i--) {
		setPosition(27, 5);
		cout << i;
		setPosition(27, 32);
		Sleep(1000);
	}
	setPosition(27, 5);
	cout << " ";

	setPosition(27, 32);
}