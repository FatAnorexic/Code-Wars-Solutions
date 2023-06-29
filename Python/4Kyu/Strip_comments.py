"""
Complete the solution so that it strips all text that follows any of a set of comment 
markers passed in. Any whitespace at the end of the line should also be stripped out.

Example:

Given an input string of:

apples, pears # and bananas
grapes
bananas !apples

The output expected would be:

apples, pears
grapes
bananas

The code would be called like so:

result = solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"])
# result should == "apples, pears\ngrapes\nbananas"
"""

#This one can trip you up if you're not careful.
def strip_comments(strng, markers):
    list=strng.split('\n') #split the string into an array with each new line as the indexer
    
    for x in markers:
       
        #some of the tests have leading spaces. this is why we are using right strip
        #to delete any trailing spaces. had this function called for only leading
        #spaces to be removed, we could have simply used lstrip() 
        list=[y.split(x)[0].rstrip() for y in list]
    
    return '\n'.join(list)
