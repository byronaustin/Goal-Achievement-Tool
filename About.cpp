//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "TabPages.h"
//#include "Main.h"
//---------------------------------------------------------------------
#pragma link "Mystd"
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
  : TForm(AOwner)
{
}
//---------------------------------------------------------------------


void __fastcall TAboutBox::ProgramIconClick(TObject *Sender)
{
        URLLabel1->Click();        
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormActivate(TObject *Sender)
{
        if(PagesDlg->Language == "E"){AboutBox->Comments->Caption = "Licensed for life to the Universe";}
        if(PagesDlg->Language == "F"){AboutBox->Comments->Caption = "License valide à vie à: L'Univers";}
        if(PagesDlg->Language == "S"){AboutBox->Comments->Caption = "Licenciado para la vida al universo";}
}
//---------------------------------------------------------------------------

