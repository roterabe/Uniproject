#!/usr/bin/env python3

import sys
import os
import requests

stem = ""
word = ""

try:
    if len(sys.argv) > 2:
        rfile = sys.argv[1]
        wfile = sys.argv[2]
    else:
        raise
except:
    print("\n" "You need to specify a file to read and file to write to.")
    print("Example usage: \"python F90739_L10_T1.py -filetoread.txt -word_to_search\"." "\n")

with open(stem, "r") as file:
    lines = file.readlines()

