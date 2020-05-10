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
#    print(list(item))
    temp = {item.find('{http://purl.org/rss/1.0/}title').text : item.find('{http://purl.org/rss/1.0/}description').text}
    text.update(temp)

print(text.values())
#for line in lines:
#    print(line)


