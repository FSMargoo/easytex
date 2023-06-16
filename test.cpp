#include "easytex.h"

int main()
{
	initgraph(1920, 1080);
	setbkcolor(WHITE);
	cleardevice();

	BeginBatchDraw();

	TexRender Renderer;
	Renderer.TextHeight = 24;

	Renderer.Rendering(
		TEXT(
			R"(
\begin{align}
若 \int_{a}^{b}f(x)d(x).x=\frac{-b \pm \sqrt {b^2-4ac}}{2a}，请在二维欧几里得空间 \R^{2} 中求出一个满足的 f(x). \\
补充背景：c\in\R，a\in\R，b\in\R，显然，只有当 b^{2}-4ac\lt0 时，该积分在 \R^{2} 中存在. \\
首先考虑考虑当 \int_{a}^{b}f(x)d(x).x = \frac{-b + \sqrt {b^2-4ac}}{2a} 时考虑到 [a, b] 为一定闭区间，采用 Riemann\quad integral 的定义，故设 f 为在闭区间 [a, b] 有定义的实值函数 f，令此时其黎曼和为 \Alpha 则有 \\
\Alpha=\sum^{n-1}_{i=1}f(t_{i})(x_{i+1}-x_{i})=\lim_{\N\to\inf}\int^{a}_{b}f_{\N}dx，我们不妨将原式变形：\int_{a}^{b}f(x)dx = \frac{-b + \sqrt {b^2-4ac}}{2a}=-\frac{b}{2a} + \frac{\sqrt {b^2-4ac}}{2a}，令 a=1, b=0, c=-1，发现此时 b^{2}-4ac=0+4=4，此时 \Alpha 在实数范围内存在 \Alpha=\frac{4}{2}=2，于是此时 \\
问题转换为了寻找一个[0, 1] 中的实值函数 f，使得 \sum^{n-1}_{i=1}f(t_{i})(x_{i+1}-x_{i})=1，这就非常简单了，显然我们可以找到一个符合条件的一次函数 f(x)=kx，带入得到 f(x)=2x，\\
显然地 \int^{1}_{0}f(x)dx=1\\ Q.E.D
\end{align}
)"),
		/*
		*
		观察一个极限：$\lim{x\to0}\frac{sinx}{x}=1$
		对于任意 $\lim{x\to\infity}\frac{sin\Delta}{\Delta}$ 且 $\lim{}\Delta\eq0$ 的形式，其极限都为 1$
		$F:X\rightarrow Y (X\in R)$
		For every integer $n \geq 1$, let $H$ be an arbitrary ($2^{n-1}+1$) vertex induced subgraph of $Q^{n}$, then
		$\Delta(H) \geq \sqrt{n}$ 欧拉公式：$e^{i\pi}+1=0$
		$\int kdx=kx+C$
		$\int \frac{1}{\sqrt{x}}dx=2\sqrt{x}+C$
		$g(xy)=g(x)\cdot f(xy)+g(x)^{2}$ ($x\in \R$)
		${Z_{i}\in\C}_{i\in\N} Z\in\C$
		$\lim{i\to\infity}Z_{i}=Z$
		$z=re^{i\phi}, -\pi\ge\phi\geq\pi$
		*/
		20, 20);

	saveimage(TEXT("./demo.png"));

	while (true)
	{
		FlushBatchDraw();

		Sleep(8);
	}

	EndBatchDraw();

	return 0;
}