#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}

point shape::getReferencePoint() { return RefPoint; }

shape::~shape()
{
	
}

void shape::move(int step, bool isVertical)
{
	RefPoint.move(step, isVertical);
}

int shape::getRotationAngle() { return iRotationAngle; }
int shape::getNumberOfResizeCalls() { return iResizeCalls; }

void shape::setcolor(color color)
{
	fillColor = color;
}

//point* shape::getRefPoint() { return &RefPoint; }

//void shape::move()
//{
//	cout << "RefPoint.x before moving " << RefPoint.x <<endl;
//	int const MovementConstant = 100;
//	RefPoint.x += MovementConstant;
//	cout << "RefPoint.x after moving " << RefPoint.x << endl;
//	grid* pGrid = pGame->getGrid();
//	window* pW = pGame->getWind();
//	draw();
//}

//void shape::move(ARROWS clckdArw)
//{
//	int const MovementConstant = 100;
//	if (clckdArw == RightArrow) {
//		RefPoint.x += MovementConstant;
//	}
//	else if (clckdArw == LeftArrow)
//		RefPoint.x -= MovementConstant;
//	else if (clckdArw == UpArrow)
//		RefPoint.y -= MovementConstant;
//	else if (clckdArw == DownArrow)
//		RefPoint.y += MovementConstant;
//}
