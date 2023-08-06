"""
Build Tower

Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors. 
A tower block is represented with "*" character.

For example, a tower with 3 floors looks like this:

[
  "  *  ",
  " *** ", 
  "*****"
]

And a tower with 6 floors looks like this:

[
  "     *     ", 
  "    ***    ", 
  "   *****   ", 
  "  *******  ", 
  " ********* ", 
  "***********"
]

"""

def tower_builder(n_floors):
    #for the number of floors, it will be 2n-1 spaces wide
    #the bottom floor will always be 2n-1 stars
    #each floor has 2floor-1 stars
    #each floor stars begin at n-(floor-1) and end at n+(floor-1)
    #spaces for each floor start are n-floor long
    
    
    pyramid=[]
    for floor in range(n_floors):
        spaces=(n_floors-(floor+1))*" "
        stars=(2*(floor+1)-1)*"*"
        pyramid.append(spaces+stars+spaces)
    return pyramid