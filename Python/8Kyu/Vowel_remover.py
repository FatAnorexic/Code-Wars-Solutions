"""
Create a function called shortcut to remove the lowercase vowels (a, e, i, o, u ) in a given string.

Examples
"hello"     -->  "hll"
"codewars"  -->  "cdwrs"
"goodbye"   -->  "gdby"
"HELLO"     -->  "HELLO"
don't worry about uppercase vowels
y is not considered a vowel for this kata
"""

#The best practices solution based on the highest votes

def shortcut( s ):
    return ''.join(c for c in s if c not in 'aeiou')

#for a more in depth approach
def shortcut( s ):
    lower_case=['a','e','i','o','u']
    newstr=''
    for i in range(len(s)):
        if(s[i] not in lower_case):
            newstr+=s[i]
    return newstr
