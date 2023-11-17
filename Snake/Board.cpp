#include <iostream>
#include "Board.h"

struct Coordinates
{
	int yPos;
	int xPos;
};

Board::Board()
{
	for (int i = 0; i < 30; ++i) {

		for (int j = 0; j < 120; ++j) {
			
			if (i == 0 || i == 29 || j == 0 || j == 119) {
				m_gameBoard[i][j] = 1;
			}
			else {
				m_gameBoard[i][j] = 0;
			}
		}
	}

	m_gameBoard[15][60] = 2;
}

void Board::assignValue(const Coordinates& coords, int value)
{
	m_gameBoard[coords.yPos][coords.xPos] = value;
}

void Board::drawBoard()
{
	for (int i = 0; i < 30; ++i) {

		for (int j = 0; j < 120; ++j) {

			if (m_gameBoard[i][j] == 1) {
				std::cout << 'X';
			}
			else if (m_gameBoard[i][j] == 0) {
				std::cout << ' ';
			}
			else if (m_gameBoard[i][j] == 2) {
				std::cout << 'O';
			}
		}
		if (i != 29) {
			std::cout << '\n';
		}
	}
}

Coordinates Board::getposition()
{
	Coordinates coords{ 0,0 };
	
	for (int i = 0; i < 30; ++i) {

		for (int j = 0; j < 120; ++j) {

			if (m_gameBoard[i][j] == 2) {
				coords.yPos = i;
				coords.xPos = j;
				break;
			}
			
		}
	}

	return coords;
}

void Board::moveSnake()
{
	Coordinates currentCoords = this->getposition();
	m_gameBoard[currentCoords.yPos][currentCoords.xPos] = 0;

	currentCoords.xPos -= 1;

	m_gameBoard[currentCoords.yPos][currentCoords.xPos] = 2;
}
