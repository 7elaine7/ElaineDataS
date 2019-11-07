#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
binary search.
'''

def b_search(array, value: int):
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if array[mid] == value:
            return mid
        elif array[mid] > value:
            high = mid - 1
        else:
            low = mid + 1
    print("No value in the array!")
    return -1

if __name__ == '__main__':
    array = [0, 1, 2, 7, 8, 17, 77, 177, 520, 777]
    index = b_search(array, 77)
    print("The value index is: %s" % index)