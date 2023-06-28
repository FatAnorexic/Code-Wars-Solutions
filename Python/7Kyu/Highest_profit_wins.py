"""
Story:

Ben has a very simple idea to make some profit: he buys something and sells it again. 
Of course, this wouldn't give him any profit at all if he was simply to buy and sell 
it at the same price. Instead, he's going to buy it for the lowest possible price and 
sell it at the highest.

Task:

Write a function that returns both the minimum and maximum number of the given list/array.
Examples (Input --> Output)

[1,2,3,4,5] --> [1,5]
[2334454,5] --> [5,2334454]
[1]         --> [1,1]

Remarks:

All arrays or lists will always have at least one element, so you don't need to check the length. 
Also, your function will always get an array or a list, you don't have to check for null, undefined or similar.
"""
#a best practices solution:
def min_max(lst):
  #we simply call upon the min max functions for python, and return an array with the two numbers from lst
  return [min(lst), max(lst)]

#This solution gives a little more context as to what's actually going on. 
def min_max(lst):
    #We set two variables to the same value at index 0 of lst|These values may change when iterating through the loop. 
    min, max=lst[0], lst[0]
    for i in lst:
        if i<min:
            min=i
        if i>max:
            max=i
    return [min,max]
