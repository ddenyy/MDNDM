//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls3D.hpp>
#include <FMX.MaterialSources.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Types.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Viewport3D.hpp>
#include <System.Math.Vectors.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TViewport3D *Viewport3D1;
	TLightMaterialSource *LightMaterialSource1;
	TLight *Light1;
	TDummy *Dummy1;
	TFloatAnimation *FloatAnimation1;
	TLightMaterialSource *LightMaterialSource2;
	TDummy *Dummy2;
	TFloatAnimation *FloatAnimation4;
	TSpeedButton *LeftButton;
	TSpeedButton *RightButton;
	TToolBar *ToolBar1;
	TSpeedButton *PositionButton;
	TToolBar *ToolBar2;
	TDummy *Dummy3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Viewport3D1MouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          bool &Handled);
	void __fastcall LeftButtonClick(TObject *Sender);
	void __fastcall RightButtonClick(TObject *Sender);
	void __fastcall PositionButtonMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          bool &Handled);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
