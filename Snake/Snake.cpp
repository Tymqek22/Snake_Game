#include "Snake.h"
#include "Board.h"
#include <conio.h>

Snake::Snake(size_t segments, Board* gameBoard) 
	: m_snakeSegments{segments}, m_direction{'L'}, m_snakeLength{segments}, m_gameBoard{gameBoard}
{
	m_snakeSegments[0] = { 15,60 };
	int xPosition = 60;
	
	for (int i = 1; i < segments; ++i) {
		xPosition++;
		m_snakeSegments[i] = { 15,xPosition };
	}
}

void Snake::placeSnake()
{
	for (int i = 0; i < m_snakeLength; ++i) {

		m_gameBoard->assignValue(m_snakeSegments[i], 2);
	}
}

void Snake::uploadSegmentsCoords()
{
	
}

void Snake::moveSnake()
{
	std::vector<Coordinates> segmentsCoords = m_snakeSegments;

	if (m_direction == 'U') {
		m_snakeSegments[0].yPos--;
	}
	else if (m_direction == 'D') {
		m_snakeSegments[0].yPos++;
	}
	else if (m_direction == 'L') {
		m_snakeSegments[0].xPos--;
	}
	else if (m_direction == 'R') {
		m_snakeSegments[0].xPos++;
	}

	for (int i = 1; i < m_snakeLength; i++) {

		m_snakeSegments[i] = segmentsCoords[i - 1];
	}

	m_gameBoard->assignValue(segmentsCoords[segmentsCoords.size() - 1], 0);
}

void Snake::changeDirection()
{
	if (_kbhit()) {

		char sign = _getch();
		switch (sign) {
		case 'w':
			m_direction = 'U';
			break;
		case 's':
			m_direction = 'D';
			break;
		case 'a':
			m_direction = 'L';
			break;
		case 'd':
			m_direction = 'R';
			break;
		default:
			break;
		}
	}
}