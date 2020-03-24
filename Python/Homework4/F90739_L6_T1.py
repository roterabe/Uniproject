#!/usr/bin/env python3

import sys


def fib(n, elem):
    elem.append(elem[len(elem)-1]+elem[len(elem)-2])
    while (len(elem) < n):
        fib(n, elem)
    return elem


end = int(sys.argv[len(sys.argv)-1])
begin = int(sys.argv[len(sys.argv)-2])
elem = [0, 1]

fib(end, elem)
print(elem[begin-1:])
