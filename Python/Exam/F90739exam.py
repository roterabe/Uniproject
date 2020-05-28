#!/usr/bin/env python3

import wx
import wx.html
import urllib.request
import urllib.parse
from PIL import Image


class Wiki(wx.Frame):
    def __init__(self, parent, id):

        no_resize = wx.DEFAULT_FRAME_STYLE & ~ (wx.RESIZE_BORDER |
                                                wx.MAXIMIZE_BOX)

        super().__init__(
            None, title="News Feed", style=no_resize, size=(900, 900))
        self.SetBackgroundColour("White")
        self.panel = wx.Panel(self, size=(200, 300))
        self.panel.SetBackgroundColour("Gray")
        self.info = wx.Panel(self, size=(400, 300))
        self.info.SetBackgroundColour("Gray")
        self.imageplace = wx.Panel(self, size=(300, 300))
        self.imageplace.SetBackgroundColour("Gray")
        self.titlequery = 'https://en.wikipedia.org/w/api.php?format=json&action=query&prop=extracts&exintro=&explaintext=&titles='
        self.imagequery = 'https://en.wikipedia.org/w/api.php?action=query&format=json&prop=images&titles='
        self.imageshowurl = 'https://en.wikipedia.org/w/api.php?action=query&list=allimages&format=json&aifrom='
        self.imageurl = 'https://upload.wikimedia.org/wikipedia/en/f/ff/'
        self.disp = wx.StaticBitmap(
            self.imageplace, size=(300, 900))

        sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.html = wx.html.HtmlWindow(self.info, pos=(0, 0), size=(400, 900),
                                       style=wx.html.HW_DEFAULT_STYLE)

        self.searchbox = wx.TextCtrl(self.panel, pos=(10, 60), size=(180, 30))
        self.search = wx.Button(self.panel, pos=(10, 100), label='Search')
        self.close = wx.Button(self.panel, pos=(100, 100), label='Close')

        self.search.Bind(wx.EVT_BUTTON, self.onSearch)
        self.close.Bind(wx.EVT_BUTTON, self.onClose)

        sizer.Add(self.panel, flag=wx.EXPAND | wx.ALL)
        sizer.Add(self.info, flag=wx.EXPAND | wx.ALL)
        sizer.Add(self.imageplace, flag=wx.EXPAND | wx.ALL)

        self.SetSizer(sizer)
        self.Centre()

    def onSearch(self, event):
        query = self.searchbox.GetValue()
        url = self.titlequery
        url += urllib.parse.quote(query)
        self.getDesc(url)
        imgurl = self.imagequery
        imgurl += urllib.parse.quote(query)
        self.getImage(imgurl)

    def onClose(self, event):
        self.Close()

    def getDesc(self, url):
        data = urllib.request.urlopen(url)
        text = data.read()
        pre, desc = text.decode().split('"extract":', 1)
        desc = desc.replace('\\n', '')
        desc = desc.replace('}', '')
        desc = desc[1:-1]
        html = "<html>\n <head></head>\n <body> <p>" + desc + "</p></body>\n </html>"
        self.html.SetPage(html)

    def getImage(self, url):
        data = urllib.request.urlopen(url)
        text = data.read()
        # print(url)
        pre, imgdict = text.decode().split('"images":')
        imgdict = imgdict.replace('}}}}', '')
        imgdict = imgdict[1:-1]
        imgdict = imgdict.replace('{', '')
        imgdict = imgdict.replace('}', '')
        imgdict = imgdict.split(',')
        image = ""
        for obj in imgdict:
            if 'poster' in obj:
                image = obj
                break
            elif 'poster' not in obj and '.jpg' in obj:
                image = obj
        pre, mid = image.split('"title":"File:')
        image = mid[0:-1]
        self.imageshowurl += urllib.parse.quote(image)
        self.loadImg(self.imageshowurl, image)

    def loadImg(self, imageshow, image):
        url = imageshow
        imgdata = urllib.request.urlopen(url)
        text = imgdata.read()
        pre, urldict = text.decode().split('"allimages":')
        text = urldict.replace('}}}}', '')
        text = text[1:-1]
        text = text.replace('{', '')
        text = text.replace('}', '')
        # text = text.split(',')
        text = text.replace('[', '')
        text = text.replace(']', '')
        text = text.replace('\'', '')
        text = text.split(',')
        image = image.replace(' ', '_')

        for url in text:
            if '"url":' in url and image in url:
                self.imageurl = url
                break
        self.imageurl = self.imageurl.split('"url":')
        self.imageurl = self.imageurl[1]
        self.imageurl = self.imageurl[1:-1]
        print(self.imageurl)
        file = urllib.request.urlopen(self.imageurl)
        self.displayimage(file)

    def displayimage(self, path):
        self.pilimage = Image.open(path)
        self.width, self.height = self.pilimage.size
        self.pilimage.thumbnail((700, 800))
        self.PilImageToWxImage(self.pilimage)

    def PilImageToWxImage(self, img):

        myWxImage = wx.Image(img.size[0], img.size[1])
        dataRGB = img.convert(
            'RGB').tobytes()
        myWxImage.SetData(dataRGB)
        if myWxImage.HasAlpha():
            dataRGBA = img.tobytes()[3::4]
            myWxImage.SetAlphaData(dataRGBA)
        self.disp.SetBitmap(wx.Bitmap(myWxImage))


app = wx.App()
frame = Wiki(None, -1)
frame.Show()
app.MainLoop()
