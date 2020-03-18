#include "Headers.h"

void playerShooting(Bullet& playerBullet)
{
	if (playerBullet.fire) {
		if (playerBullet.pos.y < 27) {
			setPosition(playerBullet.pos.x, playerBullet.pos.y);
			cout << " ";
		}
		if (playerBullet.pos.y > 3) {
			playerBullet.pos.y--;
			setPosition(playerBullet.pos.x, playerBullet.pos.y);
			cout << "|";
		}
		else {
			setPosition(playerBullet.pos.x, playerBullet.pos.y);
			cout << " ";
			playerBullet.fire = false;
		}
	}
}