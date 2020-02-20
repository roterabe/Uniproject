#!/usr/bin/env python3

a = int(input())
b = int(input())
c = int(input())

if a != 0:
    print("yep")
    if b**2-4*a*c > 0:
        print("x1 & x2")

else:
    if b != 0:
        print("bx+c=0")
        print("x1 = -c/b")
    else:
        print("nope - 0x+c-0")

