"""Write a function that takes an integer as input, and returns the number of bits 
   that are equal to one in the binary representation of that number. You can 
   guarantee that input is non-negative.

   Example: The binary representation of 1234 is 10011010010, so the function 
   should return 5 in this case"""

def count_bits(n):
    c=0
    b=bin(n)
    b_list=list(b)
    
    for i in range(len(b)):
        if b_list[i]=='1':
            c+=1
    return c

  #more straight forward approach is to use the count method, accumulating the 
  #number of times '1' showns up in bin.n
  def count_bits(n):
    return bin(n).count('1')
