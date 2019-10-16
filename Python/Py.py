#!/usr/bin/env python3


def square(n):
    k = 0
    while True:
        if (k == n * n):
            return k
        k += 1

number = 100000

print(square(number))
