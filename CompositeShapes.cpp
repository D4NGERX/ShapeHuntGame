#include "CompositeShapes.h"
#include "gameConfig.h"
#include <fstream>

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	ShapeSafeBoundaries = config.sighShape.baseHeight + 0.5 * config.sighShape.topHeight;
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	topRef = ref;	//top rect ref is the same as the sign
	baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
	refpointx = ref.x;
	refpointy = ref.y;
	csth = config.sighShape.topHeight;
	cstw = config.sighShape.topWdth;
	csbh = config.sighShape.baseHeight;
	csbw = config.sighShape.baseWdth;
}

void Sign::calcCorners() 
{
	top->calcCorners();
	base->calcCorners();
}

void Sign::draw() 
{
	base->SetColor(BEIGE);
	base->draw();
	top->SetColor(BEIGE);
	top->draw();


}

void Sign::rotate()
{
	top->rotate();
	base->getLowerBottom()->rotate(topRef);
	base->getUpperLeft()->rotate(topRef);
	
}

void Sign::move(int step, bool isVerical)
{
	topRef.move(step, isVerical);
	top->move(step, isVerical);
	base->move(step, isVerical);
	calcCorners();

}
void Sign::resizeUp()
{
	base->resizeUp();
	top->resizeUp();
	csth *= 2;
	cstw *= 2;
	csbh *= 2;
	csbw *= 2;
	point BaseRef = { refpointx, refpointy + csth/ 2 + csbh/ 2 };
	top-> setRefPoint(topRef);
	base-> setRefPoint(BaseRef);
	calcCorners();
}

void Sign::resizeDown()
{
	base->resizeDown();
	top->resizeDown();
	
	csth /= 2;
	cstw /= 2;
	csbh /= 2;
	csbw /= 2;

	// Recalculate reference points
	
	point BaseRef = { refpointx, refpointy + csth / 2 + csbh / 2 };

	// Update the positions of the rectangles
	top -> setRefPoint(topRef);
	base -> setRefPoint(BaseRef);
	calcCorners();
}
void Sign::flip() {
	top->flip();
	base->getLowerBottom()->flip(topRef);
	base->getUpperLeft()->flip(topRef);
	calcCorners();
}

ShapeType Sign::getShapeType() { return type = SIGN; }


I_Shape::I_Shape(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	midRef = ref;
	topRef = {ref.x, ref.y - config.I_Shape.midHeight / 2 - config.I_Shape.topHeight / 2};
	baseRef = {ref.x, ref.y + config.I_Shape.baseHeight / 2 + config.I_Shape.midHeight / 2};
	// ==============================================================================
	rect_pMid = new Rect(pGame, midRef, config.I_Shape.midHeight, config.I_Shape.midWdth);
	top = new Rect(pGame, topRef, config.I_Shape.topHeight, config.I_Shape.topWdth);
	base = new Rect(pGame, baseRef, config.I_Shape.baseHeight, config.I_Shape.baseWdth);
	midHeight = config.I_Shape.midHeight;
	midWidth = config.I_Shape.midWdth;
	topHeight = config.I_Shape.topHeight;
	topWidth = config.I_Shape.topWdth;
	baseHeight = config.I_Shape.baseHeight;
	baseWidth = config.I_Shape.baseWdth;
	refpointx = ref.x;
	refpointy = ref.y;
}



void I_Shape::rotate()
{
	rect_pMid->rotate();
	top->getLowerBottom()->rotate(midRef);
	top->getLowerBottom()->rotate(midRef);
	base->getLowerBottom()->rotate(midRef);
	base->getLowerBottom()->rotate(midRef);
	
}

void I_Shape::move(int step, bool isVerical)
{
	base->move(step,isVerical);
	top->move(step, isVerical);
	rect_pMid->move(step, isVerical);
	midRef.move(step, isVerical);
	calcCorners();
	
}

void I_Shape::draw() 
{
	base->draw();
	top->draw();
	rect_pMid->draw();
}



void I_Shape::calcCorners() 
{
	base->calcCorners();
	top->calcCorners();
	rect_pMid->calcCorners();
}
void I_Shape::resizeUp()
{
	base->resizeUp();
	top->resizeUp();
	rect_pMid->resizeUp();
	midHeight *= 2;
	midWidth *= 2;
	topHeight *= 2;
	topWidth *= 2;
	baseHeight *= 2;
	baseWidth *= 2;
	point MidRef = { refpointx, refpointy };
	point TopRef = { refpointx, refpointy - midHeight / 2 - topHeight / 2 };
	point BaseRef = { refpointx, refpointy + baseHeight / 2 + midHeight / 2 };
	base->setRefPoint(BaseRef);
	rect_pMid->setRefPoint(MidRef);
	top->setRefPoint(TopRef);
	calcCorners();
}

void I_Shape::resizeDown()
{
	base->resizeDown();
	top->resizeDown();
	rect_pMid->resizeDown();
	midHeight /= 2;
	midWidth /= 2;
	topHeight /= 2;
	topWidth /= 2;
	baseHeight /= 2;
	baseWidth /= 2;
	point MidRef = { refpointx, refpointy };
	point TopRef = { refpointx, refpointy - midHeight / 2 - topHeight / 2 };
	point BaseRef = { refpointx, refpointy + baseHeight / 2 + midHeight / 2 };
	base->setRefPoint(BaseRef);
	rect_pMid->setRefPoint(MidRef);
	top->setRefPoint(TopRef);
	calcCorners();
}
void I_Shape::flip()
{
}
ShapeType I_Shape::getShapeType() { return type = I; }
cHouse::cHouse(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	baseRef = ref;
	headRef = { ref.x, ref.y - config.House.baseHeight / 2 };
	// ===================================================================
	base = new Rect(pGame, baseRef, config.House.baseHeight, config.House.baseWidth);
	head = new Isso_triangle(pGame, headRef, config.House.headBase, config.House.headHeight);
	baseHeight = config.House.baseHeight;
	baseWidth = config.House.baseWidth;
	headBase = config.House.headBase;
	headHeight = config.House.headHeight;
	refpointx = ref.x;
	refpointy = ref.y;
}

void cHouse::draw()
{

	base->draw();
	head->SetColor(BLUE);
	head->draw();
}

void cHouse::calcCorners() 
{
	head->calcCorners();
	base->calcCorners();
}

void rocket::calcCorners() 
{
	baseRect->calcCorners();
	headIsso->calcCorners();
	triangle_pBottomRight->calcCorners();
	triangle_pBottomLeft->calcCorners();

}
void Blender::calcCorners() 
{
	TopRect->calcCorners();
	BodyRect->calcCorners();
	LowerRect->calcCorners();
	TopCircle->calcCorners();
	triangle_pBottomRight->calcCorners();
	triangle_pBottomLeft->calcCorners();
}
void Envelope::calcCorners() 
{
	BodyRect->calcCorners();
	TopRect->calcCorners();
	TriRight->calcCorners();
	TriLeft->calcCorners();
}
void Cap::calcCorners() 
{
	baseRect->calcCorners();
	midTri->calcCorners();
	topCircle->calcCorners();
}

void cHouse::rotate()
{
	base->rotate();
	head->getRightLower()->rotate(baseRef);
	head->getleftLower()->rotate(baseRef);
	head->getUpperPoint()->rotate(baseRef);

}
void cHouse::resizeUp()
{
	head->resizeUp();
	base->resizeUp();
	baseHeight *= 2;
	baseWidth *= 2;
	headBase *= 2;
	headHeight *= 2;
	point HeadRef = { refpointx, refpointy - baseHeight / 2 };
	head->setRefPoint(HeadRef);



	config.House.headBase *= 2;
	config.House.baseWidth *= 2;
	config.House.headHeight *= 2;
	config.House.baseHeight *= 2;
	headRef = { refpointx, refpointy - config.House.baseHeight /2 };

	calcCorners();
}

void cHouse::resizeDown()
{

	head->resizeDown();
	base->resizeDown();
	baseHeight /= 2;
	baseWidth /= 2;
	headBase /= 2;
	headHeight /= 2;
	point HeadRef = { refpointx, refpointy - baseHeight / 2 };
	head->setRefPoint(HeadRef);
	calcCorners();
}

void cHouse::flip() {
	
	base->flip();
	head->getRightLower()->flip(baseRef);
	head->getleftLower()->flip(baseRef);
	head->getUpperPoint()->flip(baseRef);

	config.House.headBase /= 2;
	config.House.baseWidth/=2;
	config.House.headHeight/=2;
	config.House.baseHeight /= 2;
	headRef = { refpointx, refpointy - config.House.baseHeight / 2 };

	
	calcCorners();
}
	

void cHouse::move(int step, bool isVerical) 
{
	head->move(step, isVerical);
	base->move(step, isVerical);
	baseRef.move(step, isVerical);
	calcCorners();
}

ShapeType cHouse::getShapeType() { return type = House; }


rocket::rocket(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	baseRectRef = ref;
	headTriRef = { ref.x, ref.y - (config.Rocket_Shape.baseRectHeight) / 2 };
	RightLowerTriRef = { ref.x + (config.Rocket_Shape.baseRectWidth) / 2, ref.y + (config.Rocket_Shape.baseRectHeight) / 2 };
	LeftLowerTriRef = { ref.x - (config.Rocket_Shape.baseRectWidth) / 2, ref.y + (config.Rocket_Shape.baseRectHeight) / 2 };
	//=========================================================================
	baseRect = new Rect(pGame, baseRectRef, config.Rocket_Shape.baseRectHeight, config.Rocket_Shape.baseRectWidth);
	headIsso = new Isso_triangle(pGame, headTriRef, config.Rocket_Shape.headTriBase, config.Rocket_Shape.headTriHeight);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Rocket_Shape.LowerRightTriWidth, config.Rocket_Shape.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Rocket_Shape.LowerRightTriWidth), config.Rocket_Shape.LowerRightTriHeight);
	baseRectHeight = config.Rocket_Shape.baseRectHeight;
	baseRectWidth = config.Rocket_Shape.baseRectWidth;
	headTriBase = config.Rocket_Shape.headTriBase;
	headTriHeight = config.Rocket_Shape.headTriHeight;
	LowerRightTriWidth = config.Rocket_Shape.LowerRightTriWidth;
	LowerRightTriHeight = config.Rocket_Shape.LowerRightTriHeight;
	refpointx = ref.x;
	refpointy = ref.y;
}
void rocket::draw()  {
	baseRect->SetColor(BLACK);
	baseRect->draw();
	headIsso->SetColor(BLACK);
	headIsso->draw();
	triangle_pBottomRight->SetColor(BLACK);
	triangle_pBottomRight->draw();
	triangle_pBottomLeft->SetColor(BLACK);
	triangle_pBottomLeft->draw();

}

void rocket::rotate()
{
	baseRect->rotate();
	headIsso->getUpperPoint()->rotate(baseRectRef);
	headIsso->getleftLower()->rotate(baseRectRef);
	headIsso->getRightLower()->rotate(baseRectRef);
	triangle_pBottomLeft->getUpperPoint()->rotate(baseRectRef);
	triangle_pBottomLeft->getleftLower()->rotate(baseRectRef);
	triangle_pBottomLeft->getrightLowerPoint()->rotate(baseRectRef);
	triangle_pBottomRight->getUpperPoint()->rotate(baseRectRef);
	triangle_pBottomRight->getleftLower()->rotate(baseRectRef);
	triangle_pBottomRight->getrightLowerPoint()->rotate(baseRectRef);
}
void rocket::resizeUp()
{
	baseRect->resizeUp();
	headIsso->resizeUp();
	triangle_pBottomRight->resizeUp();
	triangle_pBottomLeft->resizeUp();
	baseRectHeight *= 2;
	baseRectWidth *= 2;
	headTriBase *= 2;
	headTriHeight *= 2;
	LowerRightTriWidth *= 2;
	LowerRightTriHeight *= 2;
	LowerLeftTriWidth *= 2;
	LowerLeftTriHeight *= 2;
	point HeadTriRef = { refpointx, refpointy - (baseRectHeight) / 2 };
	point rightLowerTriRef = { refpointx + (baseRectWidth) / 2, refpointy + (baseRectHeight) / 2 };
	point leftLowerTriRef = { refpointx - (baseRectWidth) / 2, refpointy + (baseRectHeight) / 2 };
	
	headIsso->setRefPoint(HeadTriRef);
	triangle_pBottomRight->setRefPoint(rightLowerTriRef);
	triangle_pBottomLeft->setRefPoint(leftLowerTriRef);

	
	calcCorners();
}

void rocket::resizeDown()
{
	baseRect->resizeDown();
	headIsso->resizeDown();
	triangle_pBottomRight->resizeDown();
	triangle_pBottomLeft->resizeDown();
	baseRectHeight /= 2;
	baseRectWidth /= 2;
	headTriBase /= 2;
	headTriHeight /= 2;
	LowerRightTriWidth /= 2;
	LowerRightTriHeight /= 2;
	LowerLeftTriWidth /= 2;
	LowerLeftTriHeight /= 2;
	point HeadTriRef = { refpointx, refpointy - (baseRectHeight) / 2 };
	point rightLowerTriRef = { refpointx + (baseRectWidth) / 2, refpointy + (baseRectHeight) / 2 };
	point leftLowerTriRef = { refpointx - (baseRectWidth) / 2, refpointy + (baseRectHeight) / 2 };
	headIsso->setRefPoint(HeadTriRef);
	triangle_pBottomRight->setRefPoint(rightLowerTriRef);
	triangle_pBottomLeft->setRefPoint(leftLowerTriRef);

	
	calcCorners();
}

void rocket::flip() {
	baseRect->flip();
	headIsso->getUpperPoint()->flip(baseRectRef);
	headIsso->getleftLower()->flip(baseRectRef);
	headIsso->getRightLower()->flip(baseRectRef);
	triangle_pBottomLeft->getUpperPoint()->flip(baseRectRef);
	triangle_pBottomLeft->getleftLower()->flip(baseRectRef);
	triangle_pBottomLeft->getrightLowerPoint()->flip(baseRectRef);
	triangle_pBottomRight->getUpperPoint()->flip(baseRectRef);
	triangle_pBottomRight->getleftLower()->flip(baseRectRef);
	triangle_pBottomRight->getrightLowerPoint()->flip(baseRectRef);
	calcCorners();
}


void rocket::move(int step, bool isVerical)
{
	baseRectRef.move(step, isVerical);
	headTriRef.move(step, isVerical);
	RightLowerTriRef.move(step, isVerical);
	LeftLowerTriRef.move(step, isVerical);
	baseRect->move(step, isVerical);
	headIsso->move(step, isVerical);
	triangle_pBottomLeft->move(step, isVerical);
	triangle_pBottomRight->move(step, isVerical);
	calcCorners();
}

ShapeType rocket::getShapeType() { return type = Rocket; }

Blender::Blender(game* r_pGame, point ref) : shape(r_pGame, ref) {
	BodyRectRef = ref;
	TopRectRef = { ref.x, ref.y - (config.Blender.BodyRectHeight) / 2 };
	TopCircleRef = { ref.x,ref.y - ((config.Blender.BodyRectHeight / 2) + config.Blender.TopRectHight + (config.Blender.TopCircleRad / 2)) };
	LowerRectRef = { ref.x, ref.y + (config.Blender.BodyRectHeight) / 2 };
	RightLowerTriRef = { ref.x + (config.Blender.BodyRectWidth) / 2, ref.y + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	LeftLowerTriRef = { ref.x - (config.Blender.BodyRectWidth) / 2, ref.y + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	//=================================================
	BodyRect = new Rect(pGame, BodyRectRef, config.Blender.BodyRectHeight, config.Blender.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Blender.TopRectHight, config.Blender.TopRectWidth);
	TopCircle = new circle(pGame, TopCircleRef, config.Blender.TopCircleRad);
	LowerRect = new Rect(pGame, LowerRectRef, config.Blender.LowerRectHeight, config.Blender.LowerRectWidth);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Blender.LowerRightTriWidth, config.Blender.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Blender.LowerRightTriWidth), config.Blender.LowerRightTriHeight);
	Rect1Height = config.Blender.BodyRectHeight;
	Rect1Width = config.Blender.BodyRectWidth;
	Rect2Height = config.Blender.TopRectHight;
	Rect2Width = config.Blender.TopRectWidth;
	Rect3Height = config.Blender.LowerRectHeight;
	Rect3Width = config.Blender.LowerRectWidth;
	circleRad = config.Blender.TopCircleRad;
	RTriBase = config.Blender.LowerRightTriWidth;
	RTriHeight = config.Blender.LowerRightTriHeight;
	LTriBase = config.Blender.LowerRightTriWidth;
	LTriHeight = config.Blender.LowerRightTriHeight;
	refpointx = ref.x;
	refpointy = ref.y;
}

void Blender::draw() {
	BodyRect->SetColor(GREEN);
	BodyRect->draw();
	TopRect->SetColor(GREEN);
	TopRect->draw();
	TopCircle->SetColor(GREEN);
	TopCircle->draw();
	triangle_pBottomRight->SetColor(GREEN);
	triangle_pBottomRight->draw();
	triangle_pBottomLeft->SetColor(GREEN);
	triangle_pBottomLeft->draw();
	LowerRect->SetColor(GREEN);
	LowerRect->draw();
}
void Blender::rotate()
{
	BodyRect->rotate();
	TopRect->getLowerBottom()->rotate(BodyRectRef);
	TopRect->getUpperLeft()->rotate(BodyRectRef);
	triangle_pBottomLeft->getUpperPoint()->rotate(BodyRectRef);
	triangle_pBottomLeft->getleftLower()->rotate(BodyRectRef);
	triangle_pBottomLeft->getrightLowerPoint()->rotate(BodyRectRef);
	triangle_pBottomRight->getUpperPoint()->rotate(BodyRectRef);
	triangle_pBottomRight->getleftLower()->rotate(BodyRectRef);
	triangle_pBottomRight->getrightLowerPoint()->rotate(BodyRectRef);
	LowerRect->getLowerBottom()->rotate(BodyRectRef);
	LowerRect->getUpperLeft()->rotate(BodyRectRef);
	TopCircle->getRefPoint()->rotate(BodyRectRef);

}

void Blender::move(int step, bool isVerical)
{
	BodyRectRef.move(step, isVerical);
	TopRectRef.move(step, isVerical);
	TopCircleRef.move(step, isVerical);
	LowerRectRef.move(step, isVerical);
	RightLowerTriRef.move(step, isVerical);
	LeftLowerTriRef.move(step, isVerical);
	TopCircle->move(step, isVerical);
	TopRect->move(step, isVerical);
	BodyRect->move(step, isVerical);
	LowerRect->move(step, isVerical);
	triangle_pBottomRight->move(step, isVerical);
	triangle_pBottomLeft->move(step, isVerical);
	calcCorners();
}



void Blender::resizeUp()
{
	BodyRect->resizeUp();
	TopRect->resizeUp();
	TopCircle->resizeUp();
	LowerRect->resizeUp();
	triangle_pBottomRight->resizeUp();
	triangle_pBottomLeft->resizeUp();
	Rect1Height*=2;
	Rect1Width*=2;
	Rect2Height*=2;
	Rect2Width*=2;
	Rect3Height*=2;
	Rect3Width*=2;
	circleRad*=2;
	RTriBase*=2;
	RTriHeight*=2;
	LTriBase*=2;
	LTriHeight*=2;
	point topRectRef = { refpointx, refpointy - (Rect2Height)  };
	point topCircleRef = { refpointx, refpointy - ((Rect1Height / 2) + Rect2Height + (circleRad / 8)) };
	point lowerRectRef = { refpointx, refpointy + (Rect1Height) / 2 };
	point rightLowerTriRef = { refpointx + (Rect1Width)/2, refpointy + ((Rect1Height) / 2) + Rect3Height / 2 };
	point leftLowerTriRef = { refpointx - (Rect1Width)/2 , refpointy + ((Rect1Height) / 2) + Rect3Height/ 2 };
	TopRect->setRefPoint(topRectRef);
	TopCircle->setRefPoint(topCircleRef);
	LowerRect->setRefPoint(lowerRectRef);
	triangle_pBottomRight-> setRefPoint(rightLowerTriRef);
	triangle_pBottomLeft-> setRefPoint(leftLowerTriRef);
	
	calcCorners();
}
void Blender::resizeDown()
{
	BodyRect->resizeDown();
	TopRect->resizeDown();
	TopCircle->resizeDown();
	LowerRect->resizeDown();
	triangle_pBottomRight->resizeDown();
	triangle_pBottomLeft->resizeDown();
	Rect1Height /= 2;
	Rect1Width /= 2;
	Rect2Height /= 2;
	Rect2Width /= 2;
	Rect3Height /= 2;
	Rect3Width /= 2;
	circleRad /= 2;
	RTriBase /= 2;
	RTriHeight /= 2;
	LTriBase /= 2;
	LTriHeight /= 2;
	point topRectRef = { refpointx, refpointy - (Rect2Height)  };
	point topCircleRef = { refpointx, refpointy - ((Rect1Height / 2) + Rect2Height + (circleRad / 8)) };
	point lowerRectRef = { refpointx, refpointy + (Rect1Height) / 2 };
	point rightLowerTriRef = { refpointx + (Rect1Width) /2, refpointy + ((Rect1Height) / 2) + Rect3Height / 2 };
	point leftLowerTriRef = { refpointx - (Rect1Width) /2, refpointy + ((Rect1Height) / 2) + Rect3Height / 2 };;
	TopRect->setRefPoint(topRectRef);
	TopCircle->setRefPoint(topCircleRef);
	LowerRect->setRefPoint(lowerRectRef);
	triangle_pBottomRight->setRefPoint(rightLowerTriRef);
	triangle_pBottomLeft->setRefPoint(leftLowerTriRef);
	calcCorners();

}
void Blender::flip() {
	BodyRect->flip();
	TopRect->getLowerBottom()->flip(BodyRectRef);
	TopRect->getUpperLeft()->flip(BodyRectRef);
	triangle_pBottomLeft->getUpperPoint()->flip(BodyRectRef);
	triangle_pBottomLeft->getleftLower()->flip(BodyRectRef);
	triangle_pBottomLeft->getrightLowerPoint()->flip(BodyRectRef);
	triangle_pBottomRight->getUpperPoint()->flip(BodyRectRef);
	triangle_pBottomRight->getleftLower()->flip(BodyRectRef);
	triangle_pBottomRight->getrightLowerPoint()->flip(BodyRectRef);
	LowerRect->getLowerBottom()->flip(BodyRectRef);
	LowerRect->getUpperLeft()->flip(BodyRectRef);
	TopCircle->getRefPoint()->flip(BodyRectRef);
	calcCorners();
}

ShapeType Blender::getShapeType() { return type = blender; }

Envelope::Envelope(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	BodyRectRef = ref;
	TopRectRef = { ref.x, ref.y - (config.Envelope.TopRectHight) / 2 };
	UpperTriRightRef = { ref.x + (config.Envelope.TopRectWidth) / 2,ref.y - (config.Envelope.BodyRectHight) / 2 };
	UpperTriLeftRef = { ref.x - (config.Envelope.TopRectWidth) / 2,ref.y - (config.Envelope.BodyRectHight) / 2 };
	//=================================================================================
	BodyRect = new Rect(pGame, BodyRectRef, config.Envelope.BodyRectHight, config.Envelope.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Envelope.TopRectHight, config.Envelope.TopRectWidth);
	TriRight = new Right_triangle(pGame, UpperTriRightRef, config.Envelope.TriWidth, config.Envelope.TriHeight);
	TriLeft = new Right_triangle(pGame, UpperTriLeftRef, -config.Envelope.TriWidth, config.Envelope.TriHeight);
	RectHeight = config.Envelope.BodyRectHight;
	RectWidth = config.Envelope.BodyRectWidth;
	TriBase = config.Envelope.TriWidth;
	TriHeight = config.Envelope.TriHeight;
	refpointx = ref.x;
	refpointy = ref.y;
}


void Envelope::draw() 

{
	BodyRect->SetColor(BROWN);
	BodyRect->draw();
	TopRect->SetColor(BROWN);
	TopRect->draw();
	TriRight->SetColor(BROWN);
	TriRight->draw();
	TriLeft->SetColor(BROWN);
	TriLeft->draw();
}

void Envelope::rotate()
{
	BodyRect->rotate();
	TopRect->getLowerBottom()->rotate(BodyRectRef);
	TopRect->getUpperLeft()->rotate(BodyRectRef);
	TriRight->getUpperPoint()->rotate(BodyRectRef);
	TriRight->getleftLower()->rotate(BodyRectRef);
	TriRight->getrightLowerPoint()->rotate(BodyRectRef);
	TriLeft->getUpperPoint()->rotate(BodyRectRef);
	TriLeft->getleftLower()->rotate(BodyRectRef);
	TriLeft->getrightLowerPoint()->rotate(BodyRectRef);
}


void Envelope::resizeUp()
{
	BodyRect->resizeUp();
	TopRect->resizeUp();
	TriRight->resizeUp();
	TriLeft->resizeUp();
	RectHeight *= 2;
	RectWidth *= 2;
	TriBase *= 2;
	TriHeight *= 2;

	point topRectRef = { refpointx, refpointy - (RectHeight) / 2 };
	point upperTriRightRef = { refpointx + (RectWidth) / 4, refpointy - (RectHeight) /2 };
	point upperTriLeftRef = { refpointx - (RectWidth) /4, refpointy - (RectHeight)  /2};
	TopRect->setRefPoint(topRectRef);
	TriRight->setRefPoint(upperTriRightRef);
	TriLeft->setRefPoint(upperTriLeftRef);
	calcCorners();
}
void Envelope::resizeDown()
{
	BodyRect->resizeDown();
	TopRect->resizeDown();
	TriRight->resizeDown();
	TriLeft->resizeDown();
	RectHeight /= 2;
	RectWidth /= 2;
	TriBase /= 2;
	TriHeight /= 2;

	point topRectRef = { refpointx, refpointy - (RectHeight) / 2 };
	point upperTriRightRef = { refpointx + (RectWidth) / 4, refpointy - (RectHeight) / 2 };
	point upperTriLeftRef = { refpointx - (RectWidth) / 4, refpointy - (RectHeight) / 2 };
	TopRect->setRefPoint(topRectRef);
	TriRight->setRefPoint(upperTriRightRef);
	TriLeft->setRefPoint(upperTriLeftRef);
	calcCorners();
}
void Envelope::flip() {
	BodyRect->flip();
	TopRect->getLowerBottom()->flip(BodyRectRef);
	TopRect->getUpperLeft()->flip(BodyRectRef);
	TriRight->getUpperPoint()->flip(BodyRectRef);
	TriRight->getleftLower()->flip(BodyRectRef);
	TriRight->getrightLowerPoint()->flip(BodyRectRef);
	TriLeft->getUpperPoint()->flip(BodyRectRef);
	TriLeft->getleftLower()->flip(BodyRectRef);
	TriLeft->getrightLowerPoint()->flip(BodyRectRef);
}

void Envelope::move(int step, bool isVerical)
{
	BodyRectRef.move(step, isVerical);
	TopRectRef.move(step, isVerical);
	UpperTriRightRef.move(step, isVerical);
	UpperTriLeftRef.move(step, isVerical);
	BodyRect->move(step, isVerical);
	TopRect->move(step, isVerical);
	TriRight->move(step, isVerical);
	TriLeft->move(step, isVerical);
	/*TriRight->getleftLower()->move(step, isVerical);
	TriRight->getrightLowerPoint()->move(step, isVerical);
	TriRight->getUpperPoint()->move(step, isVerical);
	TriLeft->getleftLower()->move(step, isVerical);
	TriLeft->getrightLowerPoint()->move(step, isVerical);
	TriLeft->getUpperPoint()->move(step, isVerical);*/
	

}

ShapeType Envelope::getShapeType() { return type = envelop; }

Cap::Cap(game* r_pGame, point ref) :shape(r_pGame, ref) {

	MidTriRef = ref;
	TopCircleRef = { ref.x,ref.y - config.Cap.midTriHeight };
	BaseRectRef = { ref.x, ref.y + config.Cap.baseRectHeight / 2 };

	//=========================================================================================
	midTri = new Isso_triangle(pGame, MidTriRef, config.Cap.midTriHeight, config.Cap.midTriHeight);
	topCircle = new circle(pGame, TopCircleRef, config.Cap.topCircleRad);
	baseRect = new Rect(pGame, BaseRectRef, config.Cap.baseRectHeight, config.Cap.baseRectWidth);
	RectHeight = config.Cap.baseRectHeight;
	RectWidth = config.Cap.baseRectWidth;
	TriBase = config.Cap.midTriWidth;
	TriHeight = config.Cap.midTriHeight;
	circlerad = config.Cap.topCircleRad;
	refpointx = ref.x;
	refpointy = ref.y;
}


void Cap::draw() 

{
	midTri->SetColor(PINK);
	midTri->draw();
	topCircle->SetColor(PINK);
	topCircle->draw();
	baseRect->SetColor(PINK);
	baseRect->draw();

}

void Cap::rotate()
{
	midTri->rotate();
	baseRect->getLowerBottom()->rotate(MidTriRef);
	baseRect->getUpperLeft()->rotate(MidTriRef);
	topCircle->getRefPoint()->rotate(MidTriRef);

}


void Cap::resizeUp()
{
	midTri->resizeUp();
	topCircle->resizeUp();
	baseRect->resizeUp();
	RectHeight *= 2;
	RectWidth *= 2;
	TriBase *= 2;
	TriHeight *= 2;
	circlerad *= 2;
	point midtriref = { refpointx, refpointy };
	point topCircleRef = { refpointx, refpointy - TriHeight };
	point baseRectRef = { refpointx, refpointy + RectHeight / 2 };
	midTri->setRefPoint(midtriref);
	topCircle->setRefPoint(topCircleRef);
	baseRect->setRefPoint(baseRectRef);
	calcCorners();
}

void Cap::resizeDown()
{
	midTri->resizeDown();
	topCircle->resizeDown();
	baseRect->resizeDown();
	RectHeight /= 2;
	RectWidth /= 2;
	TriBase /= 2;
	TriHeight /= 2;
	circlerad /= 2;
	point midtriref = { refpointx, refpointy };
	point topCircleRef = { refpointx, refpointy - TriHeight };
	point baseRectRef = { refpointx, refpointy + RectHeight / 2 };
	midTri->setRefPoint(midtriref);
	topCircle->setRefPoint(topCircleRef);
	baseRect->setRefPoint(baseRectRef);
	calcCorners();

}

void Cap::flip() {
	midTri->flip();
	baseRect->getLowerBottom()->flip(MidTriRef);
	baseRect->getUpperLeft()->flip(MidTriRef);
	topCircle->getRefPoint()->flip(MidTriRef);
}


void Cap::move(int step, bool isVerical)
{
	MidTriRef.move(step, isVerical);
	TopCircleRef.move(step, isVerical);
	BaseRectRef.move(step, isVerical);
	baseRect->move(step, isVerical);
	midTri->move(step, isVerical);
	topCircle->move(step, isVerical);
}

ShapeType Cap::getShapeType() { return type = cap; }









//=====================================================
void Cap::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 10 << endl;
	OutFile << MidTriRef.x << endl;
	OutFile << MidTriRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void Envelope::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 20 << endl;
	OutFile << BodyRectRef.x << endl;
	OutFile << BodyRectRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void Blender::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 30 << endl;
	OutFile << BodyRectRef.x << endl;
	OutFile << BodyRectRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void rocket::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 40 << endl;
	OutFile << baseRectRef.x << endl;
	OutFile << baseRectRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void cHouse::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 50 << endl;
	OutFile << baseRef.x << endl;
	OutFile << baseRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void I_Shape::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 60 << endl;
	OutFile << midRef.x << endl;
	OutFile << midRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void Sign::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 70 << endl;
	OutFile << topRef.x << endl;
	OutFile << topRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}


void Sign::DontExceed()
{
	
	if (top->getLowerBottom()->DontExceed(ShapeSafeBoundaries))
	{
		topRef -= 300;
		calcCorners();
		draw();
	}
}
void I_Shape::DontExceed()
{

}
void rocket::DontExceed(){}
void Blender::DontExceed(){}
void Cap::DontExceed(){}
void Envelope::DontExceed(){}
void cHouse::DontExceed(){}