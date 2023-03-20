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
void __fastcall TMainForm::RulesRectButClick(TObject *Sender)
{
    MainTabControl -> ActiveTab = RulesTab;
    RulesMemo -> Text = "There is no rules!";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AuthorsRectButClick(TObject *Sender)
{
    MainTabControl -> ActiveTab = AuthorsTab;
    AuthorsMemo -> Text = "()-()\n \\\"/  \n   `\n\t\t()-()\n\t\t \\\"/  \n\t\t   `\n\t()-()\n\t \\\"/  \n\t   `";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GameRectButClick(TObject *Sender)
{
    MainTabControl -> ActiveTab = GameTab;

}
//---------------------------------------------------------------------------

