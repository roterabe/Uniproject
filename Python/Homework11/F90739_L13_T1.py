#!/usr/bin/env python3

import wx
import wx.html
import urllib.request
import xml.etree.ElementTree as xml

url = 'http://rss.slashdot.org/Slashdot/slashdot'
data1 = urllib.request.urlopen(url)
tree = xml.parse(data1)
root = tree.getroot()
items = []
text = {}
for item in root.findall('{http://purl.org/rss/1.0/}item'):
    items.append(item)
for item in items:
    temp = {item.find('{http://purl.org/rss/1.0/}title').text: item.find(
        '{http://purl.org/rss/1.0/}description').text}
    text.update(temp)


class News(wx.Frame):
    def __init__(self, parent, id):

        no_resize = wx.DEFAULT_FRAME_STYLE & ~ (wx.RESIZE_BORDER |
                                                wx.MAXIMIZE_BOX)

        super().__init__(
            None, title="News Feed", style=no_resize, size=(976, 500))
        self.SetBackgroundColour("White")
        self.panel = wx.Panel(self)
        self.panel.SetBackgroundColour("White")
        self.info = wx.Panel(self)
        self.info.SetBackgroundColour("White")

        sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.temp = []
        self.temp1 = []
        self.head = wx.StaticText(self.panel, label="News Feed", pos=(8, 10))
        font = wx.Font(18, wx.DECORATIVE, wx.NORMAL, wx.BOLD)
        self.head.SetFont(font)
        self.ver = wx.StaticText(self.info, label="ver 0.1a", pos=(420, 430))
        font1 = wx.Font(10, wx.DECORATIVE, wx.NORMAL, wx.NORMAL)
        self.ver.SetFont(font1)

        self.html = wx.html.HtmlWindow(self.info, pos=(5, 50), size=(470, 300),
                                       style=wx.html.HW_DEFAULT_STYLE)

        sizer.Add(self.panel, flag=wx.EXPAND | wx.ALL)
        sizer.Add(self.info, flag=wx.EXPAND | wx.ALL)

        for title in text.keys():
            self.temp.append(title)
        for description in text.values():
            description = description.split('<p>', 1)[0]
            self.temp1.append(description)

        self.titles = wx.ListBox(self.panel, pos=(
            8, 50), size=(470, 300), choices = self.temp)

        self.titles.Bind(wx.EVT_LISTBOX, self.onLeftClick)

        self.SetSizer(sizer)
        self.Centre()

    def onLeftClick(self, event):
        titl = event.GetString()
        desc = ""
        for i in range(len(self.temp)):
            if titl == self.temp[i]:
                desc = self.temp1[i]
        html = "<html>\n <head></head>\n <body> <p>" + desc + "</p></body>\n </html>"
        self.html.SetPage(html)


app = wx.App()
frame = News(None, -1)
frame.Show()
app.MainLoop()
