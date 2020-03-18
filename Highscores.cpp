#include "Headers.h"

void saveScore(string str, int num)
{
	fstream fin("HighScores.txt", ios::in | ios::app);
	int score[10], score_tmp;
	string nickname[10], nickname_tmp;

	if (fin.is_open())
	{
		for (int i = 0; i < 10; i++) {
			nickname[i] = " ";
			score[i] = 0;
		}
		int i = 0;
		while (fin >> score_tmp && fin >> nickname_tmp)
		{
			nickname[i] = nickname_tmp;
			score[i] = score_tmp;
			i++;
		}

		for (int i = 0; i < 10; i++) {
			if (i == 0 && num <= score[9]) break;
			if (num > score[9 - i] && i < 9) {
				nickname[9 - i] = nickname[8 - i];
				score[9 - i] = score[8 - i];
			}
			else if (num < score[0]) {
				nickname[10 - i] = str;
				score[10 - i] = num;
				break;
			}
			if (i == 9 && num > score[0]) {
				nickname[0] = str;
				score[0] = num;
				break;
			}
		}
	}
	else {
		setPosition(13, 25);
		cout << "Error. Unable to create file.";
		setPosition(27, 32);
		Sleep(1500);
		return;
	}
	ofstream fout("HighScores.txt", ios::ate);
	if (fout.is_open()) {
		for (int i = 0; i < 10; i++) {
			fout << score[i] << "\t" << nickname[i] << endl;
		}
	}
}

void printHighScores()
{
	fstream fin("HighScores.txt", ios::in | ios::app);

	int score[10], score_tmp;
	string nickname[10], nickname_tmp;

	if (fin.is_open())
	{
		for (int i = 0; i < 10; i++) {
			nickname[i] = " ";
			score[i] = 0;
		}
		int i = 0;
		while (fin >> score_tmp && fin >> nickname_tmp)
		{
			nickname[i] = nickname_tmp;
			score[i] = score_tmp;
			i++;
		}

		setPosition(22, 5);
		cout << "High Scores";
		for (int i = 0; i < 10 && score[i] != 0; i++) {
			setPosition(17 - i / 9, 8 + i);
			cout << i + 1;

			setPosition(21, 8 + i);
			cout << nickname[i];

			setPosition(35, 8 + i);
			cout << score[i];
		}
	}
	else {
		setPosition(13, 25);
		cout << "Error. Unable to create file.";
		setPosition(27, 32);
		Sleep(1500);
		system("cls");
		return;
	}
	fin.close();

	setPosition(27, 32);

	char c;
	while (true) {
		c = _getch();
		if (c == 27) {
			system("cls");
			break;
		}
	}
}