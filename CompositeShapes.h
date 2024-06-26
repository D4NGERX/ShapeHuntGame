#pragma once
#include "Basicshapes.h"



class Sign : public shape
{
	Rect* base;
	Rect* top;
	point& topRef = RefPoint;	
	point baseRef;
	int refpointx;
	int refpointy;
	int csth;
	int cstw;
	int csbh;
	int csbw;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void rotate() override;
	virtual void move(int step, bool isVerical) override;
	virtual void flip() override;
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
	//void move();
	//virtual void move() override;

};




class I_Shape : public shape // Ref at mid rect
{
	Rect* base;
	Rect* top;
	Rect* rect_pMid;
	int refpointx;
	int refpointy;
	point& midRef = RefPoint;
	point topRef;
	point baseRef;
	int midHeight;
	int midWidth;
	int topHeight;
	int topWidth;
	int baseHeight;
	int baseWidth;
public:
	I_Shape(game* r_pGame, point ref);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void rotate() override;
	virtual void move(int step, bool isVerical) override;
	virtual void flip() override;
	//virtual void move() override;
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
};

class cHouse : public shape
{
	Rect* base;
	Isso_triangle* head;
	point& baseRef = RefPoint;
	point headRef;
	int refpointx;
	int refpointy;
	//circle* test;
	int baseHeight;
	int baseWidth;
	int headBase;
	int headHeight;
public:
	cHouse(game* r_pGame, point ref);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void move(int step, bool isVerical) override;
	virtual void rotate() override;
	virtual void flip() override;
	virtual void resizeUp() override;
	virtual void resizeDown()override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
	
};



class rocket : public shape
{
	point& baseRectRef = RefPoint;
	point headTriRef;
	point RightLowerTriRef;
	point LeftLowerTriRef;
	Rect* baseRect;
	Isso_triangle* headIsso;
	Right_triangle* triangle_pBottomRight;
	Right_triangle* triangle_pBottomLeft;
	int refpointx;
	int refpointy;
	int baseRectHeight;
	int baseRectWidth;
	int headTriBase;
	int headTriHeight;
	int LowerRightTriWidth;
	int LowerRightTriHeight;
	int LowerLeftTriWidth;
	int LowerLeftTriHeight;

public:
	rocket(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	virtual void resizeUp()override;
	virtual void resizeDown()override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
};


class Blender : public shape {
	point& BodyRectRef = RefPoint;
	point TopRectRef;
	point TopCircleRef;
	point LowerRectRef;
	point RightLowerTriRef;
	point LeftLowerTriRef;
	circle* TopCircle;
	Rect* TopRect;
	Rect* BodyRect;
	Rect* LowerRect;
	Right_triangle* triangle_pBottomRight;
	Right_triangle* triangle_pBottomLeft;
	int refpointx;
	int refpointy;
	int Rect1Height;
	int Rect1Width;
	int Rect2Height;
	int Rect2Width;
	int Rect3Height;
	int Rect3Width;
	int circleRad;
	int RTriBase;
	int RTriHeight;
	int LTriBase;
	int LTriHeight;
public:
	Blender(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	virtual void resizeUp()override;
	virtual void resizeDown()override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
};



class Envelope : public shape
{
	point& BodyRectRef = RefPoint;
	point TopRectRef;
	point UpperTriRightRef;
	point UpperTriLeftRef;
	Rect* BodyRect;
	Rect* TopRect;
	Right_triangle* TriRight;
	Right_triangle* TriLeft;
	int refpointx;
	int refpointy;
	int RectHeight;
	int RectWidth;
	int TriBase;
	int TriHeight;
public:
	Envelope(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	virtual void resizeUp()override;
	virtual void resizeDown()override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
};



class Cap : public shape
{
	point& MidTriRef = RefPoint;
	point TopCircleRef;
	point BaseRectRef;
	Rect* baseRect;
	Isso_triangle* midTri;
	circle* topCircle;
	int refpointx;
	int refpointy;
	int RectHeight;
	int RectWidth;
	int TriBase;
	int TriHeight;
	int circlerad;
public:
	Cap(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	virtual void resizeUp() override;
	virtual void resizeDown()override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	virtual void DontExceed() override;
};



















//class TrigInsideCircle : public shape
//{
//	circle* circ;
//	Isso_triangle* trig;
//public:
//	TrigInsideCircle(game* r_pGame, point ref) : shape(r_pGame, ref);
//	void virtual draw() const;
//};
