#!/usr/bin/env python3

lis = [42,5,3,2,42,1,6,7]
x = 0
for y in range(1,8):
    if lis[x] == lis[y]:
        print ("The meaning of life is 42.")
        if y == 8:
            x += 1
            continue
        else:
            break
    elif lis[x] != lis[y]:
        print ("It is not ready yet.")
