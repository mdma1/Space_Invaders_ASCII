#include "Headers.h"

void initializeBlocks(vector < Block >& blocks)
{
	setColor(10, 0);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 41; j++) {
			Block* temp = new Block;
			temp->condition = 2;
			temp->pos.x = 7 + j;
			temp->pos.y = 24 + i;
			setPosition(temp->pos.x, temp->pos.y);
			cout << (char)219;
			blocks.push_back(*temp);
			if (j == 4 || j == 16 || j == 28) j += 7;
		}
	}
	setColor(15, 0);
}