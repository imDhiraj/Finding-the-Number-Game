//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
int GuseeingNumber;
int points =0;


//void ResetGame() {
//	// Reset the guessing number and clear the input and label
//   // GuseeingNumber = Random(100); // For example, a new number between 0-99
//	Edit2->Text = "";
//	PositionLabel->Text = "Guess a number between 0 and 99.";
//	ConfirmButton->Enabled = true; // Re-enable the button
//}


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	PointscountLabel->Text= points ;

	Edit1->Text ="";
	PointsLabel  ->Visible = false;
	PointscountLabel    ->Visible = false;
	PositionLabel     ->Visible = false;
	ConfirmButton ->Visible = false;
	Edit2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SubmitButtonClick(TObject *Sender)
{


	if (Edit1->Text !="") {
		GuseeingNumber =  Edit1->Text.ToInt();
		PointsLabel  ->Visible = true;
		PointscountLabel    ->Visible = true;
		PositionLabel     ->Visible = true;
		QuestionLabel->Text ="Guess your number!";
		Edit1->Visible = false;
		SubmitButton    ->Visible = false;
		ConfirmButton  ->Visible = true;
		Edit1->Text ="";
		Edit2->Visible = true;

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{


		if (GuseeingNumber==Edit2->Text.ToInt()) {
			PositionLabel->Text ="Congratulations You Found Your Number :)";
			ConfirmButton->Enabled = false;
            points++;
		}
		else if (GuseeingNumber>=Edit2->Text.ToInt()) {
			 PositionLabel->Text ="Your Number is to low :(";
		}
		else if (GuseeingNumber<=Edit2->Text.ToInt())  {
			PositionLabel->Text ="Your Number is to high :(";
		}
		 Edit2->Text = "";

}
//---------------------------------------------------------------------------
