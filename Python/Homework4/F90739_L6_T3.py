#!/usr/bin/env python3

import sys

def binS (data, begin, end, search): 
  
    # Check base case 
    if end >= begin: 
  
        mid = begin + (end - begin) // 2
  
        if data[mid] == search: 
            return mid 
          
        elif data[mid] < search: 
            return binS(data, mid + 1, end, search) 
  
        else: 
            return binS(data, begin, mid-1, search) 
    else: 
        return -1

data = [30, 40, 50, 52, 56, 62, 70, 91, 100, 131, 132, 166, 170, 195, 202, 205, 212, 248, 249, 256, 263, 272, 288, 289, 290, 296, 332, 345, 352, 364, 380, 390, 407, 412, 429, 430, 438, 444, 486, 493, 497, 499, 510, 513, 514, 519, 521, 521, 535, 546, 552, 554, 556, 570, 584, 638, 640, 655, 655, 657, 692, 692, 711, 713, 731, 739, 740, 842, 858, 885, 887, 888, 893, 898, 900, 903, 908, 909, 959, 988]

search = int(sys.argv[1])

if search in data:
    print (binS(data, 0, len(data)-1, search))
else:
    print("not found")
