#pragma once

struct Position {
	int x;
	int y;
};

struct Game {
	bool isPlaying;
	bool isRunning;
	int timeCounter;
	int lives;
	bool extraLife;
	int score;
	int level;
	int alienCounter;
	int alienStage;
	int alienSpeed;
	int alienDirection;
	int commandAlienDirection;
};
