//---------------------------------------------------------------------------

#ifndef SmartDefinitionsH
#define SmartDefinitionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TSmartForm : public TForm
{
__published:  // IDE-managed Components
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TSmartForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSmartForm *SmartForm;
//---------------------------------------------------------------------------
#endif
