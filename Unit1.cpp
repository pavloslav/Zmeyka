//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <time.h>
//#include "ofstream.h "
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IWBaseComponent"
#pragma link "IWBaseHTML40Component"
#pragma link "IWBaseHTMLComponent"
#pragma link "IWExtCtrls"
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*BackCanvas;
Graphics::TBitmap*ZmeyaBlock[6];
Graphics::TBitmap*TupickBlock[2];


TPoint Tupick[100];
TPoint Zmeyka[100];			//Положення змії
TPoint MousePos;
TPoint TupickPos;
int ZmeykaHead;
int ZmeykaLength;  			//Довжина змії
int ZmeykaDirect; 			 //Рух змії
enum {Right,Down,LEFT,Up};
int NumberOfEatedMouse=0;
int Level=1;
double TotalTime = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 BackCanvas=new Graphics::TBitmap();
 BackCanvas->Width =300;
 BackCanvas->Height=300;
 Graphics::TBitmap*temp=new Graphics::TBitmap();
 temp->LoadFromFile("Zmeyka.bmp");
  for(int i=0;i<6;i++)
  {
   ZmeyaBlock[i]=new Graphics::TBitmap();
   ZmeyaBlock[i]->Width=20;
   ZmeyaBlock[i]->Height=20;
   ZmeyaBlock[i]->Canvas->CopyRect(Rect(0,0,20,20),
								temp->Canvas,
								Rect(i*20,0,i*20+20,20));
   ZmeyaBlock[i]->Transparent=true;        //прозорість
  }
 temp->Free();
 StartPositionZmeyka();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 int temp=ZmeykaHead-1;
 if(temp<0)
 temp=ZmeykaLength-1;
 int tx=Zmeyka[ZmeykaHead].x;
 int ty=Zmeyka[ZmeykaHead].y;
 ZmeykaHead=temp;
 if(ZmeykaDirect==LEFT) tx--;
 if(ZmeykaDirect==Right)tx++;
 if(ZmeykaDirect==Up)   ty--;
 if(ZmeykaDirect==Down) ty++;
 if((ty>14)||(ty<0)||(tx>14)||(tx<0))
 {
  End();
 }
 else
 {
  Zmeyka[ZmeykaHead]=Point(tx,ty);
 }


 if(HitTest())End();
 if(HitMouse())
		{
        MousePos=Point(random(15),random(15));
		Zmeyka[ZmeykaLength]=Zmeyka[temp];
		NumberOfEatedMouse++;
		Label2->Caption=NumberOfEatedMouse;
		ZmeykaLength++;
		if(NumberOfEatedMouse>4)      //з’їдених мишей
				 {
				Level=2;
				Caption="Змійка. Рівень "+IntToStr(Level);
				Timer1->Interval=180;
				}
				if(NumberOfEatedMouse>=8)
				{
				Level=3;
				Caption="Змійка. Рівень "+IntToStr(Level);
					Timer1->Interval=100;
				}
					if(NumberOfEatedMouse>=9)
				{
				Level=4;
				}
				if(Level>3) //левел
						{
						Timer1->Enabled=false;
						ShowMessage("Молодець,пройшов гру");
						Close();
						}
				}

 ClearBuffer();
 DrawZmeyka();
 DrawMouse();
 FlipBuffer();
 DrawTupick();
 }


//---------------------------------------------------------------------------
void __fastcall TForm1::StartPositionZmeyka()
{
 Zmeyka[0]=Point(5,1);
 Zmeyka[1]=Point(4,1);
 Zmeyka[2]=Point(3,1);
 Zmeyka[3]=Point(2,1);
 Zmeyka[4]=Point(1,1);
 ZmeykaLength=NumberOfEatedMouse+2;
 ZmeykaHead=0;
 ZmeykaDirect=Down;
 MousePos=Point(random(15),random(15));
 NumberOfEatedMouse=0;
 Caption="Змійка. Рівень "+IntToStr(Level);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawZmeyka()
{
	  for(int i=0;i<ZmeykaLength;i++)
		{
		if(i!=ZmeykaHead){
		BackCanvas->Canvas->Draw(Zmeyka[i].x*20,Zmeyka[i].y*20,ZmeyaBlock[4]);
		}
		else
		{
		BackCanvas->Canvas->Draw(Zmeyka[i].x*20,Zmeyka[i].y*20,ZmeyaBlock[ZmeykaDirect]);
		}
		}
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::DrawTupick()
 {
 BackCanvas=new Graphics::TBitmap();
 BackCanvas->Width =300;
 BackCanvas->Height=300;
 Graphics::TBitmap*temp=new Graphics::TBitmap();
 temp->LoadFromFile("Tupick.bmp");
  for(int i=0;i<4;i++)
  {
   TupickBlock[i]=new Graphics::TBitmap();
   TupickBlock[i]->Width=20;
   TupickBlock[i]->Height=20;
  TupickBlock[i]->Canvas->CopyRect(Rect(100,100,120,100),
								temp->Canvas,
							  Rect(i*100,0,i*100+20,20));
  TupickBlock[i]->Transparent=true;        //прозорість
  }
 temp->Free();
  Tupick[0]=Point(8,3);
  Tupick[1]=Point(11,5);
  Tupick[2]=Point(10,10);
	TupickPos=Point(random(10),random(10));
	BackCanvas->Canvas->Draw(TupickPos.x*20,TupickPos.y*20,TupickBlock[1]);
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearBuffer()
{
 BackCanvas->Canvas->FillRect(Rect(0,0,300,300));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FlipBuffer()
{
 Canvas->Draw(0,0,BackCanvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
 if(ZmeykaDirect!=Down) if(Key==VK_UP)      ZmeykaDirect=Up;
 if(ZmeykaDirect!=Up)   if(Key==VK_DOWN)    ZmeykaDirect=Down;
 if(ZmeykaDirect!=Right)if(Key==VK_LEFT)    ZmeykaDirect=LEFT;
 if(ZmeykaDirect!=LEFT) if(Key==VK_RIGHT)   ZmeykaDirect=Right;
}
//---------------------------------------------------------------------------
bool __fastcall TForm1::HitTest()
{
 for(int i=0;i<ZmeykaLength;i++)
		{
				if(ZmeykaHead!=i)
				{
				if((Zmeyka[ZmeykaHead].x==Zmeyka[i].x)&&
				   (Zmeyka[ZmeykaHead].y==Zmeyka[i].y))
						return true;
				}
		}
return false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::End()
{
	  Timer1->Enabled=false;
	  if(MessageDlg("Кінець гри. Рoзпочати спочатку ? ",mtConfirmation,TMsgDlgButtons()
											<<mbYes <<mbNo,0)==mrYes)
		 {
			Level=1;
			Label2->Caption=" ";
			NumberOfEatedMouse=0;
			StartPositionZmeyka();
			Timer1->Enabled=true;  }
		  else
		   {
			 Form1->Close(); }

}
 //---------------------------------------------------------------------------
void __fastcall TForm1::DrawMouse()
{
 BackCanvas->Canvas->Draw(MousePos.x*20,MousePos.y*20,ZmeyaBlock[5]);
}
//---------------------------------------------------------------------------
bool __fastcall TForm1::HitMouse()
{
		int tx=Zmeyka[ZmeykaHead].x;
		int ty=Zmeyka[ZmeykaHead].y;
        if((tx==MousePos.x)&&(ty==MousePos.y))return true;
        else return false;
}

//---------------------------------------------------------------------------




void __fastcall TForm1::N3Click(TObject *Sender)
{
Timer1->Enabled=false;
Label2->Visible=false;
Label3->Visible=false;
 ShowMessage("Продолжить");
	 Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
 /*
void __fastcall TForm1::FormCreate(TObject *Sender)
{
int Step;
Label3->Caption="0:00";
 Timer1 -> Interval = Step;
}                             */
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
ShowMessage ("Натисніть ок для початку гри ");
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IWTimer1AsyncTimer(TObject *Sender, TStringList *EventParams)

{
static int i = 1;
Label3->Caption = IntToStr( i++ );
if ( i>00,00 ) {
    i = 1;
	Timer1->Enabled = false;
}
}
//---------------------------------------------------------------------------

