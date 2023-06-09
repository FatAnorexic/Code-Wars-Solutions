"""Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the 
"instructions" for the development and functioning of living organisms.

If you want to know more: http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". 
Your function receives one side of the DNA (string, except for Haskell); you need to 
return the other complementary side. DNA strand is never empty or there is no DNA at 
all (again, except for Haskell).

More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)"""

def DNA_strand(dna):
    compliment=''
    for i in range(len(dna)):
        if dna[i]=='A':
            compliment+='T'
        elif dna[i]=='T':
            compliment+='A'
        elif dna[i]=='G':
            compliment+='C'
        elif dna[i]=='C':
            compliment+='G'
    return compliment

#Another solution, though not as elementary is to create a dictionary and return 
#The string using .join() method and list comprhension
def DNA_strand(dna):
    pairs={'A':'T', 'T':'A', 'G':'C', 'C':'G'}
    return ''.join([pairs[x] for x in dna])
