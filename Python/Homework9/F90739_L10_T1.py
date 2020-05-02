#!/usr/bin/env python3

from sys import argv

rfile = ""
wfile = ""

try:
    if len(argv) > 2:
        rfile = argv[1]
        wfile = argv[2]
    else:
        raise
except:
    print("\nWARNING! \nYou need to specify a file to read and file to write to.")
    print("Example usage: \"python F90739_L10_T1.py -filetoread.txt -filetowrite.txt\"." "\n")

with open(rfile, 'r') as file:
    lines = file.readlines()

with open(wfile, 'w') as file:
    lines.sort()
    file.writelines(lines)



