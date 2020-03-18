#include "Headers.h"

void printHelpPage1()
{
	string text[20] =
	{
		"Space Invaders is a fixed shooter in which the",
		"player controls a laser cannon by moving it",
		"horizontally across the bottom of the screen and",
		"firing at descending aliens. The aim is to defeat",
		"five rows of eleven aliens that move horizontally",
		"back and forth across the screen as they advance",
		"toward the bottom of the screen. The player's",
		"laser cannon is partially protected by several",
		"stationary defense bunkers that are gradually",
		"destroyed from the top and bottom by blasts from",
		"either the aliens or the player.",
		"",
		"The player defeats an alien and earns points by",
		"shooting it with the laser cannon. As more aliens",
		"are defeated, the alien's movement speed up.",
		"Defeating all the aliens on-screen brings another",
		"wave that is more difficult, a loop which can",
		"continue endlessly. A special mystery ship will",
		"occasionally move across the top of the screen",
		"and award bonus points if destroyed."
	};

	setPosition(43, 1);
	cout << "Help";

	setPosition(20, 3);
	cout << "Space Invaders";

	for (int i = 0; i < 20; i++) {
		setPosition(3, 4 + i);
		cout << text[i];
	}

	for (int i = 0; i < 3; i++) {
		setPosition(25 + i * 2, 28);
		cout << (char)254;
	}

	setColor(10, 0);
	setPosition(25, 28);
	cout << (char)254;
	setColor(15, 0);

	setPosition(27, 32);
}

void printHelpPage2()
{
	string text[7] =
	{
		"The aliens attempt to destroy the player's cannon",
		"by firing at it while they approach the bottom of",
		"the screen. If they reach the bottom, the alien",
		"invasion is declared successful and the game ends",
		"tragically; otherwise, it ends generally if the",
		"player's last cannon is destroyed by the enemy's",
		"projectiles."
	};

	setPosition(43, 1);
	cout << "Help";

	for (int i = 0; i < 7; i++) {
		setPosition(3, 3 + i);
		cout << text[i];
	}

	setPosition(3, 13);
	setColor(10, 0);
	cout << (char)220 << (char)254 << (char)220;
	setColor(15, 0);
	cout << "   - your ship";

	setPosition(3, 15);
	cout << (char)201 << (char)254 << (char)187 << "   - alien ship";

	setPosition(3, 17);
	setColor(4, 0);
	cout << (char)254 << (char)254 << (char)254 << (char)254;
	setColor(15, 0);
	cout << "  - command alien ship";

	for (int i = 0; i < 3; i++) {
		setPosition(25 + i * 2, 28);
		cout << (char)254;
	}

	setColor(10, 0);
	setPosition(27, 28);
	cout << (char)254;
	setColor(15, 0);

	setPosition(27, 32);
}

void printHelpPage3()
{
	setPosition(43, 1);
	cout << "Help";

	string text[6] =
	{
		"Controls",
		"",
		"W      Shooting",
		"A      Move left",
		"D      Move right",
		"Esc    Pause"
	};

	for (int i = 0; i < 6; i++) {
		setPosition(4, 6 + i);
		cout << text[i];
	}

	for (int i = 0; i < 3; i++) {
		setPosition(25 + i * 2, 28);
		cout << (char)254;
	}

	setColor(10, 0);
	setPosition(29, 28);
	cout << (char)254;
	setColor(15, 0);

	setPosition(27, 32);
}

void printHelp()
{
	printHelpPage1();

	bool decision = false;
	int choice = 0;

	while (!decision) {

		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				if (choice != 0) {
					choice--;
					system("cls");
					if (choice == 0) printHelpPage1();
					if (choice == 1) printHelpPage2();
					if (choice == 2) printHelpPage3();
				}
				break;
			case 'd':
				if (choice != 2) {
					choice++;
					system("cls");
					if (choice == 0) printHelpPage1();
					if (choice == 1) printHelpPage2();
					if (choice == 2) printHelpPage3();
				}
				break;
			case 27:
				decision = true;
				system("cls");
				break;
			}
		}
	}
}