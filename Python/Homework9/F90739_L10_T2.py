#!/usr/bin/env python3

from sys import argv

stem = ""
word = ""
d = {}

try:
    if len(argv) > 2:
        stem = argv[1]
        word = argv[2]
    else:
        raise
except:
    print("\nWARNING! \nYou need to specify a file to read and file to write to.")
    print("Example usage: \"python F90739_L10_T1.py -filetoread.txt -word_to_search.\n")

with open(stem, "r") as file:
    lines = file.read().splitlines()

for line in lines:
    x = line.split(":")
    d[x[0]] = x[1]

try:
    print(d[word])
except:
    print("\n The word you want to find is not available in the database. Try another word instead. \n")
