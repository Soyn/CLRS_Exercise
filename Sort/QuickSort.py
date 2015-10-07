#!/usr/bin/env python
#-*- coding:utf-8 -*-

'''
	QuickSort Algorithm
	Average Runing Time ---> O(nlgn)
 	Create by Soyn. 26/7/15.
'''

def partion(a,p,r):
    pivot = a[p]
    i = p
    j = p + 1
    while j < r:
        if a[j] <= pivot:
            i += 1
            a[i],a[j] = a[j],a[i]
        j += 1

    a[i],a[p] = a[p],a[i]
    return i



def QuickSort(a,p,q):
    if p < q:
        r = partion(a,p,q)
        QuickSort(a,p,r)
        QuickSort(a,r + 1,q)

def test():
    a = [6,10,13,5,8,3,2,11]
    QuickSort(a,0,len(a))
    print "After Sorted: ", a

if __name__ == "__main__":
    test()