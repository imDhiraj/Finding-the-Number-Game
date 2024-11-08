//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

bool isNumberEnterd = false;
int guessNumber;
int attemtontCounter =0;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TitleLabel->Text ="Please Enter the Number you want to be guessed?";
	CounterLabel->Text ="0";
	HelperLabel->Text ="";
   // this->Color = TColor(RGB(0, 0, 128));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{
	   if (!isNumberEnterd) {
		   guessNumber=NumberEdit->Text .ToInt();
		   isNumberEnterd=true;
		   TitleLabel->Text ="Type your number that you think is the Number:";
		   NumberEdit->Text ="";
	   }
	   else{
		   int secondUserNumber =   NumberEdit->Text .ToInt();
		   if (secondUserNumber== guessNumber) {
			   HelperLabel->Text ="You Won! Congratution:)";
			   ConfirmButton->Enabled =false;
			   return;
		   }
		   else if(secondUserNumber > guessNumber){
				HelperLabel->Text="Number Too big";
				NumberEdit->Text ="";
		   }
		   else if(secondUserNumber < guessNumber){
				HelperLabel->Text="Number Too Small";
                NumberEdit->Text ="";
		   }

				CounterLabel->Text=++attemtontCounter;
	   }
}
//---------------------------------------------------------------------------
