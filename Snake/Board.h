#pragma once
#include <vector>

struct Coordinates;

class Board
{
private:
	int m_gameBoard[29][120];
	std::vector<Coordinates> m_fruitsPositions;
	int m_points;
public:
	Board();
	int getThePositionValue(const Coordinates& coords) const;
	std::vector<Coordinates> getFruitsPositions() const;
	void assignValue(const Coordinates& coords, int value);
	void drawBoard();
	void generateFruit();
	void deleteFruit(const Coordinates& coordsToDelete);
	void addPoint();
	void displayPoints();
};