#!/usr/bin/env python3

import unittest


class TestBi(unittest.TestCase):

    def test_bi(self):
        self.assertEqual(bisection(-200, 300, f1), 1.15,
                         "Failure in calculation.")

    def test_values(self):
        self.assertFalse(f1(-200)*f1(300) >= 0,
                         "The value for \"a\" or \"b\" is not a valid one.. Please supply some other input.")

    def test_ifFloat(self):
        self.assertFalse(bisection(-200, 300, f1) != float(bisection(-200,
                                                                     300, f1)), "The return type is not of type float!")


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
        print("The value for \"a\" or \"b\" is not a valid one.. Please supply some other input.")

    diff = b - a
    while (diff >= 0.001):
        t = (a + b) / 2
        if (func(t) * func(a)) < 0:
            b = t
        if (func(t) * func(b)) < 0:
            a = t
        if (diff < 0.001 or func(t) == 0.0):
            break

    return float(("%.2f" % t))


if __name__ == '__main__':
    unittest.main()
