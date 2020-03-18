#include "Headers.h"

int main()
{
	SetConsoleTitle("Space Invaders");
	system("mode con cols=55 lines=33");
	srand(time(NULL));

	Game game;
	Player player;
	vector < Alien > aliens;
	CommandAlien commandAlien;
	vector < Block > blocks;
	Bullet playerBullet;
	Bullet alienBullet;
	player.pos.y = 27;
	commandAlien.pos.y = 3;

	while (true) {
		
		int choice = openMainMenu();
		system("cls");

		switch (choice) {
		case 0:
			startGame(game, player, aliens, commandAlien, blocks, playerBullet, alienBullet);
			while (game.isPlaying) gameLogic(game, player, aliens, commandAlien, blocks, playerBullet, alienBullet);
			system("cls");
			if (game.isRunning) finishGame(game);
			break;
		case 1:
			printHighScores();
			break;
		case 2:
			printHelp();
			break;
		case 3:
			return 0;
		}
	}

	return 0;
}