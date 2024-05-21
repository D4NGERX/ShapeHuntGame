#pragma once
#include <iostream>
#include <string>
#include "gameConfig.h"
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;


	void rotate(point ref)
	{


		int temp_virtual;  // virtual means that I want to test the result before use it.
		int x1 = x, y1 = y; // transformation matrix ==> 
		x1 -= ref.x;
		y1 -= ref.y;
		temp_virtual = x1;
		x1 = -y1;
		y1 = temp_virtual;
		x1 += ref.x;
		y1 += ref.y;
		bool what = isItExceeded(x1, y1);
		if (isItExceeded(x1, y1) == false) {
			x -= ref.x;
			y -= ref.y;

			int temp = x;
			x = -y;
			y = temp;

			x += ref.x;
			y += ref.y;
		}
		else
			return;
	}
	void move(int step,bool isVertical)
	{
		int x1 = x, y1 = y;
		x1 += config.gridSpacing; y1 += config.gridSpacing;

			if (isVertical == false)
				x += step; //int = 30;
			else if (isVertical == true)
				y += step;
	}

	void flip(point pnt)
	{
		x -= pnt.x;
	y -= pnt.y;
	y = -y;

	x += pnt.x;
	y += pnt.y;

	}

	bool isItExceeded(int xs, int ys)
	{
		if (xs > config.windWidth || xs < 0 || ys < 0 || ys > config.windHeight)
			return true;
		else
			return false;
	}


	bool operator ==(point other) {
		if (other.x == x && other.y == y)
			return true;
		return false;
	}

	point& operator-=(const int& value) {
		x -= value;
		y -= value;
		return *this;
	}
	friend std::ostream& operator <<(std::ostream& out, const point& other)
	{
		out << "x: " << other.x << " " << "y: " << other.y;
		return out;
	}

	bool DontExceed(int distance)
	{
		if (x > 1200) {
			x -= distance;
			return true;
		}
		if (x < 0) {
			x += distance;
			return true;
		}
		if (y > 550) {
			y -= distance;
			return true;
		}
		if (y < 60) {
			y += distance;
			return true;
		}
		return false;
	}
};

enum ShapeType
{
	//Basic shapes
	SIGN,
	I,
	House,
	cap,
	envelop,
	Rocket,
	blender,
	ShapeEnd,
};

enum ShapeOperations
{
	Rotate,
	Resize,
	OperationEnds,

};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
	game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	int iRotationAngle = 0;
	int iResizeCalls = 0;
	ShapeType type;
	int ShapeSafeBoundaries;
	//int iRotationCalls = 0;
public:
	shape(game* r_pGame, point ref);
	~shape();
	virtual void draw() = 0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	virtual void calcCorners() = 0;
	virtual void rotate() = 0;
	virtual void move(int step, bool isVertical);
	//virtual bool isExceeded() = 0;
	//virtual point* getBoundaryBox() = 0;
	virtual void flip() = 0;
	virtual point getReferencePoint();
	//virtual void resize() = 0;
	virtual void resizeUp() = 0;     //Resize the shape up
	virtual void resizeDown() = 0;	//Resize the shape down
	virtual int getRotationAngle();
	virtual int getNumberOfResizeCalls();

	void setcolor(color color);
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file

	virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file
	virtual void DontExceed() = 0;
	virtual ShapeType getShapeType() = 0;
};




