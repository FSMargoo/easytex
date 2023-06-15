#include "easytex.h"

#include <conio.h>

void DrawSqrt(int X, int Y, int Width, int Height)
{
	TexFont SqrtFont(Height, BLACK, L"Times New Roman");
	SqrtFont.SelectToDevice();
	LINESTYLE Style;
	outtextxy(X, Y, L'√');
	if (Height >= 30)
	{
		getlinestyle(&Style);
		Style.thickness = Height / 30.f;
		setlinestyle(&Style);
	}
	setlinecolor(BLACK);
	line(X + textwidth(L'√'), Y, X + Width, Y);
}

int main()
{
	initgraph(256, 192);

	setbkcolor(WHITE);
	cleardevice();

	BeginBatchDraw();

	TexRender Render;
	Render.DisableItalic = true;
	Render.TextHeight	 = 40;
	Render.Rendering(LR"($E@{A}^{S}_{Y}@{T}&{E}@{X}$)",
					 getwidth() / 2 - Render.GetTexWidth(LR"($E@{A}^{S}_{Y}@{T}&{E}@{X}$)") / 2, 40);
	Render.TextHeight = 20;
	Render.Rendering(LR"(在 EasyX 中使用 $L&{A}T@{E}X$)",
					 getwidth() / 2 - Render.GetTexWidth(LR"(在 EasyX 中使用 $L&{A}T@{E}X$)") / 2, 120);
	Render.ResetRenderer();

	FlushBatchDraw();

	saveimage(L"./easytex.png", nullptr);

	while (true)
	{
		FlushBatchDraw();

		Sleep(16);
	}

	return 0;
}