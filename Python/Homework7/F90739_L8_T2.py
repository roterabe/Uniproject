#!/usr/bin/env python3

import sys

space = [['#' for x in range(10)] for y in range(10)]

for wall in range(len(space)):
    if(wall+1 % 10):
        print()
    print(space[wall], end='')

class Maze(object):
    def __init__(self):
        