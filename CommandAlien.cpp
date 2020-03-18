#include "Headers.h"

void initializeCommandAlien(Game& game, CommandAlien& commandAlien)
{
	commandAlien.isAlive = true;
	game.commandAlienDirection = rand() % 2;
	if (game.commandAlienDirection == 1) {
		commandAlien.pos.x = 1;
	}
	if (game.commandAlienDirection == 0) {
		game.commandAlienDirection = -1;
		commandAlien.pos.x = 50;
	}

}

void commandAlienMovement(Game& game, CommandAlien& commandAlien)
{
	setPosition(commandAlien.pos.x, commandAlien.pos.y);
	cout << "    ";
	commandAlien.pos.x += game.commandAlienDirection;
	if (commandAlien.pos.x != 0 && commandAlien.pos.x != 51) {
		setPosition(commandAlien.pos.x, commandAlien.pos.y);
		setColor(4, 0);
		cout << (char)254 << (char)254 << (char)254 << (char)254;
		setColor(15, 0);
	}
	else commandAlien.isAlive = false;
}