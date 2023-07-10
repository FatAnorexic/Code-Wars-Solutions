/*
In this Kata we are passing a number (n) into a function.

Your code will determine if the number passed is even (or not).

The function needs to return either a true or false.

Numbers may be positive or negative, integers or floats.

Floats with decimal part non equal to zero are considered UNeven for this kata.
*/

//My solution made use of the modf module for c++. A link to documentation:
//https://cplusplus.com/reference/cmath/modf/

#include <math.h>

bool is_even(double n)
{
  double temp;
  //the modf function is used to deduce if n has a fractional component
  //and returns false if it does.
  if(modf(n, &temp)!=0)
    return false;
  return int(n)%2==0; //converts n to int if it passed the first test|
  //uses modulous division to see if n is even
}

//the best practices solution ranked highest on codewars:
#include <cmath>

bool is_even(double n){
    return fmod(n,2)==0;
}