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
	Renderer.Rendering(TEXT(R"(观察一个极限：$\lim{x\to0}\frac{sinx}{x}=1$
对于任意 $\lim{x\to\infity}\frac{sin\Delta}{\Delta}$ 且 $\lim{}\Delta\eq0$ 的形式，其极限都为 1$
$F:X\rightarrow Y (X\in R)$
For every integer $n \geq 1$, let $H$ be an arbitrary ($2^{n-1}+1$) vertex induced
subgraph of $Q^{n}$, then $\Delta(H) \geq \sqrt{n}$
欧拉公式：$e^{i\pi}+1=0$
$\int kdx=kx+C$
$\int \frac{1}{\sqrt{x}}dx=2\sqrt{x}+C$
$g(xy)=g(x)\cdot f(xy)+g(x)^{2}$ ($x\in \R$)
${Z_{i}\in\C}_{i\in\N} Z\in\C$
$\lim{i\to\infity}Z_{i}=Z$
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