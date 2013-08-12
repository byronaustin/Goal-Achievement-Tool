//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SMART.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSMARTInfo *SMARTInfo;
//---------------------------------------------------------------------------
__fastcall TSMARTInfo::TSMARTInfo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
