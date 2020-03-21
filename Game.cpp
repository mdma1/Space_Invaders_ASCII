#include "Headers.h"

void gameLogic(Game& game, Player& player, vector < Alien >& aliens, CommandAlien& commandAlien, vector < Block >& blocks, Bullet& playerBullet, Bullet& alienBullet)
{
	inputControls(game, player, aliens, playerBullet, alienBullet);
	playerShooting(playerBullet);
	if (game.timeCounter % game.alienSpeed == 0) alienMovement(game, aliens);
	if (game.timeCounter % 2 == 0) alienShooting(player, aliens, alienBullet);
	if (game.timeCounter % 670 == 669 && game.alienCounter > 22) initializeCommandAlien(game, commandAlien);
	if (commandAlien.isAlive && game.timeCounter % 3 == 0) commandAlienMovement(game, commandAlien);
	alienHitCheck(game, player, aliens, playerBullet);
	commandAlienHitCheck(game, commandAlien, playerBullet);
	playerHitCheck(game, player, alienBullet);
	blockHitCheck(aliens, blocks, playerBullet, alienBullet);
	bulletHitCheck(playerBullet, alienBullet);
	if (game.alienCounter == 0) resetGame(game, player, aliens, commandAlien, blocks, alienBullet);

	game.timeCounter++;

	setPosition(27, 32);
	Sleep(25);
}

void resetGame(Game& game, Player& player, vector < Alien >& aliens, CommandAlien& commandAlien, vector < Block >& blocks, Bullet& alienBullet)
{
	setPosition(27, 32);
	Sleep(200);

	game.timeCounter = 0;
	game.level++;
	game.alienCounter = 55;
	game.alienSpeed = 55;
	game.alienDirection = 1;
	commandAlien.isAlive = false;

	if (alienBullet.fire) {
		setPosition(alienBullet.pos.x, alienBullet.pos.y);
		cout << " ";
		alienBullet.fire = false;
	}

	if (game.level == 2) game.alienStage += 3;
	if (game.level == 3) game.alienStage += 2;
	if (game.level == 4 || game.level == 7) game.alienStage++;

	blocks.clear();
	aliens.clear();
	initializeBlocks(blocks);
	initializeAliens(game, aliens);

	setPosition(player.pos.x, player.pos.y);
	cout << "   ";

	player.pos.x = 1;

	setPosition(player.pos.x, player.pos.y);
	setColor(10, 0);
	cout << (char)220 << (char)254 << (char)220;
	setColor(15, 0);
}

void startGame(Game& game, Player& player, vector < Alien >& aliens, CommandAlien& commandAlien, vector < Block >& blocks, Bullet& playerBullet, Bullet& alienBullet)
{
	game.isPlaying = true;
	game.isRunning = true;
	game.timeCounter = 0;
	game.lives = 3;
	game.extraLife = true;
	game.score = 0;
	game.level = 1;
	game.alienCounter = 55;
	game.alienStage = 16;
	game.alienSpeed = 55;
	game.alienDirection = 1;
	player.pos.x = 1;
	commandAlien.isAlive = false;
	playerBullet.fire = false;
	alienBullet.fire = false;

	blocks.clear();
	aliens.clear();
	initializeBlocks(blocks);
	initializeAliens(game, aliens);

	setPosition(38, 1);
	cout << "Score: " << game.score;

	setPosition(player.pos.x, player.pos.y);
	setColor(10, 0);
	cout << (char)220 << (char)254 << (char)220;

	setPosition(0, 29);
	cout << "_______________________________________________________";

	setPosition(5, 30);
	setColor(15, 0);
	cout << game.lives;

	setColor(10, 0);
	for (int i = 0; i < game.lives - 1; i++) {
		setPosition(4 * i + 8, 30);
		cout << (char)220 << (char)254 << (char)220;
	}
	setColor(15, 0);
}

void finishGame(Game& game)
{
	game.isRunning = false;
	setPosition(23, 14);
	cout << "GAME OVER";

	setPosition(27, 32);
	Sleep(2000);

	setPosition(23, 14);
	cout << "         ";

	setPosition(5, 17);
	cout << "Score: " << game.score;

	setPosition(5, 18);
	cout << "Nickname: ";
	
	char line[64];
	bool check = true;

	while (check) {
		setPosition(15, 18);
		cin.getline(line, sizeof line);
		cin.clear();
		for (int i = 3; i < 12; i++) {
			if (line[i] == '\0') check = false;
		}
		if (check) {
			setPosition(15, 18);
			cout << "                                        ";
			setPosition(7, 27);
			cout << "Enter a nickname from 3 to 11 characters";
		}
	}

	for (int i = 0; i < 11; i++) {
		if (line[i] == ' ') line[i] = '_';
	}
	string str = line;

	if (game.score > 0 && game.score < 1000000) saveScore(str, game.score);

	system("cls");
}
