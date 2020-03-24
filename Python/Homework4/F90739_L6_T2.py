#!/usr/bin/env python3

import sys


def rec_pow(num, power):
    if (power == 0):
        return 1
    if (power == 1):
        return num
    return num * rec_pow(num, power-1)


num = int(sys.argv[1])
power = int(sys.argv[2])
num = rec_pow(num, power)
print(num)
