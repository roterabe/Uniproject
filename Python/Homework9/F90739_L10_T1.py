#!/usr/bin/env python3

import sys
import os

rfile = ""
wfile = ""
try:
    if len(sys.argv) > 2:
        rfile = sys.argv[1]
        wfile = sys.argv[2]
    else:
        raise
except:
    print("\n" "You need to specify a file to read and file to write to.")
    print("Example usage: \"python F90739_L10_T1.py -filetoread.txt -filetowrite.txt\"." "\n")

with open(rfile, 'r') as file:
    lines = file.readlines()

with open(wfile, 'w') as file:
    lines.sort()
    file.writelines(lines)



