object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1047#1084#1110#1081#1082#1072
  ClientHeight = 313
  ClientWidth = 582
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 380
    Top = 24
    Width = 86
    Height = 18
    Caption = #1050'-'#1089#1090#1100' '#1073#1072#1083#1110#1074
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Verdana'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 492
    Top = 24
    Width = 29
    Height = 18
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Verdana'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 424
    Top = 128
    Width = 5
    Height = 18
    Color = clBlack
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Verdana'
    Font.Style = [fsItalic]
    ParentColor = False
    ParentFont = False
  end
  object Label4: TLabel
    Left = 416
    Top = 88
    Width = 57
    Height = 18
    Caption = #1063#1072#1089' '#1075#1088#1080
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Verdana'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 240
    OnTimer = Timer1Timer
    Left = 544
    Top = 264
  end
  object MainMenu1: TMainMenu
    Left = 544
    Top = 104
    object N1: TMenuItem
      Caption = #1043#1088#1072
      object N2: TMenuItem
        Caption = '-'
      end
      object N3: TMenuItem
        Caption = #1055#1072#1091#1079#1072
        ShortCut = 112
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object N5: TMenuItem
        Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1110#1075#1086#1088
      end
      object N6: TMenuItem
        Caption = '-'
      end
    end
    object N7: TMenuItem
      Caption = #1055#1088#1086#1075#1088#1072#1084#1072
      object N8: TMenuItem
        Caption = '-'
      end
      object N9: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1082#1072
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object N11: TMenuItem
        Caption = #1055#1088#1086' '#1088#1086#1079#1088#1086#1073#1085#1080#1082#1072
      end
      object N12: TMenuItem
        Caption = '-'
      end
    end
  end
end
