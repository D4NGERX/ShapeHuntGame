#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#include "CompositeShapes.h"
//#include "RandomShape.h"
class game;
class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int height, width;
	point uprLeft;	//upper left point of the grid
	shape* shapeList[MaxShapeCount];	//2D array of shape pointers
	//vector<int> shapesList(MaxShapeCount, 0);
	shape* activeShape;	//The shape that the user works on to match to the ranom shapes
	int MatchedShapeIndex;
	int shapeCount = 1;		//current number of shapes in the list
	game* pGame;
    ofstream OutFile;//new file to save data by hema
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	void clearGridArea() const;
	bool addShape(shape* newShape);
	void setActiveShape(shape* actShape);
	shape* getActiveShape() const;
	void deleteActiveShape();
	void createRandomShape();
	void countSteps(shape* actv);
	bool matchingCheck();
	int getMatchedShapeIndex();
	void editShapeList(int Index, shape* Value, bool wannaRemove);
	void clearShapeList();
	void resetShapeCount();
	bool checkShapeList();
	void save();
	void Hint();
};


