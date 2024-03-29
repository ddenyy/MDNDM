﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Additional_Libraries.h"
#include "Classes/board.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}

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
    MainTabControl -> ActiveTab = GameTab;

    Board *Ground;
    Ground = new Board (3, 3);

    //Ground -> CreateBoard(GroundMainDummy, 2.0, 2.0);

    int i, j, x, y;
    for (i = 0, y = 2; i < 3; i++, y -= 2) {
        for (j = 0, x = -2; j < 3; j++, x += 2) {
            Ground -> Pole[i][j].ground = new TCube(GroundMainDummy);

            Ground -> Pole[i][j].ground -> Parent = GroundMainDummy;
            Ground -> Pole[i][j].ground -> Height = 0.25;
            Ground -> Pole[i][j].ground -> Depth = 1.95;
            Ground -> Pole[i][j].ground -> Width = 1.95;

            Ground -> Pole[i][j].ground -> Position -> Z = y;
            Ground -> Pole[i][j].ground -> Position -> X = x;
        }
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

/*функция отвечает за повороты сцены в пространстве
Привязана к viewport3d*/
void __fastcall TMainForm::Viewport3DKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
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




