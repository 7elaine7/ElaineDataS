#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
loop array search.
'''

def loop_search(array, value: int) -> int:
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if array[mid] == value:
            return mid
        elif array[low] <= array[mid]:    #左边有序
            if array[low] <= value <= array[mid]:    #value落在左边
                high = mid - 1
            else:
                low = mid + 1
        else:
            if array[mid] <= value <= array[high]:
                low = mid + 1
            else:
                high = mid - 1
    print("No value in the array!")
    return -1


if __name__ == '__main__':
    array = [4, 5, 6, 7, 8, 1, 2, 3]
    index = loop_search(array, 9)
    print("The value index is: %s" % index)



