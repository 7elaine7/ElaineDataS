#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
binary search.
1. 查找第一个值等于给定值的元素
2. 查找最后一个值等于给定值的元素
3. 查找第一个大于等于给定值的元素
4. 查找最后一个小于等于给定值的元素
'''

def search_first_eq(array, value: int) -> int:
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 1
        if array[mid] == value:
            if array[mid - 1] != value or mid == 0:
                return mid
            else:
                high = mid - 1
        elif array[mid] > value:
            high = mid - 1
        else:
            low = mid + 1
    print("No value in the array!")
    return -1

def search_last_eq(array, value: int) -> int:
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 1
        if array[mid] == value:
            if array[mid + 1] != value or mid == len(array) - 1:
                return mid
            else:
                low = mid + 1
        elif array[mid] > value:
            high = mid - 1
        else:
            low = mid + 1
    print("No value in the array!")
    return -1

def search_first(array, value: int) -> int:
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 1
        if array[mid] >= value:
            if array[mid - 1] < value or mid == 0:
                return mid
            else:
                high = mid - 1
        else:
            low = mid + 1
    print("No value in the array!")
    return -1

def search_last(array, value: int) -> int:
    low = 0
    high = len(array) - 1
    while low <= high:
        mid = low + (high - low) // 1
        if array[mid] <= value:
            if array[mid + 1] > value or mid == len(array) - 1:
                return mid
            else:
                low = mid + 1
        else:
            high = mid - 1
    print("No value in the array!")
    return -1

if __name__ == '__main__':
    array = [1, 2, 7, 7, 7, 8, 77, 77, 177, 520, 777, 777]
    index = search_first_eq(array, 777)
    print("The value index is: %s" % index)
    assert search_last_eq(array, 77) == 7
    assert search_first(array, 666) == 10
    assert search_last(array, 666) == 9


