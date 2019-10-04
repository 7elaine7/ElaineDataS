#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Merge sort
'''

def Merge_Sort(array, n1, start, n2):
    tmp = []
    i = n1;
    j = start + 1
    n = i

    while i <= start and j <= n2:
        if array[i] <= array[j]:
            tmp.append(array[i])
            i+=1
        else:
            tmp.append(array[j])
            j+=1
        n+=1

    if i > start:
        array[n1:n] = tmp
    elif j > n2:
        tmp.extend(array[i:(start+1)])
        array[n1:(n2+1)] = tmp

def Merge(array, n1, n2):
    if n1 >= n2:
        return
    mid = (n1 + n2) // 2

    Merge(array, n1, mid)
    Merge(array, mid+1, n2)

    Merge_Sort(array, n1, mid, n2)


if __name__ == '__main__':
    array = [7, 2, 5, 9, 1, 6, 10, 7, 8]
    size = len(array)

    Merge(array, 0, size-1)
    print(array)


