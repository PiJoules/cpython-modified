#!/usr/bin/env python
# -*- coding: utf-8 -*-

class MyClass(object):
    def __init__(self, x):
        self.__x = x

    def x(self):
        return self.__x


def main():
    mc = MyClass(2)
    print(mc.x())
    return 0


if __name__ == "__main__":
    main()

