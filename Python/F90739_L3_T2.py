#!/usr/bin/env python3

import sys

result = []
cipheredtext = ""
print("Key = " + str(sys.argv[len(sys.argv)-1]))

for i in range(1, (len(sys.argv)-1)):
    key = (sys.argv[len(sys.argv)-1])
    char = sys.argv[i]
    keycode = [ord(letter) for letter in key]
    textcode = [ord(letter) for letter in char]
    for j in range(len(textcode)):
        if (chr(textcode[j]).isupper()):
            value = (textcode[j] + keycode[j % len(key)]) % 26
            cipheredtext += chr(value + 65)
        else:
            value = (textcode[j] + keycode[j % len(key)]) % 26
            cipheredtext += chr(value + 97)

    if(i == (len(sys.argv))-2):
        print(str(cipheredtext))
