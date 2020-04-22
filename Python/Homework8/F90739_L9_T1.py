#!/usr/bin/env python3


def f(x):
    return pow(2.71828, x) - 2*x-2


def f1(x):
    return x*x*x+3*x-5


def bisection(a, b, func):
    try:
        a = float(a)
        b = float(b)

    except ValueError:
        print("The value provided for \"a\" or \"b\" is not a number..")
        return 0

    try:
        if (func(a)*func(b) >= 0):
            raise
    except:
        print("Not a valid calculation!")
        return 0

    diff = b - a
    while (diff >= 0.001):
        t = (a + b) / 2
        if (func(t) * func(a)) < 0:
            b = t
        if (func(t) * func(b)) < 0:
            a = t
        if (diff < 0.001 or func(t) == 0.0):
            break

    return ("%.2f" % t)
