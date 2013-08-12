//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SmartDefinitions.h"
#include "TabPages.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSmartForm *SmartForm;
//---------------------------------------------------------------------------
__fastcall TSmartForm::TSmartForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSmartForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
SmartForm->Visible = false;
}
//---------------------------------------------------------------------------

