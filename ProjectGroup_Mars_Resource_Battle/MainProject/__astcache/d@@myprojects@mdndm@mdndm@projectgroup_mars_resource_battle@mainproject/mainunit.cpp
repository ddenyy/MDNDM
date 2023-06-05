//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Additional_Libraries.h"
#include "Classes/Board.h"
#include "Classes/Cards.h"
#include "Classes/Robot.h"
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
        sphere -> Position -> Y -= (0.05 + root_cube -> Height * 0.5 + 0.5);
        material = new TLightMaterialSource(root_cube);

        if (artefact_type == "rare") {
            sphere -> Width = 0.8;
	        sphere -> Depth = 0.8;
            material -> Diffuse = 0x00ff0000;
            sphere -> MaterialSource = material;
        }

        if (artefact_type == "usually") {
            sphere -> Width = 0.5;
	        sphere -> Depth = 0.5;
            material -> Diffuse = 0x000000ff;
            sphere -> MaterialSource = material;
        }

        if (artefact_type == "frequent") {
            sphere -> Width = 0.3;
	        sphere -> Depth = 0.3;
            material -> Diffuse = 0x0000ff00;
            sphere -> MaterialSource = material;
        }
    }
};

class InterfaceCell
{
public:
    TCube* cube;
    InterfaceArtefact * artefact;

    ~InterfaceCell() = default;

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

    void set_hill(int height_value)
    {
        float new_height = (height_value + 1) * .95;
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
	for (int i = 1; i < NewRoute.Length(); i++)
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
        //ShowMessage(rorect -> Name);

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

class InterfaceRobot
{
public:
    TCone* cone;

    void create_robot(TDummy* RootDummy)
    {
        cone = new TCone(RootDummy);
        cone -> Parent = RootDummy;
        cone -> Height = 1.8;
        cone -> Width = 1.8;
        cone -> Depth = 1.8;
        cone -> RotationAngle -> X = 270;
    }

    void set_position(float new_x, float new_y, float new_z)
    {
        cone -> Position -> X = new_x;
        cone -> Position -> Y = new_y;
        cone -> Position -> Z = new_z;
    }

    void set_material(TLightMaterialSource* Material)
    {
        cone -> MaterialSource = Material;
    }
};

void __fastcall TMainForm::ExecuteCommand(TLabel* CardLabel)
{
    ShowMessage("Success");
}

vector <vector <InterfaceCell> > IBoard;
LogicBoard *LBoard;
vector <InterfaceCard> CardsInHand;
InterfaceRobot* IRobot;
LogicRobot* LRobot;

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
    IBoard.resize(board_height, vector <InterfaceCell>(board_width));

    //логика поля
    LBoard = new LogicBoard(board_height, board_width);
    LBoard -> generateAllHills();
    LBoard -> initAllRandomArtefacts(40);

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

            if (LBoard -> field[i][j].getHeightHill() != 0)
                IBoard[i][j].set_hill(LBoard-> field[i][j].getHeightHill());

            type_of_cell = LBoard -> field[i][j].getTypeOfArtefact();
            if (type_of_cell != "no") {
                IBoard[i][j].set_artefact(type_of_cell);
            }
        }
    }

    IBoard[board_height - 1][0].set_material(LightMaterialSourceBase);
    IBoard[0][board_width - 1].set_material(LightMaterialSourceBase);
    IBoard[0][0].set_material(LightMaterialSourceBase);
    IBoard[board_height - 1][board_width - 1].set_material(LightMaterialSourceBase);

    //создание карт
    DECK Deck;
    int num_of_cards;
    num_of_cards = 7;
    Deck.formDeck(num_of_cards);
    //Deck.shuffleDeck();

    CardsInHand.resize(num_of_cards);

    sparse_coef = CardsRect -> Width * (1.0 / num_of_cards);
    for (i = 0, curr_x = 5; i < CardsInHand.size(); i++, curr_x += sparse_coef) {
        CardsInHand[i].create_rorect(CardsRect, StoreLabel);
        CardsInHand[i].set_position(curr_x, 0);
        CardsInHand[i].rorect -> Align = TAlignLayout::Vertical;
        CardsInHand[i].rorect -> Margins -> Bottom = 5;
        CardsInHand[i].rorect -> Margins -> Top = 5;

        CardsInHand[i].rorect -> OnClick = RoundRectForExecuteCommandFuncClick;
    }

    for (i = 0; i < CardsInHand.size(); i++)
		CardsInHand[i].set_command(Deck.takeCard());

    IRobot = new InterfaceRobot;
    IRobot -> create_robot(Player1Dummy);
    IRobot -> set_position(IBoard[19][0].cube->Position->X, IBoard[19][0].cube->Position->Y - 0.9 - IBoard[19][0].cube->Height, IBoard[19][0].cube->Position->Z);
    IRobot -> set_material(LightMaterialSourceRobot1);

    LRobot = new LogicRobot;
    LRobot -> x = 19;
    LRobot -> y = 0;
    LRobot -> z = 0;
    LRobot -> rotation = 0;
    LRobot -> curr_score = 0;
    LRobot -> score = 0;
    LRobot -> board_computer_on_robot = LBoard;
    LRobot -> now_cell = LBoard -> field[LRobot -> x][LRobot -> y];

    ScoreValueLabel -> Text = "0";
    StoreValueLabel -> Text = "0";
}

void DisplayRobotMovement()
{
  	MainForm -> StoreValueLabel -> Text = IntToStr(LRobot->curr_score) + "(" + IntToStr(LRobot->num_of_artefacts) + ")";
    MainForm -> ScoreValueLabel -> Text = IntToStr(LRobot->score);

    IRobot -> set_position(IBoard[LRobot -> x][LRobot -> y].cube -> Position -> X,
				      	   IBoard[LRobot -> x][LRobot -> y].cube -> Position -> Y - 0.9 - IBoard[LRobot -> x][LRobot -> y].cube->Height,
                           IBoard[LRobot -> x][LRobot -> y].cube -> Position -> Z);
    IRobot -> cone -> RotationAngle -> Z = 90 * LRobot -> rotation;

    if (LRobot->delete_inter_artef) {
        delete IBoard[LRobot -> x][LRobot -> y].artefact->sphere;
        LRobot->delete_inter_artef = false;
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::RoundRectForExecuteCommandFuncClick(TObject *Sender)
{
    AnsiString ansi_command_type;

    if (Sender->ClassNameIs("TRoundRect")) {
        ansi_command_type = GetPropValue(Sender, "Name", true);
    }
    else
        return;

    //ShowMessage(ansi_command_type);
    string command_type = AnsiToStr(ansi_command_type);
    while(command_type.size() > 0 && command_type.back() >= '1' && command_type.back() <= '9')
        command_type.pop_back();
    //ShowMessage(ToAnsiString(command_type));

    if (command_type == "stepOne")
        LRobot -> make_step_forward();
    if (command_type == "left")
        LRobot -> command_to_turn(command_type);
    if (command_type == "right")
        LRobot -> command_to_turn(command_type);
    if (command_type == "stepToStop")
        LRobot -> move_until_stop();

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
	ScoreTB -> Height = 0.3 * (DeckRect -> Height - BackButGame -> Height);
    StoreTB -> Height = 0.7 * (DeckRect -> Height - BackButGame -> Height);
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

void __fastcall TMainForm::BackButGameClick(TObject *Sender)
{
    int i, j;
    vector<InterfaceCell> MemoryDestVecCell;
    vector<vector<InterfaceCell>> MemoryDestVecVecCell;
    for (i = 0; i < IBoard.size(); i++) {
        for (j = 0; j < IBoard[i].size(); j++) {
            delete IBoard[i][j].cube;
            delete IBoard[i][j].artefact;
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

    if (IRobot != NULL) {
        if (IRobot -> cone != NULL)
            delete IRobot -> cone;
        delete IRobot;
    }

    MainTabControl -> ActiveTab = StartTab;
}
//---------------------------------------------------------------------------

