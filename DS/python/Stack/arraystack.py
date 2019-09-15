#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Array stack common function.
'''

class MyStack(object):

    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)

    def pop(self):
        return self.stack.pop()

    def dump_all(self):
        print(self.stack)

if __name__ == '__main__':
    stack = MyStack()
    for i in range(7):
        stack.push(i)
    stack.dump_all()
    for _ in range(3):
        stack.pop()
    stack.dump_all()