﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Additional_Libraries.h"
#include "Classes/Board.h"
#include "Classes/Cards.h"
#include "Classes/Robot.h"
#include "Classes/Interfaces/InterfaceArtefact.h"
#include "Classes/Interfaces/InterfaceCell.h"
#include "Classes/Interfaces/InterfaceCard.h"
#include "Classes/Interfaces/Interfacerobot.h"
#include "Classes/Ultimate_Robot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TMainForm::ExecuteCommand(TLabel* CardLabel)
{
    ShowMessage("Success");
}

vector <vector <InterfaceCell> > IBoard;
LogicBoard *LBoard;
DECK Deck;
vector <InterfaceCard> CardsInHand;

sct_ultimate_robot Players[2];

int curr_turn;
vector<string> RobotCommands;
bool GameOver = false;

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

void create_robot(sct_ultimate_robot &Robot, TDummy *& PlayerDummy, int x, int y, TLightMaterialSource *Material)
{
    Robot.I = new InterfaceRobot(PlayerDummy);
    Robot.I -> set_position(IBoard[x][y].cube->Position->X,
    						IBoard[x][y].cube->Position->Y - 0.9 - IBoard[x][y].cube -> Height * 0.5,
                            IBoard[x][y].cube->Position->Z);
    Robot.I -> set_material(Material);

    Robot.L = new LogicRobot;
    Robot.L -> x = x;
    Robot.L -> y = y;
    Robot.L -> z = 0;
    Robot.L -> rotation = 0;
    Robot.L -> curr_score = 0;
    Robot.L -> score = 0;
    Robot.L -> board_computer_on_robot = LBoard;
    Robot.L -> now_cell = LBoard -> field[x][y];
}

//---------------------------------------------------------------------------
void DisplayRobotMovement()
{
    if (curr_turn == 0) {
        MainForm -> StoreValueLabel1 -> Text = IntToStr(Players[curr_turn].L->curr_score) + "(" + IntToStr(Players[curr_turn].L->num_of_artefacts) + ")";
	    MainForm -> ScoreValueLabel1 -> Text = IntToStr(Players[curr_turn].L->score);
    }
    else
    {
        MainForm -> StoreValueLabel2 -> Text = IntToStr(Players[curr_turn].L->curr_score) + "(" + IntToStr(Players[curr_turn].L->num_of_artefacts) + ")";
	    MainForm -> ScoreValueLabel2 -> Text = IntToStr(Players[curr_turn].L->score);
    }


    Players[curr_turn].I -> set_position(IBoard[Players[curr_turn].L -> x][Players[curr_turn].L -> y].cube -> Position -> X,
				      	   IBoard[Players[curr_turn].L -> x][Players[curr_turn].L -> y].cube -> Position -> Y - 0.9 - IBoard[Players[curr_turn].L -> x][Players[curr_turn].L -> y].cube->Height * 0.5,
                           IBoard[Players[curr_turn].L -> x][Players[curr_turn].L -> y].cube -> Position -> Z);
    Players[curr_turn].I -> rdummy -> RotationAngle -> Z = 90 * Players[curr_turn].L -> rotation;

    if (Players[curr_turn].L->delete_inter_artef) {
        IBoard[Players[curr_turn].L -> x][Players[curr_turn].L -> y].artefact->delete_interface();

        Players[curr_turn].L->delete_inter_artef = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::TurnButtonClick(TObject *Sender)
{
    if (GameOver) {
        return;
    }

    int j, i, num_of_cards = 7;
    float sparse_coef, curr_x;
    pair<string, int> new_card;

    vector<InterfaceCard> MemoryDestVecCards;
    for (j = 0; j < CardsInHand.size(); j++) {
        delete CardsInHand[j].rorect;
        CardsInHand[j].~InterfaceCard();
    }
    CardsInHand = MemoryDestVecCards;

    curr_turn = curr_turn ^ 1;
    if (curr_turn == 0)
        TurnButton -> Text = "Ход первого";
    else
        TurnButton -> Text = "Ход второго";

    CardsInHand.resize(num_of_cards);

    sparse_coef = CardsRect -> Width * (1.0 / num_of_cards);
    for (i = 0, curr_x = 5; i < CardsInHand.size(); i++, curr_x += sparse_coef) {
        CardsInHand[i].create_rorect(CardsRect, StoreLabel1);
        CardsInHand[i].set_position(curr_x, 0);
        CardsInHand[i].rorect -> Align = TAlignLayout::Vertical;
        CardsInHand[i].rorect -> Margins -> Bottom = 5;
        CardsInHand[i].rorect -> Margins -> Top = 5;

        CardsInHand[i].rorect -> OnClick = RoundRectForExecuteCommandFuncClick;
    }

    for (i = 0; i < CardsInHand.size(); i++){
        new_card = Deck.takeCard();
        if (new_card.first == "" && new_card.second == 0){
            GameOver = true;
            break;
        }
		CardsInHand[i].set_command(new_card);
    }
}

//---------------------------------------------------------------------------
/*функция переключает вид на страничку с главным игровым интерфейсом.
Здесь будут вызываться все основные функции и создаваться компоненты
Функция назначена на прямоугольник*/
void __fastcall TMainForm::GameRectButClick(TObject *Sender)
{
    //turn on game page
    MainTabControl -> ActiveTab = GameTab;
    ScoreValueLabel1 -> Text = "0";
    StoreValueLabel1 -> Text = "0";
    ScoreValueLabel2 -> Text = "0";
    StoreValueLabel2 -> Text = "0";
    TurnButton -> Text = "Ход первого";

    int board_height = 20, board_width = 20;
    //интерфейс поля
    IBoard.resize(board_height, vector <InterfaceCell>(board_width));

    //логика поля
    LBoard = new LogicBoard(board_height, board_width);
    LBoard -> generateAllHills();
    LBoard -> initAllRandomArtefacts(40);

    int i, j, k, l, max_hill_height = -1;
    float curr_x, curr_z, start_x, start_z;
    float sparse_coef = 2;//distance between two cell's centres
    string type_of_cell;

    //находим координаты первой клетки
    if (board_height % 2 == 0) {
        start_x = -0.5 * 1.95 - (float)((float)board_height * 0.5 - 1) * (1.95 + 0.05);
        start_z = -start_x;
    }
    else
    {
        start_x = -0.05 - 1.95 - (float)((float)(board_height - 1) * 0.5 - 1) * (1.95 + 0.05);
        start_z = -start_x;
    }

    //creation of field's image
    for (i = 0, curr_z = start_z; i < board_height; i++, curr_z -= sparse_coef) {
        for (j = 0, curr_x = start_x; j < board_width; j++, curr_x += sparse_coef) {
            IBoard[i][j].create_cube(GroundMainDummy);
            IBoard[i][j].set_position(curr_x, 0.0, curr_z);
            IBoard[i][j].set_material(LightMaterialSourceGrass);
        	if (LBoard-> field[i][j].getHeightHill() == 0)
            	IBoard[i][j].set_material(LightMaterialSourceLowGrass);

            if (LBoard -> field[i][j].getHeightHill() != 0) {
                IBoard[i][j].set_hill(LBoard-> field[i][j].getHeightHill());
                max_hill_height = max(max_hill_height, LBoard-> field[i][j].getHeightHill());
            }

            type_of_cell = LBoard -> field[i][j].getTypeOfArtefact();
            if (type_of_cell != "no") {
                IBoard[i][j].set_artefact(type_of_cell, LBoard -> field[i][j].get_form());
            }
        }
    }

    for (i = 0; i < board_height; i++) {
        for (j = 0; j < board_width; j++) {
            if (LBoard-> field[i][j].getHeightHill() != max_hill_height)
                continue;
            for (k = 0; k < board_height; k++) {
                for (l = 0; l < board_width; l++) {
                    if (IBoard[k][l].cube -> MaterialSource != NULL && IBoard[k][l].cube -> MaterialSource != LightMaterialSourceGrass
                    && IBoard[k][l].cube -> MaterialSource != LightMaterialSourceLowGrass)
                        continue;

                    if (abs(k - i) + abs(l - j) <= 8)
                        IBoard[k][l].set_material(LightMaterialSourceGround);
                    if (abs(k - i) + abs(l - j) <= 5)
                        IBoard[k][l].set_material(LightMaterialSourceHill);
                    if (abs(k - i) + abs(l - j) <= 3)
                        IBoard[k][l].set_material(LightMaterialSourcePike);
                }
            }
        }
    }

    IBoard[board_height - 1][0].set_material(LightMaterialSourceBase);
    IBoard[0][board_width - 1].set_material(LightMaterialSourceBase);
    IBoard[0][0].set_material(LightMaterialSourceBase);
    IBoard[board_height - 1][board_width - 1].set_material(LightMaterialSourceBase);

    //создание карт
    int num_of_cards = 7;
    Deck.formDeck(num_of_cards);
    Deck.shuffleDeck();

    CardsInHand.resize(num_of_cards);

    sparse_coef = CardsRect -> Width * (1.0 / num_of_cards);
    for (i = 0, curr_x = 5; i < CardsInHand.size(); i++, curr_x += sparse_coef) {
        CardsInHand[i].create_rorect(CardsRect, StoreLabel1);
        CardsInHand[i].set_position(curr_x, 0);
        CardsInHand[i].rorect -> Align = TAlignLayout::Vertical;
        CardsInHand[i].rorect -> Margins -> Bottom = 5;
        CardsInHand[i].rorect -> Margins -> Top = 5;

        CardsInHand[i].rorect -> OnClick = RoundRectForExecuteCommandFuncClick;
    }

    for (i = 0; i < CardsInHand.size(); i++)
		CardsInHand[i].set_command(Deck.takeCard());

    create_robot(Players[0], Player1Dummy, board_height - 1, 0, LightMaterialSourceRobot1);
    create_robot(Players[1], Player2Dummy, board_height - 1, board_height - 1, LightMaterialSourceRobot2);

    Players[0].L -> enemy_pos.first = Players[1].L -> x;
    Players[0].L -> enemy_pos.second = Players[1].L -> y;

    Players[1].L -> enemy_pos.first = Players[0].L -> x;
    Players[1].L -> enemy_pos.second = Players[0].L -> y;

    curr_turn = 0;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::RoundRectForExecuteCommandFuncClick(TObject *Sender)
{
    if (GameOver)
        return;

    AnsiString ansi_command_type;

    if (Sender->ClassNameIs("TRoundRect")) {
        ansi_command_type = GetPropValue(Sender, "Name", true);
    }
    else
        return;

    string command_type = AnsiToStr(ansi_command_type);
    string number = "";

    while(command_type.size() > 0 && command_type.back() >= '0' && command_type.back() <= '9'){
        number += command_type.back();
        command_type.pop_back();
    }

    AnsiString new_name = "shit" + ToAnsiString(number);

    SetPropValue(Sender, "Name", new_name);
    SetPropValue(Sender, "Visible", false);

    if (command_type == "stepOne")
    	Players[curr_turn].L -> make_step_forward();
    if (command_type == "left")
        Players[curr_turn].L -> command_to_turn(command_type);
    if (command_type == "right")
        Players[curr_turn].L -> command_to_turn(command_type);
    if (command_type == "stepToStop")
        Players[curr_turn].L -> move_until_stop();

    Players[curr_turn ^ 1].L -> enemy_pos.first = Players[curr_turn].L -> x;
    Players[curr_turn ^ 1].L -> enemy_pos.second = Players[curr_turn].L -> y;

    DisplayRobotMovement();
}

//---------------------------------------------------------------------------
/*функция отвечает за то, чтобы с изменениям размеров окна приложения
менялись размеры компонентов, у которых они не меняются самостоятельно
функция выполняется автоматически при изменении размеров окна*/
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	CardsBackGroundRect -> Height = MainForm -> Height * (1.0 / 6);
    CardsBackGroundRect -> Width = MainForm -> Height * (1.0 / 6);
    DeckBackGroundRect -> Width = MainForm -> Width * (1.0 / 6);

    //меняются объекты на DeckRect
    //вывод параметров робота
	ScoreTB1 -> Height = 0.37 * (DeckRect -> Height - BackButGame -> Height);
    StoreTB1 -> Height = 0.37 * (DeckRect -> Height - BackButGame -> Height);
    ScoreLabel1 -> Height = 0.48 * ScoreTB1 -> Height;
    ScoreValueLabel1 -> Height = 0.48 * ScoreTB1 -> Height;
    StoreLabel1 -> Height = 0.48 * StoreTB1 -> Height;
    StoreValueRect1 -> Height = 0.48 * StoreTB1 -> Height;

    ScoreTB2 -> Height = 0.37 * (DeckRect -> Height - BackButGame -> Height);
    StoreTB2 -> Height = 0.37 * (DeckRect -> Height - BackButGame -> Height);
    ScoreLabel2 -> Height = 0.48 * ScoreTB2 -> Height;
    ScoreValueLabel2 -> Height = 0.48 * ScoreTB2 -> Height;
    StoreLabel2 -> Height = 0.48 * StoreTB2 -> Height;
    StoreValueRect2 -> Height = 0.48 * StoreTB2 -> Height;
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

void __fastcall TMainForm::BackButGameClick(TObject *Sender)
{
    int i, j;
    vector<InterfaceCell> MemoryDestVecCell;
    vector<vector<InterfaceCell>> MemoryDestVecVecCell;
    for (i = 0; i < IBoard.size(); i++) {
        for (j = 0; j < IBoard[i].size(); j++) {
            delete IBoard[i][j].artefact;
            delete IBoard[i][j].cube;
            IBoard[i][j].~InterfaceCell();
        }
        IBoard[i] = MemoryDestVecCell;
    }
    IBoard = MemoryDestVecVecCell;

    delete LBoard;

    vector<InterfaceCard> MemoryDestVecCards;
    for (j = 0; j < CardsInHand.size(); j++) {
        delete CardsInHand[j].rorect;
        CardsInHand[j].~InterfaceCard();
    }
    CardsInHand = MemoryDestVecCards;

    if (Players[0].I != NULL) {
        if (Players[0].I -> rdummy != NULL)
            delete Players[0].I -> rdummy;
        delete Players[0].I;
    }

    if (Players[1].I != NULL) {
        if (Players[1].I -> rdummy != NULL)
            delete Players[1].I -> rdummy;
        delete Players[1].I;
    }

    MainTabControl -> ActiveTab = StartTab;
}
//---------------------------------------------------------------------------

