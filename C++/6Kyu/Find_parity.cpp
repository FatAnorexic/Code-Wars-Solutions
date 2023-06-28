/*
You are given an array (which will have a length of at least 3, but could be very large) 
containing integers. The array is either entirely comprised of odd integers or entirely 
comprised of even integers except for a single integer N. Write a method that takes the 
array as an argument and returns this "outlier" N.
Examples

[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
*/
#include <vector>

int FindOutlier(std::vector<int> arr){
    //creating two vectors to hold an array of odds n evens. 
  std::vector<int> odd;
  std::vector<int> even;
  //When using a for loop with a vector, I always assign unsigned long to our counter
  //this is to avoid any warnings of conflicting data types at runtime. 
  for(unsigned long x=0;x<arr.size();x++){
    if(arr[x]%2!=0)
      odd.push_back(arr[x]);
    else
      even.push_back(arr[x]);
  }
  //using the short hand of an if else statment.
  return (odd.size()<even.size() ? odd[0]:even[0]);
}

//upon review i realized I could make this even shorter
int FindOutlier(std::vector<int> arr)
{
  std::vector<int> odd; 
  std::vector<int> even;
  //Same as before, but this time we use this shorthand for loop for immediate comparisons. 
  for (auto x:arr){
    x %2==0 ? even.push_back(x):odd.push_back(x);
  }
  return (odd.size()<even.size() ? odd[0]:even[0]);
}