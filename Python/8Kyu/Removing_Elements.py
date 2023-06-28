"""Take an array and remove every second element from the array. Always keep the first element 
and start removing with the next element.
Example:

["Keep", "Remove", "Keep", "Remove", "Keep", ...] --> ["Keep", "Keep", "Keep", ...]

None of the arrays will be empty, so you don't have to worry about that!
"""
#2 solutions. One shows better what's going on, the other is more of a best practices solution
def remove_every_other(my_list):
    new=[]
    for i in range(len(my_list)):
        if i%2==0:
            new.append(my_list[i])
    return new

def remove_every_other(my_list):
    return my_list[::2]
