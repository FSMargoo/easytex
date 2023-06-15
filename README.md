<div align="center">
<img src="./Readme-Src/easytex.png" width="256" height="192">
</div>

## 介绍

不知道各位是否又在 EasyX 中想要显示数学公式却难以实现的困扰呢？而现在，EasyTex， 一个基于 EasyX 的简单的仿 LaTeX 排版引擎，或许可以帮你解决一些问题，EasyTex 非常轻量地实现了一些 LaTeX 中最基本的功能，或许能成为低配版 LaTeX 替代品。

当然，EasyTex 还有很多不足，我会在日后将这些不足完善，希望各位也不要吝啬建议，可以在 GitHub 的 issues 中提出你的看法！

## 使用方法

您可以将 EasyTex 自行编译成 Lib 或者是 Dll，亦或者是你可以在你的项目中加入这两个文件：

```
easytex.cpp
easytex.h
```

就这样，就这么简单~

## 实例

下面是用 EasyTex 渲染一段 LaTeX 内容的实例：

```C++
#include "../easytex.h"

int main() {
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
)"), 40, 40);

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
```

运行后，会有如下效果：

<div align="center">
<image src="./Readme-Src/demo.png">
</div>
