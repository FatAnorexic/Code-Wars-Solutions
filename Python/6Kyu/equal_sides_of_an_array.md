# Description:

You are going to be given an array of integers. Your job is to take that array and find an index **N** where the sum of the integers to the left of **N** is equal to the sum of the integers to the right of **N**. If there is no index that would make this happen, return -1.
For example:

Let's say you are given the array `{1,2,3,4,3,2,1}`:
Your function will return the index **3**, because at the 3rd position of the array, the sum of left side of the index (`{1,2,3}`) and the sum of the right side of the index (`{3,2,1}`) both equal 6.

Let's look at another one.
You are given the array `{1,100,50,-51,1,1}`:
Your function will return the index **1**, because at the 1st position of the array, the sum of left side of the index (`{1}`) and the sum of the right side of the index (`{50,-51,1,1}`) both equal 1.

Last one:
You are given the array `{20,10,-80,10,10,15,35}`
At index 0 the left side is `{}`
The right side is `{10,-80,10,10,15,35}`
They both are equal to 0 when added. (Empty arrays are equal to 0 in this problem)
Index **0** is the place where the left side and right side are equal.

---
>**_NOTE:_**  Please remember that in most languages the index of an array starts at 0.
---
# Input
An integer array of length `0 < arr < 1000`. The numbers in the array can be any integer positive or negative.

---

# Output
The lowest index **N** where the side to the left of **N** is equal to the side to the right of **N**. If you do not find an index that fits these rules, then you will return -1.

---

---
>**_Note:_** If you are given an array with multiple answers, return the lowest correct index.
---

# Solution:

This problem may require a little bit of crunching in order to grasp how to go about solving. 

## What is it asking?

We're tasked with slicing the array into a **"Left"** and a **"Right"** side. To get a feel for how this might look we 
can start by slicing at the mid point of the array. 

```Python
def find_even_index(arr):
    mid=int(len(arr)/2)
    left=arr[:mid]
    right=arr[mid:]
    print(f'Left Side: {left}')
    print(f'Right Side: {right}')
```
---
### A few cases shows us: 

```
Log
Left Side: [1, 2, 3]
Right Side: [4, 3, 2, 1]
```
```
Log
Left Side: [1, 100, 50]
Right Side: [-51, 1, 1]
```

```
Log
Left Side: [1, 2, 3]
Right Side: [4, 5, 6]
```
---
## Meaning?

This looks a little janky. To start with, this doesn't tell us how the two sides are correlated. Nor is it consistent.
For lists of even length we get an even split between left and right side, but uneven lengths give us a split between the two. We can solve this by adding in a conditional. 

```Python
def find_even_index(arr):
    mid=int(len(arr)/2)
    if len(arr)%2!=0:
        left=arr[:mid]
        right=arr[mid+1:]
    else:
        left=arr[:mid]
        right=arr[mid:]
        
    print(f'Left Side: {left}')
    print(f'Right Side: {right}')
```
---

### Log Cases:

```
Log
Left Side: [1, 2, 3]
Right Side: [3, 2, 1]
```
```
Log
Left Side: [1, 100, 50]
Right Side: [-51, 1, 1]
```

---
## Threading the Loop
As you can see, this now displays evenly on both sides, but really only splits the lists. This will work for a few of the tests, but will not act as a general solution to the problem. Reframing this another way we can say that what we're really trying to do is sum any number of indices on the left such that they are equivilant on the right. To see where these points meet up, we can create a loop which iterates through, and prints each slice of the list for both left and right. 

```Python
def find_even_index(arr):
    for x in range(len(arr)):
        print(x, arr[:x], arr[x:])
```
Looking at our first test case, 

```
Log
0 [] [1, 2, 3, 4, 3, 2, 1]
1 [1] [2, 3, 4, 3, 2, 1]
2 [1, 2] [3, 4, 3, 2, 1]
3 [1, 2, 3] [4, 3, 2, 1]
4 [1, 2, 3, 4] [3, 2, 1]
5 [1, 2, 3, 4, 3] [2, 1]
6 [1, 2, 3, 4, 3, 2] [1]
```
We wish to make this even at the midpoint. Referencing the code earlier,

```Python
def find_even_index(arr):
    for x in range(len(arr)):
        print(x, arr[:x], arr[x+1:])
```

```
Log
0 [] [2, 3, 4, 3, 2, 1]
1 [1] [3, 4, 3, 2, 1]
2 [1, 2] [4, 3, 2, 1]
3 [1, 2, 3] [3, 2, 1]
4 [1, 2, 3, 4] [2, 1]
5 [1, 2, 3, 4, 3] [1]
6 [1, 2, 3, 4, 3, 2] []
```
---
## Summing the array and a general solution

We can sum the sliced arrays to see if there is a point which the indecis align,
```Python
def find_even_index(arr):
    for x in range(len(arr)):
        print(x, sum(arr[:x]), sum(arr[x+1:]))
```
```
Log
0 0 15
1 1 13
2 3 10
3 6 6
4 10 3
5 13 1
6 15 0
```
```
0 0 101
1 1 1
2 101 -49
3 151 2
4 100 1
5 101 0
```
It should be pretty obvious where this is going now. If we create a conditional within the loop that equates the sum
of the two together, we can return the exact index in which that occurs. Add to that, it will be the first index that
this algorithm satisfies. 

```Python
def find_even_index(arr):
    for x in range(len(arr)):
        if sum(arr[:x])==sum(arr[x+1:]):
            return x
    return -1
```