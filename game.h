#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"

enum Levels
{
	LVL1 = 1,
	LVL2,
	LVL3,
	LVL4,
	LVL5,
};

//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;

	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	window* ExitWindow;
	Levels* lvl;
	int steps;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid

	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);
	Levels* getLevel();
	void setLevel(Levels level);
	int countSteps() const ;

	void run();	//start the game

};
// dkfmn
