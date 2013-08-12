//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TabPages.h"
//#include "Main.h"
#include "About.h"
#include "Mastermind.h"
#include "Unit2.h"
#include "SmartDefinitions.h"
#include "Language.h"
//#include "Unit1.h"
#include "Splash.h"
//---------------------------------------------------------------------
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TPagesDlg *PagesDlg;
//---------------------------------------------------------------------
__fastcall TPagesDlg::TPagesDlg(TComponent* AOwner)
  : TForm(AOwner)
{
}
//---------------------------------------------------------------------

void __fastcall TPagesDlg::Button2Click(TObject *Sender)
{
        if(ListBox1->Items->Count > 19){Application->MessageBoxA("Limit 20 Goals per user. To enter more goals add a new user","Max Goals Reached",MB_OK);}
        else
        {
                if(Memo4->Lines->Strings[0] != "")
                {
                        ListBox1->Items->Add(Memo4->Lines->Strings[0]);
                        CheckListBox1->Items->Add(Memo4->Lines->Strings[0]);
                        CheckListBox2->Items->Add(Memo4->Lines->Strings[0]);
                        CheckListBox3->Items->Add(Memo4->Lines->Strings[0]);
                        CheckListBox4->Items->Add(Memo4->Lines->Strings[0]);
                        CheckListBox5->Items->Add(Memo4->Lines->Strings[0]);
                        CheckListBox6->Items->Add(Memo4->Lines->Strings[0]);
                        ListBox2->Items->Add(ListBox1->Items->Count);
                        Memo4->Clear();
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::AboutMegaGoalAchiever1Click(TObject *Sender)
{
        AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::CheckListBox6ClickCheck(TObject *Sender)
{
        int i;
        i = CheckListBox6->ItemIndex;
        if (CheckListBox6->Checked[i] == true)
        {
                CheckListBox1->Checked[i] = true;
                CheckListBox2->Checked[i] = true;
                CheckListBox3->Checked[i] = true;
                CheckListBox4->Checked[i] = true;
                CheckListBox5->Checked[i] = true;
        }
        if (CheckListBox6->Checked[i] == false)
        {
                CheckListBox1->Checked[i] = false;
                CheckListBox2->Checked[i] = false;
                CheckListBox3->Checked[i] = false;
                CheckListBox4->Checked[i] = false;
                CheckListBox5->Checked[i] = false;
        }
        ListBox1->ItemIndex = i;
        ListBox2->ItemIndex = i;
        ListBox1->Selected[i] = true;
        ListBox2->Selected[i] = true;
        Edit3->Text = ListBox1->Items->Strings[i];
        Cancel = false;
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::ListBox1Click(TObject *Sender)
{
        int i;
        Cancel = false;
        i = ListBox1->ItemIndex;
        Button1->Enabled = true;
        EditBtn->Enabled = true;
        DeleteBtn->Enabled = true;
        UpBtn->Enabled  = true;
        DownBtn->Enabled = true;
        listitem = ListBox1->ItemIndex;
        Selected = ListBox1->Items->Strings[listitem];
        Edit3->Text = Selected;
        GABtn->Enabled = true;
        PrintSelectedGoalandCriticalTasks1->Enabled = true;
        //ListBox1->ItemIndex = i;
        ListBox2->ItemIndex = i;
        //ListBox1->Selected[i] = true;
        ListBox2->Selected[i] = true;
        CheckListBox1->ItemIndex = i;
        CheckListBox1->Selected[i] = true;
        CheckListBox2->ItemIndex = i;
        CheckListBox2->Selected[i] = true;
        CheckListBox3->ItemIndex = i;
        CheckListBox3->Selected[i] = true;
        CheckListBox4->ItemIndex = i;
        CheckListBox4->Selected[i] = true;
        CheckListBox5->ItemIndex = i;
        CheckListBox5->Selected[i] = true;
        CheckListBox6->ItemIndex = i;
        CheckListBox6->Selected[i] = true;
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::DeleteBtnClick(TObject *Sender)
{
        int goaldelete, i;
        AnsiString temp;
        if(Language == "E")
        {
                goaldelete = Application->MessageBoxA("Are you sure you want to delete this item?","Delete Warning",MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "F")
        {
                goaldelete = Application->MessageBoxA("Êtes-vous certain de vouloir effacer cet item?","Attention!",MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "S")
        {
                goaldelete = Application->MessageBoxA("¿Es usted seguro usted desea suprimir este artículo?","Advertencia De la Cancelación",MB_YESNO|MB_ICONWARNING );
        }
        if (goaldelete == 6)
        {
                AnsiString temp;
                int line;
                line = ListBox1->ItemIndex;
                temp = ListBox1->Items->Strings[line];
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Rew)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Dat)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Vis)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Mas)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ide)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Sma)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Cr6)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ick)&&(MidStr(ProfileMemo->Lines->Strings[i],5,temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                ProfileMemo->Lines->SaveToFile(filename);
                CheckListBox1->Items->Delete(line);
                CheckListBox2->Items->Delete(line);
                CheckListBox3->Items->Delete(line);
                CheckListBox4->Items->Delete(line);
                CheckListBox5->Items->Delete(line);
                CheckListBox6->Items->Delete(line);
                ListBox2->Clear();
                ListBox1->Items->Delete(line);
                for (int i = 0;i < ListBox1->Items->Count; i++)
                {
                        ListBox2->Items->Add(i+1);
                }
                DeleteBtn->Enabled = false;
                UpBtn->Enabled = false;
                DownBtn->Enabled = false;
                EditBtn->Enabled = false;
                GABtn->Enabled = false;
                Button1->Enabled = false;
                PrintSelectedGoalandCriticalTasks1->Enabled = false;
                Edit3->Clear();
                Memo4->SetFocus();
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::UpBtnClick(TObject *Sender)
{
        listitem = ListBox1->ItemIndex;
        if (listitem > 0)
        {
                ListBox1->Items->Move(listitem,listitem-1);
                CheckListBox1->Items->Move(listitem,listitem-1);
                CheckListBox2->Items->Move(listitem,listitem-1);
                CheckListBox3->Items->Move(listitem,listitem-1);
                CheckListBox4->Items->Move(listitem,listitem-1);
                CheckListBox5->Items->Move(listitem,listitem-1);
                CheckListBox6->Items->Move(listitem,listitem-1);
                ListBox1->Selected[listitem-1] = true;
                ListBox1->ItemIndex = listitem-1;
                ListBox2->Selected[listitem-1] = true;
                ListBox2->ItemIndex = listitem-1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::DownBtnClick(TObject *Sender)
{
        listitem = ListBox1->ItemIndex;
        if (listitem < ListBox1->Items->Count-1)
        {
                ListBox1->Items->Move(listitem,listitem+1);
                CheckListBox1->Items->Move(listitem,listitem+1);
                CheckListBox2->Items->Move(listitem,listitem+1);
                CheckListBox3->Items->Move(listitem,listitem+1);
                CheckListBox4->Items->Move(listitem,listitem+1);
                CheckListBox5->Items->Move(listitem,listitem+1);
                CheckListBox6->Items->Move(listitem,listitem+1);
                ListBox1->Selected[listitem+1] = true;
                ListBox1->ItemIndex = listitem+1;
                ListBox2->Selected[listitem+1] = true;
                ListBox2->ItemIndex = listitem+1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::EditBtnClick(TObject *Sender)
{
        AnsiString oldgoal = Edit3->Text;
        listitem = ListBox1->ItemIndex;
        if(Language == "E")
        {
                ListBox1->Items->Strings[listitem] = InputBox("Goal Editor","Enter new text for this Goal",ListBox1->Items->Strings[listitem]);
        }
        if(Language == "F")
        {
                ListBox1->Items->Strings[listitem] = InputBox("Rédacteur De But","Écrivez le nouveau texte pour ce but",ListBox1->Items->Strings[listitem]);
        }
        if(Language == "S")
        {
                ListBox1->Items->Strings[listitem] = InputBox("Redactor De la Meta","Incorpore el nuevo texto para esta meta",ListBox1->Items->Strings[listitem]);
        }
        AnsiString newgoal = ListBox1->Items->Strings[listitem];
        Edit3->Text = newgoal;
        AnsiString MM, newline;
        int i;
        if (newgoal != oldgoal)
        {
                AnsiString temp;
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Gol)&&(RightStr(ProfileMemo->Lines->Strings[i],oldgoal.Length()) == oldgoal))
                        {
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Gol + newgoal);
                        }
                }
                oldgoal = "[" + oldgoal + "]";
                newgoal = "[" + newgoal + "]";
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Rew)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Rew + newgoal + RightStr(temp,(temp.Length() - (3 + oldgoal.Length()))));
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Dat)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Dat + newgoal + RightStr(temp,(temp.Length() - (3 + oldgoal.Length()))));
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Vis)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Vis + newgoal + RightStr(temp,(temp.Length() - (3 + oldgoal.Length()))));
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ide)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                temp = RightStr(temp,temp.Length() - (3 + oldgoal.Length()));
                                int j = temp.Length();
                                newline = "";
                                while ((MidStr(temp,j,1) != "]")&&( j > 0 ))
                                {
                                        newline = MidStr(temp,j,1) + newline;
                                        j--;
                                }
                                MM = "";
                                j = 3 + oldgoal.Length() + 1;
                                while ((MidStr(temp,j,1) != "]")&&( j < temp.Length()))
                                {
                                        MM = MM + MidStr(temp,j,1);
                                        j++;
                                }
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Ide + newgoal + MM + newline);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Mas)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Mas + newgoal + RightStr(temp,(temp.Length() - (3 + oldgoal.Length()))));
                        }
                }


                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Sma)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Sma + newgoal + RightStr(temp,(temp.Length() - (3 + oldgoal.Length()))));

                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Cr6)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                temp = RightStr(temp,temp.Length() - (3 + oldgoal.Length()));
                                int j = temp.Length();
                                newline = "";
                                while ((MidStr(temp,j,1) != "]")&&( j > 0 ))
                                {
                                        newline = MidStr(temp,j,1) + newline;
                                        j--;
                                }
                                MM = "";
                                j = 3 + oldgoal.Length() + 1;
                                while ((MidStr(temp,j,1) != "]")&&( j < temp.Length()))
                                {
                                        MM = MM + MidStr(temp,j,1);
                                        j++;
                                }
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Cr6 + newgoal + MM + newline);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ick)&&(MidStr(ProfileMemo->Lines->Strings[i],4,oldgoal.Length()) == oldgoal))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Ick + newgoal + RightStr(temp,(temp.Length() - (3 + oldgoal.Length()))));

                        }
                        ProfileMemo->Lines->SaveToFile(filename);
                }
        }
 }
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::Exit1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::FormActivate(TObject *Sender)
{
        if (Startup)
        {
                Startup = false;
                Cancel = true;
               // SplashForm->Show();
                Smart = 0;
                DateTimePicker1->Date = Date();
                Path = "C:\\Program Files\\Mega Goal Achiever Data\\";
                if (!DirectoryExists(Path))
                {
                        CreateDir(Path);
                        FileSetAttr(Path, faHidden);
                        StartHereLbl->Visible = true;
                        StartHereLbl->Caption = "<-- START HERE";
                        PrintBox->Lines->Add("E");
                        PrintBox->Lines->SaveToFile(Path + "mga.ini");
                        PrintBox->Clear();
                }
                try
                {
                        PrintBox->Lines->LoadFromFile(Path + "mga.ini");
                }
                catch (...)
                {
                        PrintBox->Lines->Clear();
                        PrintBox->Lines->Add("E");
                        PrintBox->Lines->SaveToFile(Path + "mga.ini");
                        PrintBox->Lines->LoadFromFile(filename);
                }
                Language = PrintBox->Lines->Strings[0];
                PrintBox->Clear();
                if(Language == "E")
                {
                        English1->Click();
                }
                if(Language == "F")
                {
                        French1->Click();
                }
                if(Language == "S")
                {
                        Spanish1->Click();
                }
                UserBox->Items->Add(NewUser);
                TSearchRec sr;
                if (FindFirst(Path + "*.gol",0,sr)==0)
                {
                        do
                        {
                                UserBox->Items->Add(LeftStr(sr.Name,sr.Name.Length()-4));
                        } while (FindNext(sr) == 0);
                        FindClose(sr);
                }
                Gol = "[G]";
                Dat = "[D]";
                Vis = "[V]";
                Rew = "[R]";
                Mas = "[M]";
                Ide = "[I]";
                Cr6 = "[C]";
                Sma = "[S]";
                Ick = "[K]";
                Com = "[O]";
                Suc = "[U]";
                URLName = "http://www.MegaGoalAchiever.com";
                ListBox2->Clear();
                ListBox1->Clear();
                CheckListBox1->Clear();
                CheckListBox2->Clear();
                CheckListBox3->Clear();
                CheckListBox4->Clear();
                CheckListBox5->Clear();
                CheckListBox6->Clear();
                UserBox->Text = SelectUser;
                UserBox->ItemIndex = -1;
                PageControl1Change(Sender);
                PageControl1->Enabled = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet2Show(TObject *Sender)
{
        AnsiString goal = "[" + Edit3->Text + "]";
        int len = goal.Length();
        int i;
        for (i = ProfileMemo->Lines->Count; i > -1; i--)
        {
                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Vis + goal)
                {
                        VisMemo->Lines->Insert(0,RightStr(ProfileMemo->Lines->Strings[i],(ProfileMemo->Lines->Strings[i].Length() - (3 + len))));
                }
        }
        bool d = false;
        for (i = ProfileMemo->Lines->Count; i > -1; i--)
        {
                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Dat + goal)
                {
                        DateTimePicker1->Date = RightStr(ProfileMemo->Lines->Strings[i],(ProfileMemo->Lines->Strings[i].Length()-(3 + len)));
                        d = true;
                        Label21->Visible = false;
                }
                if(!d)
                {
                        DateTimePicker1->Date = Date();
                        Label21->Visible = true;
                }
        }
        for (i = ProfileMemo->Lines->Count; i > -1; i--)
        {
                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Vis + goal)
                {
                        ProfileMemo->Lines->Delete(i);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet3Show(TObject *Sender)
{
        AnsiString goal = "[" + Edit3->Text + "]";
        int len = goal.Length();
        for (int i = ProfileMemo->Lines->Count; i > -1; i--)
        {
                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Rew + goal)
                {
                        RewMemo->Lines->Insert(0,RightStr(ProfileMemo->Lines->Strings[i],(ProfileMemo->Lines->Strings[i].Length() - (3 + len))));
                }
        }
        for (int i = ProfileMemo->Lines->Count; i > -1; i--)
        {
                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Rew + goal)
                {
                        ProfileMemo->Lines->Delete(i);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet1Hide(TObject *Sender)
{
        if(!Cancel)
        {
        UserBox->Enabled = false;
        int i;
        AnsiString smart, goal;
        smart = "";
        for(i = 0;i < ListBox1->Items->Count; i++)
        {
                goal = "[" + ListBox1->Items->Strings[i] + "]";
                if(CheckListBox1->Checked[i] == true){smart = "s";}
                if(CheckListBox1->Checked[i] == false){smart = "x";}
                if(CheckListBox2->Checked[i] == true){smart = smart + "m";}
                if(CheckListBox2->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox3->Checked[i] == true){smart = smart + "a";}
                if(CheckListBox3->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox4->Checked[i] == true){smart = smart + "r";}
                if(CheckListBox4->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox5->Checked[i] == true){smart = smart + "t";}
                if(CheckListBox5->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox6->Checked[i] == true){smart = smart + "l";}
                if(CheckListBox6->Checked[i] == false){smart = smart + "x";}
                ProfileMemo->Lines->Add(Sma + goal + smart);
                ProfileMemo->Lines->Add(Gol + ListBox1->Items->Strings[i]);
        }
        ProfileMemo->Lines->SaveToFile(filename);
        ListBox1->Clear();
        CheckListBox1->Clear();
        CheckListBox2->Clear();
        CheckListBox3->Clear();
        CheckListBox4->Clear();
        CheckListBox5->Clear();
        CheckListBox6->Clear();
        ListBox2->Clear();
        }
        else
        {
        TabSheet1->Show();
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet2Hide(TObject *Sender)
{
        if (Edit3->Text != "")
        {
                AnsiString goal = "[" + Edit3->Text + "]" ;
                Agoal = goal;
                AnsiString vision = Vis + goal;
                int i;
                for (i = 0; i < VisMemo->Lines->Count; i++)
                {
                        ProfileMemo->Lines->Add(vision + VisMemo->Lines->Strings[i]);
                }
                ProfileMemo->Lines->SaveToFile(filename);
                VisMemo->Clear();
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet3Hide(TObject *Sender)
{
        if (Edit3->Text != "")
        {
                AnsiString goal = "[" + Edit3->Text + "]" ;
                Agoal = goal;
                AnsiString reward = Rew + goal;
                int i;
                for (i = 0; i < RewMemo->Lines->Count; i++)
                {
                        ProfileMemo->Lines->Add(reward + RewMemo->Lines->Strings[i]);
                }
                ProfileMemo->Lines->SaveToFile(filename);
                RewMemo->Clear();
        }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet1Show(TObject *Sender)
{
        UserBox->Enabled = true;
        int i, len, listindex;
        if(Edit3->Text != "")
        {
                UpBtn->Enabled = true;
                DownBtn->Enabled = true;
                EditBtn->Enabled = true;
                DeleteBtn->Enabled = true;
                Button1->Enabled = true;
                GABtn->Enabled = true;
        }
        AnsiString temp, goal;
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        temp = ProfileMemo->Lines->Strings[i];
                        len = temp.Length();
                        if(LeftStr(temp,3) == Gol)
                        {
                                ListBox1->Items->Insert(0,RightStr(temp,len - 3));
                                goal = "[" + ListBox1->Items->Strings[0] + "]";
                                CheckListBox1->Items->Insert(0,RightStr(temp,len - 3));
                                CheckListBox2->Items->Insert(0,RightStr(temp,len - 3));
                                CheckListBox3->Items->Insert(0,RightStr(temp,len - 3));
                                CheckListBox4->Items->Insert(0,RightStr(temp,len - 3));
                                CheckListBox5->Items->Insert(0,RightStr(temp,len - 3));
                                CheckListBox6->Items->Insert(0,RightStr(temp,len - 3));
                                ListBox2->Items->Add(ListBox1->Items->Count);
                        }
                        if((LeftStr(temp,3) == Sma)&&(MidStr(temp,4,goal.Length()) == goal ))
                        {
                                if(MidStr(temp,3 + goal.Length() + 1,1) == "s"){CheckListBox1->Checked[0] = true;}
                                if(MidStr(temp,3 + goal.Length() + 2,1) == "m"){CheckListBox2->Checked[0] = true;}
                                if(MidStr(temp,3 + goal.Length() + 3,1) == "a"){CheckListBox3->Checked[0] = true;}
                                if(MidStr(temp,3 + goal.Length() + 4,1) == "r"){CheckListBox4->Checked[0] = true;}
                                if(MidStr(temp,3 + goal.Length() + 5,1) == "t"){CheckListBox5->Checked[0] = true;}
                                if(MidStr(temp,3 + goal.Length() + 6,1) == "l"){CheckListBox6->Checked[0] = true;}
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        temp = ProfileMemo->Lines->Strings[i];
                        if((LeftStr(temp,3) == Sma)||(LeftStr(temp,3) == Gol)){ProfileMemo->Lines->Delete(i);}
                }
                for (i = ListBox1->Items->Count-1; i > -1; i--)
                {
                        if(ListBox1->Items->Strings[i] == Edit3->Text)
                        {
                                ListBox1->ItemIndex = i;
                                ListBox2->ItemIndex = i;
                                CheckListBox1->ItemIndex = i;
                                CheckListBox2->ItemIndex = i;
                                CheckListBox3->ItemIndex = i;
                                CheckListBox4->ItemIndex = i;
                                CheckListBox5->ItemIndex = i;
                                CheckListBox6->ItemIndex = i;
                        }
                }
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::Button3Click(TObject *Sender)
{
        if(MMMemo->Lines->Strings[0] != "")
        {
                MMCheckList->Items->Add(MMMemo->Lines->Strings[0]);
                MMMemo->Clear();
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Button1Click(TObject *Sender)
{
        TabSheet4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::MMEditBtnClick(TObject *Sender)
{
        AnsiString MM, oldMM, newMM, newline, goal, baseMM;
        listitem = MMCheckList->ItemIndex;
        bool C = false;
        oldMM = MMCheckList->Items->Strings[listitem];
        if(LeftStr(oldMM,3)==Cr6)
        {
                oldMM = RightStr(oldMM,oldMM.Length()-3);
                C = true;
        }
        if (Language == "E")
        {
                MMCheckList->Items->Strings[listitem] = InputBox("Mastermind Editor","Enter new text for this idea",oldMM);
        }
        if (Language == "F")
        {
                MMCheckList->Items->Strings[listitem] = InputBox("Rédacteur de brainstorming","Écrivez le nouveau texte pour cette idée",oldMM);
        }
        if (Language == "S")
        {
                MMCheckList->Items->Strings[listitem] = InputBox("Redactor de reunión de reflexión","Incorpore el nuevo texto para esta idea",oldMM);
        }
        newMM = MMCheckList->Items->Strings[listitem];
        if(C){MMCheckList->Items->Strings[listitem]= Cr6 + MMCheckList->Items->Strings[listitem];}
        baseMM = newMM;
        MM = "[" + MMName->Text + "]";
        int i;
        goal = Edit3->Text;
        goal = "[" + goal + "]";
        if (newMM != oldMM)
        {
                AnsiString temp;
        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3 + goal.Length()) == Ide + goal)&&(MidStr(ProfileMemo->Lines->Strings[i],4 + goal.Length(),oldMM.Length()) == oldMM))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                temp = RightStr(temp,temp.Length() - (3 + goal.Length() + oldMM.Length()));
                                int j = temp.Length();
                                newline = "";
                                while ((MidStr(temp,j,1) != "]")&&( j > 0 ))
                                {
                                        newline = MidStr(temp,j,1) + newline;
                                        j--;
                                }
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Ide + goal + newMM + newline);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3 + goal.Length() + MM.Length()) == Cr6 + goal + MM)&&(RightStr(ProfileMemo->Lines->Strings[i],ProfileMemo->Lines->Strings[i].Length()-(3 + goal.Length() + MM.Length())) == oldMM))
                        {
                                newline = "";
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Cr6 + goal + MM + newMM);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ick)&&(MidStr(ProfileMemo->Lines->Strings[i],4 + goal.Length(),oldMM.Length()) == oldMM))
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                ProfileMemo->Lines->Delete(i);
                                ProfileMemo->Lines->Insert(i,Ick + goal + newMM + RightStr(temp,(temp.Length() - (3 + oldMM.Length()))));

                        }
                }
        }
        ProfileMemo->Lines->SaveToFile(filename);


}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::MMCheckListClick(TObject *Sender)
{
        Button4->Enabled = true;
        Button5->Enabled = true;
        MMDeleteBtn->Enabled = true;
        MMEditBtn->Enabled  = true;
        MMUpBtn->Enabled = true;
        MMDownBtn->Enabled = true;
        listitem = MMCheckList->ItemIndex;
        Selected = MMCheckList->Items->Strings[listitem];
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::MMDeleteBtnClick(TObject *Sender)
{
        int mmdelete, i;
        if(Language == "E")
        {
                mmdelete = Application->MessageBox("Are you sure you want to delete this item?","Delete Warning", MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "F")
        {
                mmdelete = Application->MessageBox("Êtes-vous certain de vouloir effacer cet item?","Attention!", MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "S")
        {
                mmdelete = Application->MessageBox("¿Es usted seguro usted desea suprimir este artículo?","Advertencia De la Cancelación", MB_YESNO|MB_ICONWARNING );
        }
        if (mmdelete == 6)
        {
                AnsiString temp;
                int line;
                line = MMCheckList->ItemIndex;
                temp = MMCheckList->Items->Strings[line];
                if(LeftStr(temp,3)==Cr6){temp = RightStr(temp,temp.Length()-3);}
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ide)&&(RightStr(ProfileMemo->Lines->Strings[i],temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Cr6)&&(RightStr(ProfileMemo->Lines->Strings[i],temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Ick)&&(RightStr(ProfileMemo->Lines->Strings[i],temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                MMCheckList->Items->Delete(line);
                MMDeleteBtn->Enabled = false;
                MMUpBtn->Enabled = false;
                MMDownBtn->Enabled = false;
                MMEditBtn->Enabled = false;
        }
        ProfileMemo->Lines->SaveToFile(filename);
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::TabSheet4Hide(TObject *Sender)
{
        if ((Edit3->Text != "")&&(MMName->Text != NewMastermindSession))
        {
                AnsiString name, lname;
                AMMName = MMName->Text;
                lname = "";
                Aname = "[" + Edit3->Text + "][" + MMName->Text + "]";
                int i;
                for ( i = MMName->Items->Count; i > -1; i--)
                {
                        if (MMName->Items->Strings[i] == "")
                        {
                                MMName->Items->Delete(i);
                        }
                }
                for ( i = MMName->Items->Count; i > -1; i--)
                {
                        if (MMName->Items->Strings[i] != NewMastermindSession)
                        {
                                name = Mas + "[" + Edit3->Text + "]" + MMName->Items->Strings[i];
                                if ((name != lname)&&(name != Mas + "[" + Edit3->Text + "]"))
                                {ProfileMemo->Lines->Add(name);}
                                lname = name;
                                MMName->Items->Delete(i);
                        }
                }
                for (i = 0; i < MMCheckList->Items->Count;i++)//                    MMCheckList->Items->Count-1; i > -1; i--)
                {
                        if(LeftStr(MMCheckList->Items->Strings[i],3)=="[C]"){MMCheckList->Items->Strings[i] = RightStr(MMCheckList->Items->Strings[i],MMCheckList->Items->Strings[i].Length()-3);}
                        if(MMCheckList->Checked[i] == true){ProfileMemo->Lines->Add(Ick + Aname + "[" +MMCheckList->Items->Strings[i] + "]");}
                        ProfileMemo->Lines->Add(Ide + Aname + MMCheckList->Items->Strings[i]);
                }
                ProfileMemo->Lines->SaveToFile(filename);
                MMCheckList->Clear();
                MMName->Clear();
                MMName->Text = Select;
                Ename = "";
        }
}
//---------------------------------------------------------------------------



void __fastcall TPagesDlg::TabSheet4Show(TObject *Sender)
{
        if (Edit3->Text != "")
        {
                int i, len, nlen, ilen;
                AnsiString goal, name;
                goal = "[" + Edit3->Text + "]";
                Agoal = goal;
                len = goal.Length();
                Cancel = false;
                MMName->Items->Add(NewMastermindSession);
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Mas + goal)
                        {
                                MMName->Items->Add(RightStr(ProfileMemo->Lines->Strings[i],(ProfileMemo->Lines->Strings[i].Length() - (3 + len))));
                        }
                }
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Mas + goal)
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                MMName->ItemIndex = 0;
                if(AMMName == "")
                {
                        MMName->Text = Select;
                }
                else
                {
                        MMName->Text = AMMName;
                        MMName->ItemIndex = MMName->Items->IndexOf(AMMName);
                {
                        goal = "[" + Edit3->Text + "]";
                        name = "[" + MMName->Text + "]";
                        len = goal.Length();
                        nlen = name.Length();
                        MMCheckList->Clear();
                        for (i = ProfileMemo->Lines->Count; i > - 1; i--)                 //0; i < ProfileMemo->Lines->Count; i++)
                        {
                                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len + nlen) == Ide + goal + name)
                                {
                                        MMCheckList->Items->Insert(0,RightStr(ProfileMemo->Lines->Strings[i],(ProfileMemo->Lines->Strings[i].Length() - (3 + len + nlen))));
                                }
                        }

                        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                        {
                                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len + nlen) == Ide + goal + name)
                                {
                                        ProfileMemo->Lines->Delete(i);
                                }
                        }
                        AnsiString Pidea;
                        AnsiString Lidea;
                        int index;
                        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                        {
                                Pidea = RightStr(ProfileMemo->Lines->Strings[i],ProfileMemo->Lines->Strings[i].Length()-( 3 + len + nlen));
                                index = MMCheckList->Items->IndexOf(Pidea);
                                if ((index > -1)&&(index < MMCheckList->Items->Count))
                                {
                                        MMCheckList->Items->Strings[index] = Cr6 + MMCheckList->Items->Strings[index];
                                }
                        }
                        AnsiString idea;
                        for (int j = MMCheckList->Items->Count-1; j > -1; j--)
                        {
                                if(MMCheckList->Items->Strings[j] != ""){idea = "[" + MMCheckList->Items->Strings[j] + "]";}
                                ilen = idea.Length();
                                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                                {
                                        if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len + nlen + ilen) == Ick + goal + name + idea)
                                        {
                                                MMCheckList->Checked[j] = true;
                                                ProfileMemo->Lines->Delete(i);
                                        }
                                }
                        }
                }
                }
        }
        else
        {
                if(Language == "E")
                {
                        Application->MessageBoxA("You must have an Active Goal. Return to the Goals tab and click on a goal","Missing Selection",MB_OK);
                }
                if(Language == "F")
                {
                        Application->MessageBoxA("Vous devez avoir un but sélectionné, retournez sur l'écran des buts et choisissez un but.","Sélection manquante",MB_OK);
                }
                if(Language == "S")
                {
                        Application->MessageBoxA("Usted debe tener una meta activa. Vuelva a la lengüeta de las metas y chasque encendido una meta","Selección Que falta",MB_OK);
                }
                Cancel = true;
                PageControl1->TabIndex = 0;
        }
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::Button5Click(TObject *Sender)
{
        int done;
        if (Language == "E")
        {
                done = Application->MessageBoxA("You are about to remove this item from the Critical 6 list. This cannot be undone. You must delete and re-enter the idea. Do you still want to check the task completed box?","Are You Sure?",MB_YESNOCANCEL);
        }
        if (Language == "F")
        {
                done = Application->MessageBoxA("Vous allez retirer cet item de la liste de 6 critiques, cette opération ne peut pas être annulée.  Vous devrez effacer et rentrer à nouveau cette idée.  Voulez-vous toujours marquez cette tâche comme complète?","Confirmation requise",MB_YESNOCANCEL);
        }
        if (Language == "S")
        {
                done = Application->MessageBoxA("Usted está a punto de quitar este artículo de la lista crítica 6. Esto no puede ser deshecha. Usted debe suprimir y volver a entrar la idea. ¿Usted sin embargo desea comprobar la caja terminada tarea?","¿Es Usted Seguro?",MB_YESNOCANCEL);
        }
        if(done == 6)
        {
                int i,chk;
                AnsiString temp = Cr6 + "[" + Edit3->Text + "]" + "[" + MMName->Text + "]" + MMCheckList->Items->Strings[MMCheckList->ItemIndex];
                chk = MMCheckList->ItemIndex;
                MMCheckList->Checked[chk] = true;
                for(i = ProfileMemo->Lines->Count;i > -1; i--)
                {
                        if(ProfileMemo->Lines->Strings[i] == temp)
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
        }
        else
        {
                if (Language == "E")
                {
                        Application->MessageBoxA("Operation cancelled","Operation cancelled",MB_OK);
                }
                if (Language == "F")
                {
                        Application->MessageBoxA("Opération annulée","Opération annulée",MB_OK);
                }
                if (Language == "S")
                {
                        Application->MessageBoxA("Operación cancelada","Operación cancelada",MB_OK);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::MMUpBtnClick(TObject *Sender)
{
        listitem = MMCheckList->ItemIndex;
        if (listitem > 0)
        {
                MMCheckList->Items->Move(listitem,listitem-1);
                MMCheckList->Selected[listitem-1] = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::MMDownBtnClick(TObject *Sender)
{
        listitem = MMCheckList->ItemIndex;
        if (listitem < MMCheckList->Items->Count-1)
        {
                MMCheckList->Items->Move(listitem,listitem+1);
                MMCheckList->Selected[listitem+1] = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Button4Click(TObject *Sender)
{
        listitem = MMCheckList->ItemIndex;

        if (listitem == -1)
        {
                if(Language == "E")
                {
                        Application->MessageBoxA("You need to select an Idea to add to the Critical 6 list, then click the button","Missing Selection", MB_OK);
                }
                if(Language == "F")
                {
                        Application->MessageBoxA("Vous devez sélectionner une idée à ajouter aux 6 Critiques avant d'appuyer sur ce bouton","Sélection manquante", MB_OK);
                }
                if(Language == "S")
                {
                        Application->MessageBoxA("Usted necesita seleccionar una idea de agregar a la lista crítica 6, entonces chasca el botón","Selección Que falta", MB_OK);
                }
        }
        else
        {
                if(MMCheckList->Checked[listitem] == true)
                {
                        if(Language == "E")
                        {
                                Application->MessageBoxA("You cannot send a completed item to the Critical 6 list","Task Already Completed",MB_OK);
                        }
                        if(Language == "F")
                        {
                                Application->MessageBoxA("Vous ne pouvez pas ajouter une tâche complétée aux 6 Critiques","La tâche est déjà complétée",MB_OK);
                        }
                        if(Language == "S")
                        {
                                Application->MessageBoxA("Usted no puede enviar un artículo terminado a la lista crítica 6","Tarea Terminada Ya",MB_OK);
                        }
                }
                else
                {
                        if(LeftStr(MMCheckList->Items->Strings[listitem],3) == "[C]")
                        {
                                if(Language == "E")
                                {
                                        Application->MessageBoxA("This item is already on the Critical 6 list","Already On List",MB_OK);
                                }
                                if(Language == "F")
                                {
                                        Application->MessageBoxA("Cet item est déjà sur la liste de 6 Critiques","Item est déjà sur la liste",MB_OK);
                                }
                                if(Language == "S")
                                {
                                        Application->MessageBoxA("Este artículo está ya en la lista crítica 6","Ya En Lista",MB_OK);
                                }
                        }
                        else
                        {
                                AnsiString  temp;
                                temp = MMCheckList->Items->Strings[listitem];
                                temp = Cr6 + "[" + Edit3->Text + "][" + MMName->Text + "]" + temp;
                                ProfileMemo->Lines->Add(temp);
                                MMCheckList->Items->Strings[listitem] = "[C]" + MMCheckList->Items->Strings[listitem];
                                if(Language == "E")
                                {
                                        Application->MessageBoxA("You have successfully added this Idea to your Critical 6 List","Idea Added",MB_OK);
                                }
                                if(Language == "F")
                                {
                                        Application->MessageBoxA("L'idée a été ajoutée aux 6 critiques","Idée ajoutée",MB_OK);
                                }
                                if(Language == "S")
                                {
                                        Application->MessageBoxA("Usted ha agregado con éxito esta idea a su lista crítica 6","La Idea Agregó",MB_OK);
                                }
                        }
                }                        
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::C6UPBtnClick(TObject *Sender)
{
        listitem = C6CheckListBox->ItemIndex;
        if (listitem > 0)
        {
                C6CheckListBox->Items->Move(listitem,listitem-1);
                C6CheckListBox->Selected[listitem-1] = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::C6DownBtnClick(TObject *Sender)
{
        listitem = C6CheckListBox->ItemIndex;
        if (listitem < C6CheckListBox->Items->Count-1)
        {
                C6CheckListBox->Items->Move(listitem,listitem+1);
                C6CheckListBox->Selected[listitem+1] = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::C6CheckListBoxClick(TObject *Sender)
{
        C6UPBtn->Enabled = true;
        C6DownBtn->Enabled = true;
        C6EditBtn->Enabled = true;
        C6DeleteBtn->Enabled = true;
        Button6->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Button6Click(TObject *Sender)
{
        int chk, i, done;
        AnsiString temp, check, idea;
        chk = C6CheckListBox->ItemIndex;
        idea = C6CheckListBox->Items->Strings[chk];
        if(Language == "E")
        {
                done = Application->MessageBoxA("You are about to remove this item from the Critical 6 list. This cannot be undone. You must delete and re-enter the idea. Do you still want to check the task completed box?","Are You Sure?",MB_YESNOCANCEL);
        }
        if(Language == "F")
        {
                done = Application->MessageBoxA("Vous allez retirer cet item de la liste de 6 critiques, cette opération ne peut pas être annulée.  Vous devrez effacer et rentrer à nouveau cette idée.  Voulez-vous toujours marquez cette tâche comme complète?","Confirmation requise",MB_YESNOCANCEL);
        }
        if(Language == "S")
        {
                done = Application->MessageBoxA("Usted está a punto de quitar este artículo de la lista crítica 6. Esto no puede ser deshecha. Usted debe suprimir y volver a entrar la idea. ¿Usted sin embargo desea comprobar la caja terminada tarea?","¿Es Usted Seguro?",MB_YESNOCANCEL);
        }
        if(done == 6)
        {
                for(i = ProfileMemo->Lines->Count;i > -1; i--)
                {
                        check = ProfileMemo->Lines->Strings[i];
                        if((LeftStr(check,3) == Ide)&&(RightStr(check,idea.Length()) == idea ))
                        {
                                temp = Ick + RightStr(check,check.Length()-3);
                                temp = LeftStr(temp,temp.Length()-idea.Length()) + "[" + idea + "]";
                                ProfileMemo->Lines->Add(temp);
                        }
                }
                for(i = ProfileMemo->Lines->Count;i > -1; i--)
                {
                        check = ProfileMemo->Lines->Strings[i];
                        if((LeftStr(check,3) == Cr6)&&(RightStr(check,idea.Length()) == idea ))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                C6CheckListBox->Items->Delete(chk);
        }
        else
        {
                C6CheckListBox->Checked[chk] = false;
                if(Language == "E")
                {
                        Application->MessageBoxA("Operation cancelled","Operation cancelled",MB_OK);
                }
                if(Language == "F")
                {
                        Application->MessageBoxA("Opération annulée","Opération annulée",MB_OK);
                }
                if(Language == "S")
                {
                        Application->MessageBoxA("Operación cancelada","Operación cancelada",MB_OK);
                }

        }
}
//---------------------------------------------------------------------------



void __fastcall TPagesDlg::MMMemoEnter(TObject *Sender)
{
        if(Language == "E")
        {
                if(( MMName->Text == "")||( MMName->Text == "Select a Mastermind Session")){Application->MessageBoxA("You must Select a Mastermind Session or Enter a new one","Missing Selection",MB_OK);}
        }
        if(Language == "F")
        {
                if(( MMName->Text == "")||( MMName->Text == "Choisissez une session de brainstorming")){Application->MessageBoxA("Vous devez sélection une session de brainstorming ou en créer une nouvelle","Sélection manquante",MB_OK);}
        }
        if(Language == "S")
        {
                if(( MMName->Text == "")||( MMName->Text == "Elija una sesión de reunión de reflexión")){Application->MessageBoxA("Deben selección una sesión de reunión de reflexión o crear una noticia","Selección Que falta",MB_OK);}
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::VisMemoClick(TObject *Sender)
{
        if(Edit3->Text == "")
        {
                Cancel = true;
                PageControl1->TabIndex = 0;
                if (Language == "E")
                {
                        Application->MessageBoxA("You must have an Active Goal. Return to the Goals tab and click on a goal","Missing Selection",MB_OK);
                }
                if (Language == "F")
                {
                        Application->MessageBoxA("Vous devez avoir un but sélectionné, retournez sur l'écran des buts et choisissez un but.","Sélection manquante",MB_OK);
                }
                if (Language == "S")
                {
                        Application->MessageBoxA("Usted debe tener una meta activa. Vuelva a la lengüeta de las metas y chasque encendido una meta","Selección Que falta",MB_OK);
                }
                PageControl1Change(Sender);
        }
        else
        {
                Cancel = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::RewMemoClick(TObject *Sender)
{
        if(Edit3->Text == "")
        {
                Cancel = true;
                PageControl1->TabIndex = 0;
                if(Language == "E")
                {
                        Application->MessageBoxA("You must have an Active Goal. Return to the Goals tab and click on a goal","Missing Selection",MB_OK);
                }
                if(Language == "F")
                {
                        Application->MessageBoxA("Vous devez avoir un but sélectionné, retournez sur l'écran des buts et choisissez un but.","Sélection manquante",MB_OK);
                }
                if(Language == "S")
                {
                        Application->MessageBoxA("Usted debe tener una meta activa. Vuelva a la lengüeta de las metas y chasque encendido una meta","Selección Que falta",MB_OK);
                }
                PageControl1Change(Sender);
        }
        else
        {
                Cancel = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::TabSheet5Show(TObject *Sender)
{
        AnsiString temp, goal;
        int i;
        C6CheckListBox->Clear();
        goal = "[" + Edit3->Text + "]";
        for (i = 0; i < ProfileMemo->Lines->Count; i++)// ProfileMemo->Lines->Count; i > -1; i--)
        {
                temp = ProfileMemo->Lines->Strings[i];
                if ((LeftStr(temp,3) == Cr6)&&(MidStr(temp,4,goal.Length()) == goal))
                {
                        int j = 0;
                        while ((LeftStr(RightStr(temp,j),1) != "]")&& (j < temp.Length()))
                        {
                                j++;
                        }
                        C6CheckListBox->Items->Add(RightStr(temp,j-1));
                }
        }
        if(C6CheckListBox->Items->Count < 0){Button6->Enabled = false;}
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::C6DeleteBtnClick(TObject *Sender)
{
        int c6delete;
        if(Language == "E")
        {
                c6delete = Application->MessageBoxA("Are you sure you want to delete this item?","Delete Warning",MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "F")
        {
                c6delete = Application->MessageBoxA("Êtes-vous certain de vouloir effacer cet item?","Attention!",MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "S")
        {
                c6delete = Application->MessageBoxA("¿Es usted seguro usted desea suprimir este artículo?","Advertencia De la Cancelación",MB_YESNO|MB_ICONWARNING );
        }
        if (c6delete == 6)
        {
                AnsiString temp;
                int line;
                line = C6CheckListBox->ItemIndex;
                temp = C6CheckListBox->Items->Strings[line];
                for (int i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if((LeftStr(ProfileMemo->Lines->Strings[i],3) == Cr6)&&(RightStr(ProfileMemo->Lines->Strings[i],temp.Length()) == temp))
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                C6CheckListBox->Items->Delete(line);
        }
        ProfileMemo->Lines->SaveToFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
        PrintBox->Clear();
        PrintBox->Lines->Add(Language);
        PrintBox->Lines->SaveToFile(Path + "mga.ini");
        PrintBox->Clear();
if((UserBox->Text != "")&&(filename != ""))
{
        int i;
        AnsiString smart, goal;
        smart = "";
        //Save any data in Goals list and SMART Boxes
        for(i = 0;i < ListBox1->Items->Count; i++)
        {
                goal = "[" + ListBox1->Items->Strings[i] + "]";
                if(CheckListBox1->Checked[i] == true){smart = "s";}
                if(CheckListBox1->Checked[i] == false){smart = "x";}
                if(CheckListBox2->Checked[i] == true){smart = smart + "m";}
                if(CheckListBox2->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox3->Checked[i] == true){smart = smart + "a";}
                if(CheckListBox3->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox4->Checked[i] == true){smart = smart + "r";}
                if(CheckListBox4->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox5->Checked[i] == true){smart = smart + "t";}
                if(CheckListBox5->Checked[i] == false){smart = smart + "x";}
                if(CheckListBox6->Checked[i] == true){smart = smart + "l";}
                if(CheckListBox6->Checked[i] == false){smart = smart + "x";}
                ProfileMemo->Lines->Add(Sma + goal + smart);
                ProfileMemo->Lines->Add(Gol + ListBox1->Items->Strings[i]);
        }
        ListBox1->Clear();
        CheckListBox1->Clear();
        CheckListBox2->Clear();
        CheckListBox3->Clear();
        CheckListBox4->Clear();
        CheckListBox5->Clear();
        CheckListBox6->Clear();
        ListBox2->Clear();
        //Save any data left in date picker and Visions page
        //Date picker saves to the ProfileMemo when it is changed
        //ProfileMemo->Lines->Add(Dat + Agoal + DateTimePicker1->Date);
        AnsiString vision = Vis + Agoal;
        for (int i = 0; i < VisMemo->Lines->Count; i++)
        {
                ProfileMemo->Lines->Add(vision + VisMemo->Lines->Strings[i]);
        }
        VisMemo->Clear();
        //Save any data left on Rewards Page
        AnsiString reward = Rew + Agoal;
        for (int i = 0; i < RewMemo->Lines->Count; i++)
        {
                ProfileMemo->Lines->Add(reward + RewMemo->Lines->Strings[i]);
        }
        RewMemo->Clear();
        //Save any data left on the Masterming page
        if(MMName->Text != Select)
        {
        AnsiString name, lname;
        ProfileMemo->Lines->SaveToFile(filename);
        for ( i = MMName->Items->Count; i > -1; i--)
        {
                if (MMName->Items->Strings[i] == "")
                {
                        MMName->Items->Delete(i);
                }
        }
        for ( i = MMName->Items->Count; i > -1; i--)
        {
                if (MMName->Items->Strings[i] != NewMastermindSession)
                {
                        if(Edit3->Text != "")
                        {
                                name = Mas + "[" + Edit3->Text + "]" + MMName->Items->Strings[i];
                                if (name != lname){ProfileMemo->Lines->Add(name);}
                                lname = name;
                                MMName->Items->Delete(i);
                                ProfileMemo->Lines->SaveToFile(filename);
                        }
                }
        }
        for (i = 0;i < MMCheckList->Items->Count; i++)
        {
                if(MMCheckList->Checked[i] == true){ProfileMemo->Lines->Add(Ick + Aname + "[" +MMCheckList->Items->Strings[i] + "]");}
                ProfileMemo->Lines->Add(Ide + Aname + MMCheckList->Items->Strings[i]);
        }
        if (filename != ""){ProfileMemo->Lines->SaveToFile(filename);}
        MMCheckList->Clear();
        }
        //Save any data left on the Critical 6 Page
        //This data is already saved when it is added to the C6 list from the
        //Mastermind list. It is save also when it is edited.

}
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::DeleteUserClick(TObject *Sender)
{
        int i, userdelete;
        if(Language =="E")
        {
                userdelete = Application->MessageBoxA("You are about to delete this user and the associated user profile, ARE YOU SURE?","Delete User",MB_YESNOCANCEL|MB_ICONWARNING);
        }
        if(Language =="F")
        {
                userdelete = Application->MessageBoxA("Vous êtes sur le point d'effacer cet usager et tout son profil, voulez-vous continuer?","Effacer un usager",MB_YESNOCANCEL|MB_ICONWARNING);
        }
        if(Language =="S")
        {
                userdelete = Application->MessageBoxA("¿Usted está a punto de suprimir a este usuario y el perfil de usuario asociado, ES USTED SEGURO?","Usuario De la Cancelación",MB_YESNOCANCEL|MB_ICONWARNING);
        }
        if(userdelete == 6)
        {
                filename = Path + UserBox->Text + ".gol";
                AnsiString temp = UserBox->Items->Strings[UserBox->ItemIndex];
                UserBox->Items->Delete(UserBox->ItemIndex);
                for (i = UserBox->Items->Count; i > -1; i--)
                {
                        if(UserBox->Items->Strings[i] == temp){UserBox->Items->Delete(i);}
                }
                ListBox1->Clear();
                ListBox2->Clear();
                CheckListBox1->Clear();
                CheckListBox2->Clear();
                CheckListBox3->Clear();
                CheckListBox4->Clear();
                CheckListBox5->Clear();
                CheckListBox6->Clear();
                UserBox->ItemIndex = 0;
                ProfileMemo->Clear();
                DeleteFile(filename);
                Edit3->Clear();
                Memo4->Clear();
                VisMemo->Clear();
                RewMemo->Clear();
                MMMemo->Clear();
                MMCheckList->Clear();
                C6CheckListBox->Clear();
                TabSheet1->Show();
                filename = "";
        }

}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::UserBoxClick(TObject *Sender)
{
        int i, len;
        AnsiString smart, goal, temp, NUser;
        smart = "";
        NextUser = UserBox->Text;
        if((NextUser != CurrentUser)&&(NextUser != ""))
        {
/*Start of Add New User Section*/
                if(NextUser == NewUser)
                {
                        if(Language == "E")
                        {
                                NUser = InputBox("New User","Enter new user name","");
                        }
                        if(Language == "F")
                        {
                                NUser = InputBox("Nouvel usager","Entrez le nom du nouvel usager","");
                        }
                        if(Language == "S")
                        {
                                NUser = InputBox("Nuevo Usuario","Incorpore el nuevo nombre del usuario","");
                        }
                        if (NUser != "")
                        {
                //Save any existing data on GOALS list
                                for(i = 0;i < ListBox1->Items->Count; i++)
                                {
                                        goal = "[" + ListBox1->Items->Strings[i] + "]";
                                        if(CheckListBox1->Checked[i] == true){smart = "s";}
                                        if(CheckListBox1->Checked[i] == false){smart = "x";}
                                        if(CheckListBox2->Checked[i] == true){smart = smart + "m";}
                                        if(CheckListBox2->Checked[i] == false){smart = smart + "x";}
                                        if(CheckListBox3->Checked[i] == true){smart = smart + "a";}
                                        if(CheckListBox3->Checked[i] == false){smart = smart + "x";}
                                        if(CheckListBox4->Checked[i] == true){smart = smart + "r";}
                                        if(CheckListBox4->Checked[i] == false){smart = smart + "x";}
                                        if(CheckListBox5->Checked[i] == true){smart = smart + "t";}
                                        if(CheckListBox5->Checked[i] == false){smart = smart + "x";}
                                        if(CheckListBox6->Checked[i] == true){smart = smart + "l";}
                                        if(CheckListBox6->Checked[i] == false){smart = smart + "x";}
                                        ProfileMemo->Lines->Add(Sma + goal + smart);
                                        ProfileMemo->Lines->Add(Gol + ListBox1->Items->Strings[i]);
                                }
                        //Save any data left in date picker and Visions page
                                if (Agoal != "")
                                {
                                        AnsiString vision = Vis + Agoal;
                                        for (int i = 0; i < VisMemo->Lines->Count; i++)
                                        {
                                                ProfileMemo->Lines->Add(vision + VisMemo->Lines->Strings[i]);
                                        }

                        //Save any data left on Rewards Page
                                        AnsiString reward = Rew + Agoal;
                                        for (int i = 0; i < RewMemo->Lines->Count; i++)
                                        {
                                                ProfileMemo->Lines->Add(reward + RewMemo->Lines->Strings[i]);
                                        }

                        //Save any data left on the Masterming page
                                        for (i = MMCheckList->Items->Count-1; i > -1; i--)
                                        {
                                                if(MMCheckList->Checked[i] == true){ProfileMemo->Lines->Add(Ick + Aname + "[" +MMCheckList->Items->Strings[i] + "]");}
                                                ProfileMemo->Lines->Add(Ide + Aname + MMCheckList->Items->Strings[i]);
                                        }
                                }
                                if (filename != "")
                                {
                                        ProfileMemo->Lines->SaveToFile(filename);
                                }

                        //Save any data left on the Critical 6 Page
                        //This data is already saved when it is added to the C6 list from the
                        //Mastermind list. It is save also when it is edited.

                                MMCheckList->Clear();
                                VisMemo->Clear();
                                RewMemo->Clear();
                        //Set up new user file and save empty profile
                                UserBox->Items->Add(NUser);
                                NextUser = NUser;
                                User = NextUser;
                                UserBox->ItemIndex = UserBox->Items->IndexOf(User);
                                filename = Path + User + ".gol";
                                ListBox1->Clear();
                                ListBox2->Clear();
                                VisMemo->Clear();
                                RewMemo->Clear();
                                DateTimePicker1->Date = Date();
                                CheckListBox1->Clear();
                                CheckListBox2->Clear();
                                CheckListBox3->Clear();
                                CheckListBox4->Clear();
                                CheckListBox5->Clear();
                                CheckListBox6->Clear();
                                C6CheckListBox->Clear();
                                Memo4->Clear();
                                Edit3->Clear();
                                MMCheckList->Clear();
                                MMName->Clear();
                                MMMemo->Clear();
                                ProfileMemo->Clear();
                                ProfileMemo->Lines->SaveToFile(filename);
                                ProfileMemo->Lines->LoadFromFile(filename);
                                DeleteUser->Enabled = true;
                        }
                        //Selected user is empty user
                        else
                        {
                                UserBox->Text = CurrentUser;
                                UserBox->ItemIndex = UserBox->Items->IndexOf(CurrentUser);
                                if(CurrentUser == "")
                                {
                                        UserBox->Text = SelectUser;
                                        UserBox->ItemIndex = -1;
                                }
                        }
                }
        }
        //No new user selected or empty user selected
        else
        {
                if(NextUser == "")
                {
                        NextUser = CurrentUser;
                }
        }
/*End of add new user section*/
/*Start of Change User Section*/
        if((NextUser != "")&&(NextUser != NewUser)&&(NextUser != SelectUser))
        {
        //Check to see if New User is the Current User
                if(NextUser == CurrentUser)
                {
                        //Don't change the data - restore the user name and return to the goal edit.
                        UserBox->ItemIndex = UserBox->Items->IndexOf(CurrentUser);
                }
                else
                {
                //New user is an existing profile
                //Save any existing data on GOALS list
                        for(i = 0;i < ListBox1->Items->Count; i++)
                        {
                                goal = "[" + ListBox1->Items->Strings[i] + "]";
                                if(CheckListBox1->Checked[i] == true){smart = "s";}
                                if(CheckListBox1->Checked[i] == false){smart = "x";}
                                if(CheckListBox2->Checked[i] == true){smart = smart + "m";}
                                if(CheckListBox2->Checked[i] == false){smart = smart + "x";}
                                if(CheckListBox3->Checked[i] == true){smart = smart + "a";}
                                if(CheckListBox3->Checked[i] == false){smart = smart + "x";}
                                if(CheckListBox4->Checked[i] == true){smart = smart + "r";}
                                if(CheckListBox4->Checked[i] == false){smart = smart + "x";}
                                if(CheckListBox5->Checked[i] == true){smart = smart + "t";}
                                if(CheckListBox5->Checked[i] == false){smart = smart + "x";}
                                if(CheckListBox6->Checked[i] == true){smart = smart + "l";}
                                if(CheckListBox6->Checked[i] == false){smart = smart + "x";}
                                ProfileMemo->Lines->Add(Sma + goal + smart);
                                ProfileMemo->Lines->Add(Gol + ListBox1->Items->Strings[i]);
                        }
                        //Save any data left in date picker and Visions page
                        if (Agoal != "")
                        {
                                AnsiString vision = Vis + Agoal;
                                for (int i = 0; i < VisMemo->Lines->Count; i++)
                                {
                                        ProfileMemo->Lines->Add(vision + VisMemo->Lines->Strings[i]);
                                }
                        //Save any data left on Rewards Page
                                AnsiString reward = Rew + Agoal;
                                for (int i = 0; i < RewMemo->Lines->Count; i++)
                                {
                                        ProfileMemo->Lines->Add(reward + RewMemo->Lines->Strings[i]);
                                }
                        //Save any data left on the Masterming page
                                for (i = MMCheckList->Items->Count-1; i > -1; i--)
                                {
                                        if(MMCheckList->Checked[i] == true){ProfileMemo->Lines->Add(Ick + Aname + "[" +MMCheckList->Items->Strings[i] + "]");}
                                        ProfileMemo->Lines->Add(Ide + Aname + MMCheckList->Items->Strings[i]);
                                }
                        }
                        if (filename != "")
                        {
                                ProfileMemo->Lines->SaveToFile(filename);
                        }
                        //Save any data left on the Critical 6 Page
                        //This data is already saved when it is added to the C6 list from the
                        //Mastermind list. It is save also when it is edited.
                        //Clear all visible data
                        MMCheckList->Clear();
                        VisMemo->Clear();
                        RewMemo->Clear();
                        ListBox1->Clear();
                        ListBox2->Clear();
                        CheckListBox1->Clear();
                        CheckListBox2->Clear();
                        CheckListBox3->Clear();
                        CheckListBox4->Clear();
                        CheckListBox5->Clear();
                        CheckListBox6->Clear();
                        //Load Next User data
                        filename = Path + NextUser + ".gol";
                        try
                        {
                                ProfileMemo->Lines->LoadFromFile(filename);
                        }
                        catch (...)
                        {
                                ProfileMemo->Clear();
                                ProfileMemo->Lines->SaveToFile(filename);
                                ProfileMemo->Lines->LoadFromFile(filename);
                        }
                        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                len = temp.Length();
                                if(LeftStr(temp,3) == Gol)
                                {
                                        ListBox1->Items->Insert(0,RightStr(temp,len - 3));
                                        goal = "[" + ListBox1->Items->Strings[0] + "]";
                                        CheckListBox1->Items->Insert(0,RightStr(temp,len - 3));
                                        CheckListBox2->Items->Insert(0,RightStr(temp,len - 3));
                                        CheckListBox3->Items->Insert(0,RightStr(temp,len - 3));
                                        CheckListBox4->Items->Insert(0,RightStr(temp,len - 3));
                                        CheckListBox5->Items->Insert(0,RightStr(temp,len - 3));
                                        CheckListBox6->Items->Insert(0,RightStr(temp,len - 3));
                                        ListBox2->Items->Add(ListBox1->Items->Count);
                                }
                                if((LeftStr(temp,3) == Sma)&&(MidStr(temp,4,goal.Length()) == goal ))
                                {
                                        if(MidStr(temp,3 + goal.Length() + 1,1) == "s"){CheckListBox1->Checked[0] = true;}
                                        if(MidStr(temp,3 + goal.Length() + 2,1) == "m"){CheckListBox2->Checked[0] = true;}
                                        if(MidStr(temp,3 + goal.Length() + 3,1) == "a"){CheckListBox3->Checked[0] = true;}
                                        if(MidStr(temp,3 + goal.Length() + 4,1) == "r"){CheckListBox4->Checked[0] = true;}
                                        if(MidStr(temp,3 + goal.Length() + 5,1) == "t"){CheckListBox5->Checked[0] = true;}
                                        if(MidStr(temp,3 + goal.Length() + 6,1) == "l"){CheckListBox6->Checked[0] = true;}
                                }
                        }
                        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                        {
                                temp = ProfileMemo->Lines->Strings[i];
                                if((LeftStr(temp,3) == Sma)||(LeftStr(temp,3) == Gol)){ProfileMemo->Lines->Delete(i);}
                        }
                        PageControl1->Enabled = true;
                        DeleteUser->Enabled = true;
                        ListBox1->Enabled = true;
                        if(UserBox->Text != ""){Memo4->SetFocus();}
                        }
        }
        if(NextUser != NewUser){CurrentUser = NextUser;}
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::UserBoxExit(TObject *Sender)
{
        StartHereLbl->Visible = false;
        StartHereLbl->Caption = "";
        PrintGoalsCriticalTasks1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::DeleteProfilesClick(TObject *Sender)
{
        int Profiledelete;
        if(Language == "E")
        {
                Profiledelete = Application->MessageBoxA("Are you sure you want to delete ALL Profiles?","ALL Profile Delete Warning",MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "F")
        {
                Profiledelete = Application->MessageBoxA("Êtes-vous certain de vouloir effacer tous les profils?","Avertissement!",MB_YESNO|MB_ICONWARNING );
        }
        if(Language == "S")
        {
                Profiledelete = Application->MessageBoxA("¿Es usted seguro usted desea suprimir TODOS LOS perfiles?","TODA LA Advertencia De la Cancelación Del Perfil",MB_YESNO|MB_ICONWARNING );
        }
        if(Profiledelete == 6)
        {
                UserBox->Clear();
                UserBox->Items->Add(NewUser);
                TSearchRec sr;
                if (FindFirst(Path + "*.gol",0,sr)==0)
                {
                        do
                        {
                                DeleteFile(Path + sr.Name);
                        } while (FindNext(sr) == 0);
                FindClose(sr);
                }
                Edit3->Clear();
                ListBox1->Clear();
                ListBox2->Clear();
                CheckListBox1->Clear();
                CheckListBox2->Clear();
                CheckListBox3->Clear();
                CheckListBox4->Clear();
                CheckListBox5->Clear();
                CheckListBox6->Clear();
                UpBtn->Enabled = false;
                DownBtn->Enabled = false;
                EditBtn->Enabled = false;
                DeleteBtn->Enabled = false;
                GABtn->Enabled = false;
                Button1->Enabled = false;
                PrintSelectedGoalandCriticalTasks1->Enabled = false;
                ProfileMemo->Clear();
                VisMemo->Clear();
                DateTimePicker1->Date = Date();
                RewMemo->Clear();
                MMMemo->Clear();
                MMName->Clear();
                MMCheckList->Clear();
                Button4->Enabled = false;
                Button5->Enabled = false;
                MMUpBtn->Enabled = false;
                MMDownBtn->Enabled = false;
                MMEditBtn->Enabled = false;
                MMDeleteBtn->Enabled = false;
                C6CheckListBox->Clear();
                C6UPBtn->Enabled = false;
                C6DownBtn->Enabled = false;
                C6EditBtn->Enabled = false;
                C6DeleteBtn->Enabled = false;
                Button6->Enabled = false;
                C6Print->Enabled = false;


        }
        UserBox->Text = SelectUser;
        UserBox->ItemIndex = -1;
        UserBox->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::DateTimePicker1CloseUp(TObject *Sender)
{
        int i, len;
        if(Edit3->Text != "")
        {
                AnsiString goal = "[" + Edit3->Text + "]";
                len = goal.Length();
                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                {
                        if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len) == Dat + goal)
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
                ProfileMemo->Lines->Add(Dat + goal + DateTimePicker1->Date);
                Label21->Visible = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::MMNameClick(TObject *Sender)
{
        if (MMName->Text != Ename)
        {
                AnsiString goal, name;
                int len, nlen, ilen, i;

                for (i = MMCheckList->Items->Count-1; i > -1; i--)
                {
                        if(MMCheckList->Checked[i] == true){ProfileMemo->Lines->Add(Ick + Aname + "[" +MMCheckList->Items->Strings[i] + "]");}
                        ProfileMemo->Lines->Add(Ide + Aname + MMCheckList->Items->Strings[i]);
                }
                ProfileMemo->Lines->SaveToFile(filename);


                if ((MMName->Text != NewMastermindSession)&&(MMName->Text != "")&&(MMName->Text != Select))
                {
                        goal = "[" + Edit3->Text + "]";
                        name = "[" + MMName->Text + "]";
                        len = goal.Length();
                        nlen = name.Length();
                        MMCheckList->Clear();
                        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                        {
                                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len + nlen) == Ide + goal + name)
                                {
                                        MMCheckList->Items->Insert(0,RightStr(ProfileMemo->Lines->Strings[i],(ProfileMemo->Lines->Strings[i].Length() - (3 + len + nlen))));
                                }
                        }

                        for (i = ProfileMemo->Lines->Count; i > -1; i--)
                        {
                                if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len + nlen) == Ide + goal + name)
                                {
                                        ProfileMemo->Lines->Delete(i);
                                }
                        }
                        AnsiString idea;
                        for (int j = MMCheckList->Items->Count-1; j > -1; j--)
                        {
                                if(MMCheckList->Items->Strings[j] != ""){idea = "[" + MMCheckList->Items->Strings[j] + "]";}
                                ilen = idea.Length();
                                for (i = ProfileMemo->Lines->Count; i > -1; i--)
                                {
                                        if (LeftStr(ProfileMemo->Lines->Strings[i],3 + len + nlen + ilen) == Ick + goal + name + idea)
                                        {
                                                MMCheckList->Checked[j] = true;
                                                ProfileMemo->Lines->Delete(i);
                                        }
                                }
                        }
                }
                if(MMName->Text == NewMastermindSession)
                {
                        AnsiString NewMM = InputBox(NewMastermindSession,"Enter " + NewMastermindSession + " Name","");
                        if (NewMM != "")
                        {
                                MMCheckList->Clear();
                                MMName->Items->Add(NewMM);
                                MMName->ItemIndex = MMName->Items->IndexOf(NewMM);
                                MMMemo->SetFocus();
 ProfileMemo->Lines->SaveToFile(filename);
                        }
                        else
                        {
                                MMName->ItemIndex = MMName->Items->IndexOf(Ename);
                        }
                        if(MMName->Text == "")
                        {
                                MMName->Text = Select;
                        }

                }
                if((MMName->Text != "")&&(MMName->Text != Select))
                {
                        Ename = MMName->Text;
                        Aname = "[" + Edit3->Text + "][" + MMName->Text + "]";
                }
        }
 }
//---------------------------------------------------------------------------



void __fastcall TPagesDlg::C6EditBtnClick(TObject *Sender)
{
        int i;
        AnsiString temp, old;
        listitem = C6CheckListBox->ItemIndex;
        old = C6CheckListBox->Items->Strings[listitem];
        if(Language == "E")
        {
                C6CheckListBox->Items->Strings[listitem] = InputBox("Critical 6 Editor","Enter new text for this idea",C6CheckListBox->Items->Strings[listitem]);
        }
        if(Language == "F")
        {
                C6CheckListBox->Items->Strings[listitem] = InputBox("Rédacteur 6 Critique","Écrivez le nouveau texte pour cette idée",C6CheckListBox->Items->Strings[listitem]);
        }
        if(Language == "S")
        {
                C6CheckListBox->Items->Strings[listitem] = InputBox("Redactor Crítico 6","Incorpore el nuevo texto para esta idea",C6CheckListBox->Items->Strings[listitem]);
        }
        for (i = -1; i < ProfileMemo->Lines->Count; i++)
        {
                if(RightStr(ProfileMemo->Lines->Strings[i],old.Length()) == old)
                {
                        temp = LeftStr(ProfileMemo->Lines->Strings[i],ProfileMemo->Lines->Strings[i].Length()-old.Length())+C6CheckListBox->Items->Strings[listitem];
                        ProfileMemo->Lines->Delete(i);
                        ProfileMemo->Lines->Insert(i,temp);
                }
        }
        ProfileMemo->Lines->SaveToFile(filename);

}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::CheckListBox2ClickCheck(TObject *Sender)
{
        int i;
        i = CheckListBox2->ItemIndex;
          if((CheckListBox1->Checked[i] == true)&&(CheckListBox2->Checked[i] == true)&&(CheckListBox3->Checked[i] == true)&&(CheckListBox4->Checked[i] == true)&&(CheckListBox5->Checked[i] == true))
          {
             CheckListBox6->Checked[i] = true;
          }
          else
          {
              CheckListBox6->Checked[i] = false;
          }
          ListBox1->ItemIndex = i;
          ListBox2->ItemIndex = i;
          ListBox1->Selected[i] = true;
          ListBox2->Selected[i] = true;
          Edit3->Text = ListBox1->Items->Strings[i];
          Cancel = false;
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::CheckListBox3ClickCheck(TObject *Sender)
{
        int i;
        i = CheckListBox3->ItemIndex;
          if((CheckListBox1->Checked[i] == true)&&(CheckListBox2->Checked[i] == true)&&(CheckListBox3->Checked[i] == true)&&(CheckListBox4->Checked[i] == true)&&(CheckListBox5->Checked[i] == true))
          {
             CheckListBox6->Checked[i] = true;
          }
          else
          {
              CheckListBox6->Checked[i] = false;
          }
          ListBox1->ItemIndex = i;
          ListBox2->ItemIndex = i;
          ListBox1->Selected[i] = true;
          ListBox2->Selected[i] = true;
          Edit3->Text = ListBox1->Items->Strings[i];
          Cancel = false;
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::CheckListBox4ClickCheck(TObject *Sender)
{
        int i;
        i = CheckListBox4->ItemIndex;
          if((CheckListBox1->Checked[i] == true)&&(CheckListBox2->Checked[i] == true)&&(CheckListBox3->Checked[i] == true)&&(CheckListBox4->Checked[i] == true)&&(CheckListBox5->Checked[i] == true))
          {
             CheckListBox6->Checked[i] = true;
          }
          else
          {
              CheckListBox6->Checked[i] = false;
          }
          ListBox1->ItemIndex = i;
          ListBox2->ItemIndex = i;
          ListBox1->Selected[i] = true;
          ListBox2->Selected[i] = true;
          Edit3->Text = ListBox1->Items->Strings[i];
          Cancel = false;
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::CheckListBox5ClickCheck(TObject *Sender)
{
        int i;
        i = CheckListBox5->ItemIndex;
          if((CheckListBox1->Checked[i] == true)&&(CheckListBox2->Checked[i] == true)&&(CheckListBox3->Checked[i] == true)&&(CheckListBox4->Checked[i] == true)&&(CheckListBox5->Checked[i] == true))
          {
             CheckListBox6->Checked[i] = true;
          }
          else
          {
              CheckListBox6->Checked[i] = false;
          }
          ListBox1->ItemIndex = i;
          ListBox2->ItemIndex = i;
          ListBox1->Selected[i] = true;
          ListBox2->Selected[i] = true;
          Edit3->Text = ListBox1->Items->Strings[i];
          Cancel = false;
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::CheckListBox1ClickCheck(TObject *Sender)
{
        int i;
        i = CheckListBox1->ItemIndex;
          if((CheckListBox1->Checked[i] == true)&&(CheckListBox2->Checked[i] == true)&&(CheckListBox3->Checked[i] == true)&&(CheckListBox4->Checked[i] == true)&&(CheckListBox5->Checked[i] == true))
          {
             CheckListBox6->Checked[i] = true;
          }
          else
          {
              CheckListBox6->Checked[i] = false;
          }
          ListBox1->ItemIndex = i;
          ListBox2->ItemIndex = i;
          ListBox1->Selected[i] = true;
          ListBox2->Selected[i] = true;
          Edit3->Text = ListBox1->Items->Strings[i];
          Cancel = false;
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::GABtnClick(TObject *Sender)
{
        AnsiString goal = Edit3->Text;
        Edit3->Clear();
        AnsiString Bgoal = "[" + goal + "]";
        AnsiString Cgoal = Com + Bgoal;
        AnsiString temp;
        int i, line;
        line = ListBox1->ItemIndex;
        ListBox1->Items->Delete(line);
        CheckListBox1->Items->Delete(line);
        CheckListBox2->Items->Delete(line);
        CheckListBox3->Items->Delete(line);
        CheckListBox4->Items->Delete(line);
        CheckListBox5->Items->Delete(line);
        CheckListBox6->Items->Delete(line);
        ListBox2->Clear();//Items->Delete(line);
        for(i = 0;i<ListBox1->Items->Count;i++)
        {
                ListBox2->Items->Add(i+1);
        }//(ListBox2->Items->Count-1);
        ProfileMemo->Lines->Add(Com + Gol + goal + " - Completed " + Date());
        if(Language == "E")
        {
                Application->MessageBoxA("You have successfully moved your goal to the Completed Goals page","CONGRATULATIONS!",MB_OK);
        }
        if(Language == "F")
        {
                Application->MessageBoxA("Vous avez réussi à ajouter un but à votre tableau de succès","Félicitations!",MB_OK);
        }
        if(Language == "S")
        {
                Application->MessageBoxA("Usted ha movido con éxito su meta a la página terminada de las metas","¡cFelicitaciones!",MB_OK);
        }
        for(i = -1; i < ProfileMemo->Lines->Count; i++)
        {
                temp = ProfileMemo->Lines->Strings[i];
                if (MidStr(temp,4,Bgoal.Length())==Bgoal)
                {
                        temp = Com + temp;
                        ProfileMemo->Lines->Delete(i);
                        ProfileMemo->Lines->Insert(i,temp);
                }
        }
        Memo4->SetFocus();
        GABtn->Enabled = false;
        UpBtn->Enabled = false;
        DownBtn->Enabled = false;
        EditBtn->Enabled = false;
        DeleteBtn->Enabled = false;
        Button1->Enabled = false;
/*        OpenDialog1->DefaultExt = "WAV";
        OpenDialog1->FileName = "*.wav";

        if (OpenDialog1->Execute())
        {
                MGAMusic->FileName = OpenDialog1->FileName;
                MGAMusic->Open();
        }   */
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::TabSheet7Show(TObject *Sender)
{
        int i;
        AnsiString temp;
        for (i = -1; i < ProfileMemo->Lines->Count; i++)
        {
                temp = ProfileMemo->Lines->Strings[i];
                if((LeftStr(temp,6) == Com + Gol)&&(MidStr(temp,7,1) != "["))
                {
                        DoneListBox->Items->Add(RightStr(temp,temp.Length()-6));
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::TabSheet7Hide(TObject *Sender)
{
        DoneListBox->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::TabSheet6Show(TObject *Sender)
{
        int i;
        AnsiString temp, goal;
        goal = "[" + Edit3->Text + "]";
        for (i = -1; i < ProfileMemo->Lines->Count; i ++)
        {
                temp = ProfileMemo->Lines->Strings[i];
                if(LeftStr(temp,3 + goal.Length()) == Suc + goal)
                {
                        Memo2->Lines->Add(RightStr(temp,temp.Length() - (3 + goal.Length())));
                }
        }
        for (i = ProfileMemo->Lines->Count;i > -1; i --)
        {
                temp = ProfileMemo->Lines->Strings[i];
                if(LeftStr(temp,3 + goal.Length()) == Suc + goal) 
                {
                        ProfileMemo->Lines->Delete(i);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::TabSheet6Hide(TObject *Sender)
{
        int i;
        AnsiString temp, goal;
        goal = "[" + Edit3->Text + "]";
        for (i = -1; i < Memo2->Lines->Count; i ++)
        {
                if(Memo2->Lines->Strings[i] != "")
                {
                        temp = Suc + goal + Memo2->Lines->Strings[i];
                        ProfileMemo->Lines->Add(temp);
                }
        }
        Memo2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Label7Click(TObject *Sender)
{
        int length;
        if(Language == "E")
        {
                if((SmartMemo->Visible == true)&&(Smart == 1))
                {
                        SmartMemo->Visible = false;
                }
                else
                {
                        Smart = 1;
                        if(SmartMemo->Visible == true)
                        {
                                SmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 1;

                        }
                        if(SmartMemo->Visible == false)
                        {
                                SmartMemo->Visible = true;
                                for (int I = 0; I < SmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SmartMemo->Lines->Strings[I].Pos("S:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SmartMemo->SetFocus();
                                                        SmartMemo->SelStart = Skipchars;

                                                        SmartMemo->SelLength = length;
                                                        break;
                                        }
                                }
                        }
                }
        }
        if(Language == "F")
        {
                if((FRSmartMemo->Visible == true)&&(Smart == 1))
                {
                        FRSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 1;
                        if(FRSmartMemo->Visible == true)
                        {
                                FRSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 1;

                        }
                        if(FRSmartMemo->Visible == false)
                        {
                                FRSmartMemo->Visible = true;
                                for (int I = 0; I < FRSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = FRSmartMemo->Lines->Strings[I].Pos("S:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += FRSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        FRSmartMemo->SetFocus();
                                                        FRSmartMemo->SelStart = Skipchars;

                                                        FRSmartMemo->SelLength = length;//316;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
        if(Language == "S")
        {
                if((SPSmartMemo->Visible == true)&&(Smart == 1))
                {
                        SPSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 1;
                        if(SPSmartMemo->Visible == true)
                        {
                                SPSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 1;

                        }
                        if(SPSmartMemo->Visible == false)
                        {
                                SPSmartMemo->Visible = true;
                                for (int I = 0; I < SPSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SPSmartMemo->Lines->Strings[I].Pos("S:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SPSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SPSmartMemo->SetFocus();
                                                        SPSmartMemo->SelStart = Skipchars;

                                                        SPSmartMemo->SelLength = length;//316;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Label8Click(TObject *Sender)
{
        int length;
        if(Language == "E")
        {
                if((SmartMemo->Visible == true)&&(Smart == 2))
                {
                        SmartMemo->Visible = false;
                }
                else
                {
                        Smart = 2;
                        if(SmartMemo->Visible == true)
                        {
                        SmartMemo->SetFocus();
                        SmartMemo->SelLength = 1000;
                                SmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 239;
                        }
                        if(SmartMemo->Visible == false)
                        {
                                SmartMemo->Visible = true;
                                for (int I = 0; I < SmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SmartMemo->Lines->Strings[I].Pos("M:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SmartMemo->SetFocus();
                                                        SmartMemo->SelStart = Skipchars;

                                                        SmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }


                        }

                }
        }
        if(Language == "F")
        {
                if((FRSmartMemo->Visible == true)&&(Smart == 2))
                {
                        FRSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 2;
                        if(FRSmartMemo->Visible == true)
                        {
                                FRSmartMemo->SetFocus();
                                FRSmartMemo->SelLength = 1000;
                                FRSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 239;
                        }
                        if(FRSmartMemo->Visible == false)
                        {
                                FRSmartMemo->Visible = true;
                                for (int I = 0; I < FRSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = FRSmartMemo->Lines->Strings[I].Pos("M:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += FRSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        FRSmartMemo->SetFocus();
                                                        FRSmartMemo->SelStart = Skipchars;

                                                        FRSmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }


                        }

                }
        }
        if(Language == "S")
        {
                if((SPSmartMemo->Visible == true)&&(Smart == 2))
                {
                        SPSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 2;
                        if(SPSmartMemo->Visible == true)
                        {
                                SPSmartMemo->SetFocus();
                                SPSmartMemo->SelLength = 1000;
                                SPSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 239;
                        }
                        if(SPSmartMemo->Visible == false)
                        {
                                SPSmartMemo->Visible = true;
                                for (int I = 0; I < SPSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SPSmartMemo->Lines->Strings[I].Pos("M:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SPSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SPSmartMemo->SetFocus();
                                                        SPSmartMemo->SelStart = Skipchars;

                                                        SPSmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }


                        }

                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Label9Click(TObject *Sender)
{
        int length;
        if(Language == "E")
        {
                if((SmartMemo->Visible == true)&&(Smart == 3))
                {
                        SmartMemo->Visible = false;
                }
                else
                {
                        Smart = 3;
                        if(SmartMemo->Visible == true)
                        {
                                SmartMemo->SetFocus();
                                SmartMemo->SelLength = 1000;
                                SmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 400;
                        }
                        if(SmartMemo->Visible == false)
                        {
                                SmartMemo->Visible = true;
                                for (int I = 0; I < SmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SmartMemo->Lines->Strings[I].Pos("A:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SmartMemo->SetFocus();
                                                        SmartMemo->SelStart = Skipchars;

                                                        SmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
        if(Language == "F")
        {
                if((FRSmartMemo->Visible == true)&&(Smart == 3))
                {
                        FRSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 3;
                        if(FRSmartMemo->Visible == true)
                        {
                                FRSmartMemo->SetFocus();
                                FRSmartMemo->SelLength = 1000;
                                FRSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 400;
                        }
                        if(FRSmartMemo->Visible == false)
                        {
                                FRSmartMemo->Visible = true;
                                for (int I = 0; I < FRSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = FRSmartMemo->Lines->Strings[I].Pos("A:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += FRSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        FRSmartMemo->SetFocus();
                                                        FRSmartMemo->SelStart = Skipchars;

                                                        FRSmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
        if(Language == "S")
        {
               if((SPSmartMemo->Visible == true)&&(Smart == 3))
                {
                        SPSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 3;
                        if(SPSmartMemo->Visible == true)
                        {
                                SPSmartMemo->SetFocus();
                                SPSmartMemo->SelLength = 1000;
                                SPSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 400;
                        }
                        if(SPSmartMemo->Visible == false)
                        {
                                SPSmartMemo->Visible = true;
                                for (int I = 0; I < SPSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SPSmartMemo->Lines->Strings[I].Pos("A:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SPSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SPSmartMemo->SetFocus();
                                                        SPSmartMemo->SelStart = Skipchars;

                                                        SPSmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Label10Click(TObject *Sender)
{
        int length;
        if(Language == "E")
        {
                if((SmartMemo->Visible == true)&&(Smart == 4))
                {
                        SmartMemo->Visible = false;
                }
                else
                {
                        Smart = 4;
                        if(SmartMemo->Visible == true)
                        {
                                SmartMemo->SetFocus();
                                SmartMemo->SelLength = 2000;
                                SmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 400;
                        }
                        if(SmartMemo->Visible == false)
                        {
                                SmartMemo->Visible = true;
                                for (int I = 0; I < SmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SmartMemo->Lines->Strings[I].Pos("R:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SmartMemo->SetFocus();
                                                        SmartMemo->SelStart = Skipchars;

                                                        SmartMemo->SelLength =length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
        if(Language == "F")
        {
                if((FRSmartMemo->Visible == true)&&(Smart == 4))
                {
                        FRSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 4;
                        if(FRSmartMemo->Visible == true)
                        {
                                FRSmartMemo->SetFocus();
                                FRSmartMemo->SelLength = 2000;
                                FRSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 400;
                        }
                        if(FRSmartMemo->Visible == false)
                        {
                                FRSmartMemo->Visible = true;
                                for (int I = 0; I < FRSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = FRSmartMemo->Lines->Strings[I].Pos("R:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += FRSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        FRSmartMemo->SetFocus();
                                                        FRSmartMemo->SelStart = Skipchars;

                                                        FRSmartMemo->SelLength =length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
        if(Language == "S")
        {
                if((SPSmartMemo->Visible == true)&&(Smart == 4))
                {
                        SPSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 4;
                        if(SPSmartMemo->Visible == true)
                        {
                                SPSmartMemo->SetFocus();
                                SPSmartMemo->SelLength = 2000;
                                SPSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 400;
                        }
                        if(SPSmartMemo->Visible == false)
                        {
                                SPSmartMemo->Visible = true;
                                for (int I = 0; I < SPSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SPSmartMemo->Lines->Strings[I].Pos("R:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SPSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SPSmartMemo->SetFocus();
                                                        SPSmartMemo->SelStart = Skipchars;

                                                        SPSmartMemo->SelLength =length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Label11Click(TObject *Sender)
{
        int length;
        if(Language == "E")
        {
                if((SmartMemo->Visible == true)&&(Smart == 5))
                {
                        SmartMemo->Visible = false;
                }
                else
                {
                        Smart = 5;
                        if(SmartMemo->Visible == true)
                        {
                                SmartMemo->SetFocus();
                                SmartMemo->SelLength = 2000;
                                SmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 320;
                                                        }
                        if(SmartMemo->Visible == false)
                        {
                                SmartMemo->Visible = true;
                                for (int I = 0; I < SmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SmartMemo->Lines->Strings[I].Pos("T:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SmartMemo->SetFocus();
                                                        SmartMemo->SelStart = Skipchars;

                                                        SmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }

                }
        }
        if(Language == "F")
        {
                if((FRSmartMemo->Visible == true)&&(Smart == 5))
                {
                        FRSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 5;
                        if(FRSmartMemo->Visible == true)
                        {
                                FRSmartMemo->SetFocus();
                                FRSmartMemo->SelLength = 2000;
                                FRSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 320;
                                                        }
                        if(FRSmartMemo->Visible == false)
                        {
                                FRSmartMemo->Visible = true;
                                for (int I = 0; I < FRSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = FRSmartMemo->Lines->Strings[I].Pos("T:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += FRSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        FRSmartMemo->SetFocus();
                                                        FRSmartMemo->SelStart = Skipchars;

                                                        FRSmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }

                }
        }
        if(Language == "S")
        {
                if((SPSmartMemo->Visible == true)&&(Smart == 5))
                {
                        SPSmartMemo->Visible = false;
                }
                else
                {
                        Smart = 5;
                        if(SPSmartMemo->Visible == true)
                        {
                                SPSmartMemo->SetFocus();
                                SPSmartMemo->SelLength = 2000;
                                SPSmartMemo->Visible = false;
                                length = 1;
                        }
                        else
                        {
                                length = 320;
                                                        }
                        if(SPSmartMemo->Visible == false)
                        {
                                SPSmartMemo->Visible = true;
                                for (int I = 0; I < SPSmartMemo->Lines->Count; I++)
                                {
                                        int PosReturn = SPSmartMemo->Lines->Strings[I].Pos("T:");
                                        if (PosReturn) //found!
                                        {
                                                int Skipchars = 0;
                                                for (int J = 0; J < I; J++)
                                                        Skipchars += SPSmartMemo->Lines->Strings[J].Length();
                                                        Skipchars += I*2; // add CR/LF for all skipped lines
                                                        Skipchars += PosReturn - 1;
                                                        SPSmartMemo->SetFocus();
                                                        SPSmartMemo->SelStart = Skipchars;

                                                        SPSmartMemo->SelLength = length;//FindDialog1->FindText.Length();
                                                        break;
                                        }
                                }
                        }

                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::C6PrintClick(TObject *Sender)
{
        int i;
        PrintBox->Lines->Add(URLName);
        PrintBox->Lines->Add("");
        PrintBox->Lines->Add("My Goal is: " + Edit3->Text);
        PrintBox->Lines->Add("");
        PrintBox->Lines->Add("My Tasks List:");
        PrintBox->Lines->Add("");
        for(i = 0;i<C6CheckListBox->Items->Count;i++)
        {
                PrintBox->Lines->Add(C6CheckListBox->Items->Strings[i]);

        }
        PrintDialog1->Execute();
        PrintBox->Print(PagesDlg->Caption);
        PrintBox->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::PrintSelectedGoalandCriticalTasks1Click(
      TObject *Sender)
{
        int i,j;
        AnsiString temp, goal;
        goal = "[" + Edit3->Text + "]";
        PrintBox->Lines->AddObject(URLName,Image2->Picture->Graphic);
        PrintBox->Lines->Add("");
        PrintBox->Lines->Add("Goal: " + Edit3->Text);
        for (i=0;i<ProfileMemo->Lines->Count;i++)
        {
                temp = ProfileMemo->Lines->Strings[i];
                if(LeftStr(temp,3+goal.Length())==Cr6+goal)
                {
                        j = 4 + goal.Length();
                        while(MidStr(temp,j,1)!="]"){j++;}
                        PrintBox->Lines->Add(RightStr(temp,temp.Length()-j));
                }
        }
        PrintDialog1->Execute();
        PrintBox->Print(PagesDlg->Caption);
        PrintBox->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::PrintGoalsCriticalTasks1Click(TObject *Sender)
{
        int i,j;
        bool flag = false;
        AnsiString temp, goal;
        PrintBox->Lines->AddObject(URLName,Image2->Picture->Graphic);
        PrintBox->Lines->Add("");
        if(ListBox1->Items->Count < 1)
        {
                flag = true;
                for (i=0;i<ProfileMemo->Lines->Count;i++)
                {
                        if(LeftStr(ProfileMemo->Lines->Strings[i],3)==Gol)
                        {
                                ListBox1->Items->Add(ProfileMemo->Lines->Strings[i]);
                        }
                }
        }
        for(i=0;i<ListBox1->Items->Count;i++)
        {
                PrintBox->Lines->Add(IntToStr(i+1) + ") " + RightStr(ListBox1->Items->Strings[i],ListBox1->Items->Strings[i].Length()));
                goal = "[" + RightStr(ListBox1->Items->Strings[i],ListBox1->Items->Strings[i].Length()) + "]";
                for (j=0;j<ProfileMemo->Lines->Count;j++)
                {
                        temp = ProfileMemo->Lines->Strings[j];
                        if(LeftStr(temp,3+goal.Length())==Cr6+goal)
                        {
                                int k = 4 + goal.Length();
                                while(MidStr(temp,k,1)!="]"){k++;}
                                PrintBox->Lines->Add(RightStr(temp,temp.Length()-k));

                        }
                }
                PrintBox->Lines->Add("");

        }
        if(flag){ListBox1->Clear();}
        PrintDialog1->Execute();
        PrintBox->Print(PagesDlg->Caption);
        PrintBox->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::French1Click(TObject *Sender)
{
        int i, line;
        AnsiString temp;
        Language = "F";
        SelectUser = "Choisir un usager";
        NewUser = "Nouvel usager";
        NewMastermindSession = "Nouvelle session de brainstorming";
        Select = "Choisissez une session de brainstorming";
        line = UserBox->ItemIndex;
        AnsiString TUser = UserBox->Text;
        for(i = 0; i < UserBox->Items->Count; i++)
        {
                if((UserBox->Items->Strings[i] == "New User")||(UserBox->Items->Strings[i] == "Nuevo Usuario"))
                {
                        UserBox->Items->Delete(i);
                        UserBox->Items->Insert(i,NewUser);
                }
        }
        AnsiString TName = MMName->Text;
        for(i = 0; i < MMName->Items->Count; i++)
        {
                if((MMName->Items->Strings[i] == "New Mastermind Session")||(MMName->Items->Strings[i] == "Nueva sesión de reunión de reflexión"))
                {
                        MMName->Items->Delete(i);
                        MMName->Items->Insert(i,NewMastermindSession);
                }
        }
        if((TName == "")||(TName == Select))
        {
                MMName->Text = Select;
        }
        if ((TUser == "Select User")||(TUser == "Seleccione A Usuario"))
        {
                UserBox->Text = SelectUser;
        }
        UserBox->ItemIndex = line;
        SmartMemo->Visible = false;
        SPSmartMemo->Visible = false;
        Label14->Left = 250;
        i = 1;
        while(i < LanguageForm->LanguageMemo->Lines->Count)
        {
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[PagesDlg]"){PagesDlg->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[File1]"){File1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Print1]"){Print1->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,36) == "[PrintSelectedGoalandCriticalTasks1]"){PrintSelectedGoalandCriticalTasks1->Caption = RightStr(temp,temp.Length()-39);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,26) == "[PrintGoalsCriticalTasks1]"){PrintGoalsCriticalTasks1->Caption = RightStr(temp,temp.Length()-29);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Exit1]"){Exit1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Edit2]"){Edit2->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,12) == "[DeleteUser]"){DeleteUser->Caption = RightStr(temp,temp.Length()-15);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,16) == "[DeleteProfiles]"){DeleteProfiles->Caption = RightStr(temp,temp.Length()-19);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,26) == "[SelectGoalAchievedTheme1]"){SelectGoalAchievedTheme1->Caption = RightStr(temp,temp.Length()-29);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Help1]"){Help1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,24) == "[AboutMegaGoalAchiever1]"){AboutMegaGoalAchiever1->Caption = RightStr(temp,temp.Length()-27);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[Language1]"){Language1->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[English1]"){English1->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[French1]"){French1->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[Spanish1]"){Spanish1->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet1]"){TabSheet1->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label1]"){Label1->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label2]"){Label2->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label7]"){Label7->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label8]"){Label8->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label9]"){Label9->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label10]"){Label10->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label11]"){Label11->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label12]"){Label12->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button1]"){Button1->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button2]"){Button2->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[GABtn]"){GABtn->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet2]"){TabSheet2->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label4]"){Label4->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label5]"){Label5->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet3]"){TabSheet3->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label6]"){Label6->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet4]"){TabSheet4->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[SrcLabel]"){SrcLabel->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label13]"){Label13->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label14]"){Label14->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label15]"){Label15->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label16]"){Label16->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label17]"){Label17->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button3]"){Button3->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button4]"){Button4->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button5]"){Button5->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[CheckBox2]"){CheckBox2->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet5]"){TabSheet5->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label18]"){Label18->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label19]"){Label19->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button6]"){Button6->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[C6Print]"){C6Print->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[CheckBox3]"){CheckBox3->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet6]"){TabSheet6->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label22]"){Label22->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label23]"){Label23->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet7]"){TabSheet7->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label20]"){Label20->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label3]"){Label3->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,14) == "[StartHereLbl]"){StartHereLbl->Caption = RightStr(temp,temp.Length()-17);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label21]"){Label21->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
       }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Spanish1Click(TObject *Sender)
{
        int i, line;
        i = 2;
        AnsiString temp;
        Language = "S";
        SelectUser = "Seleccione A Usuario";
        NewUser = "Nuevo Usuario";
        NewMastermindSession = "Nueva sesión de reunión de reflexión";
        Select = "Elija una sesión de reunión de reflexión";
        line = UserBox->ItemIndex;
        AnsiString TUser = UserBox->Text;
        for(i = 0; i < UserBox->Items->Count; i++)
        {
                if((UserBox->Items->Strings[i] == "Nouvel usager")||(UserBox->Items->Strings[i] == "New User"))
                {
                        UserBox->Items->Delete(i);
                        UserBox->Items->Insert(i,NewUser);
                }
        }
        AnsiString TName = MMName->Text;
        for(i = 0; i < MMName->Items->Count; i++)
        {
                if((MMName->Items->Strings[i] == "Nouvelle session de brainstorming")||(MMName->Items->Strings[i] == "New Mastermind Session"))
                {
                        MMName->Items->Delete(i);
                        MMName->Items->Insert(i,NewMastermindSession);
                }
        }
        if((TName == "")||(TName == Select))
        {
                MMName->Text = Select;
        }
        if ((TUser == "Choisir un usager")||(TUser == "SSelect User"))
        {
                UserBox->Text = SelectUser;
        }
        UserBox->ItemIndex = line;
        FRSmartMemo->Visible = false;
        SmartMemo->Visible = false;
        Label14->Left = 296;
        i = 2;
        while(i < LanguageForm->LanguageMemo->Lines->Count)
        {
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[PagesDlg]"){PagesDlg->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[File1]"){File1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Print1]"){Print1->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,36) == "[PrintSelectedGoalandCriticalTasks1]"){PrintSelectedGoalandCriticalTasks1->Caption = RightStr(temp,temp.Length()-39);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,26) == "[PrintGoalsCriticalTasks1]"){PrintGoalsCriticalTasks1->Caption = RightStr(temp,temp.Length()-29);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Exit1]"){Exit1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Edit2]"){Edit2->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,12) == "[DeleteUser]"){DeleteUser->Caption = RightStr(temp,temp.Length()-15);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,16) == "[DeleteProfiles]"){DeleteProfiles->Caption = RightStr(temp,temp.Length()-19);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,26) == "[SelectGoalAchievedTheme1]"){SelectGoalAchievedTheme1->Caption = RightStr(temp,temp.Length()-29);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Help1]"){Help1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,24) == "[AboutMegaGoalAchiever1]"){AboutMegaGoalAchiever1->Caption = RightStr(temp,temp.Length()-27);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[Language1]"){Language1->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[English1]"){English1->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[French1]"){French1->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[Spanish1]"){Spanish1->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet1]"){TabSheet1->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label1]"){Label1->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label2]"){Label2->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label7]"){Label7->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label8]"){Label8->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label9]"){Label9->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label10]"){Label10->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label11]"){Label11->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label12]"){Label12->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button1]"){Button1->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button2]"){Button2->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[GABtn]"){GABtn->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet2]"){TabSheet2->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label4]"){Label4->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label5]"){Label5->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet3]"){TabSheet3->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label6]"){Label6->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet4]"){TabSheet4->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[SrcLabel]"){SrcLabel->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label13]"){Label13->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label14]"){Label14->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label15]"){Label15->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label16]"){Label16->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label17]"){Label17->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button3]"){Button3->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button4]"){Button4->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button5]"){Button5->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[CheckBox2]"){CheckBox2->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet5]"){TabSheet5->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label18]"){Label18->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label19]"){Label19->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button6]"){Button6->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[C6Print]"){C6Print->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[CheckBox3]"){CheckBox3->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet6]"){TabSheet6->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label22]"){Label22->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label23]"){Label23->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet7]"){TabSheet7->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label20]"){Label20->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label3]"){Label3->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,14) == "[StartHereLbl]"){StartHereLbl->Caption = RightStr(temp,temp.Length()-17);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label21]"){Label21->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
       }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::English1Click(TObject *Sender)
{
        int i, line;
        AnsiString temp;
        Language = "E";
        SelectUser = "Select User";
        Select = "Select a Mastermind Session";
        NewUser = "New User";
        NewMastermindSession = "New Mastermind Session";
        line = UserBox->ItemIndex;
        AnsiString TUser = UserBox->Text;
        for(i = 0; i < UserBox->Items->Count; i++)
        {
                if((UserBox->Items->Strings[i] == "Nouvel usager")||(UserBox->Items->Strings[i] == "Nuevo Usuario"))
                {
                        UserBox->Items->Delete(i);
                        UserBox->Items->Insert(i,NewUser);
                }
        }
        AnsiString TName = MMName->Text;
        for(i = 0; i < MMName->Items->Count; i++)
        {
                if((MMName->Items->Strings[i] == "Nouvelle session de brainstorming")||(MMName->Items->Strings[i] == "Nueva sesión de reunión de reflexión"))
                {
                        MMName->Items->Delete(i);
                        MMName->Items->Insert(i,NewMastermindSession);
                }
        }
        if((TName == "")||(TName == Select))
        {
                MMName->Text = Select;
        }
        if ((TUser == "Choisir un usager")||(TUser == "Seleccione A Usuario"))
        {
                UserBox->Text = SelectUser;
        }
        i=0;
        UserBox->ItemIndex = line;
        FRSmartMemo->Visible = false;
        SPSmartMemo->Visible = false;
        Label14->Left = 296;
        while(i < LanguageForm->LanguageMemo->Lines->Count)
        {
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[PagesDlg]"){PagesDlg->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[File1]"){File1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Print1]"){Print1->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,36) == "[PrintSelectedGoalandCriticalTasks1]"){PrintSelectedGoalandCriticalTasks1->Caption = RightStr(temp,temp.Length()-39);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,26) == "[PrintGoalsCriticalTasks1]"){PrintGoalsCriticalTasks1->Caption = RightStr(temp,temp.Length()-29);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Exit1]"){Exit1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Edit2]"){Edit2->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,12) == "[DeleteUser]"){DeleteUser->Caption = RightStr(temp,temp.Length()-15);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,16) == "[DeleteProfiles]"){DeleteProfiles->Caption = RightStr(temp,temp.Length()-19);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,26) == "[SelectGoalAchievedTheme1]"){SelectGoalAchievedTheme1->Caption = RightStr(temp,temp.Length()-29);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[Help1]"){Help1->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,24) == "[AboutMegaGoalAchiever1]"){AboutMegaGoalAchiever1->Caption = RightStr(temp,temp.Length()-27);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[Language1]"){Language1->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[English1]"){English1->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[French1]"){French1->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[Spanish1]"){Spanish1->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet1]"){TabSheet1->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label1]"){Label1->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label2]"){Label2->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label7]"){Label7->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label8]"){Label8->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label9]"){Label9->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label10]"){Label10->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label11]"){Label11->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label12]"){Label12->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button1]"){Button1->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button2]"){Button2->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,7) == "[GABtn]"){GABtn->Caption = RightStr(temp,temp.Length()-10);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet2]"){TabSheet2->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label4]"){Label4->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label5]"){Label5->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet3]"){TabSheet3->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label6]"){Label6->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet4]"){TabSheet4->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,10) == "[SrcLabel]"){SrcLabel->Caption = RightStr(temp,temp.Length()-13);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label13]"){Label13->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label14]"){Label14->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label15]"){Label15->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label16]"){Label16->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label17]"){Label17->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button3]"){Button3->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button4]"){Button4->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button5]"){Button5->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[CheckBox2]"){CheckBox2->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet5]"){TabSheet5->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label18]"){Label18->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label19]"){Label19->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Button6]"){Button6->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[C6Print]"){C6Print->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[CheckBox3]"){CheckBox3->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet6]"){TabSheet6->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label22]"){Label22->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label23]"){Label23->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,11) == "[TabSheet7]"){TabSheet7->Caption = RightStr(temp,temp.Length()-14);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label20]"){Label20->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,8) == "[Label3]"){Label3->Caption = RightStr(temp,temp.Length()-11);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,14) == "[StartHereLbl]"){StartHereLbl->Caption = RightStr(temp,temp.Length()-17);}
                i = i+3;
                temp = LanguageForm->LanguageMemo->Lines->Strings[i];
                if(MidStr(temp,4,9) == "[Label21]"){Label21->Caption = RightStr(temp,temp.Length()-12);}
                i = i+3;
                 ;
       }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Print1Click(TObject *Sender)
{
        int i,j;
        AnsiString temp, goal;
        PrintBox->Lines->AddObject(URLName,Image2->Picture->Graphic);
        PrintBox->Lines->Add("");
        PrintBox->Lines->Add("List of Goals");
        PrintBox->Lines->Add("");
        if(ListBox1->Items->Count < 1)
        {
        for (i=0;i<ProfileMemo->Lines->Count;i++)
        {
                if(LeftStr(ProfileMemo->Lines->Strings[i],3)==Gol)
                {
                        PrintBox->Lines->Add(RightStr(ProfileMemo->Lines->Strings[i],ProfileMemo->Lines->Strings[i].Length()-3));
                }
        }
        }
        else
        {
                for (i = 0; i < ListBox1->Items->Count; i++)
                {
                        PrintBox->Lines->Add(ListBox1->Items->Strings[i]);
                }
        }
        PrintDialog1->Execute();
        PrintBox->Print(PagesDlg->Caption);
        PrintBox->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TPagesDlg::File1Click(TObject *Sender)
{
        if(ListBox1->Items->Count < 1)
        {
                Print1->Enabled = false;
                PrintSelectedGoalandCriticalTasks1->Enabled = false;
                PrintGoalsCriticalTasks1->Enabled = false;
        }
        else
        {
                Print1->Enabled = true;
                PrintGoalsCriticalTasks1->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Edit2Click(TObject *Sender)
{
        if((UserBox->Text == NewUser)||(UserBox->Text == "")||(UserBox->Text == SelectUser))
        {
                DeleteUser->Enabled = false;
        }
        else
        {
                DeleteUser->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::MMCheckListClickCheck(TObject *Sender)
{
        int done;
        if(Language == "E")
        {
                done = Application->MessageBoxA("You are about to remove this item from the Critical 6 list. This cannot be undone. You must delete and re-enter the idea. Do you still want to check the task completed box?","Are You Sure?",MB_YESNOCANCEL);
        }
        if(Language == "F")
        {
                done = Application->MessageBoxA("Vous allez retirer cet item de la liste de 6 critiques, cette opération ne peut pas être annulée.  Vous devrez effacer et rentrer à nouveau cette idée.  Voulez-vous toujours marquez cette tâche comme complète?","Confirmation requise",MB_YESNOCANCEL);
        }
        if(Language == "S")
        {
                done = Application->MessageBoxA("Usted está a punto de quitar este artículo de la lista crítica 6. Esto no puede ser deshecha. Usted debe suprimir y volver a entrar la idea. ¿Usted sin embargo desea comprobar la caja terminada tarea?","¿Es Usted Seguro?",MB_YESNOCANCEL);
        }
        int i,chk;
        if(done == 6)
        {
                AnsiString temp = Cr6 + "[" + Edit3->Text + "]" + "[" + MMName->Text + "]" + MMCheckList->Items->Strings[MMCheckList->ItemIndex];
                chk = MMCheckList->ItemIndex;
                MMCheckList->Checked[chk] = true;
                for(i = ProfileMemo->Lines->Count;i > -1; i--)
                {
                        if(ProfileMemo->Lines->Strings[i] == temp)
                        {
                                ProfileMemo->Lines->Delete(i);
                        }
                }
        }
        else
        {
                if(Language == "E")
                {
                        Application->MessageBoxA("Operation cancelled","Operation cancelled",MB_OK);
                }
                if(Language == "F")
                {
                        Application->MessageBoxA("Opération annulée","Opération annulée",MB_OK);
                }
                if(Language == "S")
                {
                        Application->MessageBoxA("La operación canceló","La operación canceló",MB_OK);
                }
                MMCheckList->Checked[chk] = false;
        }
}
//---------------------------------------------------------------------------



void __fastcall TPagesDlg::FormCreate(TObject *Sender)
{
        Startup = true;        
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::C6CheckListBoxClickCheck(TObject *Sender)
{
        Button6->Click();        
}
//---------------------------------------------------------------------------

void __fastcall TPagesDlg::Edit3Change(TObject *Sender)
{
        AMMName = "";        
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::ListBox2Click(TObject *Sender)
{
        int i;
        Cancel = false;
        i = ListBox2->ItemIndex;
        Button1->Enabled = true;
        EditBtn->Enabled = true;
        DeleteBtn->Enabled = true;
        UpBtn->Enabled  = true;
        DownBtn->Enabled = true;
        listitem = ListBox2->ItemIndex;
        Selected = ListBox1->Items->Strings[listitem];
        Edit3->Text = Selected;
        GABtn->Enabled = true;
        PrintSelectedGoalandCriticalTasks1->Enabled = true;
        ListBox1->ItemIndex = i;
        ListBox1->Selected[i] = true;
        CheckListBox1->ItemIndex = i;
        CheckListBox1->Selected[i] = true;
        CheckListBox2->ItemIndex = i;
        CheckListBox2->Selected[i] = true;
        CheckListBox3->ItemIndex = i;
        CheckListBox3->Selected[i] = true;
        CheckListBox4->ItemIndex = i;
        CheckListBox4->Selected[i] = true;
        CheckListBox5->ItemIndex = i;
        CheckListBox5->Selected[i] = true;
        CheckListBox6->ItemIndex = i;
        CheckListBox6->Selected[i] = true;
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::PageControl1Change(TObject *Sender)
{
        if(Cancel)
        {
                PageControl1->TabIndex = 0;
                TabSheet1->Show();
                Cancel = false;
        }
}
//---------------------------------------------------------------------------


void __fastcall TPagesDlg::DateTimePicker1Click(TObject *Sender)
{
        if(Edit3->Text == "")
        {
                Cancel = true;
                PageControl1->TabIndex = 0;
                if (Language == "E")
                {
                        Application->MessageBoxA("You must have an Active Goal. Return to the Goals tab and click on a goal","Missing Selection",MB_OK);
                }
                if (Language == "F")
                {
                        Application->MessageBoxA("Vous devez avoir un but sélectionné, retournez sur l'écran des buts et choisissez un but.","Sélection manquante",MB_OK);
                }
                if (Language == "S")
                {
                        Application->MessageBoxA("Usted debe tener una meta activa. Vuelva a la lengüeta de las metas y chasque encendido una meta","Selección Que falta",MB_OK);
                }
                PageControl1Change(Sender);
        }
        else
        {
                Cancel = false;
        }       
}
//---------------------------------------------------------------------------

