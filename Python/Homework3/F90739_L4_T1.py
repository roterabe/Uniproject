#!/usr/bin/env python3

import sys

search = sys.argv[len(sys.argv)-1]
res = []

d = {1: 'a', 2: 'b', 3: 'c', 4: 'a', 5: 'd', 6: 'e', 7: 'a', 8: 'b'}
index = list(d.keys())
value = list(d.values())

for idx in range(len(index)):
    if (search == value[idx]):
        res.append(index[idx])
print(res)
