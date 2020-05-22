#!/usr/bin/env python3

import wx
import imghdr
import os
import random
from sys import platform
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
        self.panel.SetBackgroundColour("Gray")

        self.info = wx.Panel(self, size=(1024, 324))
        self.info.SetBackgroundColour("Gray")

        self.disp = wx.StaticBitmap(
            self.panel, size=(700, 1000))

        self.pathname = ""
        menubar = wx.MenuBar()
        filemenu = wx.Menu()
        open = wx.MenuItem(filemenu, wx.ID_OPEN, '&Open')
        filemenu.Append(open)
        menubar.Append(filemenu, '&File')
        self.SetMenuBar(menubar)
        self.Bind(wx.EVT_MENU, self.menuhandler)

        self.rotate = wx.Button(
            self.info, id=0, label="rotate", size=(50, 20), pos=(130, 930))
        self.rotate.Bind(wx.EVT_BUTTON, self.onrotate)

        self.fliph = wx.Button(
            self.info, id=1, label="Flip horizontally", size=(100, 20), pos=(20, 930))
        self.flipv = wx.Button(
            self.info, id=2, label="Flip vertically", size=(100, 20), pos=(190, 930))
        self.fliph.Bind(wx.EVT_BUTTON, self.onfliph)
        self.flipv.Bind(wx.EVT_BUTTON, self.onflipv)

        filters = [
            'BLUR',
            'CONTOUR',
            'DETAIL',
            'EDGE_ENHANCE',
            'EDGE_ENHANCE_MORE',
            'EMBOSS',
            'FIND_EDGES',
            'SHARPEN',
            'SMOOTH',
            'SMOOTH_MORE',
        ]

        self.effects = wx.ComboBox(self.info, choices=filters, pos=(65, 890))
        self.effects.Bind(wx.EVT_TEXT, self.oneffect)
        self.eff = wx.StaticText(self.info, label="Effects: ", pos=(18, 893))
        self.cleareffect = wx.Button(
            self.info, id=3, label="Reset all", pos=(240, 891), size=(50, 20))
        self.cleareffect.Bind(wx.EVT_BUTTON, self.onclear)

        self.save = wx.Button(
            self.info, id=4, label="Save File", pos=(215, 850))
        self.save.Bind(wx.EVT_BUTTON, self.onsave)
        self.open = wx.Button(
            self.info, id=5, label="Open File", pos=(19, 850))
        self.open.Bind(wx.EVT_BUTTON, self.onopen)

        self.filename = wx.StaticText(
            self.info, label="File name:", pos=(20, 10))
        self.filesize = wx.StaticText(self.info, label="Size:", pos=(20, 25))
        self.filetype = wx.StaticText(
            self.info, label="File type:", pos=(20, 40))
        self.filecolor = wx.StaticText(
            self.info, label="Color mode:", pos=(20, 55))

        sizes = ['Original', '1920x1080', '1600x900', '1440x900',
                 '1280x720', '1024x768', '800x600', '640x480']
        self.rsize = wx.ComboBox(self.info, choices=sizes, pos=(65, 790))
        self.rsizetxt = wx.StaticText(
            self.info, label="Resize: ", pos=(18, 793))
        self.rsize.Bind(wx.EVT_TEXT, self.onresize)
        """ self.changesize = wx.Button(
            self.info, id=6, label="Resize", pos=(212, 790))
        self.changesize.Bind(wx.EVT_BUTTON, self.onresize) """

        sizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer.Add(self.panel, flag=wx.EXPAND | wx.ALL)
        sizer.Add(self.info, flag=wx.EXPAND | wx.ALL)

        self.SetSizer(sizer)
        self.Centre()

    def menuhandler(self, event):
        id = event.GetId()
        if id == wx.ID_OPEN:
            with wx.FileDialog(self.panel, "Open Image file", wildcard="Image files (*.jpg,*.jpeg,*.png,*.bmp,*.tiff,*.rast,*.xbm,*.rgb,*.pbm,*.pgm,*.ppm)|*.jpg;*.jpeg;*.png;*.bmp;*.tiff;*.rast;*.xbm;*.rgb;*.pbm;*.pgm;*.ppm",
                               style=wx.FD_OPEN | wx.FD_FILE_MUST_EXIST) as file:

                if file.ShowModal() == wx.ID_CANCEL:
                    return

                self.pathname = file.GetPath()
                try:
                    self.displayimage(self.pathname)

                except IOError:
                    wx.LogError("Cannot open file '%s'." % newfile)

    def displayimage(self, path):
        self.modified = True
        self.pilimage = Image.open(path)
        self.og = Image.open(path)
        self.prefog = Image.open(path)
        width, height = self.pilimage.size
        self.pilimage.thumbnail((700, 800))
        self.preEffect = self.pilimage
        self.PilImageToWxImage(self.pilimage)
        self.filesize.SetLabel("Size: " + str(width) +
                               " x" + str(height) + "px")
        self.filename.SetLabel("Name: " + os.path.split(path)[-1])
        self.filetype.SetLabel("File type: " + path.split('.')[-1])
        mode = ""
        for letter in self.pilimage.getbands():
            mode += letter
        self.filecolor.SetLabel("Color mode: " + mode)

    def PilImageToWxImage(self, myPilImage):

        myWxImage = wx.Image(myPilImage.size[0], myPilImage.size[1])

        dataRGB = myPilImage.convert(
            'RGB').tobytes()    # RGBA --> RGB
        myWxImage.SetData(dataRGB)
        if myWxImage.HasAlpha():
            dataRGBA = myPilImage.tobytes()[3::4]
            myWxImage.SetAlphaData(dataRGBA)
        self.disp.SetBitmap(wx.Bitmap(myWxImage))

    def onrotate(self, event):
        self.pilimage = self.pilimage.rotate(angle=90, expand=True)
        self.og = self.og.rotate(angle=90, expand=True)
        self.PilImageToWxImage(self.pilimage)

    def onfliph(self, event):
        self.pilimage = self.pilimage.transpose(Image.FLIP_LEFT_RIGHT)
        self.og = self.og.transpose(Image.FLIP_LEFT_RIGHT)
        self.PilImageToWxImage(self.pilimage)

    def onflipv(self, event):
        self.pilimage = self.pilimage.transpose(Image.FLIP_TOP_BOTTOM)
        self.og = self.og.transpose(Image.FLIP_TOP_BOTTOM)
        self.PilImageToWxImage(self.pilimage)

    def oneffect(self, event):
        effect = event.GetString()
        self.pilimage = self.pilimage.filter(getattr(ImageFilter, effect))
        self.og = self.og.filter(getattr(ImageFilter, effect))
        self.PilImageToWxImage(self.pilimage)

    def onclear(self, event):
        self.PilImageToWxImage(self.preEffect)
        self.modified = False

    def onsave(self, event):
        ran = random.randrange(0, 100)
        ran = str(ran)
        if self.modified is True:
            if platform == "linux" or platform == "linux2":
                self.og.save(os.path.split(self.pathname)[
                             0] + "/" + ran + " - " + os.path.split(self.pathname)[-1])
            elif platform == "darwin":
                self.og.save(os.path.split(self.pathname)[
                             0] + "/" + ran + " - " + os.path.split(self.pathname)[-1])
            elif platform == "win32":
                self.og.save(os.path.split(self.pathname)[
                             0] + "\\" + ran + " - " + os.path.split(self.pathname)[-1])
        elif self.modified is False:
            if platform == "linux" or platform == "linux2":
                self.prefog.save(os.path.split(self.pathname)[
                                 0] + "/" + ran + " - " + os.path.split(self.pathname)[-1])
            elif platform == "darwin":
                self.prefog.save(os.path.split(self.pathname)[
                                 0] + "/" + ran + " - " + os.path.split(self.pathname)[-1])
            elif platform == "win32":
                self.prefog.save(os.path.split(self.pathname)[
                                 0] + "\\" + ran + " - " + os.path.split(self.pathname)[-1])

    def onresize(self, event):
        resolution = event.GetString()
        res = resolution.split('x')
        if resolution != "Original":
            w = res[0]
            w = int(w)
            h = res[1]
            h = int(h)
            self.og.thumbnail((w, h))
        elif resolution == "Original":
            w, h = self.prefog.size
            w = int(w)
            h = int(h)
            self.og.thumbnail((w, h))

    def onopen(self, event):
        with wx.FileDialog(self.panel, "Open Image file", wildcard="Image files (*.jpg,*.jpeg,*.png,*.bmp,*.tiff,*.rast,*.xbm,*.rgb,*.pbm,*.pgm,*.ppm)|*.jpg;*.jpeg;*.png;*.bmp;*.tiff;*.rast;*.xbm;*.rgb;*.pbm;*.pgm;*.ppm",
                           style=wx.FD_OPEN | wx.FD_FILE_MUST_EXIST) as file:

            if file.ShowModal() == wx.ID_CANCEL:
                return

            self.pathname = file.GetPath()
            try:
                self.displayimage(self.pathname)

            except IOError:
                wx.LogError("Cannot open file '%s'." % newfile)


app = wx.App()
frame = Scope(None, -1)
frame.Show()
app.MainLoop()
