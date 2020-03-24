#!/usr/bin/env python3

import sys

for arg in range(1, (len(sys.argv)-1)):
    list1 = list(sys.argv[arg])
    list1.sort()
    list2 = list(sys.argv[arg+1])
    list2.sort()

if list1 == list2:
    print ("True")
else:
    print ("False")