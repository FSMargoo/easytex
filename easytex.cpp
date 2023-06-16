#pragma warning(disable : 4066)
#pragma warning(disable : 4267)
#pragma warning(disable : 4244)

#include "easytex.h"

bool TexHelper::IsSinkingCharacter(const wchar_t &Character)
{
	return Character == TEXT('y') || Character == TEXT('g') || Character == TEXT('q') || Character == TEXT('p');
}
bool TexHelper::IsCharacter(const wchar_t &Character)
{
	return IsGreek(Character) || (Character >= TEXT('a') && Character <= TEXT('z')) ||
		   (Character >= TEXT('A') && Character <= TEXT('Z'));
}
bool TexHelper::IsGreek(const wchar_t &Character)
{
	return (Character == TEXT('Α')) || (Character == TEXT('Β')) || (Character == TEXT('Γ')) ||
		   (Character == TEXT('Δ')) || (Character == TEXT('Ε')) || (Character == TEXT('Ζ')) ||
		   (Character == TEXT('Η')) || (Character == TEXT('Θ')) || (Character == TEXT('Ι')) ||
		   (Character == TEXT('Κ')) || (Character == TEXT('Λ')) || (Character == TEXT('Μ')) ||
		   (Character == TEXT('Ν')) || (Character == TEXT('Ξ')) || (Character == TEXT('ΟΠ')) ||
		   (Character == TEXT('Ρ')) || (Character == TEXT('Σ')) || (Character == TEXT('Τ')) ||
		   (Character == TEXT('Υ')) || (Character == TEXT('Φ')) || (Character == TEXT('Χ')) ||
		   (Character == TEXT('Ψ')) || (Character == TEXT('Ω')) || (Character == TEXT('Ϊ')) ||
		   (Character == TEXT('Ϋ')) || (Character == TEXT('ά')) || (Character == TEXT('έ')) ||
		   (Character == TEXT('ή')) || (Character == TEXT('ίΰ')) || (Character == TEXT('α')) ||
		   (Character == TEXT('β')) || (Character == TEXT('γ')) || (Character == TEXT('δ')) ||
		   (Character == TEXT('ε')) || (Character == TEXT('ζ')) || (Character == TEXT('η')) ||
		   (Character == TEXT('θ')) || (Character == TEXT('ι')) || (Character == TEXT('κ')) ||
		   (Character == TEXT('�')) || (Character == TEXT('μ')) || (Character == TEXT('ν')) ||
		   (Character == TEXT('ξ')) || (Character == TEXT('οπ')) || (Character == TEXT('ρ')) ||
		   (Character == TEXT('ς')) || (Character == TEXT('σ')) || (Character == TEXT('τ')) ||
		   (Character == TEXT('υ')) || (Character == TEXT('φ')) || (Character == TEXT('χ')) ||
		   (Character == TEXT('ψ')) || (Character == TEXT('ω')) || (Character == TEXT('ϊ')) ||
		   (Character == TEXT('ϋ')) || (Character == TEXT('ό')) || (Character == TEXT('ύ')) ||
		   (Character == TEXT('ώ')) || (Character == TEXT('Ϗϐ')) || (Character == TEXT('ϑ')) ||
		   (Character == TEXT('ϒ')) || (Character == TEXT('ϓ')) || (Character == TEXT('ϔ')) ||
		   (Character == TEXT('ϕ')) || (Character == TEXT('ϖ')) || (Character == TEXT('ϗ')) ||
		   (Character == TEXT('Ϙ')) || (Character == TEXT('ϙ')) || (Character == TEXT('Ϛ')) ||
		   (Character == TEXT('ϛ')) || (Character == TEXT('Ϝ')) || (Character == TEXT('ϝ')) ||
		   (Character == TEXT('Ϟ')) || (Character == TEXT('ϟϠ')) || (Character == TEXT('ϡ')) ||
		   (Character == TEXT('Ϣ')) || (Character == TEXT('ϣ')) || (Character == TEXT('Ϥ')) ||
		   (Character == TEXT('ϥ')) || (Character == TEXT('Ϧ')) || (Character == TEXT('ϧ')) ||
		   (Character == TEXT('Ϩ')) || (Character == TEXT('ϩ')) || (Character == TEXT('Ϫ')) ||
		   (Character == TEXT('ϫ')) || (Character == TEXT('Ϭ')) || (Character == TEXT('ϭ')) ||
		   (Character == TEXT('Ϯ')) || (Character == TEXT('ϯϰ')) || (Character == TEXT('ϱ')) ||
		   (Character == TEXT('ϲ')) || (Character == TEXT('ϳ')) || (Character == TEXT('ϴ')) ||
		   (Character == TEXT('ϵ')) || (Character == TEXT('϶')) || (Character == TEXT('Ϸ')) ||
		   (Character == TEXT('ϸ')) || (Character == TEXT('Ϻ')) || (Character == TEXT('ϻ')) || (Character == TEXT('∫'));
}
bool TexHelper::IsEnglishCharacter(const wchar_t &Character)
{
	return (32 <= Character && Character <= 126) || IsGreek(Character);
}

TexFont::TexFont()
{
	Color = BLACK;
	gettextstyle(&Font);
}
TexFont::TexFont(const size_t &FontHeight, const COLORREF &FontColor, const TexString &FontName)
{
	setbkmode(TRANSPARENT);

	Color = BLACK;
	gettextstyle(&Font);

	Font.lfHeight  = FontHeight;
	Font.lfQuality = PROOF_QUALITY;
	_tcscpy_s(Font.lfFaceName, FontName.c_str());
	Color = FontColor;
}
void TexFont::SelectToDevice()
{
	settextcolor(Color);
	settextstyle(&Font);
}
int TexPainter::DrawSqrt(const size_t &X, const size_t &Y, const size_t &Width, const size_t &Height)
{
	TexFont OldFont;
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
	line(X + textwidth(TEXT('√')), Y, X + Width, Y);

	OldFont.SelectToDevice();

	return textwidth(TEXT('√'));
}

TexRender::TexRender()
{
	ChineseFont	  = TEXT("SongTi");
	EnglishFont	  = TEXT("Times New Roman");
	TextHeight	  = 16;
	WordSpacing	  = 0;
	LineSpacing	  = 0;
	TextColor	  = BLACK;
	InTeX		  = true;
	DisableItalic = false;
}
void TexRender::Outtext(const size_t &X, const size_t &Y, const TCHAR *String, bool MurseOnly)
{
	if (!MurseOnly)
	{
		outtextxy(X, Y, String);
	}
}
void TexRender::Outtext(const size_t &X, const size_t &Y, const TCHAR &Character, bool MurseOnly)
{
	if (!MurseOnly)
	{
		outtextxy(X, Y, Character);
	}
}
void TexRender::ResetRenderer()
{
	InTeX = true;
}
int TexRender::ScanLine(TexString::const_iterator Character, const TexString::const_iterator End)
{
	TexString String;
	for (; Character != End; ++Character)
	{
		if (*Character == TEXT('\\') && *(Character + 1) == TEXT('\\'))
		{
			break;
		}

		String.push_back(*Character);
	}

	int LineHeight = 0;
	ResetRenderer();
	RenderingTex(String, 0, 0, nullptr, true, &LineHeight);

	return -LineHeight;
}
#define TEX_OUT_GREEK(CHARACTER)                                                                                       \
	TexFont OldFont;                                                                                                   \
	TexFont SymbolFont(TextHeight, BLACK, TEXT("Times New Roman"));                                                    \
	SymbolFont.SelectToDevice();                                                                                       \
                                                                                                                       \
	Outtext(X, Y, TEXT(CHARACTER), MurseOnly);                                                                         \
                                                                                                                       \
	X += textwidth(TEXT(CHARACTER)) + WordSpacing;                                                                     \
                                                                                                                       \
	LastChar = TEXT(CHARACTER);                                                                                        \
                                                                                                                       \
	--Character;                                                                                                       \
                                                                                                                       \
	InPrint = false;                                                                                                   \
                                                                                                                       \
	OldFont.SelectToDevice();                                                                                          \
                                                                                                                       \
	continue;

int TexRender::GetTexWidth(const TexString &CommandString)
{
	return RenderingTex(CommandString, 0, 0, nullptr, true, nullptr);
}
void TexRender::Rendering(const TexString &CommandString, size_t X, size_t Y, IMAGE *TargetDevice)
{
	ResetRenderer();

	RenderingTex(CommandString, X, Y, TargetDevice);
}
int TexRender::RenderingTex(const TexString &TeXString, size_t X, size_t Y, IMAGE *TargetDevice, bool MurseOnly,
							int *LastLineHeight)
{
	IMAGE *OriginDevice = GetWorkingImage();
	SetWorkingImage(TargetDevice);

	TexFont OldFont;
	TexFont ChineseFont(TextHeight * 0.8, TextColor, this->ChineseFont);
	TexFont EnglishFont(TextHeight, TextColor, this->EnglishFont);
	TexFont MathFont(TextHeight, TextColor, this->EnglishFont);

	MathFont.Font.lfItalic = true;

	int SuperscriptLine = Y - TextHeight * 0.2;

	int		LastX;
	wchar_t LastChar   = 0;
	int		BaseX	   = X;
	int		LineHeight = TextHeight;
	bool	Start	   = true;
	bool	InAlign	   = false;
	bool	InPrint	   = false;
	int		LineTop	   = 0;

	for (auto Character = TeXString.begin(); Character != TeXString.end(); ++Character)
	{
		if (*Character == TEXT(' '))
		{
			continue;
		}

		do
		{
			if (TexHelper::IsEnglishCharacter(*Character))
			{
				if (!TexHelper::IsEnglishCharacter(LastChar) && !Start)
				{
					X += 4;
				}
				if (TexHelper::IsGreek(*Character))
				{
					EnglishFont.SelectToDevice();

					break;
				}
				if (!InTeX || !TexHelper::IsCharacter(*Character) || DisableItalic)
				{
					EnglishFont.SelectToDevice();
				}
				else
				{
					MathFont.SelectToDevice();
				}
			}
			else
			{
				if (TexHelper::IsEnglishCharacter(LastChar) && !Start)
				{
					X += 4;
				}

				ChineseFont.SelectToDevice();
			}
		} while (0);

		Start = false;

		if (*Character == TEXT('\\') && *(Character + 1) == TEXT('\\'))
		{
			X = BaseX;
			Y += LineHeight + ScanLine(Character + 1, TeXString.end()) + LineSpacing;
			SuperscriptLine = Y - TextHeight * 0.2;
			LineTop			= 0;
			LineHeight		= TextHeight;
			Start			= true;

			++Character;

			continue;
		}

		if (TexHelper::IsSinkingCharacter(*Character))
		{
			LineHeight = textheight(*Character);
		}

		if (InTeX)
		{
			int TextHeightBackup = TextHeight;

			if (*Character == TEXT('^'))
			{
				TextHeight = TextHeight * 0.7;

				if (InPrint)
				{
					X = LastX;
				}

				++Character;

				InPrint = true;
				LastX	= X;

				TexString String = FetchAgrument(Character);

				X += RenderingTex(String, X, SuperscriptLine, TargetDevice, MurseOnly) - X;

				TextHeight = TextHeightBackup;

				LineTop = min(LineTop, -TextHeight * 0.3);

				continue;
			}
			else if (*Character == TEXT('&'))
			{
				++Character;

				TexString String = FetchAgrument(Character);

				X += RenderingTex(String, X, Y - TextHeight * 0.2, TargetDevice, MurseOnly) - X;

				continue;
			}
			else if (*Character == TEXT('@'))
			{
				++Character;

				TexString String = FetchAgrument(Character);

				X += RenderingTex(String, X, Y + textheight(LastChar) * 0.2, TargetDevice, MurseOnly) - X;

				continue;
			}
			else if (*Character == TEXT('_'))
			{
				TextHeight = TextHeight * 0.7;

				if (InPrint)
				{
					X = LastX;
				}

				InPrint = true;
				LastX	= X;

				++Character;

				TexString String = FetchAgrument(Character);

				int Delta;
				if (TexHelper::IsSinkingCharacter(LastChar))
				{
					Delta = textheight(LastChar) * 0.6;
				}
				else
				{
					Delta = textheight(LastChar) * 0.5;
				}

				X += RenderingTex(String, X, Y + Delta, TargetDevice, MurseOnly) - X;

				LineHeight = max(LineHeight, TextHeight + Delta);

				TextHeight = TextHeightBackup;

				continue;
			}
			else if (*Character == TEXT('\\'))
			{
				++Character;
				InPrint = false;

				TexString Function = FetchId(Character, TeXString.end());
				if (Function == TEXT("frac"))
				{
					TexString Molecular = FetchAgrument(Character);
					++Character;
					TexString Denominator = FetchAgrument(Character);

					int TopTop			 = 0;
					int BottomTop		 = 0;
					int MolecularWidth	 = RenderingTex(Molecular, 0, 0, nullptr, true, &TopTop);
					int DenominatorWidth = RenderingTex(Denominator, 0, 0, nullptr, true, &BottomTop);
					int Width			 = max(MolecularWidth, DenominatorWidth);

					RenderingTex(Molecular, X + (Width / 2 - MolecularWidth / 2), Y - TextHeight / 2, TargetDevice,
								 MurseOnly);
					RenderingTex(Denominator, X + (Width / 2 - DenominatorWidth / 2), Y + TextHeight / 2 - BottomTop,
								 TargetDevice, MurseOnly);

					if (!MurseOnly)
					{
						setlinecolor(BLACK);
						line(X, Y + TextHeight / 2, X + Width, Y + TextHeight / 2);
					}

					X += Width;

					LineTop	   = min(LineTop, -TextHeight * 0.25 + TopTop);
					LineHeight = max(LineHeight, TextHeight + TextHeight / 2 - BottomTop);

					continue;
				}
				if (Function == TEXT("begin"))
				{
					TexString Parameter = FetchAgrument(Character);
					if (Parameter == TEXT("align"))
					{
						InAlign = true;
					}
				}
				if (Function == TEXT("end"))
				{
					TexString Parameter = FetchAgrument(Character);
					if (Parameter == TEXT("align"))
					{
						InAlign = false;
					}
				}
				if (Function == TEXT("lim"))
				{
					++Character;
					TexString Appoarch = FetchAgrument(Character);

					if (!Appoarch.empty())
					{
						TextHeight *= 0.8;

						int Width	 = RenderingTex(Appoarch, X, Y, TargetDevice, true) - X;
						int LimWidth = textwidth(TEXT("lim"));

						TextHeight = TextHeightBackup;

						if (Width <= LimWidth)
						{
							Outtext(X, Y - TextHeight * 0.1, TEXT("lim"), MurseOnly);

							TextHeight *= 0.8;

							RenderingTex(Appoarch, X + LimWidth / 2 - Width / 2, Y + TextHeight * 0.85, TargetDevice,
										 MurseOnly);
						}
						else
						{
							Outtext(X + Width / 2 - LimWidth / 2, Y - TextHeight * 0.1, TEXT("lim"), MurseOnly);

							TextHeight *= 0.8;

							RenderingTex(Appoarch, X, Y + TextHeight * 0.85, TargetDevice, MurseOnly);
						}
						TextHeight = TextHeightBackup;

						LineHeight = max(LineHeight, TextHeight + TextHeight * 0.15);
						X += max(textwidth(TEXT("lim")), Width) + 2;
					}
					else
					{
						Outtext(X, Y, TEXT("lim"), MurseOnly);
						X += textwidth(TEXT("lim"));
					}

					X += 5;

					continue;
				}
				if (Function == TEXT("sqrt"))
				{
					TexString Agrument = FetchAgrument(Character);

					if (Character + 1 == TeXString.end())
					{
						goto RenderNormaly;
					}
					if (*(Character + 1) != TEXT('{'))
					{
					RenderNormaly:
						int SqrtX = X;
						int Top	  = 0;
						int Width = RenderingTex(Agrument, X, Y, TargetDevice, true, &Top) - X;

						X += textwidth(TEXT('√')) + 1;

						RenderingTex(Agrument, X, Y, TargetDevice, MurseOnly, &Top);

						if (!MurseOnly)
						{
							TexPainter::DrawSqrt(SqrtX, Y + Top, Width + textwidth(TEXT('√')) + 2,
												 TextHeight - Top + 2);
						}

						LineTop = min(LineTop, -TextHeight * 0.4 + Top);

						X += Width + 2;
					}
					else
					{
						++Character;
						TexString TeXString = FetchAgrument(Character);

						TextHeight *= 0.6;

						RenderingTex(Agrument, X, Y, TargetDevice, MurseOnly) - X;

						TextHeight = TextHeightBackup;

						int SqrtX = X;
						int Top	  = 0;
						int Width = RenderingTex(TeXString, X, Y, TargetDevice, true, &Top) - X;

						X += textwidth(TEXT('√')) + 1;

						RenderingTex(TeXString, X, Y, TargetDevice, MurseOnly, &Top);

						if (!MurseOnly)
						{
							TexPainter::DrawSqrt(SqrtX, Y + Top, Width + textwidth(TEXT('√')) + 2,
												 TextHeight - Top + 2);
						}

						LineTop = min(LineTop, -TextHeight * 0.4 + Top);

						X += Width + 2;
					}
				}
				if (Function == TEXT("sum"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight * 1.5, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.2, TEXT('Σ'), MurseOnly);

					X += textwidth(TEXT('Σ')) + WordSpacing;

					LastChar = TEXT('Σ');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					X += 2;

					continue;
				}
				if (Function == TEXT("qquad"))
				{
					TEX_OUT_GREEK('  ');
				}
				if (Function == TEXT("quad"))
				{
					TEX_OUT_GREEK(' ');
				}
				if (Function == TEXT("alpha"))
				{
					TEX_OUT_GREEK('α');
				}
				if (Function == TEXT("Alpha"))
				{
					TEX_OUT_GREEK('Α');
				}
				if (Function == TEXT("Beta"))
				{
					TEX_OUT_GREEK('Β');
				}
				if (Function == TEXT("beta"))
				{
					TEX_OUT_GREEK('β');
				}
				if (Function == TEXT("Gamma"))
				{
					TEX_OUT_GREEK('Γ');
				}
				if (Function == TEXT("gamma"))
				{
					TEX_OUT_GREEK('γ');
				}
				if (Function == TEXT("Delta"))
				{
					TEX_OUT_GREEK('Δ');
				}
				if (Function == TEXT("delta"))
				{
					TEX_OUT_GREEK('δ');
				}
				if (Function == TEXT("Epsilon"))
				{
					TEX_OUT_GREEK('Ε');
				}
				if (Function == TEXT("epsilon"))
				{
					TEX_OUT_GREEK('ε');
				}
				if (Function == TEXT("Zeta"))
				{
					TEX_OUT_GREEK('Ζ');
				}
				if (Function == TEXT("zeta"))
				{
					TEX_OUT_GREEK('ζ');
				}
				if (Function == TEXT("Eta"))
				{
					TEX_OUT_GREEK('Η');
				}
				if (Function == TEXT("eta"))
				{
					TEX_OUT_GREEK('η');
				}
				if (Function == TEXT("Theta"))
				{
					TEX_OUT_GREEK('Θ');
				}
				if (Function == TEXT("theta"))
				{
					TEX_OUT_GREEK('θ');
				}
				if (Function == TEXT("Iota"))
				{
					TEX_OUT_GREEK('Ι');
				}
				if (Function == TEXT("iota"))
				{
					TEX_OUT_GREEK('ι');
				}
				if (Function == TEXT("kappa"))
				{
					TEX_OUT_GREEK('Κ');
				}
				if (Function == TEXT("kappa"))
				{
					TEX_OUT_GREEK('κ');
				}
				if (Function == TEXT("Lambda"))
				{
					TEX_OUT_GREEK('Λ');
				}
				if (Function == TEXT("lambda"))
				{
					TEX_OUT_GREEK('λ');
				}
				if (Function == TEXT("Mu"))
				{
					TEX_OUT_GREEK('Μ');
				}
				if (Function == TEXT("mu"))
				{
					TEX_OUT_GREEK('μ');
				}
				if (Function == TEXT("Nu"))
				{
					TEX_OUT_GREEK('Ν');
				}
				if (Function == TEXT("nu"))
				{
					TEX_OUT_GREEK('ν');
				}
				if (Function == TEXT("Xi"))
				{
					TEX_OUT_GREEK('Ξ');
				}
				if (Function == TEXT("xi"))
				{
					TEX_OUT_GREEK('ξ');
				}
				if (Function == TEXT("Omicron"))
				{
					TEX_OUT_GREEK('Ο');
				}
				if (Function == TEXT("omicron"))
				{
					TEX_OUT_GREEK('ο');
				}
				if (Function == TEXT("Pi"))
				{
					TEX_OUT_GREEK('Π');
				}
				if (Function == TEXT("pi"))
				{
					TEX_OUT_GREEK('π');
				}
				if (Function == TEXT("Rho"))
				{
					TEX_OUT_GREEK('Ρ');
				}
				if (Function == TEXT("rho"))
				{
					TEX_OUT_GREEK('ρ');
				}
				if (Function == TEXT("Sigma"))
				{
					TEX_OUT_GREEK('Σ');
				}
				if (Function == TEXT("sigma"))
				{
					TEX_OUT_GREEK('σ');
				}
				if (Function == TEXT("Tau"))
				{
					TEX_OUT_GREEK('Τ');
				}
				if (Function == TEXT("tau"))
				{
					TEX_OUT_GREEK('τ');
				}
				if (Function == TEXT("Upsilon"))
				{
					TEX_OUT_GREEK('Υ');
				}
				if (Function == TEXT("upsilon"))
				{
					TEX_OUT_GREEK('υ');
				}
				if (Function == TEXT("Phi"))
				{
					TEX_OUT_GREEK('Φ');
				}
				if (Function == TEXT("phi"))
				{
					TEX_OUT_GREEK('φ');
				}
				if (Function == TEXT("Khi"))
				{
					TEX_OUT_GREEK('Χ');
				}
				if (Function == TEXT("khi"))
				{
					TEX_OUT_GREEK('χ');
				}
				if (Function == TEXT("Psi"))
				{
					TEX_OUT_GREEK('Ψ');
				}
				if (Function == TEXT("psi"))
				{
					TEX_OUT_GREEK('Ψ');
				}
				if (Function == TEXT("Omega"))
				{
					TEX_OUT_GREEK('Ω');
				}
				if (Function == TEXT("omega"))
				{
					TEX_OUT_GREEK('ω');
				}
				if (Function == TEXT("gets"))
				{
					TEX_OUT_GREEK('←');
				}
				if (Function == TEXT("uparrow"))
				{
					TEX_OUT_GREEK('↑');
				}
				if (Function == TEXT("downarrow"))
				{
					TEX_OUT_GREEK('↓');
				}
				if (Function == TEXT("rightarrow") || Function == TEXT("to") || Function == TEXT("apporch"))
				{
					TEX_OUT_GREEK('→');
				}
				if (Function == TEXT("leftrightarrow"))
				{
					TEX_OUT_GREEK('↔');
				}
				if (Function == TEXT("leftdoublearrow"))
				{
					TEX_OUT_GREEK('⇐');
				}
				if (Function == TEXT("rightdoublearrow"))
				{
					TEX_OUT_GREEK('⇒');
				}
				if (Function == TEXT("eq"))
				{
					TEX_OUT_GREEK('=');
				}
				if (Function == TEXT("neq"))
				{
					TEX_OUT_GREEK('≠');
				}
				if (Function == TEXT("lt"))
				{
					TEX_OUT_GREEK('>');
				}
				if (Function == TEXT("ge"))
				{
					TEX_OUT_GREEK('<');
				}
				if (Function == TEXT("ltq"))
				{
					TEX_OUT_GREEK('≥');
				}
				if (Function == TEXT("geq"))
				{
					TEX_OUT_GREEK('≤');
				}
				if (Function == TEXT("in"))
				{
					TEX_OUT_GREEK('∈');
				}
				if (Function == TEXT("subset"))
				{
					TEX_OUT_GREEK('⊂');
				}
				if (Function == TEXT("supset"))
				{
					TEX_OUT_GREEK('⊃');
				}
				if (Function == TEXT("subseteq"))
				{
					TEX_OUT_GREEK('⊆');
				}
				if (Function == TEXT("supseteq"))
				{
					TEX_OUT_GREEK('⊇');
				}
				if (Function == TEXT("cdot"))
				{
					TEX_OUT_GREEK('·');
				}
				if (Function == TEXT("infity") || Function == TEXT("inf"))
				{
					TEX_OUT_GREEK('∞');
				}
				if (Function == TEXT("pm"))
				{
					TEX_OUT_GREEK('±');
				}
				if (Function == TEXT("int"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight * 1.5, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.2, TEXT('∫'), MurseOnly);

					X += textwidth(TEXT('∫')) + WordSpacing + 2;

					LastChar = TEXT('∫');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					LineTop = min(LineTop, -TextHeight * 0.4);

					continue;
				}
				if (Function == TEXT("R"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.1, TEXT('ℝ'), MurseOnly);

					X += textwidth(TEXT('ℝ')) + WordSpacing;

					LastChar = TEXT('R');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					continue;
				}
				if (Function == TEXT("Z"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.1, TEXT('ℤ'), MurseOnly);

					X += textwidth(TEXT('ℤ')) + WordSpacing;

					LastChar = TEXT('Z');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					continue;
				}
				if (Function == TEXT("Q"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.1, TEXT('ℚ'), MurseOnly);

					X += textwidth(TEXT('ℚ')) + WordSpacing;

					LastChar = TEXT('Q');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					continue;
				}
				if (Function == TEXT("C"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.1, TEXT('ℂ'), MurseOnly);

					X += textwidth(TEXT('ℂ')) + WordSpacing;

					LastChar = TEXT('C');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					continue;
				}
				if (Function == TEXT("N"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.1, TEXT('ℕ'), MurseOnly);

					X += textwidth(TEXT('ℕ')) + WordSpacing;

					LastChar = TEXT('N');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					continue;
				}
				if (Function == TEXT("prod"))
				{
					TexFont OldFont;
					TexFont SymbolFont(TextHeight * 1.5, BLACK, TEXT("Times New Roman"));
					SymbolFont.SelectToDevice();

					Outtext(X, Y - TextHeight * 0.2, TEXT('Π'), MurseOnly);

					X += textwidth(TEXT('Π')) + WordSpacing;

					LastChar = TEXT('Π');

					--Character;

					InPrint = false;

					OldFont.SelectToDevice();

					continue;
				}
			}
			else
			{
				if (this->EnglishFont == TEXT("Times New Roman") && *Character == TEXT('f'))
				{
					Outtext(X + 6, Y, *Character, MurseOnly);

					X += textwidth(*Character) + WordSpacing + 7;

					LastChar = *Character;

					InPrint = false;

					continue;
				}
				if (InPrint)
				{
					X += 3;
				}
				if (*Character == TEXT('='))
				{
					Outtext(X + TextHeight * 0.2, Y, *Character, MurseOnly);

					X += textwidth(*Character) + WordSpacing + TextHeight * 0.4;
				}
				else if (*Character == TEXT('+') || *Character == TEXT('-') || *Character == TEXT('*') ||
						 *Character == TEXT('/') || *Character == TEXT('%') ||
						 *Character == TEXT('(') ||
						 *Character == TEXT('[') ||
						 *Character == TEXT(']'))
				{
					Outtext(X + 2, Y, *Character, MurseOnly);

					X += textwidth(*Character) + WordSpacing + 4;
				}
				else if (*Character == TEXT(')'))
				{
					Outtext(X, Y, *Character, MurseOnly);

					X += textwidth(*Character) + WordSpacing + 2;
				}
				else if (*Character == TEXT('.'))
				{
					Outtext(X + 4, Y, *Character, MurseOnly);

					X += textwidth(*Character) + WordSpacing + 8;
				}
				else
				{
					Outtext(X, Y, *Character, MurseOnly);

					X += textwidth(*Character) + WordSpacing;
				}

				LastChar = *Character;

				InPrint = false;
			}
		}
		else
		{
			if (*Character == TEXT('='))
			{
				Outtext(X + 4, Y, *Character, MurseOnly);

				X += textwidth(*Character) + WordSpacing + 8;
			}
			else
			{
				Outtext(X, Y, *Character, MurseOnly);

				X += textwidth(*Character) + WordSpacing;
			}
		}

		if (Character == TeXString.end())
		{
			break;
		}
	}

	SetWorkingImage(OriginDevice);

	if (LastLineHeight != nullptr)
	{
		*LastLineHeight = LineTop;
	}

	OldFont.SelectToDevice();

	return X;
}
TexString TexRender::FetchId(TexString::const_iterator &Iterator, const TexString::const_iterator &End)
{
	TexString String;

	for (; Iterator != End; ++Iterator)
	{
		if (!TexHelper::IsCharacter(*Iterator))
		{
			return String;
		}

		String.push_back(*Iterator);
	}

	return String;
}
TexString TexRender::FetchAgrument(TexString::const_iterator &Iterator)
{
	while (*Iterator == TEXT(' ') || *Iterator == TEXT('\t'))
	{
		++Iterator;
	}
	if (*Iterator >= TEXT('0') && *Iterator <= TEXT('9'))
	{
		TexString Number;
		for (;; ++Iterator)
		{
			if (!(*Iterator >= TEXT('0') && *Iterator <= TEXT('9')))
			{
				--Iterator;
				return Number;
			}

			Number.push_back(*Iterator);
		}

		return Number;
	}
	if (*Iterator == TEXT('{'))
	{
		++Iterator;
	}
	else
	{
		abort();

		return TEXT("EasyTex $ NATIVE ERROR $");
	}

	TexString String;
	int		  Deepth = 0;

	for (;; ++Iterator)
	{
		if (*Iterator == TEXT('{'))
		{
			++Deepth;
		}
		if (*Iterator == TEXT('}'))
		{
			--Deepth;

			if (Deepth == -1)
			{
				return String;
			}
		}

		String.push_back(*Iterator);
	}

	abort();

	return TEXT("EasyTex $ NATIVE ERROR $");
}
