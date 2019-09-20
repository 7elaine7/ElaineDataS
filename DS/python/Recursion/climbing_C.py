#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Climbing the stairs.
动态规划
'''


class ClimbC(object):

    @staticmethod
    #静态方法  与类无关不需要实例化
    def climb(n: int):
        if n in range(3):
            return n

        a = 1
        b = 2
        while n > 2:
            a, b = b, a+b
            n -= 1

        return b


if __name__ == '__main__':
    for i in range(8):
        print("climb %s stairs have %s ways" % (i, ClimbC.climb(i)))




