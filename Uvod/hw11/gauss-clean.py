#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import division

a=[[2.0,9.0,0.0,67.0],[9.0,-3.0,9.0,12.0],[7.0,3.0,5.0,-36.0]]


def printMatrix(a):
	for row in a:
		s=''
		for element in row:
			s+=str(element)+"|"
		print (s+"\n")

for i in range(len(a)):
	first_element=a[i][i]
	for j in range(i,len(a)):
		a[i][j]=a[i][j]/first_element
	#b[i]/=first_element
	for k in range(i+1,len(a)):
		ff=a[k][i]
		for l in range(i,len(a)):
			a[k][l]=a[k][l]-ff*a[i][l]
		#b[k]=b[k]-ff*b[i]

printMatrix(a)
for row in a:
		s=''
		for element in row:
			s+=str(element)+"|"
		print (s+"\n")

