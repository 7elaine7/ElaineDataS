#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Array queue common function.
'''

from typing import Optional

class MayQueue(object):

    def __init__(self, len: int):
        self.queue = []
        self.len = len+1
        self.head = 0
        self.tail = 0

    def enqueue(self, value: int) -> bool:
        if (self.tail+1) % self.len == self.head:
            print("Full queue")
            return False

        self.queue.append(value)
        self.tail = (self.tail + 1) % self.len


    def dequeue(self) -> Optional[int]:
        if self.head == self.tail:
            print("Empty queue")
            return False
        else:
            value = self.queue[self.head]
            self.queue[self.head] = None
            self.head = (self.head + 1) % self.len
            return value

    def dumpqueue(self):
        print("len: %s, head: %s, tail: %s" % (self.len, self.head, self.tail))
        print(self.queue)

if __name__ == "__main__":
    q = MayQueue(5)
    for i in range(7):
        q.enqueue(i)
    q.dequeue()
    q.dequeue()

    q.enqueue(7)
    q.enqueue(7)
    q.dumpqueue()

