/*
Implement a pseudo-encryption algorithm which given a string S and an integer N 
concatenates all the odd-indexed characters of S with all the even-indexed 
characters of S, this process should be repeated N times.

Examples:

encrypt("012345", 1)  =>  "135024"
encrypt("012345", 2)  =>  "135024"  ->  "304152"
encrypt("012345", 3)  =>  "135024"  ->  "304152"  ->  "012345"

encrypt("01234", 1)  =>  "13024"
encrypt("01234", 2)  =>  "13024"  ->  "32104"
encrypt("01234", 3)  =>  "13024"  ->  "32104"  ->  "20314"

Together with the encryption function, you should also implement a decryption 
function which reverses the process.

If the string S is an empty value or the integer N is not positive, return the 
first argument without changes.
*/

//Full transparency| this problem proved to be a real challenge despit its simplicity
//The first half was a typical intermediate problem, taking about 10-15 minutes to solve
//if that. However, the second half of the problem(decryption) had me running in circles 
//for hours. Had I stuck with the problem I likely would have solved it, but for the sake
//of brevity I looked up a solution to the problem. Future problems on here may focus more
//on this type of problem, as I continue to hone and perfect my craft. 
#include <string>
std::string encrypt(std::string text, int n)
{
  std::string odd, even;
  if(n<=0)
    return text;
  for(unsigned x=0;x<n;x++){
    for(unsigned y=0;y<text.size();y++){
      if(y%2!=0)
        odd+=text[y];
      else
        even+=text[y];
    }
    text=odd+even;
    odd="";
    even="";
  }
  return text;
}

//Full credit for this half goes to IronAttorney
std::string decrypt(std::string encryptedText, int n)
{
    if (n <= 0) return encryptedText;
    
    
    const unsigned stringSizeHalf = encryptedText.size()/2;
    
    for (unsigned i = 0; i < n; i++) 
    {
        std::string dText;
        
        for (unsigned j = 0; j < stringSizeHalf; j++) 
        {
            dText.push_back(encryptedText[j+stringSizeHalf]);
            dText.push_back(encryptedText[j]);
        }
        
        if (encryptedText.size() & 1)
            dText.push_back(encryptedText[encryptedText.size() - 1]);
            
        encryptedText = dText;
    }
 
    return encryptedText;
}