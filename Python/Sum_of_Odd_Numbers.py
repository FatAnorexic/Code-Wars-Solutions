"""
Given the triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...

Calculate the sum of the numbers in the nth row of this triangle (starting at index 1) e.g.:

(Input --> Output)
1 -->  1
2 --> 3 + 5 = 8
"""

#For this, we can look at how each row begins and the next begins
# (end of nth row and begin of nth+1 row)
#Playing with each row a little you may find, that each row begins:
#(n*n)-(n-1) and ends ((n*n)-(n-1))+n*2|The start of the next row
def row_sum_odd_numbers(n):
    sum=0
    begin=(n*n)-(n-1)
    end=begin+n*2
    for i in range(begin,end,2):
        sum+=i
    return sum

#But a far more trivial solution exists should you notice the pattern
def row_sum_odd_numbers(n):
    #while we can use a loop to iterate,
    #a quick summation of the first few lines shows us each row
    #is the cube of n
    return n*n*n