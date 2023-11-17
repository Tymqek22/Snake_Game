#pragma once

struct Coordinates;

class Board
{
private:
	int m_gameBoard[30][120];
public:
	Board();
	int getThePositionValue(const Coordinates& coords) const;
	void assignValue(const Coordinates& coords, int value);
	void drawBoard();
	void generateFruit();
};