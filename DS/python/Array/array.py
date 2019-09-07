#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Array common function.
'''

class MyArray(object):

    def __init__(self, size):
        self.__array = []
        self.__size = size

    def search_value(self, value):
        index = 0
        for i in self.__array:
            if i == value:
                break
            index = index + 1

        if index >= len(self.__array):
            print('can not find the value')
            return None
        else:
            return index


    def insert_value(self, index, value):
        if len(self.__array) >= self.__size:
            return False
        else:
            self.__array.insert(index, value)

    def delete_value(self, index):
        try:
            self.__array.pop(index)
            return True
        except IndexError as e:
            print('Error:', e)
            return False

    def dump_all(self):
        for value in self.__array:
            print(value)

def test_Myarray():
    array = MyArray(5)
    array.insert_value(0, 7)
    array.insert_value(0, 17)
    array.insert_value(1, 77)
    array.insert_value(4, 66)
    array.insert_value(2, 9)
    assert array.insert_value(1, 11) is False
    assert array.search_value(77) == 1
    assert array.search_value(33) is None
    assert array.delete_value(2) is True
    assert array.delete_value(8) is False
    array.dump_all()

if __name__ == "__main__":
    test_Myarray()






