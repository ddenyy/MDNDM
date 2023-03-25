﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainUnit.h"
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
функция назначена на прямоугольник*/
void __fastcall TMainForm::GameRectButClick(TObject *Sender)
{
    MainTabControl -> ActiveTab = GameTab;


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
