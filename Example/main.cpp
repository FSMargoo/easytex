#include "../easytex.h"

int main()
{
	// 开启一个 EasyX 窗口
	initgraph(640, 480);
	// 设置背景色
	setbkcolor(WHITE);
	cleardevice();

	BeginBatchDraw();

	// 定义一个 EasyTex 渲染器
	TexRender Renderer;
	// 设置字体高度
	Renderer.TextHeight = 24;
	// 设置行间距
	Renderer.LineSpacing = 4;
	// 渲染 LaTeX 内容
	Renderer.Rendering(TEXT(R"(观察一个极限：$lim_{x\rightarrow0}\frac{sinx}{x}=1$
对于任意 $lim_{x\rightarrow\infity}\frac{sin\Delta}{\Delta}$ 且 $lim\Delta\eq0$ 的形式，其极限都为 1$
$F:X\rightarrow Y (X\in R)$
For every integer $n \geq 1$, let $H$ be an arbitrary ($2^{n-1}+1$) vertex induced
subgraph of $Q^{n}$, then $\Delta(H) \geq \sqrt{n}$
)"),
					   40, 40);

	FlushBatchDraw();

	saveimage(TEXT("./demo.png"));

	while (true)
	{
		FlushBatchDraw();

		Sleep(8);
	}

	EndBatchDraw();

	return 0;
}