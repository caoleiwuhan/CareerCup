#include <iostream>

using namespace std;

// 在长宽为row、col的screen中，用color填充(x,y)以及与x、y同色且相连的位置
void FillColor(int **screen, int row, int col, int x, int y, int newColor);

void FillColorHelp(int **screen, int row, int col, int x, int y, int oldColor, int newColor);