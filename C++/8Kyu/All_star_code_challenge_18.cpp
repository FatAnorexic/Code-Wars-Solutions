/*
Create a function that accepts a string and a single character, and returns an 
integer of the count of occurrences the 2nd argument is found in the first one.

If no occurrences can be found, a count of 0 should be returned.

("Hello", "o")  ==>  1
("Hello", "l")  ==>  2
("", "z")       ==>  0

str_count("Hello", 'o'); // returns 1
str_count("Hello", 'l'); // returns 2
str_count("", 'z'); // returns 0

*/

//A standard practice for such a scenario
#include <string>

unsigned int strCount(const std::string& word, char letter){
  return std::count(word.begin(),word.end(), letter);
}

//This is a more intuitive solution
unsigned int strCount(const std::string& word, char letter){
    //this is one of the few instances where I feel the code is documentation enough as
    //to what's going on. 
  int count=0, s=word.size();

  for(int x=0;x<s;x++){
    if(letter==word[x])
      count++;
  }
  return count;
}