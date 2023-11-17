#include <iostream>
#include <random>
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

int Board::getThePositionValue(const Coordinates& coords) const
{
	return m_gameBoard[coords.yPos][coords.xPos];
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
			else if (m_gameBoard[i][j] == 3) {
				std::cout << '$';
			}
		}
		if (i != 29) {
			std::cout << '\n';
		}
	}
}

void Board::generateFruit()
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> yRange{ 1,28 };
	std::uniform_int_distribution<> xRange{ 1,118 };

	Coordinates coords{ 0,0 };
	do {
		coords.yPos = yRange(mt);
		coords.xPos = xRange(mt);
		if (this->getThePositionValue(coords) == 0) {
			this->assignValue(coords, 3);
		}

	} while (this->getThePositionValue(coords) == 0);
}