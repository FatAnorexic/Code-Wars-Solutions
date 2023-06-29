"""
The Fibonacci numbers are the numbers in the following integer sequence (Fn):

    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...

such as

    F(n) = F(n-1) + F(n-2) with F(0) = 0 and F(1) = 1.

Given a number, say prod (for product), we search two Fibonacci numbers F(n) and F(n+1) verifying

    F(n) * F(n+1) = prod.

Your function productFib takes an integer (prod) and returns an array:

[F(n), F(n+1), true] or {F(n), F(n+1), 1} or (F(n), F(n+1), True)

depending on the language if F(n) * F(n+1) = prod.

If you don't find two consecutive F(n) verifying F(n) * F(n+1) = prodyou will return

[F(n), F(n+1), false] or {F(n), F(n+1), 0} or (F(n), F(n+1), False)

F(n) being the smallest one such as F(n) * F(n+1) > prod.
Some Examples of Return:

(depend on the language)

productFib(714) # should return (21, 34, true), 
                # since F(8) = 21, F(9) = 34 and 714 = 21 * 34

productFib(800) # should return (34, 55, false), 
                # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55
-----
productFib(714) # should return [21, 34, true], 
productFib(800) # should return [34, 55, false], 
-----
productFib(714) # should return {21, 34, 1}, 
productFib(800) # should return {34, 55, 0},        
-----
productFib(714) # should return {21, 34, true}, 
productFib(800) # should return {34, 55, false}, 

"""
#This was my approach, which in hind sight was a bit overly complicated. A much
#more efficient algorithm is implemented below. There is a lesson here on fully reading
#and understanding the problem before starting

from functools import lru_cache #because we are using a recursive function it makes sense
                                #for it to use data that's already been cached and calculated
def productFib(prod):
    value=0
    i =0
    while value<=prod:
        i+=1
        value=fib(i)*fib(i-1)
        
        if value==prod:
            return [fib(i-1), fib(i), True]
    return [fib(i-1), fib(i), False]
        
@lru_cache(maxsize=3) #I used lru cache as it allows me to set the max size, and chose 3 as
                      #we will only ever need to reference the previous two numbers in memory. 
def fib(n):
    if n == 0:
        return 0
    elif n==1 or n==2:
        return 1
    else:
        return fib(n-1)+fib(n-2)
#A side note, the recursion limit in python is set to 1000, so fib(1000) will not work|
#You can override this by sys.setrecursionlimit(n) but this can cause massive instability
#for memory purposes, and should be avoided if possible. Instead, we ought to look for different
#ways of calculating our recursive function. Which is exactly what we do in "Millionth Fib" kata in
#3Kyu folder. 

#What the best rated answer was, and similar to my solution, though much less busy work involved
def productFib(prod):
    a, b=0,1
    while prod>a*b:
        a, b=b, a+b
    return [a, b, prod==a*b]