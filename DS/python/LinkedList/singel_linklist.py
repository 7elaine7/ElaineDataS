#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__author__ = 'Elaine'

'''
Linked list common function.
1. Reverse singel-linked list
2. Check circle in the list
3. Merge two sorted list
4. Remove the N-th node from the end
5. Get the middle node
'''
from typing import Optional


#node节点
class Node(object):

    def __init__(self, data: int, next = None):
        '''
        Node节点初始化function
            data: 节点存储的数据
            next: 下一个节点地址
        '''
        self.data = data
        self.__next = next

#单链表
class Singel_Linked_List(object):

    def __init__(self):
        self.__head = None

    def search_by_value(self, value: int) -> Optional[Node]:
        '''
        在链表中按照数据查找
        :param value: 查找的值
        :return: 返回node
        '''
        p = self.__head
        while p and p.data != value:
            p = p.__next

        if not p:
            print('value is not in the list')

        return p

    def search_by_index(self, index: int) -> Optional[Node]:
        '''
        查找index索引对应的node
        :param index:
        :return: 返回node
        '''
        p = self.__head
        while index > 0:
            p = p.__next
            index -= 1
        return p

    def insert_value_to_head(self, value: int):
        '''
        链表头部插入一个存储值为value的节点
        :param value: 插入的值
        '''
        new = Node(value)
        new.__next = self.__head
        self.__head = new

    def insert_value_after(self, node: Node, value: int):
        '''
        在链表中的Node节点之后插入值为value的节点
        :param node: 指定的Node节点位置
        :param value: 要插入的新节点存储的value值
        '''
        if node is None:
            return
        new = Node(value)
        new.__next = node.__next
        node.__next = new

    def insert_value_before(self, node: Node, value: int):
        '''
        在链表中的Node节点之前插入值为value的节点
        :param node: 指定的Node节点位置
        :param value: 要插入的新节点存储的value值
        '''
        if not node or not self.__head:
            return

        if node == self.__head:
            self.insert_value_to_head(value)
            return

        new = Node(value)
        pre = self.__head
        while pre and pre.__next != node:
            pre = pre.__next

        if not pre.__next:
            print('the node is not in the list')
            return

        new.__next = node
        pre.__next = new

    def delete_by_node(self, node: Node):
        '''
        删除链表中的node
        :param node: 要删除的node
        '''

        if not self.__head or not node:
            return

        if self.__head == node:
            self.__head = node.__next
            return

        pre = self.__head
        while pre and pre.__next != node:
            pre = pre.__next

        if not pre.__next:
            print('the node is not in the list')
            return

        pre.__next = node.__next


    def delete_by_value(self, value: int):
        '''
        删除链表中data为value的node
        :param value: 要删除的值
        '''
        p = self.search_by_value(value)
        if p:
            self.delete_by_node(p)

    def dump_all(self):
        '''
        打印当前的链表
        '''
        root = self.__head
        if root is None:
            print('the list is empty')
            return
        while root.__next:
            print((root.data) , ' --> ', end = "")
            root = root.__next
        print(root.data)

    def reverse_list(self):
        '''
        reverse the list
        '''
        if self.__head is Node or self.__head.__next is None:
            return

        pre = self.__head
        current = self.__head.__next

        while current:
            tmp = current.__next
            current.__next = pre
            pre = current
            current = tmp
        self.__head.__next = None
        self.__head = pre

    def delete_N_from_end(self, n: int):
        '''
        删除链表倒数第n个节点
        :param n: 需要删除的倒数第n个节点
        '''
        fast = self.__head
        slow = self.__head
        while n > 0 and fast:
            fast = fast.__next
            n -= 1

        if n > 1:
            print('the len for list is less than n')

        elif n == 1 and fast is None:
            print('the n-th node from the end is head node, remove head node')
            self.__head = self.__head.__next

        else:
            while fast.__next is not None:
                slow = slow.__next
                fast = fast.__next
            slow.__next = slow.__next.__next

    def find_mid_node(self) -> Optional[Node]:
        '''
        查找链表中间点
        :return: 中间节点node
        '''

        fast = self.__head
        slow = self.__head

        while fast and fast.__next:
            fast = fast.__next.__next
            slow = slow.__next

        return slow

    def iscircle(self) -> bool:
        '''
        判断是否有环
        :return: True：有，False：没有
        '''
        slow = self.__head
        fast = self.__head

        while fast and fast.__next:
            slow = slow.__next
            fast = fast.__next.__next
            if slow == fast:
                print('The meet node is %s' % slow.data)
                last = self.__head
                while(last != slow):
                    last = last.__next
                    slow = slow.__next
                print('The start loop node is %s' % last.data)
                return True

        return False

    def merge_two_sorted_list(self, p1: Node, p2: Node) -> Optional[Node]:
        '''
        合并两个有序链表
        :param p1: p1有序链表
        :param p2: p2有序链表
        :return:
        '''

        l1, l2 = p1, p2
        if l1.data > l2.data:
            self.__head = l2
            l2 = l2.__next
        else:
            self.__head = l1
            l1 = l1.__next

        current = self.__head
        while l1 and l2:
            if l1.data > l2.data:
                current.__next = l2
                l2 = l2.__next
                current = current.__next
            else:
                current.__next = l1
                l1 = l1.__next
                current = current.__next

        current.__next = l1 if l1 else l2

    def makeCircle(self, n1:Node, n2:Node):
        '''
        建立一个有环的链表，n1的尾部与n2连接，PS：在int函数里不能对链表直接进行操作？
        :param n1:
        :param n2:
        :return:
        '''
        n1.__next = n2


if __name__ == "__main__":
    List = Singel_Linked_List()
    for i in range(10):
        List.insert_value_to_head(i)
    List.dump_all()

    node7 = List.search_by_value(7)
    List.insert_value_after(node7, 66)
    List.insert_value_before(node7, 11)
    List.dump_all()

    node8 = List.search_by_index(8)
    List.delete_by_node(node8)
    List.delete_by_value(4)
    List.delete_N_from_end(8)
    List.dump_all()

    List.delete_by_value(66)
    List.delete_by_value(8)
    List.delete_by_value(5)
    List.delete_by_value(2)

    List.reverse_list()
    List.dump_all()

    mid = List.find_mid_node()
    print('the middle node is %s' % mid.data)

    List2 = Singel_Linked_List()
    List2.insert_value_to_head(9)
    List2.insert_value_to_head(8)
    List2.insert_value_to_head(5)
    List2.insert_value_to_head(2)
    List2.dump_all()

    L1 = List.search_by_index(0)
    L2 = List2.search_by_index(0)

#new一个新的list, List, List2均已改变
    new = Singel_Linked_List()
    new.merge_two_sorted_list(L2, L1)
    new.dump_all()
    n1 = new.search_by_index(8)
    n2 = new.search_by_value(5)

    new.makeCircle(n1, n2)

    if new.iscircle():
        print('Circle exist')
    else:
        print('There is no circle')
