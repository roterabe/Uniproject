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
            None, title="Scope", style=no_resize, size=(976, 500))
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
            with wx.FileDialog(self.panel, "Open XYZ file", wildcard="Image files (*.jpg,*.jpeg,*.png)|*.jpg;*.jpeg;*.png",
                               style=wx.FD_OPEN | wx.FD_FILE_MUST_EXIST) as file:

                if file.ShowModal() == wx.ID_CANCEL:
                    return     # the user changed their mind

        # Proceed loading the file chosen by the user
                pathname = file.GetPath()
                try:
                    with open(pathname, 'r') as path:
                        self.displayimage(path)
                except IOError:
                    wx.LogError("Cannot open file '%s'." % newfile)

    def displayimage(self, path):
        self.img = path
        self.pilimage = Image.open(self.img)
        self.image = wx.EmptyImage(
            self.pilimage.size[0], self.pilimage.size[1])
        self.image.SetData(self.pilimage.convert("RGB").toString())
        self.image.SetAlphaData(self.pilImage.convert("RGBA").tostring()[3::4])
        self.bitmap = wx.BitmapFromImage(self.image)
        self.disp = wx.StaticBitmap(self.panel, 0, pos=(10,15))


app = wx.App()
frame = Scope(None, -1)
frame.Show()
app.MainLoop()
