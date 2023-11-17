#include <iostream>
#include <windows.h>
#include "Board.h"
#include "Snake.h"

int main()
{
	Board b1;
	Snake s1(15, &b1);
	int counter = 1;

	while (!s1.checkIfHit()) {
		system("cls");
		if (counter % 40 == 0) {
			b1.generateFruit();
		}
		s1.placeSnake();
		b1.drawBoard();
		s1.changeDirection();
		s1.moveSnake();
		Sleep(50);
		counter++;
	}
	system("pause");
}
