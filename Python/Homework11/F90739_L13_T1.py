#!/usr/bin/env python3

import wx
import urllib.request
import requests
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

        super().__init__(
            None, title="News Feed",
            size=(800, 600))
        self.SetBackgroundColour("White")
        self.panel = wx.Panel(self, size=(500, 500))
        self.panel.SetBackgroundColour("Gray")

        sizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer.Add(self.panel, flag=wx.ALIGN_LEFT |
                  wx.EXPAND | wx.BOTTOM, border=10)

        self.temp = []
        self.index = 0

        self.titles = wx.ListCtrl(self.panel, pos=(
            20, 100), size=(500, 300), style=wx.LC_REPORT)
        self.titles.InsertColumn(0, 'Title', width=480)

        for title in text.keys():
            self.temp.append(title)

        for title in self.temp:
            self.titles.InsertStringItem(self.index, title)
            self.index += 1

        self.titles.Bind(wx.EVT_LIST_ITEM_SELECTED, self.onLeftClick)

    def onLeftClick(self, event):
        pos = event.GetText()
        print(str(pos))


app = wx.App()
frame = News(None, -1)
frame.Show()
app.MainLoop()
