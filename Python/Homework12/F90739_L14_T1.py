#!/usr/bin/env python3

import wx
import imghdr
from PIL import Image
from PIL import ImageFilter


class Scope(wx.Frame):
    def __init__(self, parent, id):

        no_resize = wx.DEFAULT_FRAME_STYLE & ~ (wx.RESIZE_BORDER |
                                                wx.MAXIMIZE_BOX)

        super().__init__(
            None, title="Scope", style=no_resize, size=(1024, 1024), pos=(0, 0))
        self.SetBackgroundColour("White")
        self.panel = wx.Panel(self)
        self.panel.SetBackgroundColour("White")

        self.info = wx.Panel(self, size=(1024, 324))
        self.info.SetBackgroundColour("Gray")

        self.disp = wx.StaticBitmap(
            self.panel, size=(700, 1000))

        menubar = wx.MenuBar()
        filemenu = wx.Menu()
        open = wx.MenuItem(filemenu, wx.ID_OPEN, '&Open')
        filemenu.Append(open)
        menubar.Append(filemenu, '&File')
        self.SetMenuBar(menubar)
        self.Bind(wx.EVT_MENU, self.menuhandler)

        self.rotate = wx.Button(
            self.info, id=0, label="rotate", size=(50, 20), pos=(130, 930))
        self.rotate.Bind(wx.EVT_BUTTON, self.onclick)

        self.filename = wx.StaticText(
            self.info, label="File name:", pos=(20, 10))
        self.filesize = wx.StaticText(self.info, label="Size:", pos=(20, 25))
        self.filetype = wx.StaticText(
            self.info, label="File type:", pos=(20, 40))
        self.filecolor = wx.StaticText(
            self.info, label="Color mode:", pos=(20, 55))

        sizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer.Add(self.panel, flag=wx.EXPAND | wx.ALL)
        sizer.Add(self.info, flag=wx.EXPAND | wx.ALL)

        self.SetSizer(sizer)
        self.Centre()

    def menuhandler(self, event):
        id = event.GetId()
        if id == wx.ID_OPEN:
            with wx.FileDialog(self.panel, "Open Image file", wildcard="Image files (*.jpg,*.jpeg,*.png)|*.jpg;*.jpeg;*.png",
                               style=wx.FD_OPEN | wx.FD_FILE_MUST_EXIST) as file:

                if file.ShowModal() == wx.ID_CANCEL:
                    return

                pathname = file.GetPath()
                try:
                    self.displayimage(pathname)

                except IOError:
                    wx.LogError("Cannot open file '%s'." % newfile)

    def displayimage(self, path):
        self.pilimage = Image.open(path)
        width, height = self.pilimage.size
        self.pilimage.thumbnail((700, 800))
        self.PilImageToWxImage(self.pilimage)
        self.filesize.SetLabel("Size: " + str(width) + " x" + str(height) + "px")

    def PilImageToWxImage(self, myPilImage):

        myWxImage = wx.Image(myPilImage.size[0], myPilImage.size[1])

        dataRGB = myPilImage.convert(
            'RGB').tobytes()    # RGBA --> RGB
        myWxImage.SetData(dataRGB)
        if myWxImage.HasAlpha():
            dataRGBA = myPilImage.tobytes()[3::4]
            myWxImage.SetAlphaData(dataRGBA)
        self.disp.SetBitmap(wx.Bitmap(myWxImage))

    def onclick(self, event):
        self.pilimage = self.pilimage.rotate(angle=90, expand=True)
        self.PilImageToWxImage(self.pilimage)


app = wx.App()
frame = Scope(None, -1)
frame.Show()
app.MainLoop()
