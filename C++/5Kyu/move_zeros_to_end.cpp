/*
Write an algorithm that takes an array and moves all of the zeros to the end,
preserving the order of the other elements.
move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
*/

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> move_zeroes(const std::vector<int>& input) {
  //We'll use the partitioning approach
  int size=input.size(), y=0;

  //creating a copy as they've declared our input as a const. Also, input is being passed
  //by reference. to avoid any memory issues, it's best to make a copy. 
  std::vector<int> copy;
  
  for(int i=0; i<size;i++)
    copy.push_back(input[i]);
  
  //for each of the elements in our copy, we will check to see if they are 0|
  //If they are not zero, the swap method will be called, moving each element 
  //to the left, except zero, through the loop. the end result will be
  //a vector array of all elements in their original order, save for the 0's
  //which will all occupy the last elements in the array. 

  for(int x=0;x<size;x++){
    if(copy[x]!=0){
      std::swap(copy[y], copy[x]);
      y++;
    }
  }
  return copy;
}