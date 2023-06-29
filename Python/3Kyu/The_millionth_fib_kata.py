"""
https://www.codewars.com/kata/53d40c1e2f13e331fc000c26/python

In this kata you will have to calculate fib(n) where:

fib(0) := 0
fib(1) := 1
fin(n + 2) := fib(n + 1) + fib(n)

Write an algorithm that can handle n up to 2000000.

Your algorithm must output the exact integer answer, to full precision. 
Also, it must correctly handle negative numbers as input.

HINT I: Can you rearrange the equation fib(n + 2) = fib(n + 1) + fib(n) 
to find fib(n) if you already know fib(n + 1) and fib(n + 2)? Use this to 
reason what value fib has to have for negative values.

HINT II: See 
( https://web.archive.org/web/20220614001843/
https://mitpress.mit.edu/sites/default/files/sicp/full-text/book
/book-Z-H-11.html#%_sec_1.2.4 )
"""

#Lets start by actually looking at the problem and working it out from the 
#section linked-We'll start bellow this function at fibiter->
def fib(n):
    #we have to account for the number being <0
    if n<0:
        a,b=0,1
        for x in range(0,n,-1):
            temp_a=a
            a=b
            b=temp_a-b
            #can also be written a,b=b-a,a
        return a
    #now that we've handled negatives(somewhat) we can run our function
    return fibiter(1,0,0,1,n)

#We will make a function fibiter which will take values a, b, p, q and our 
#number to calculate n|excercise 1.19 from the link
def fibiter(a, b, p, q, n):
    if n==0:
        return b
    elif n%2==0:
        #the solution to excercise 1.19
        return fibiter(a, b, p*p+q*q, q*q+2*p*q, n/2)
    else:
        return fibiter(b*q+a*q+a*p, b*p+a*q,p,q,n-1)
    
#all well and good, lets use a shorthand version of this problem
import numpy as np

def fib(n):
    matrix=np.matrix([[1,1],[0,1]], dtype=object) ** abs(n)
    if n%2==0 and n<0:
        return -matrix[0,1]
    return matrix[0,1]
#Numpy is more than capable of handling massive numbers, but everything has its limit
#it's good practice to ensure you can still solve a problem like this without the need
#for external libraries.