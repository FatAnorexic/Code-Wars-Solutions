"""You will be given an array of numbers. You have to sort the odd numbers 
   in ascending order while leaving the even numbers at their original 
   positions."""
#For this problem, I decided to use a modified version of selection sort. 

def sort_array(source_array):
    for i in range(len(source_array)):
    #For selection sort, we start by setting the minimum index to i        
        min_index=i
        
        for j in range(i+1, len(source_array)):
        #just like regular sel sort, we compare the current element to the smallest 
        #index we set earlier, but this time, we set the condition that both must be 
        #odd. This will prevent any even number from being moved, while setting the 
        #smallest element, for any two odd numbers we come across
            if (source_array[j]<source_array[min_index]) and (source_array[j]%2!=0)\
                and (source_array[min_index]%2!=0):
                min_index=j
        #From here, it's the same as sel sort all over again| Simply set the smallest
        #element in the list to the current min_index, and set i to the smallest index
        (source_array[i], source_array[min_index])=(
            source_array[min_index],source_array[i])
    
    return source_array
