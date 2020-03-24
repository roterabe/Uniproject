#!/usr/bin/env python3

import sys

result = ""

for i in range(1, (len(sys.argv)-1)):
    key = (sys.argv[len(sys.argv)-1])
    char = sys.argv[i]
    for letter in char:
        if (letter.isupper()):
            result += chr((ord(letter) + int(key) - 65) % 26 + 65)
        else:
            result += chr((ord(letter) + int(key) - 97) % 26 + 97)
    if(i == (len(sys.argv))-2):
        print("Key = " + str((sys.argv[len(sys.argv)-1])))
        print(str(result))
