#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Linked stack common function.
'''

from typing import Optional

class Stack(object):

    def __init__(self, data: int, next = None):
        self.data = data
        self.next = next

class LinkStack(object):

    def __init__(self):
        self.top:Stack = None

    def push(self, value: int):
        new = Stack(None)
        new.data = value
        new.next = self.top
        self.top = new

    def pop(self) -> Optional[int]:
        if self.top:
            value = self.top.data
            self.top = self.top.next
            return value

        print('empty stack')

    def dump(self):
        current = self.top
        stack = []
        while current:
            stack.append(current.data)
            current = current.next

        s = ' -> '.join(map(str, stack))
        print(s)

if __name__ == "__main__":
    stack = LinkStack()
    for i in range(7):
        stack.push(i)
    stack.dump()
    for _ in range(8):
        stack.pop()
    stack.dump()




