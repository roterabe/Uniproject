#!/usr/bin/env python3

import sys

word = list(sys.argv[1])
reverse = word[::-1]

if (word == reverse):
    print("True")
else:
    print("False")