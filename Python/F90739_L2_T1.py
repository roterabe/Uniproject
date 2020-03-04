#!/usr/bin/env python3

import sys
flag = 0

for arg in range(1, (len(sys.argv)-1)):

    if sys.argv[arg] <= sys.argv[arg+1]:
        flag = 0
    else:
        flag = 1


if flag == 0:
    print("sorted")
else:
    print("unsorted")
