﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Additional_Libraries.h"
#include "Classes/Board.h"
#include "Classes/Cards.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}

class InterfaceArtefact
{
public:
    TSphere * sphere;
    TLightMaterialSource * material;

    void create_sphere(TCube* root_cube, string &artefact_type)
    {
        sphere = new TSphere(root_cube);
        sphere -> Parent = root_cube;
        sphere -> Height = 1;
        sphere -> Width = 1;
        sphere -> Depth = 1;
        sphere -> Position -> Y -= (0.05 + root_cube -> Height * 0.5);

        if (artefact_type == "rare") {
            sphere -> Width = 0.8;
	        sphere -> Depth = 0.8;
            material -> Diffuse = claTurquoise;
            sphere -> MaterialSource = material;
        }

        if (artefact_type == "usually") {
            sphere -> Width = 0.5;
	        sphere -> Depth = 0.5;
            material -> Diffuse = claIndianred;
            sphere -> MaterialSource = material;
        }

        if (artefact_type == "frequent") {
            sphere -> Width = 0.3;
	        sphere -> Depth = 0.3;
            material -> Diffuse = claMediumspringgreen;
            sphere -> MaterialSource = material;
        }
    }
};

class InterfaceCell
{
public:
    TCube* cube;
    InterfaceArtefact * artefact;

	void create_cube(TDummy*& RootDummy)
    {
        cube = new TCube(RootDummy);
        cube -> Parent = RootDummy;
        cube -> Height = 0.25;
        cube -> Depth = 1.95;
        cube -> Width = 1.95;
    }

    void set_size(float new_height, float new_depth, float new_width)
    {
        cube -> Height = new_height;
        cube -> Depth = new_depth;
        cube -> Width = new_width;
    }

    void set_hill(float new_height)
    {
        cube -> Position -> Y -= (new_height * 0.5 - cube -> Height * 0.5);
        cube -> Height = new_height;
    }

    void set_position(float new_x, float new_y, float new_z)
    {
        cube -> Position -> X = new_x;
        cube -> Position -> Y = new_y;
        cube -> Position -> Z = new_z;
    }

    void set_material(TLightMaterialSource* Material)
    {
        cube -> MaterialSource = Material;
    }

    void set_artefact(string & artefact_type)
    {
        artefact = new InterfaceArtefact;
        artefact -> create_sphere(cube, artefact_type);
    }

};

class InterfaceCard
{
public:
    TRoundRect* rorect;
    TLabel* sign;

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

    void set_command(string command)
    {
        if (command == "stepOne") {
            sign -> Text = "S";
            rorect -> Fill -> Color = claRoyalblue;
        }
        if (command == "stepToStop") {
            sign -> Text = "M";
            rorect -> Fill -> Color = claGold;
        }
        if (command == "jump") {
            sign -> Text = "J";
            rorect -> Fill -> Color = claDarkorange;
        }
        if (command == "left") {
            sign -> Text = "L";
            rorect -> Fill -> Color = claLightskyblue;
        }
        if (command == "right") {
            sign -> Text = "R";
            rorect -> Fill -> Color = claLightskyblue;
        }
        if (command == "back") {
            sign -> Text = "B";
            rorect -> Fill -> Color = claLightskyblue;
        }
        if (command == "teleportForOne") {
            sign -> Text = "T1";
            rorect -> Fill -> Color = claLightgreen;
        }
        if (command == "teleportForFive") {
            sign -> Text = "T2";
            rorect -> Fill -> Color = claMediumseagreen;
        }
        if (command == "teleportForSeven") {
            sign -> Text = "T3";
            rorect -> Fill -> Color = claDarkgreen;
        }
        if (command == "setTrap") {
            sign -> Text = "D";
            rorect -> Fill -> Color = claCrimson;
        }
        if (command == "activateTrap") {
            sign -> Text = "K";
            rorect -> Fill -> Color = claDarkred;
        }
    }
};

//---------------------------------------------------------------------------
/*эта функция переключает вид на страничку с правилами и заполняет текстовое поле
этими правилами. Пока там стоит заглушка, потом будет считывание из файла
функция назначена на прямоугольник*/
void __fastcall TMainForm::RulesRectButClick(TObject *Sender)
{
    MainTabControl -> ActiveTab = RulesTab;
    RulesMemo -> Text = "There is no rules!";
}

//---------------------------------------------------------------------------
/*эта функция переключает на страничку с информацией об авторах. Аналогично
правилам, здесь пока заглушка, потом будет ввод из файла
функция назначена на прямоугольник*/
void __fastcall TMainForm::AuthorsRectButClick(TObject *Sender)
{
    MainTabControl -> ActiveTab = AuthorsTab;
    AuthorsMemo -> Text = "()-()\n \\\"/  \n   `\n\t\t()-()\n\t\t \\\"/  \n\t\t   `\n\t()-()\n\t \\\"/  \n\t   `";
}

//---------------------------------------------------------------------------
/*функция переключает вид на страничку с главным игровым интерфейсом.
Здесь будут вызываться все основные функции и создаваться компоненты
Функция назначена на прямоугольник*/
void __fastcall TMainForm::GameRectButClick(TObject *Sender)
{
    //turn on game page
    MainTabControl -> ActiveTab = GameTab;

    int board_height = 20, board_width = 20;

    //интерфейс поля
    vector <vector <InterfaceCell> > IBoard(board_height, vector <InterfaceCell>(board_width));

    //логика поля
    LogicBoard LBoard(board_height, board_width);
    LBoard.generateAllHills();
    LBoard.initAllRandomArtefacts(5);

    int i, j;
    float curr_x, curr_z, start_x, start_z;
    float sparse_coef = 2;//distance between two cell's centres
    string type_of_cell;

    if (board_height % 2 == 0) {
        start_x = -0.5 * 1.95 - (float)((float)board_height * 0.5 - 1) * (1.95 + 0.05);
        start_z = -start_x;
    }
    else
    {
        start_x = -0.05 - 1.95 - (float)((float)(board_height - 1) * 0.5 - 1) * (1.95 + 0.05);
        start_z = -start_x;
    }

    //creation of filed's image
    for (i = 0, curr_z = start_z; i < board_height; i++, curr_z -= sparse_coef) {
        for (j = 0, curr_x = start_x; j < board_width; j++, curr_x += sparse_coef) {
            IBoard[i][j].create_cube(GroundMainDummy);
            IBoard[i][j].set_position(curr_x, 0.0, curr_z);
            IBoard[i][j].set_material(LightMaterialSourceGround);

            if (LBoard.field[i][j].getHeightHill() != 0)
                IBoard[i][j].set_hill(LBoard.field[i][j].getHeightHill());

            type_of_cell = LBoard.field[i][j].getTypeOfArtefact();
            if (type_of_cell != "no") {
                IBoard[i][j].set_artefact(type_of_cell);
            }
        }
    }

    //создание карт
    DECK Deck;
    int num_of_cards;
    num_of_cards = 7;
    Deck.formDeck(num_of_cards);
    Deck.shuffleDeck();

    vector <InterfaceCard> CardsInHand(num_of_cards);

    sparse_coef = CardsRect -> Width * (1.0 / num_of_cards);
    for (i = 0, curr_x = 5; i < CardsInHand.size(); i++, curr_x += sparse_coef) {
        CardsInHand[i].create_rorect(CardsRect, StoreLabel);
        CardsInHand[i].set_position(curr_x, 0);
        CardsInHand[i].rorect -> Align = TAlignLayout::Vertical;
        CardsInHand[i].rorect -> Margins -> Bottom = 5;
        CardsInHand[i].rorect -> Margins -> Top = 5;
    }

    for (i = 0; i < CardsInHand.size(); i++) {
        CardsInHand[i].set_command(Deck.takeCard());
    }
}

//---------------------------------------------------------------------------
/*функция отвечает за то, чтобы с изменениям размеров окна приложения
менялись размеры компонентов, у которых они не меняются самостоятельно
функция выполняется автоматически при изменении размеров окна*/
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	CardsRect -> Height = MainForm -> Height * (1.0 / 6);
    DeckRect -> Width = MainForm -> Width * (1.0 / 6);

    //меняются объекты на DeckRect
    //вывод параметров робота
    ScoreTB -> Height = 0.3 * (DeckRect -> Height - BackButGame ->Height);
    StoreTB -> Height = 0.7 * (DeckRect -> Height - BackButGame ->Height);
    ScoreLabel -> Height = 0.48 * ScoreTB -> Height;
    ScoreValueLabel -> Height = 0.48 * ScoreTB -> Height;
    StoreLabel -> Height = 0.28 * StoreTB -> Height;
    StoreValueRect -> Height = 0.68 * StoreTB -> Height;
}

//---------------------------------------------------------------------------
/*Функция отвечает за регулировку масштаба сцены с помощью колёсика
мыши (тачпада на ноуте)
Работает, когда курсор наведен на viewport3d. Не зависит на какое место на нем
Вызывается каждый раз, когда двигается колёсико мыши(или жест на тачпаде)*/
void __fastcall TMainForm::Viewport3DMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, bool &Handled)
{
    //магическая константа, вычисленная экспериментально
    float ScaleConst = 0.00125;
    GroundMainDummy -> Scale -> X += (WheelDelta * ScaleConst);
    GroundMainDummy -> Scale -> Y += (WheelDelta * ScaleConst);
    GroundMainDummy -> Scale -> Z += (WheelDelta * ScaleConst);
}
//---------------------------------------------------------------------------
/*Field movement from keyboard*/
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
    //магические константы, установленные экспериментально
    float DeltaPosX = 0.6;
    float DeltaRotAngle = 5.0;

    //движение вправо-влево
    if (KeyChar == 'a')
        GroundMainDummy -> Position -> X -= DeltaPosX;
    if (KeyChar == 'd')
        GroundMainDummy -> Position -> X += DeltaPosX;

    //вращение вокруг вертикальной оси
    if (KeyChar == 'q')
        GroundMainDummy -> RotationAngle -> Y += DeltaRotAngle;
    if (KeyChar == 'e')
        GroundMainDummy -> RotationAngle -> Y -= DeltaRotAngle;

    //вращение вдоль горизонтальной оси, лежащей в плоскости экрана
    if (KeyChar == 'w')
        GroundXRotationDummy -> RotationAngle -> X -= DeltaRotAngle;
    if (KeyChar == 's')
        GroundXRotationDummy -> RotationAngle -> X += DeltaRotAngle;
}
//---------------------------------------------------------------------------

