/*
Write a function that checks if a given string (case insensitive) is a palindrome.
A palindrome is a word, number, phrase, or other sequence of symbols that reads
the same backwards as forwards, such as madam or racecar, the date and time
12/21/33 12:21, and the sentence:"A man, a plan, a canal – Panama".
*/

//for this I took advantage of JS built int functions. 
//.split('') to split each element in the string to an array
//.reverse() to reverse the elements of the array
//.join('') to rejoin each element in the array as a string
//.toLowerCase() to remove any conflicts on the capitalization of characters.
//then gave it a boolean return option
function isPalindrome(x) {
    return x.split('').reverse().join('').toLowerCase() === x.toLowerCase();
}