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
\int \frac{dx}{\sqrt{x^{2} \pm a^{2}}} = ln(x+\sqrt{x^{2}\pm a^{2}})+C \\
\lim_{x\to\infity} (1+\frac{1}{x})^{x}=e \\
f(t)=A_{0}+\sum^{\infity}_{n=1}A_{n} sin(na\Lambda+\phi_{n}), b_{n}=A_{n}cos\phi, a\Lambda=x
\end{align}
)"),
					   40, 40);

	FlushBatchDraw();

	getmessage(EM_CHAR);

	return 0;
}