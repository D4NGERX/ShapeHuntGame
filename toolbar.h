#pragma once
#include "gameConfig.h"
////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class game;
class toolbar
{

private:
	int height, width;	
	string toolbarItemImages[ITM_CNT]; //array to hold paths to images of diffrent items in the toolbar
	game* pGame;
	//new by ebrahim
	int live;
	int score;
	int level;
	int steps;
public:
	toolbar(game* r_pGame);
	toolbarItem getItemClicked(int x);//handles clicks on toolbar icons, returns the "enum" of the clicekd item
	void GameStat();//defining the function
};

