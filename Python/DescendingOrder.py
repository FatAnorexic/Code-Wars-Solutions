"""Your task is to make a function that can take any non-negative integer as an argument 
   and return it with its digits in descending order. Essentially, rearrange the digits 
   to create the highest possible number."""

def descending_order(num):
    # Bust a move right here
    digits=[i for i in str(num)]
    digits.sort(reverse=True)
    newnum=int(''.join(digits))
    return newnum
