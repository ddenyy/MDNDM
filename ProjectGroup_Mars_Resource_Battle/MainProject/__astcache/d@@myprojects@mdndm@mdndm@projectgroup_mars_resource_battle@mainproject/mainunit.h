﻿//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Viewport3D.hpp>
#include <FMX.ActnList.hpp>
#include <System.Actions.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.Objects3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.MaterialSources.hpp>
#include <FMX.Types3D.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
//странички
	TTabControl *MainTabControl;
	TTabItem *StartTab;
	TTabItem *GameTab;
	TTabItem *RulesTab;
	TTabItem *AuthorsTab;
//кнопки переходов
	TRoundRect *RulesRectBut;
	TRectangle *BackGroundStartTabRect;
	TRoundRect *GameRectBut;
	TRoundRect *AuthorsRectBut;
	TLabel *RulesLabelBut;
	TLabel *GameLabelBut;
	TLabel *AuthorsLabelBut;
//фон и текстовые поля
	TRectangle *BackGroundRulesTabRect;
	TMemo *RulesMemo;
	TRectangle *BackGroundAuthorsTabRect;
	TMemo *AuthorsMemo;
//интерфейс странички с самой игрой
	TViewport3D *Viewport3D;
	TToolBar *ViewPort3DToolBar;
	TRectangle *DeckRect;
    TRectangle *CardsRect;
//кнопки перехода обратно на стартовую страницу
	TSpeedButton *BackButGame;
	TSpeedButton *BackButRules;
	TSpeedButton *BackButAuthors;
	TActionList *MainActionList;
	TChangeTabAction *GoToStartTabAction;
//компоненты самой игры
    //костыльный манекен поля для корректного вращения по оси Х
	TDummy *GroundXRotationDummy;
    //главный манекен поля для движения и оставшегося вращения
    //к нему привязывается поле
	TDummy *GroundMainDummy;
    //манекен артефактов, к нему будут привязываться все артефакты
	TDummy *ArtefactDummy;
    //манекены для игроков, пока что два потом будет больше
	TDummy *Player1Dummy;
	TDummy *Player2Dummy;
	TLightMaterialSource *LightMaterialSourceGround;
    //свет на 3д сцене
	TLight *Light;
    //разметка и компоненты для вывода параметров робота(очки, хранилище)
	TToolBar *ScoreTB;
	TToolBar *StoreTB;
	TLabel *ScoreLabel;
	TLabel *ScoreValueLabel;
	TLabel *StoreLabel;
	TRectangle *StoreValueRect;


//комменты по функциям в спп файле
	void __fastcall RulesRectButClick(TObject *Sender);
	void __fastcall AuthorsRectButClick(TObject *Sender);
	void __fastcall GameRectButClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Viewport3DMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          bool &Handled);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif