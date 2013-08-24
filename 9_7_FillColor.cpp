#include <iostream>

#include "9_7_FillColor.h"

using namespace std;

void FillColor(int **screen, int row, int col, int x, int y, int newColor)
{
	if (x < 0 || x > row || y < 0 || y > col || screen == NULL)
	{
		return;
	}
	int oldColor = screen[x][y];
	FillColorHelp(screen, row, col, x, y, oldColor, newColor);
}

void FillColorHelp(int **screen, int row, int col, int x, int y, int oldColor, int newColor)
{
	if (x < 0 || x > row || y < 0 || y > col)
	{
		return;
	}
	// ж╩сп
	if (screen[x][y] == oldColor)
	{
		screen[x][y] = newColor;
		FillColorHelp(screen, row, col, x + 1, y, oldColor, newColor);
		FillColorHelp(screen, row, col, x - 1, y, oldColor, newColor);
		FillColorHelp(screen, row, col, x, y + 1, oldColor, newColor);
		FillColorHelp(screen, row, col, x, y - 1, oldColor, newColor);
	}
}