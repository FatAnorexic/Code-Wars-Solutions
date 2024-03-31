# Count the number of Duplicates

Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

## Example

"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice

---
# Solutions

```Python
'''
Returns the number of duplicate characters in a string of alpha numerical string.
It does this by taking the length of a set from an array compiled via list comprhension.
The list checks each character in the lower case, and if its count is more than one, it
appends it to the list.
'''
def duplicate_count(text):
    return len(set([x.lower() for x in text if text.lower().count(x.lower()) > 1]))
```

```Python
'''
Another more intuitive solution is as follows. While it does the same thing as the previous
solution, beginners may find the code more legible and understandable. 
'''
def duplicate_count(text):
    count=[]
    for x in text:
        if text.lower().count(x.lower())>1:
            count.append(x.lower)
    return len(set(count))
```