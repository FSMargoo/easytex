#pragma once

#include <graphics.h>
#include <string>
#include <vector>

#ifdef UNICODE
using TexString = std::wstring;
#else
using TexString = std::string;
#endif

class TexSymbol
{
public:
	TexString Alpha()
	{
		return TEXT("¦Á");
	}
};

class TexHelper
{
public:
	static bool IsSinkingCharacter(const wchar_t &Character);
	static bool IsGreek(const wchar_t &Character);
	static bool IsCharacter(const wchar_t &Character);
	static bool IsEnglishCharacter(const wchar_t &Character);
};

class TexFont
{
public:
	TexFont();
	TexFont(const size_t &FontHeight, const COLORREF &FontColor, const TexString &FontName);

public:
	void SelectToDevice();

public:
	LOGFONT	 Font;
	COLORREF Color;
};

class TexPainter
{
public:
	static int DrawSqrt(const size_t &X, const size_t &Y, const size_t &Width, const size_t &Height);
};

class TexRender
{
public:
	int	 WordSpacing;
	int	 LineSpacing;
	int	 TextHeight;
	bool DisableItalic;
	bool InTeX;

	TexString EnglishFont;
	TexString ChineseFont;

	COLORREF TextColor;

public:
	TexRender();

public:
	int	 RenderingTex(const TexString &CommandString, size_t X, size_t Y, IMAGE *TargetDevice = nullptr,
					  bool MurseOnly = false, int *LastLineHeight = nullptr);
	void Rendering(const TexString &CommandString, size_t X, size_t Y, IMAGE *TargetDevice = nullptr);
	int	 GetTexWidth(const TexString &CommandString);
	void ResetRenderer();
	void Outtext(const size_t &X, const size_t &Y, const TCHAR *String, bool MurseOnly);
	void Outtext(const size_t &X, const size_t &Y, const TCHAR &Character, bool MurseOnly);
	int	 ScanLine(TexString::const_iterator Iterator, const TexString::const_iterator End);

private:
	TexString FetchId(TexString::const_iterator &Iterator, const TexString::const_iterator &End);
	TexString FetchAgrument(TexString::const_iterator &Iterator);
};