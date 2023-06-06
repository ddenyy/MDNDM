#pragma once

AnsiString ToAnsiString(string Str)
{
	AnsiString aStr = "";
	for (int i = 0; i < Str.size(); i++)
		aStr += Str[i];

    return aStr;
}

string AnsiToStr(AnsiString NewRoute)
{
    string NewRouteStr = "";
	for (int i = 1; i <= NewRoute.Length(); i++)
		NewRouteStr += NewRoute[i];

	return NewRouteStr;
}

class InterfaceCard
{
public:
    TRoundRect* rorect;
    TLabel* sign;

    ~InterfaceCard() = default;

    void create_rorect(TRectangle *& RootRect, TLabel * RootLabel)
    {
        rorect = new TRoundRect (RootRect);
        rorect -> Parent = RootRect;
        rorect -> Height = RootRect -> Height * 0.8;
        rorect -> Width = RootRect -> Width * 0.125 * 0.85;
        rorect -> Fill -> Kind = TBrushKind::Solid;

        sign = new TLabel (rorect);
        sign -> Parent = rorect;
        sign -> Align = TAlignLayout::Center;
        sign -> Height = rorect -> Width;
        sign -> Width = rorect -> Width;
        sign -> Text = "";
        sign -> StyledSettings = RootLabel -> StyledSettings;
        sign -> Font -> Size = 50;
        sign -> TextSettings -> HorzAlign = TTextAlign::Center;
        sign -> TextSettings -> VertAlign = TTextAlign::Center;
    }

    void set_position(float new_x, float new_y)
    {
        rorect -> Position -> X = new_x;
        rorect -> Position -> Y = new_y;
    }

    void set_command(pair<string, int> command)
    {
        rorect -> Name = ToAnsiString(command.first) + IntToStr(command.second);

        if (command.first == "stepOne") {
            sign -> Text = "S";
            rorect -> Fill -> Color = claRoyalblue;
        }
        if (command.first == "stepToStop") {
            sign -> Text = "M";
            rorect -> Fill -> Color = claGold;
        }
        if (command.first == "jump") {
            sign -> Text = "J";
            rorect -> Fill -> Color = claDarkorange;
        }
        if (command.first == "left") {
            sign -> Text = "L";
            rorect -> Fill -> Color = claLightskyblue;
        }
        if (command.first == "right") {
            sign -> Text = "R";
            rorect -> Fill -> Color = claLightskyblue;
        }
        if (command.first == "back") {
            sign -> Text = "B";
            rorect -> Fill -> Color = claLightskyblue;
        }
        if (command.first == "teleportForOne") {
            sign -> Text = "T1";
            rorect -> Fill -> Color = claLightgreen;
        }
        if (command.first == "teleportForFive") {
            sign -> Text = "T2";
            rorect -> Fill -> Color = claMediumseagreen;
        }
        if (command.first == "teleportForSeven") {
            sign -> Text = "T3";
            rorect -> Fill -> Color = claDarkgreen;
        }
        if (command.first == "setTrap") {
            sign -> Text = "D";
            rorect -> Fill -> Color = claCrimson;
        }
        if (command.first == "activateTrap") {
            sign -> Text = "K";
            rorect -> Fill -> Color = claDarkred;
        }
    }
};

