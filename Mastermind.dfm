object DualListDlg: TDualListDlg
  Left = 222
  Top = 179
  BorderStyle = bsDialog
  Caption = 'Mastermind'
  ClientHeight = 433
  ClientWidth = 541
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 48
    Top = 16
    Width = 97
    Height = 13
    Caption = 'Current working goal'
  end
  object OKBtn: TButton
    Left = 173
    Top = 372
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 253
    Top = 372
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object HelpBtn: TButton
    Left = 333
    Top = 372
    Width = 75
    Height = 25
    Caption = 'Help'
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 168
    Top = 16
    Width = 257
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
  end
end
