#!/usr/bin/env python3

import os
"""
with open('Shrek1.txt') as filehandle:
    lines = filehandle.readlines()

with open('Shrek1.txt', 'w') as script:
    lines = filter(str.strip, lines)
    script.writelines(lines)
"""

script = open('Shrek1.txt', 'r')

line = script.readlines()

for x in line:
    print(x)

