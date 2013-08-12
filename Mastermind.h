//----------------------------------------------------------------------------
#ifndef MastermindH
#define MastermindH
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
//----------------------------------------------------------------------------
class TDualListDlg : public TForm
{
__published:
  TButton *OKBtn;
	TButton *CancelBtn;
	TButton *HelpBtn;
        TEdit *Edit1;
        TLabel *Label2;
	void __fastcall IncludeBtnClick(TObject *Sender);
	void __fastcall ExcludeBtnClick(TObject *Sender);
	void __fastcall IncAllBtnClick(TObject *Sender);
	void __fastcall ExcAllBtnClick(TObject *Sender);
	void __fastcall MoveSelected(TCustomListBox *List, TStrings *Items);
	void __fastcall SetItem(TListBox *List, int Index);
	Integer __fastcall GetFirstSelection(TCustomListBox *List);
	void __fastcall SetButtons();
        void __fastcall Button1Click(TObject *Sender);
private:
public:
	virtual __fastcall TDualListDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDualListDlg *DualListDlg;
//----------------------------------------------------------------------------
#endif    
