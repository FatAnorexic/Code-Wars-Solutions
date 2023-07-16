/*
Your task is to write a function which returns the sum of following
series upto nth term(parameter).

Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...

Rules:

    You need to round the answer to 2 decimal places and return it
    as String.

    If the given value is 0 then it should return 0.00

    You will only be given Natural Numbers as arguments.

Examples:(Input --> Output)

1 --> 1 --> "1.00"
2 --> 1 + 1/4 --> "1.25"
5 --> 1 + 1/4 + 1/7 + 1/10 + 1/13 --> "1.57"
*/

//once again there are so many ways to approach this 
//from using methods like round,ceil, and floor->
//to developing your own rounding algorithm
//since the it's asking for a string to be returned
//I decided the the best approach was to use a string stream
//along with io manipulation to set the precision and fixed 
//position of the decimal place.

//first, what is this algorithm? Running through the first few
//terms shows us its 1/1+1/4+1/7+1/10... 3 is added to the
//denominator each term.

#include <sstream>
#include <string>
#include <iomanip>
std::string seriesSum(int n){
  //if n is 0 or some negative number->immediately throw "0.00"
  //this prevents us from bloating memory with unecessary variables.
  if(n<=0)
    return "0.00";
  
  double numerator=1, denominator=1, series=0;
  
  for(int x=0;x<n;x++){
    series+=numerator/denominator;
    denominator+=3;
  }
  
  std::stringstream stream;
  stream<<std::fixed<<std::setprecision(2)<<series;
  std::string sum=stream.str();
  return sum;
}