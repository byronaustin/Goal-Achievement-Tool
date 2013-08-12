//---------------------------------------------------------------------------

#ifndef LanguageH
#define LanguageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLanguageForm : public TForm
{
__published:  // IDE-managed Components
        TMemo *LanguageMemo;
private:	// User declarations
public:		// User declarations
        __fastcall TLanguageForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLanguageForm *LanguageForm;
//---------------------------------------------------------------------------
#endif
