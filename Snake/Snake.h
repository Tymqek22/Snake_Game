#pragma once
#include <vector>

struct Coordinates
{
	int yPos;
	int xPos;
};
class Board;

class Snake
{
private:
	std::vector<Coordinates> m_snakeSegments;
	char m_direction;
	size_t m_snakeLength;
	Board* m_gameBoard;

public:
	Snake(size_t segments, Board* gameBoard);
	void placeSnake();
	void uploadSegmentsCoords();
	void moveSnake();
	void changeDirection();
};