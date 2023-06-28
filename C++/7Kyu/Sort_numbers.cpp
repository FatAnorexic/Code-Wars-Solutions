/*
Finish the solution so that it sorts the passed in array of numbers. If the function 
passes in an empty array or null/nil value then it should return an empty array.

For example:

sortNumbers({1, 2, 10, 50, 5}) // sholud return {1, 2, 5, 10, 50}
sortNumbers({}) // should return {}
*/

#include <vector>

std::vector<int> solution(std::vector<int> nums) {
  
  int minI, minVal;
  //if we're passed an empty list, we immediatly return the list
  //This is to prevent any errors occuring when looping using sel sort.
  if(nums.size()==0){
    return nums;
  }
  //Sel sort is a go to for me. While not the fastest, it is definitely beginner friendly
  //and pretty good for what it is. 
  for(unsigned long x=0;x<(nums.size()-1);x++){
  
    minI=x;
    minVal=nums[x];
  
    for(unsigned long y=x+1; y<nums.size();y++){
    
      if(nums[y]<minVal){
        minVal=nums[y];
        minI=y;
      }
    }
    
    nums[minI]=nums[x];
    nums[x]=minVal;
  }
  
  return nums;
}


//now something that's a bit better practice and more efficient
#include <algorithm>
std::vector<int> solution(std::vector<int> nums){
    std::sort(nums.begin(), nums.end());
    return nums;
}