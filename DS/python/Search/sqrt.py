#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
get the sqrt for a value.
'''
from math import fabs

E = 0.000001
def sqrt_value(num: float) -> float:
    low = 0.0
    high = num

    if num == 1.0 or num == 0.0:
        return num
    elif num < 1.0 and num > 0.0:
        low = 0
        high = 1.0

    mid = low + (high - low) / 2  #/浮点数除法
    while fabs( mid ** 2 - num) > E:
        if mid ** 2 > num:
            high = mid
        else:
            low = mid
        mid = low + (high - low) / 2

    return mid

if __name__ == '__main__':
    num = 0.09
    result = sqrt_value(num)
    print("The square root for %.6f is: %.6f" % (num, result))