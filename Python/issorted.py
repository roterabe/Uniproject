#!/usr/bin/env python3

sort = tuple([1,2,2])
not_sorted = ['b','a']

sortt = sort[:]
ns = not_sorted[:]
ns.sort()
sortt.sort()

if sortt == sort:
    print (str(sort) + " is sorted")
else:
    print (str(sort) + " is not sorted")

if ns == not_sorted:
    print (str(not_sorted) + " is sorted")
else:
    print (str(not_sorted) + " is not sorted")