#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Linked queue common function.
'''

from typing import Optional

class QueueNode(object):

    def __init__(self, data:int, next=None):
        self.data = data
        self.next = next

class LinkQueue(object):

    def __init__(self, head=None, tail=None):
        self.head: Optional[QueueNode] = head
        self.tail: Optional[QueueNode] = tail

    def enqueue(self, data):
        new = QueueNode(data, None)
        if self.tail:
            self.tail.next = new
        else:
            #为空的时候
            self.head = new
        self.tail = new

    def dequeue(self) -> Optional[int]:
        if self.head:
            data = self.head.data
            self.head = self.head.next
            if not self.head:
                self.tail = None
            return data
        else:
            print("queue empty already")

    def dump_queue(self):
        queue = []
        current = self.head
        while current:
            queue.append(current.data)
            current = current.next
        s = " -> ".join(map(str, queue))
        print(s)


if __name__ == "__main__":
    q = LinkQueue()
    for i in range(7):
        q.enqueue(i)
    q.dump_queue()

    for _ in range(8):
        n = q.dequeue()
        if n:
            print("dequeue %s success" % n)

    q.enqueue(6)
    q.enqueue(7)
    q.dump_queue()



