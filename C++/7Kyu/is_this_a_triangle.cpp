/*
Implement a function that accepts 3 integer values a, b, c. The function should
return true if a triangle can be built with the sides of given length and false 
in any other case.

(In this case, all triangles must have surface greater than 0 to be accepted).
*/

//right off the bat, this kata fails to properly describe or link to the problem
//they wish solved. Possibly because the author thought it might give it away.
//Either way, consider this an excersise in researching what a client wants
//when they are unable to describe what they want. Google tells us this is the
//triangle inequality theorem: https://en.wikipedia.org/wiki/Triangle_inequality
//Given some of the tests thrown, our initial values should be longs, no matter-> 

#include <vector>
#include <algorithm>
namespace Triangle
{
  bool isTriangle(int a, int b, int c)
  { 
    //creating a vector and sorting it->if the two smaller sides are less than
    //the largest, a triangle cannot be formed and we return false|true otherwise. 
    std::vector <long> v={a,b,c};
    std::sort(v.begin(),v.end());
    
    return((v[0]+v[1])>v[2]);
  }
};