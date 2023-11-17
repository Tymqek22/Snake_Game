#include <iostream>
#include <windows.h>
#include "Board.h"
#include "Snake.h"

int main()
{
	Board b1;
	Snake s1(15, &b1);

	while (!s1.checkIfHit()) {
		system("cls");
		s1.placeSnake();
		b1.drawBoard();
		s1.changeDirection();
		s1.moveSnake();
		Sleep(50);
	}
	system("pause");
}
