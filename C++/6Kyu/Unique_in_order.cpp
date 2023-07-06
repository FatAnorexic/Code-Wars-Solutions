/*
Implement the function unique_in_order which takes as argument a sequence and returns a list 
of items without any elements with the same value next to each other and preserving the 
original order of elements.

For example:

uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}

*/

#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  //we'll make a copy vector that duplicates and appends each non repeating element
  std::vector<T> copy;
  int size=iterable.size();
  
  for(int x=0;x<size;x++){
    if(iterable[x]!=iterable[x+1])
      copy.push_back(iterable[x]);
  }
  
  return copy;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
  //we'll do the same here, but with a char vector
  std::vector<char> copy;
  int size=iterable.size();
  
  for(int x=0;x<size;x++){
    if(iterable[x]!=iterable[x+1])
      copy.push_back(iterable[x]);
  }
  
  return copy;
}