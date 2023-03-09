//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"

#include <vector>
#include <algorithm>

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    int n, i, j;
    n = 3;

    vector <TCube**> Field(n);

    for (i = 0; i < n; i++) {
        Field[i] = new TCube*[n];
        for (j = 0; j < n; j++) {
            Field[i][j] = new TCube(Dummy1);

            Field[i][j] -> Parent = Dummy1;
            Field[i][j] -> Height = 0.25;
            Field[i][j] -> Depth = 1.95;
            Field[i][j] -> Width = 1.95;
            Field[i][j] -> MaterialSource = LightMaterialSource1;
        }
    }

    int x, y;
    for (i = 0, y = 2; i < n; i++, y -= 2) {
        for (j = 0, x = -2; j < n; j++, x += 2) {
            Field[i][j] -> Position -> Z = y;
            Field[i][j] -> Position -> X = x;
        }
    }

    Field[0][1] -> Height = 1;
    Field[0][1] -> Position -> Y = -(0.5 - 0.125);

    TCube *Hill;
    Hill = new TCube(Dummy2);

    Hill -> Parent = Dummy2;
    Hill -> Height = 0.97;
    Hill -> Depth = 1.2;
    Hill -> Width = 1.2;
    Hill -> MaterialSource = LightMaterialSource2;

    Hill -> Position -> Z = 2;
    Hill -> Position -> X = -2;
    Hill -> Position -> Y = -0.7;

//    delete Hill;
//    for (i = 0; i < n; i++) {
//	    for (j = 0; j < n; j++)
//            delete Field[i][j];
//        delete[] Field[i];
//    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Viewport3D1MouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, bool &Handled)
{
    Dummy1 -> Scale -> X += (WheelDelta * 0.00125);
    Dummy1 -> Scale -> Y += (WheelDelta * 0.00125);
    Dummy1 -> Scale -> Z += (WheelDelta * 0.00125);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LeftButtonClick(TObject *Sender)
{
    Dummy1 -> RotationAngle -> Y += 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RightButtonClick(TObject *Sender)
{
    Dummy1 -> RotationAngle -> Y -= 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PositionButtonMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, bool &Handled)
{
    Dummy1 -> Position -> X -= (WheelDelta * 0.003);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
    if (KeyChar == 'w') {
        ShowMessage("success");
    }
}
//---------------------------------------------------------------------------

