#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Climbing the stairs.
'''


class ClimbR(object):

    def __init__(self, size):
        self.map = [0, 1, 2]
        for i in range(3, size):
            self.map.append(0)

    def climb(self, index: int):
        if index == 0:
            return self.map[0];

        if self.map[index]:
            return self.map[index]

        value = self.climb(index - 1) + self.climb(index - 2)
        self.map[index] = value
        return self.map[index]


if __name__ == '__main__':
    way = ClimbR(8)
    for i in range(8):
        print("Climb %s stairs have %s ways" % (i, way.climb(i)))



