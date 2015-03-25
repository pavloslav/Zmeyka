//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall TForm1::StartPositionZmeyka();
	void __fastcall TForm1::DrawZmeyka();
	void __fastcall TForm1::ClearBuffer();
	void __fastcall TForm1::FlipBuffer();
	bool __fastcall TForm1::HitTest();
	void __fastcall TForm1::End();
	void __fastcall TForm1::DrawMouse();
	bool __fastcall TForm1::HitMouse();




};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
