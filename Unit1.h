//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "IWBaseComponent.hpp"
#include "IWBaseHTML40Component.hpp"
#include "IWBaseHTMLComponent.hpp"
#include "IWExtCtrls.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall IWTimer1AsyncTimer(TObject *Sender, TStringList *EventParams);

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
	 void __fastcall TForm1::DrawTupick();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
