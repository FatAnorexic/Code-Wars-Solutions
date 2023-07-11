/*
How can you tell an extrovert from an introvert at NSA?
Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.

I found this joke on USENET, but the punchline is scrambled. Maybe you can decipher it?
According to Wikipedia, ROT13 is frequently used to obfuscate jokes on USENET.

For this task you're only supposed to substitute characters. Not spaces, punctuation, numbers, etc.

Test examples:

"EBG13 rknzcyr." -> "ROT13 example."

"This is my first ROT13 excercise!" -> "Guvf vf zl svefg EBG13 rkprepvfr!"
*/

//Another encryption algorithm to solve: I found this one much more approachable.

#include <string>



std::string rot13(const std::string& str) {
  std::string decrypt="";
  
  //we check if the character is alpha of upper or lower
  //we then subtract 13 characters back, take the remainder of 26,
  //and shift it that many characters forward.
  //if it is not alpha, we simply add that element to the decrypt string. 
  for(auto x=0;x<str.length();x++){
    if(isupper(str[x]))
      decrypt+=(str[x]-'A'+13)%26+'A';
    else if(islower(str[x]))
      decrypt+=(str[x]-'a'+13)%26+'a';
    else
      decrypt+=str[x];
  }
  return decrypt;
}