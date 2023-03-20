//---------------------------------------------------------------------------

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
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *MainTabControl;
	TTabItem *StartTab;
	TTabItem *GameTab;
	TTabItem *RulesTab;
	TTabItem *AuthorsTab;
	TRoundRect *RulesRectBut;
	TRectangle *BackGroundStartTabRect;
	TRoundRect *GameRectBut;
	TRoundRect *AuthorsRectBut;
	TLabel *RulesLabelBut;
	TLabel *GameLabelBut;
	TLabel *AuthorsLabelBut;
	TRectangle *BackGroundRulesTabRect;
	TMemo *RulesMemo;
	TRectangle *BackGroundAuthorsTabRect;
	TMemo *AuthorsMemo;
	TViewport3D *Viewport3D;
	TToolBar *ViewPort3DToolBar;
	TRectangle *CardsRect;
	TRectangle *DeckRect;
	TSpeedButton *BackButGame;
	TSpeedButton *BackButRules;
	TSpeedButton *BackButAuthors;
	TActionList *MainActionList;
	TChangeTabAction *GoToStartTabAction;
	void __fastcall RulesRectButClick(TObject *Sender);
	void __fastcall AuthorsRectButClick(TObject *Sender);
	void __fastcall GameRectButClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
