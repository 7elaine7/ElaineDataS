#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Quick sort, Bucket sort, Count sort, Radix sort
'''

from functools import reduce
def Select(array, n1, n2):
    q = array[n2]
    i = j = n1
    while j < n2:
        if array[j] < q:
            tmp = array[j]
            array[j] = array[i]
            array[i] = tmp
            i+=1
        j+=1
    array[n2] = array[i]
    array[i] = q
    return i

def Quick_Sort(array, n1, n2):
    if n1 >= n2:
        return

    q = Select(array, n1, n2)
    Quick_Sort(array, n1, q-1)
    Quick_Sort(array, q+1, n2)

def Bucket_sort(array):
    minnum = min(array)
    maxnum = max(array)
    #计算桶的数量
    num = maxnum//10 - minnum//10 + 1
    bucket = list([] for _ in range(num))
    #均分到各个桶里
    for data in array:
        index = data // 10 - minnum //10
        bucket[index].append(data)
    #桶内快排
    for arr in bucket:
        Quick_Sort(arr, 0, len(arr)-1)

    result = []
    #将每个桶内的数据extend进result里面
    for arr in bucket:
        if len(arr) != 0:
            result.extend(arr)
    return result

def Count_sort(array):
    max_n = max(array)
    count = [0 for _ in range(max_n+1)]
    buffer = [0 for _ in range(len(array))]
    for data in array:
        count[data] += 1
    for i in range(len(count)-1):
        count[i+1] = count[i] + count[i+1]
    for data in reversed(array):
        buffer[count[data]-1] = data
        count[data] -= 1

    return buffer

def Radix_sort(array):
    max_n = max(array)
    min_n = min(array)
    s = [[] for _ in range(len(array))]
    i = 0
    for data in array:
        s[i] = list(map(int, str(data)))    #数字转化为各位的列表
        i+=1

    for m in range(len(str(max_n))):
        count = [[] for _ in range(10)]
        for num in s:
            if len(num)-1-m < 0:
                count[0].append(num)
            else:
                count[num[len(num)-1-m]].append(num)
        s = [a for c in count for a in c]

    k = 0
    for A in s:
        s[k] = reduce(lambda x, y: x*10+y, A)
        k+=1

    return s


if __name__ == "__main__":
    array = [7, 17, 9, 59, 27, 31, 52, 40, 66, 16, 0]
    size = len(array)
#    Quick_Sort(array, 0, size-1)
    result = Bucket_sort(array)
    print(result)

    array2 = [7, 0, 8, 5, 2, 0, 7, 6, 1, 5, 2, 6, 7, 8, 6, 1]
    result2 = Count_sort(array2)
    print(result2)

    array3 = [12345, 77, 111, 0, 27, 17, 16, 1, 789652, 66, 666, 17777, 1, 520, 521]
    result3 = Radix_sort(array3)
    print(result3)