//----------------------------------------------------------------------------
#ifndef TabPagesH
#define TabPagesH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <CheckLst.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
#include <StrUtils.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
#include <Dialogs.hpp>
#include <MPlayer.hpp>
//----------------------------------------------------------------------------
class TPagesDlg : public TForm
{
__published:
  TPanel *Panel1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Print1;
        TMenuItem *Edit2;
        TMenuItem *DeleteUser;
        TMenuItem *DeleteProfiles;
        TMenuItem *Help1;
        TMenuItem *AboutMegaGoalAchiever1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        TCheckListBox *CheckListBox2;
        TCheckListBox *CheckListBox3;
        TCheckListBox *CheckListBox4;
        TCheckListBox *CheckListBox5;
        TListBox *ListBox2;
        TListBox *ListBox1;
        TButton *Button2;
        TBitBtn *UpBtn;
        TBitBtn *DownBtn;
        TBitBtn *EditBtn;
        TBitBtn *DeleteBtn;
        TPanel *Panel3;
        TEdit *Edit3;
        TLabel *Label3;
        TLabel *Label4;
        TDateTimePicker *DateTimePicker1;
        TLabel *Label5;
        TMemo *VisMemo;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TTabSheet *TabSheet6;
        TButton *GABtn;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label6;
        TMemo *RewMemo;
        TMemo *Memo2;
        TLabel *SrcLabel;
        TLabel *Label13;
        TLabel *Label14;
        TButton *Button3;
        TComboBox *MMName;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TButton *Button4;
        TButton *Button5;
        TBitBtn *MMEditBtn;
        TBitBtn *MMDeleteBtn;
        TLabel *Label18;
        TBitBtn *C6UPBtn;
        TBitBtn *C6DownBtn;
        TBitBtn *C6EditBtn;
        TBitBtn *C6DeleteBtn;
        TButton *Button6;
        TButton *C6Print;
        TLabel *Label19;
        TCheckListBox *CheckListBox1;
        TCheckBox *CheckBox1;
        TCheckListBox *CheckListBox6;
        TMemo *Memo4;
        TPanel *Panel2;
        TImage *Image1;
        TMenuItem *Exit1;
        TMemo *MMMemo;
        TComboBox *UserBox;
        TLabel *Label20;
        TCheckListBox *MMCheckList;
        TBitBtn *MMUpBtn;
        TBitBtn *MMDownBtn;
        TCheckListBox *C6CheckListBox;
        TMemo *ProfileMemo;
        TLabel *StartHereLbl;
        TMenuItem *Language1;
        TMenuItem *English1;
        TMenuItem *French1;
        TMenuItem *Spanish1;
        TMenuItem *SelectGoalAchievedTheme1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TTabSheet *TabSheet7;
        TListBox *DoneListBox;
        TLabel *Label22;
        TRichEdit *PrintBox;
        TMenuItem *PrintGoalsCriticalTasks1;
        TMenuItem *PrintSelectedGoalandCriticalTasks1;
        TImage *Image2;
        TMemo *SmartMemo;
        TPrintDialog *PrintDialog1;
        TMemo *FRSmartMemo;
        TLabel *Label21;
        TMemo *SPSmartMemo;
        TOpenDialog *OpenDialog1;
        TMediaPlayer *MGAMusic;
        TLabel *Label23;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall AboutMegaGoalAchiever1Click(TObject *Sender);
        void __fastcall CheckListBox6ClickCheck(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall DeleteBtnClick(TObject *Sender);
        void __fastcall UpBtnClick(TObject *Sender);
        void __fastcall DownBtnClick(TObject *Sender);
        void __fastcall EditBtnClick(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall TabSheet2Show(TObject *Sender);
        void __fastcall TabSheet3Show(TObject *Sender);
        void __fastcall TabSheet1Hide(TObject *Sender);
        void __fastcall TabSheet2Hide(TObject *Sender);
        void __fastcall TabSheet3Hide(TObject *Sender);
        void __fastcall TabSheet1Show(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall MMEditBtnClick(TObject *Sender);
        void __fastcall MMCheckListClick(TObject *Sender);
        void __fastcall MMDeleteBtnClick(TObject *Sender);
        void __fastcall TabSheet4Hide(TObject *Sender);
        void __fastcall TabSheet4Show(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall MMUpBtnClick(TObject *Sender);
        void __fastcall MMDownBtnClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall C6UPBtnClick(TObject *Sender);
        void __fastcall C6DownBtnClick(TObject *Sender);
        void __fastcall C6CheckListBoxClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall MMMemoEnter(TObject *Sender);
        void __fastcall VisMemoClick(TObject *Sender);
        void __fastcall RewMemoClick(TObject *Sender);
        void __fastcall TabSheet5Show(TObject *Sender);
        void __fastcall C6DeleteBtnClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall DeleteUserClick(TObject *Sender);
        void __fastcall UserBoxClick(TObject *Sender);
        void __fastcall UserBoxExit(TObject *Sender);
        void __fastcall DeleteProfilesClick(TObject *Sender);
        void __fastcall DateTimePicker1CloseUp(TObject *Sender);
        void __fastcall MMNameClick(TObject *Sender);
        void __fastcall C6EditBtnClick(TObject *Sender);
        void __fastcall CheckListBox2ClickCheck(TObject *Sender);
        void __fastcall CheckListBox3ClickCheck(TObject *Sender);
        void __fastcall CheckListBox4ClickCheck(TObject *Sender);
        void __fastcall CheckListBox5ClickCheck(TObject *Sender);
        void __fastcall CheckListBox1ClickCheck(TObject *Sender);
        void __fastcall GABtnClick(TObject *Sender);
        void __fastcall TabSheet7Show(TObject *Sender);
        void __fastcall TabSheet7Hide(TObject *Sender);
        void __fastcall TabSheet6Show(TObject *Sender);
        void __fastcall TabSheet6Hide(TObject *Sender);
        void __fastcall Label7Click(TObject *Sender);
        void __fastcall Label8Click(TObject *Sender);
        void __fastcall Label9Click(TObject *Sender);
        void __fastcall Label10Click(TObject *Sender);
        void __fastcall Label11Click(TObject *Sender);
        void __fastcall C6PrintClick(TObject *Sender);
        void __fastcall PrintSelectedGoalandCriticalTasks1Click(
          TObject *Sender);
        void __fastcall PrintGoalsCriticalTasks1Click(TObject *Sender);
        void __fastcall French1Click(TObject *Sender);
        void __fastcall Spanish1Click(TObject *Sender);
        void __fastcall English1Click(TObject *Sender);
        void __fastcall Print1Click(TObject *Sender);
        void __fastcall File1Click(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall MMCheckListClickCheck(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall C6CheckListBoxClickCheck(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall DateTimePicker1Click(TObject *Sender);
private:
public:
	virtual __fastcall TPagesDlg(TComponent* AOwner);
        int listitem;
        AnsiString Selected;
        AnsiString Path;
        AnsiString User;
        AnsiString UserB;
        AnsiString filename;

        AnsiString Gol;
        AnsiString Rew;
        AnsiString Dat;
        AnsiString Vis;
        AnsiString Mas;
        AnsiString Ide;
        AnsiString Sma;
        AnsiString Cr6;
        AnsiString Ick;
        AnsiString Com;
        AnsiString Suc;

        AnsiString Agoal;
        AnsiString Aname;
        AnsiString Ename;
        AnsiString AMMName;
        AnsiString URLName;
        AnsiString SelectUser;
        AnsiString NewUser;
        AnsiString NewMastermindSession;
        AnsiString Language;
        AnsiString Select;
        bool Startup;
        bool Cancel;

        int Smart;
        AnsiString CurrentUser;
        AnsiString NextUser;
};
//----------------------------------------------------------------------------
extern PACKAGE TPagesDlg *PagesDlg;
//----------------------------------------------------------------------------
#endif    
