//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*BackCanvas;
Graphics::TBitmap*ZmeyaBlock[6];
TPoint Zmeyka[100];//Положение змеи
TPoint MousePos;
int ZmeykaHead;
int ZmeykaLength;  //Длина змеи
int ZmeykaDirect;  //Куда движется змея
enum {Right,Down,LEFT,Up};
int NumberOfEatedMouse;
int Level=1;

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
ZmeyaBlock[i]->Transparent=true;        //прозрачность
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
		ZmeykaLength++;
		if(NumberOfEatedMouse>5)      //з’їдених мишей
                {
                Level++;
				StartPositionZmeyka();
				if(Level>3) //левел
                        {
                        Timer1->Enabled=false;
                        ShowMessage("Молодець,пройшов гру");
                        Close();
                        }
                }
        }
ClearBuffer();
DrawZmeyka();
DrawMouse();
FlipBuffer();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartPositionZmeyka()
{
Zmeyka[0]=Point(5,1);
Zmeyka[1]=Point(4,1);
Zmeyka[2]=Point(3,1);
Zmeyka[3]=Point(2,1);
Zmeyka[4]=Point(1,1);
ZmeykaLength=3;
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

void __fastcall TForm1::ClearBuffer()
{
BackCanvas->Canvas->FillRect(Rect(0,15,300,300));
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
if(ZmeykaDirect!=Down)if(Key==VK_UP)      ZmeykaDirect=Up;
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
	  ShowMessage("Кінець");
	  StartPositionZmeyka();
      Timer1->Enabled=true;

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



