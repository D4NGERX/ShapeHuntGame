#include "toolbar.h"
#include "game.h"
#include "grid.h"
//#include <string>
using namespace std;
//#include "CMUgraphicsLib\CMUgraphics.h"

////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{

	live = 5;
	score = 0;
	level = 0;
	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_Sign.jpg";
	toolbarItemImages[ITM_ROTATE] = "images\\toolbarItems\\rotate.jpg";
	toolbarItemImages[ITM_FLIP] = "images\\toolbarItems\\Flip.jpg";
	toolbarItemImages[ITM_INCR] = "images\\toolbarItems\\Increase.jpg";
	toolbarItemImages[ITM_DCR] = "images\\toolbarItems\\Decrease.jpg";
	toolbarItemImages[ITM_HNT] = "images\\toolbarItems\\hint.jpg";
	toolbarItemImages[ITM_HOUSE] = "images\\toolbarItems\\House.jpg";
	toolbarItemImages[ITM_CAP] = "images\\toolbarItems\\Cap.jpg";
	toolbarItemImages[ITM_ENV] = "images\\toolbarItems\\Envelop.jpg";
	toolbarItemImages[ITM_BLENDER] = "images\\toolbarItems\\Blender.jpg";
	toolbarItemImages[ITM_ROCKET] = "images\\toolbarItems\\Rocket.jpg";
	toolbarItemImages[ITM_I] = "images\\toolbarItems\\I_Shape.jpg";
	
	
	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height, width, height);
}
//new by ebrahim2
 void toolbar::GameStat(){

	window* pWind = pGame->getWind();
	
	//new by ebrahim
		//Draw a game status
	pWind->SetPen(BLACK, 1);
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawString(config.GameStatusWidth, config.GameStatusHeight, "Lives:" + to_string(live));
	pWind->DrawString(config.GameStatusWidth, config.GameStatusHeight - config.seprator, "Score:" + to_string(score));
	pWind->DrawString(config.GameStatusWidth, config.GameStatusHeight - 2 * (config.seprator), "Level:" + to_string(level));
	pWind->DrawString(config.GameStatusWidth, config.GameStatusHeight +  (config.seprator), "steps:" + to_string(pGame->countSteps()));
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{

	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;


	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}


