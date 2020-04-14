#!/usr/bin/env python3


class Fibs(object):
    def __init__(self):
        self.b = 0
        self.n = 1

    def __next__(self):
        self.c = self.n
        self.n = self.b+self.n
        self.b = self.c
        return self.n

    def __iter__(self):
        return self

