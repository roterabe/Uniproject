#!/usr/bin/env python3

import sys

text = ""

for arg in range(1, (len(sys.argv))):
    text += sys.argv[arg]

#Make text lowercase if needed
#text = text.lower()

cnt = {}
for idx in text:
    if idx in cnt:
        cnt[idx] += 1
    else:
        cnt[idx] = 1
        
items = list(cnt.items())
print (items)