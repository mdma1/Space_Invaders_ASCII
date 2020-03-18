#include "Headers.h"

void alienHitCheck(Game& game, Player& player, vector < Alien >& aliens, Bullet& playerBullet)
{
	vector < Alien > ::iterator alienIterator;
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		//alien approach check
		if (alienIterator->pos.y >= player.pos.y && alienIterator->isAlive) {
			setPosition(27, 32);
			Sleep(1000);
			game.isPlaying = false;
			break;
		}
		//alien hit check
		if (	(playerBullet.fire) &&
				(playerBullet.pos.x - alienIterator->pos.x >= 0) &&
				(playerBullet.pos.x - alienIterator->pos.x <= 2) &&
				(playerBullet.pos.y == alienIterator->pos.y) &&
				(alienIterator->isAlive)
			)
		{
			alienIterator->isAlive = false;

			if (alienIterator->isAttacking == true) {
				vector < Alien > ::iterator e;
				for (e = aliens.begin(); e != aliens.end(); e++) {
					if (	(e->pos.x == alienIterator->pos.x) &&
							(e->pos.y < alienIterator->pos.y) &&
							(e->isAlive)
						)
					{
						e->isAttacking = true;
						break;
					}
				}
				alienIterator->isAttacking = false;
			}

			game.alienCounter--;
			game.aliensSpeed = game.alienCounter;
			game.score += 10 * alienIterator->type;

			setPosition(alienIterator->pos.x - 1, alienIterator->pos.y);
			cout << "    ";

			setPosition(45, 1);
			cout << "      ";

			setPosition(45, 1);
			cout << game.score;

			playerBullet.fire = false;
		}
	}
}

void commandAlienHitCheck(Game& game, CommandAlien& commandAlien, Bullet& playerBullet)
{
	if (	(playerBullet.fire) &&
			(playerBullet.pos.x - commandAlien.pos.x >= 0) &&
			(playerBullet.pos.x - commandAlien.pos.x <= 3) &&
			(playerBullet.pos.y == commandAlien.pos.y) &&
			(commandAlien.isAlive)
		)
	{
		commandAlien.isAlive = false;
		game.score += (rand() % 3 + 1) * 50;
		if (game.extraLife && rand() % 4 == 0) {
			game.lives++;
			game.extraLife = false;

			setPosition(5, 30);
			cout << "              ";

			setPosition(5, 30);
			cout << game.lives;

			setColor(10, 0);
			for (int i = 0; i < game.lives - 1; i++) {
				setPosition(4 * i + 8, 30);
				cout << (char)220 << (char)254 << (char)220;
			}

			setColor(15, 0);
		}

		setPosition(commandAlien.pos.x, commandAlien.pos.y);
		cout << "    ";

		setPosition(45, 1);
		cout << "      ";

		setPosition(45, 1);
		cout << game.score;

		playerBullet.fire = false;
	}
}

void playerHitCheck(Game& game, Player& player, Bullet& alienBullet)
{
	if (	(alienBullet.fire) &&
			(alienBullet.pos.x - player.pos.x >= 0) &&
			(alienBullet.pos.x - player.pos.x <= 2) &&
			(alienBullet.pos.y == player.pos.y)
		)
	{
		game.lives--;
		if (game.lives == 0) game.isPlaying = false;

		setPosition(player.pos.x, player.pos.y);
		setColor(4, 0);
		cout << (char)220 << (char)254 << (char)220;

		setColor(15, 0);
		setPosition(27, 32);
		Sleep(700);

		setPosition(player.pos.x, player.pos.y);
		cout << "   ";

		setPosition(27, 32);
		Sleep(1000);

		if (game.isPlaying) {
			player.pos.x = 1;

			setPosition(player.pos.x, player.pos.y);
			setColor(10, 0);
			cout << (char)220 << (char)254 << (char)220;
			setColor(15, 0);

			setPosition(5, 30);
			cout << "              ";

			setPosition(5, 30);
			cout << game.lives;

			setColor(10, 0);
			for (int i = 0; i < game.lives - 1; i++) {
				setPosition(4 * i + 8, 30);
				cout << (char)220 << (char)254 << (char)220;
			}

			setColor(15, 0);
		}

		alienBullet.fire = false;
	}
}

void blockHitCheck(vector < Alien >& aliens, vector < Block >& blocks, Bullet& playerBullet, Bullet& alienBullet)
{
	vector < Block > ::iterator blockIterator;
	setColor(10, 0);
	for (blockIterator = blocks.begin(); blockIterator != blocks.end(); blockIterator++) {
		if (	(playerBullet.fire) &&
				(playerBullet.pos.x == blockIterator->pos.x) &&
				(playerBullet.pos.y == blockIterator->pos.y) &&
				(blockIterator->condition != 0)
			)
		{
			blockIterator->condition--;

			setPosition(blockIterator->pos.x, blockIterator->pos.y);
			if (blockIterator->condition == 1) cout << (char)176;
			if (blockIterator->condition == 0) cout << " ";

			playerBullet.fire = false;
		}

		if (	(alienBullet.fire) &&
				(alienBullet.pos.x == blockIterator->pos.x) &&
				(alienBullet.pos.y == blockIterator->pos.y) &&
				(blockIterator->condition != 0)
			)
		{
			blockIterator->condition--;

			setPosition(blockIterator->pos.x, blockIterator->pos.y);
			if (blockIterator->condition == 1) cout << (char)176;
			if (blockIterator->condition == 0) cout << " ";

			alienBullet.fire = false;
		}

		vector < Alien > ::iterator alienIterator;
		for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
			if (alienIterator->pos.y >= blockIterator->pos.y && alienIterator->isAlive) {
				blockIterator->condition = 0;
			}
		}
	}
	setColor(15, 0);
}

void bulletHitCheck(Bullet& playerBullet, Bullet& alienBullet)
{
	if (	(playerBullet.fire) &&
			(alienBullet.fire) &&
			(playerBullet.pos.x == alienBullet.pos.x) &&
			(	(playerBullet.pos.y == alienBullet.pos.y) ||
				(playerBullet.pos.y == alienBullet.pos.y + 1)
			)
		)
	{
		setPosition(playerBullet.pos.x, playerBullet.pos.y);
		cout << " ";

		if (playerBullet.pos.y == alienBullet.pos.y + 1) {
			setPosition(playerBullet.pos.x, playerBullet.pos.y - 1);
			cout << " ";
		}

		playerBullet.fire = false;
		alienBullet.fire = false;
	}
}