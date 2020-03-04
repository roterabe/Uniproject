#!/usr/bin/env python3

import sys

digits = []
for i in range (1, (len(sys.argv))):
    if sys.argv[i] not in digits:
        digits.append(sys.argv[i])
digits = [int(x) for x in digits]

print (digits)