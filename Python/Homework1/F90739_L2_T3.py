#!/usr/bin/env python3

import sys

sys.argv.sort()
for i in range(1, (len(sys.argv))):
    if sys.argv[i] == sys.argv[i-1]:
        result = True
        break
    else:
        result = False

print(result)
