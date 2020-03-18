#include "Headers.h"

void inputControls(Game& game, Player& player, vector < Alien >& aliens, Bullet& playerBullet, Bullet& alienBullet)
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			if (player.pos.x > 1) {
				setPosition(player.pos.x, player.pos.y);
				cout << "   ";

				player.pos.x--;

				setPosition(player.pos.x, player.pos.y);
				setColor(10, 0);
				cout << (char)220 << (char)254 << (char)220;
				setColor(15, 0);
			}
			break;
		case 'd':
			if (player.pos.x < 51) {
				setPosition(player.pos.x, player.pos.y);
				cout << "   ";

				player.pos.x++;

				setPosition(player.pos.x, player.pos.y);
				setColor(10, 0);
				cout << (char)220 << (char)254 << (char)220;
				setColor(15, 0);
			}
			break;
		case 'w':
			if (!playerBullet.fire) {
				playerBullet.fire = true;
				playerBullet.pos.x = player.pos.x + 1;
				playerBullet.pos.y = player.pos.y;
			}
			break;
		case 27:
			int choice = openPauseMenu();
			switch (choice) {
			case 0:
				closePauseMenu(aliens, playerBullet, alienBullet);
				break;
			case 1:
				game.isPlaying = false;
				game.isRunning = false;
				break;
			}

			break;
		}
	}
}