//----------------------------------------------------------------------------
#ifndef AboutH
#define AboutH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include <jpeg.hpp>
#include "Mystd.hpp"
//----------------------------------------------------------------------------
class TAboutBox : public TForm
{
__published:
  TPanel *Panel1;
	TImage *ProgramIcon;
	TLabel *ProductName;
	TLabel *Version;
	TLabel *Copyright;
	TLabel *Comments;
	TButton *OKButton;
        TzcURLLabel *URLLabel1;
        void __fastcall ProgramIconClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
private:
public:
	virtual __fastcall TAboutBox(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAboutBox *AboutBox;
//----------------------------------------------------------------------------
#endif    
