#!/usr/bin/env python3

import wx
import random


class Hangman(wx.Frame):
    def __init__(self, parent, id):

        super().__init__(
            None, title="Hangman",
            size=(800, 600))
        self.SetBackgroundColour("White")
        self.panel = wx.Panel(self, size=(500, 500))
        self.panel.SetBackgroundColour("White")
        self.pickLabel = wx.StaticText(self.panel, -1, "Random word picker:", (600, 400))
        self.pick = wx.Button(self.panel, id=27, label="Pick", pos=(720, 395), size=(60, -1))
        self.word = wx.StaticText(self.panel, -1, "", pos=(600, 440))
        self.font = wx.Font(11, wx.DEFAULT, wx.NORMAL, wx.NORMAL)
        self.word.SetFont(self.font)
        self.rem = ""
        self.hiddenword = ""
        self.cnt = 6
        # self.jpg = wx.Image("6.bmp", wx.BITMAP_TYPE_ANY)
        # self.image = wx.StaticBitmap(self, -1, self.jpg, (10 + self.jpg.GetWidth(), 5), (self.jpg.GetWidth(), self.jpg.GetHeight()))
        # self.imagеCtrl = wx.ImageFromBitmap(self.jpg)
        self.pick.Bind(wx.EVT_BUTTON, self.randClick)

        sizer = wx.BoxSizer(wx.VERTICAL)
        # self.display = wx.TextCtrl(self, -1, '',  style=wx.TE_RIGHT)
        # sizer.Add(self.display, 0, wx.EXPAND | wx.TOP | wx.BOTTOM, 4)
        gs = wx.GridSizer(4, 7, 1, 1)
        gs.AddMany([(wx.Button(self, 1, 'a'), 0, wx.EXPAND),
                    (wx.Button(self, 2, 'b'), 0, wx.EXPAND),
                    (wx.Button(self, 3, 'c'), 0, wx.EXPAND),
                    (wx.Button(self, 4, 'd'), 0, wx.EXPAND),
                    (wx.Button(self, 5, 'e'), 0, wx.EXPAND),
                    (wx.Button(self, 6, 'f'), 0, wx.EXPAND),
                    (wx.Button(self, 7, 'g'), 0, wx.EXPAND),
                    (wx.Button(self, 8, 'h'), 0, wx.EXPAND),
                    (wx.Button(self, 9, 'i'), 0, wx.EXPAND),
                    (wx.Button(self, 10, 'j'), 0, wx.EXPAND),
                    (wx.Button(self, 11, 'k'), 0, wx.EXPAND),
                    (wx.Button(self, 12, 'l'), 0, wx.EXPAND),
                    (wx.Button(self, 13, 'm'), 0, wx.EXPAND),
                    (wx.Button(self, 14, 'n'), 0, wx.EXPAND),
                    (wx.Button(self, 15, 'o'), 0, wx.EXPAND),
                    (wx.Button(self, 16, 'p'), 0, wx.EXPAND),
                    (wx.Button(self, 17, 'q'), 0, wx.EXPAND),
                    (wx.Button(self, 18, 'r'), 0, wx.EXPAND),
                    (wx.Button(self, 19, 's'), 0, wx.EXPAND),
                    (wx.Button(self, 20, 't'), 0, wx.EXPAND),
                    (wx.Button(self, 21, 'u'), 0, wx.EXPAND),
                    (wx.Button(self, 22, 'v'), 0, wx.EXPAND),
                    (wx.Button(self, 23, 'w'), 0, wx.EXPAND),
                    (wx.Button(self, 24, 'x'), 0, wx.EXPAND),
                    (wx.Button(self, 25, 'y'), 0, wx.EXPAND),
                    (wx.Button(self, 26, 'z'), 0, wx.EXPAND)])

        self.Bind(wx.EVT_BUTTON, self.onClick, id=1)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=2)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=3)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=4)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=5)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=6)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=7)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=8)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=9)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=10)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=11)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=12)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=13)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=14)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=15)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=16)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=17)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=18)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=19)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=20)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=21)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=22)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=23)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=24)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=25)
        self.Bind(wx.EVT_BUTTON, self.onClick, id=26)

        sizer.Add(self.panel, flag=wx.ALIGN_TOP | wx.EXPAND | wx.BOTTOM, border=10)
        sizer.Add(gs, flag=wx.ALIGN_BOTTOM | wx.EXPAND | wx.LEFT | wx.RIGHT |
                  wx.ALIGN_BOTTOM | wx.ALIGN_CENTER, border=100)

        sizer.SetSizeHints(self)
        self.SetSizer(sizer)
        self.Centre()

    def randClick(self, event):
        dictionary = ["meaning", "life", "towel", "dolphin", "mice"]
        self.rem = random.choice(dictionary)
        chars = list(self.rem)
        for i in range(1, len(chars)-1):
            chars[i] = '_'
        self.hiddenword = ''.join(chars)
        self.word.SetLabel(str(chars))
        self.cnt = 6

    def onClick(self, event):
        if self.cnt > 0:
            letters = "abcdefghijklmnopqrstuvwxyz"
            letters = list(letters)
            btn = event.GetId()
            rem = list(self.rem)
            hid = list(self.hiddenword)
            for j in range(1, len(rem)-1):
                if rem[j] == letters[btn-1]:
                    hid[j] = letters[btn-1]
            if letters[btn-1] not in rem:
                self.cnt -= 1

            print(self.cnt)
            # print(hid)
            self.hiddenword = ''.join(hid)
            # print(self.hiddenword)
            self.word.SetLabel(str(hid))
            if '_' not in hid:
                self.word.SetLabel("***" + str(hid) + "***")
        elif self.cnt <= 0:
            self.word.SetLabel("Game Over")


app = wx.App()
frame = Hangman(None, -1)
frame.Show()
app.MainLoop()
