#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Bubble sort, Insertion sort, Selection sort
'''

def Bubble_sort(array, size: int):
    for i in range(size):
        tag = True
        for j in range(size - i - 1):
            if array[j] > array[j+1]:
                tmp = array[j]
                array[j] = array[j+1]
                array[j+1] = tmp
                tag = False
        if tag == True:
            break

def Insertion_sort(array, size: int):
    #注意是在微排序区域查找，j已排序区域，i是未排序区域
    for i in range(1, size):
        value = array[i]
        j = i-1
        while j >= 0:
            if array[j] > value:
                array[j+1] = array[j]
                j -= 1
            else:
                break
        array[j+1] = value

def Selection_sort(array, size: int):
    for i in range(size):
        index = i
        for j in range(i, size):
            if array[j] < array[index]:
                index = j
        min = array[index]
        array[index] = array[i]
        array[i] = min



if __name__ == "__main__":
    array = [9,3,5,7,1,6,2,7]
    size = len(array)
#    Bubble_sort(array, size)
#    Insertion_sort(array, size)
    Selection_sort(array, size)
    print(array)

