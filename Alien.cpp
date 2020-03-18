#include "Headers.h"

void initializeAliens(Game& game, vector < Alien >& aliens)
{
	//initialization of aliens
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			Alien* temp = new Alien;
			temp->isAlive = true;
			if (i == 0) temp->isAttacking = true;
			if (i == 0 || i == 1) temp->type = 1;
			if (i == 2 || i == 3) temp->type = 2;
			if (i == 4) temp->type = 3;
			temp->pos.x = j * 4 + 6;
			temp->pos.y = game.aliensStage - i * 2;
			aliens.push_back(*temp);
		}
	}

	//spawn of aliens
	vector < Alien > ::iterator alienIterator;
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		setPosition(alienIterator->pos.x, alienIterator->pos.y);
		cout << (char)201 << (char)254 << (char)187;
		setPosition(27, 32);
		Sleep(10);
	}
}

void aliensMovement(Game& game, vector < Alien >& aliens)
{
	//cleaning aliens
	vector < Alien > ::iterator alienIterator;
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		if (alienIterator->isAlive) {
			setPosition(alienIterator->pos.x, alienIterator->pos.y);
			cout << "   ";
		}
	}

	//aliens movement
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		if (alienIterator->pos.x <= 2 && alienIterator->isAlive) {
			game.aliensDirection = 1;
			vector < Alien > ::iterator e;
			for (e = aliens.begin(); e != aliens.end(); e++) e->pos.y++;
			break;
		}
		if (alienIterator->pos.x >= 50 && alienIterator->isAlive) {
			game.aliensDirection = -1;
			vector < Alien > ::iterator e;
			for (e = aliens.begin(); e != aliens.end(); e++) e->pos.y++;
			break;
		}
	}
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		alienIterator->pos.x += game.aliensDirection;
	}

	//drawing aliens
	for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
		if (alienIterator->isAlive) {
			setPosition(alienIterator->pos.x, alienIterator->pos.y);
			cout << (char)201 << (char)254 << (char)187;
		}
	}
}

void aliensShooting(Player& player, vector < Alien >& aliens, Bullet& alienBullet)
{
	if (alienBullet.fire) {
		setPosition(alienBullet.pos.x, alienBullet.pos.y);
		cout << " ";
	}

	//bullet formation
	if (!alienBullet.fire) {
		vector < Alien > ::iterator alienIterator;
		for (alienIterator = aliens.begin(); alienIterator != aliens.end(); alienIterator++) {
			if (alienIterator->isAttacking == true) {
				int Rand;
				if (abs(alienIterator->pos.x - player.pos.x) < 3) Rand = rand() % 5;
				else Rand = rand() % 40;
				if (Rand == 0) {
					alienBullet.fire = true;
					alienBullet.pos.x = alienIterator->pos.x + 1;
					alienBullet.pos.y = alienIterator->pos.y;
				}
			}
		}
	}

	//bullet movement
	if (alienBullet.fire) {
		if (alienBullet.pos.y < 28) {
			alienBullet.pos.y++;
			setPosition(alienBullet.pos.x, alienBullet.pos.y);
			cout << "|";
		}
		else {
			setPosition(alienBullet.pos.x, alienBullet.pos.y);
			cout << " ";
			alienBullet.fire = false;
		}
	}
}