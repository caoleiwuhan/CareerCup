#include <iostream>

using namespace std;

// �ڳ���Ϊrow��col��screen�У���color���(x,y)�Լ���x��yͬɫ��������λ��
void FillColor(int **screen, int row, int col, int x, int y, int newColor);

void FillColorHelp(int **screen, int row, int col, int x, int y, int oldColor, int newColor);