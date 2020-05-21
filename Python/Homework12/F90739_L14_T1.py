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
            None, title="Scope", style=no_resize, size=(1024, 768))
        self.SetBackgroundColour("White")
        self.panel = wx.Panel(self)
        self.panel.SetBackgroundColour("White")
        menubar = wx.MenuBar()
        filemenu = wx.Menu()
        open = wx.MenuItem(filemenu, wx.ID_OPEN, '&Open')
        filemenu.Append(open)
        menubar.Append(filemenu, '&File')
        self.SetMenuBar(menubar)
        self.Bind(wx.EVT_MENU, self.menuhandler)

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
        self.pilimage.thumbnail((800, 800))
        #width, height = self.pilimage.size

        self.image = self.PilImageToWxImage(self.pilimage)

        #self.bitmap = wx.Bitmap(self.image)
        self.disp = wx.StaticBitmap(
            self.panel)
        #self.disp.SetBitmap(wx.Bitmap(600,600))
        self.disp.SetBitmap(wx.BitmapFromImage(self.image))

    def PilImageToWxImage(self, myPilImage):

        myWxImage = wx.Image(myPilImage.size[0], myPilImage.size[1])

        dataRGB = myPilImage.convert(
            'RGB').tobytes()    # RGBA --> RGB
        myWxImage.SetData(dataRGB)
        if myWxImage.HasAlpha():
            dataRGBA = myPilImage.tobytes()[3::4]
            myWxImage.SetAlphaData(dataRGBA)

        return myWxImage


app = wx.App()
frame = Scope(None, -1)
frame.Show()
app.MainLoop()
