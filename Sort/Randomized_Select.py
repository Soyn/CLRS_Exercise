#!/usr/bin/env python
#!-*- coding:utf-8 -*-

from random import randint


'''
    Randomized-Select Algorithm
    runing time ----> Theate(n)
    Created by Soyn. 1/8/15.
'''

def Partion(a, p, r):
    pivot = a[p]
    i = p
    j = p
    while j < r:
        if a[j] < pivot:
            i += 1
            a[i],a[j] = a[j],a[i]
        j += 1

    a[i],a[p] = a[p],a[i]
    return i


def Randomized_Partion(a, p, r):
    i =randint(p,r -1)
    a[i],a[p] = a[p], a[i]
    return Partion(a,p,r)

def Randomized_Select(a,p,r,i):
    if p == r - 1:
        return a[p]
    q = Randomized_Partion(a,p,r)
    k = q - p + 1
    if i == k:
        return a[q]
    elif i < k:
        return Randomized_Select(a,p,q, i)
    else:
        return Randomized_Select(a,q + 1, r, i - k)



def test():   #for test
    a = [2,3,1,2,4,5,7,9,4,3,-2,-3]
    print "The element selected is: ", Randomized_Select(a,0,len(a),2)

if __name__ == "__main__":
    test()




