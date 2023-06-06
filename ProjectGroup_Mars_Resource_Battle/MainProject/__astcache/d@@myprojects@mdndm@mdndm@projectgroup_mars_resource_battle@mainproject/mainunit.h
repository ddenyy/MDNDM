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
	TLight *Light00;
	TToolBar *ScoreTB1;
	TToolBar *StoreTB1;
	TLabel *ScoreLabel1;
	TLabel *ScoreValueLabel1;
	TLabel *StoreLabel1;
	TRectangle *StoreValueRect1;
	TRectangle *GameBackGroundRect;
	TRectangle *CardsBackGroundRect;
	TRectangle *DeckBackGroundRect;
	TLightMaterialSource *LightMaterialSourceRobot1;
	TLightMaterialSource *LightMaterialSourceBase;
	TLabel *LabelForExecuteCommandFunc;
	TRoundRect *RoundRectForExecuteCommandFunc;
	TLabel *StoreValueLabel1;
	TLightMaterialSource *LightMaterialSourceHill;
	TLightMaterialSource *LightMaterialSourcePike;
	TLightMaterialSource *LightMaterialSourceGrass;
	TLightMaterialSource *LightMaterialSourceLowGrass;
	TButton *TurnButton;
	TLightMaterialSource *LightMaterialSourceRobot2;
	TToolBar *ScoreTB2;
	TLabel *ScoreLabel2;
	TLabel *ScoreValueLabel2;
	TToolBar *StoreTB2;
	TLabel *StoreLabel2;
	TRectangle *StoreValueRect2;
	TLabel *StoreValueLabel2;


//комменты по функциям в спп файле
	void __fastcall RulesRectButClick(TObject *Sender);
	void __fastcall AuthorsRectButClick(TObject *Sender);
	void __fastcall GameRectButClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Viewport3DMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          bool &Handled);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall BackButGameClick(TObject *Sender);
	void __fastcall RoundRectForExecuteCommandFuncClick(TObject *Sender);
	void __fastcall TurnButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    void __fastcall ExecuteCommand(TLabel* CardLabel);


	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
