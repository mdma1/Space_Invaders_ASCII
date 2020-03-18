#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

#include "Game.h"
#include "Player.h"
#include "Alien.h"
#include "CommandAlien.h"
#include "Block.h"
#include "Bullet.h"

void setPosition(int i, int j);
void setColor(int text, int background);

int openMainMenu();
int openPauseMenu();
void closePauseMenu(vector < Alien >& aliens, Bullet& playerBullet, Bullet& alienBullet);

void saveScore(string str, int num);
void printHighScores();
void printHelpPage1();
void printHelpPage2();
void printHelpPage3();
void printHelp();

void inputControls(Game& game, Player& player, vector < Alien >& aliens, Bullet& playerBullet, Bullet& alienBullet);
void playerShooting(Bullet& playerBullet);
void initializeBlocks(vector < Block >& blocks);
void initializeAliens(Game& game, vector < Alien >& aliens);
void aliensMovement(Game& game, vector < Alien >& aliens);
void aliensShooting(Player& player, vector < Alien >& aliens, Bullet& enemyBullet);
void initializeCommandAlien(Game& game, CommandAlien& commandAlien);
void commandAlienMovement(Game& game, CommandAlien& commandAlien);

void alienHitCheck(Game& game, Player& player, vector < Alien >& aliens, Bullet& playerBullet);
void commandAlienHitCheck(Game& game, CommandAlien& commandAlien, Bullet& playerBullet);
void playerHitCheck(Game& game, Player& player, Bullet& alienBullet);
void blockHitCheck(vector < Alien >& aliens, vector < Block >& blocks, Bullet& playerBullet, Bullet& alienBullet);
void bulletHitCheck(Bullet& playerBullet, Bullet& alienBullet);

void gameLogic(Game& game, Player& player, vector < Alien >& aliens, CommandAlien& commandAlien, vector < Block >& blocks, Bullet& playerBullet, Bullet& alienBullet);
void resetGame(Game& game, Player& player, vector < Alien >& aliens, CommandAlien& commandAlien, vector < Block >& blocks, Bullet& alienBullet);
void startGame(Game& game, Player& player, vector < Alien >& aliens, CommandAlien& commandAlien, vector < Block >& blocks, Bullet& playerBullet, Bullet& alienBullet);
void finishGame(Game& game);