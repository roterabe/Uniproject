#!/usr/bin/env python3

import sys
import random

#TODO implement maze solve.


class Maze(object):
    def __init__(self, z, t):
        self.space = [['#' for x in range(z)] for y in range(t)]
        self.directions = ["left", "right", "up", "down"]
        self.x = 1
        self.y = 1

    def solveMaze(self, x, y):
        self.x = x
        self.y = y

        cnt = len(self.space)*self.x
        steps = len(self.space)/self.x+self.x
        c = steps
        while (cnt >= 0):
            direction = ""
            direction = random.choice(self.directions)
            if (direction == "up"):
                if (self.x-1 > 1):
                    self.space[self.x-1][self.y] = ' '
                    self.x -= 1
                    while (self.x > 1 and c > 0):
                        self.space[self.x-1][self.y] = ' '
                        self.x -= 1
                        c -= 1
                    c = steps
            if (direction == "down"):
                if (self.x+1 < len(self.space[self.x])-2):
                    self.space[self.x+1][self.y] = ' '
                    self.x += 1
                    while (self.x < len(self.space[self.x])-2 and c > 0):
                        self.space[self.x+1][self.y] = ' '
                        self.x += 1
                        c -= 1
                    c = steps
            if (direction == "left"):
                if (self.y-1 > 1):
                    self.space[self.x][self.y-1] = ' '
                    self.y -= 1
                    while (self.y > 1 and c > 0):
                        self.space[self.x][self.y-1] = ' '
                        self.y -= 1
                        c -= 1
                    c = steps
            if (direction == "right"):
                if (self.y+1 < len(self.space[self.y])-2):
                    self.space[self.x][self.y+1] = ' '
                    self.y += 1
                    while (self.y < len(self.space[self.y])-2 and c > 0):
                        self.space[self.x][self.y+1] = ' '
                        self.y += 1
                        c -= 1
                    c = steps
            cnt -= 1
        if self.space[self.x][self.y] != '@':
            self.space[self.x][self.y] = 'g'
        if self.space[self.x][self.y] == '@':
            cnt += 1
        self.space[x][y] = '@'
        

    """
        found = False
        dir = random.choice(self.directions)
        while found is False:
            
            if self.space[self.x-1][self.y] == '#' or self.space[self.x+1][self.y] == '#' or self.space[self.x][self.y-1] == '#' or self.space[self.x][self.y+1] == '#':
                dir = random.choice(self.directions)
                continue
            
            if dir == "up":

                if self.x > 1 and self.space[self.x-1][self.y] == ' ' or self.space[self.x-1][self.y] == 'g' or self.space[self.x-1][self.y] == 'x':

                    self.x -= 1

                    if self.space[self.x][self.y] == 'g':
                        found = True
                        break

                    elif self.space[self.x][self.y] == '.':
                        self.space[self.x][self.y] = 'x'

                    elif self.space[self.x][self.y] == ' ':
                        self.space[self.x][self.y] = "."

                    elif self.space[self.x-1][self.y] == '#':
                        dir = random.choice(self.directions)
                    continue

            if dir == "down":
                if self.x < len(self.space[self.x])-2 and self.space[self.x+1][self.y] == ' ' or self.space[self.x+1][self.y] == 'g' or self.space[self.x+1][self.y] == 'x':

                    self.x += 1

                    if self.space[self.x][self.y] == 'g':
                        found = True
                        break

                    elif self.space[self.x][self.y] == '.':
                        self.space[self.x][self.y] = 'x'

                    elif self.space[self.x][self.y] == ' ':
                        self.space[self.x][self.y] = "."

                    elif self.space[self.x-1][self.y] == '#':
                        dir = random.choice(self.directions)
                    continue

            if dir == "left":
                if self.x > 1 and self.space[self.x][self.y-1] == ' ' or self.space[self.x][self.y-1] == 'g' or self.space[self.x][self.y-1] == 'x':

                    self.y -= 1

                    if self.space[self.x][self.y] == 'g':
                        found = True
                        break

                    elif self.space[self.x][self.y] == '.':
                        self.space[self.x][self.y] = 'x'

                    elif self.space[self.x][self.y] == ' ':
                        self.space[self.x][self.y] = "."

                    elif self.space[self.x][self.y-1] == '#':
                        dir = random.choice(self.directions)
                    continue

            if dir == "right":
                if self.x < len(self.space[self.y])-2 and self.space[self.x][self.y+1] == ' ' or self.space[self.x][self.y+1] == 'g' or self.space[self.x][self.y+1] == 'x':

                    self.y += 1

                    if self.space[self.x][self.y] == 'g':
                        found = True
                        break

                    elif self.space[self.x][self.y] == '.':
                        self.space[self.x][self.y] = 'x'

                    elif self.space[self.x][self.y] == ' ':
                        self.space[self.x][self.y] = "."

                    elif self.space[self.x][self.y+1] == '#':
                        dir = random.choice(self.directions)
                    continue

    """

    def printMaze(self):
        for i in range(len(self.space)):
            for j in range(len(self.space[i])):
                print(self.space[i][j], end=' ')
            print()


x = int(sys.argv[1])
y = int(sys.argv[2])
s = Maze(x*5, y*5)
s.solveMaze(x, y)
s.printMaze()
