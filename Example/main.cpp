#include "../easytex.h"

int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();

	BeginBatchDraw();

	TexRender Renderer;
	Renderer.TextHeight	 = 24;
	Renderer.LineSpacing = 2;

	Renderer.Rendering(TEXT(
						   R"(
\begin{align}
Base Line 我们构造一个蒙特卡洛积分（Monte\quad Carlo\quad Integration）： \\
F_{N}=\frac{b-a}{N}\sum^{N}_{i=1}f(X_{i}) \\
其中地每一个 X_{i}(i=1,2,3,...,N) 为 [a,b] 之间的均匀连续随机变量。\\
其实 F_{N} 的数学期望即为积分结果 \Alpha E[F_{N}]=E[\frac{b-a}{N}\sum^{N}_{i=1}f(X_{i})] \\
所以有了 \int_{D}f(x)dx=\lim_{N\to\inf}\frac{1}{N}\sum^{N}_{i=1}\frac{f(X_{i})}{p(X_{i})}
\end{align}
)"),
					   40, 40);

	FlushBatchDraw();

	getmessage(EM_CHAR);

	return 0;
}