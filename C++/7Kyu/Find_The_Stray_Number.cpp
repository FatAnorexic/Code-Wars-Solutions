//You are given an odd-length array of integers, in which all of them are the same, except for one single number.

//Complete the method which accepts such an array, and returns that single different number.

//The input array will always be valid! (odd-length >= 3)

int stray(std::vector<int> numbers) {
    int outlier;
    for(unsigned long x=0;x<numbers.size();x++){
      //Just check the previous and future number against the current number in the vector. 
      if(numbers[x]!=numbers[x-1] && numbers[x]!=numbers[x+1])
        outlier=numbers[x];
    }
    return outlier;
};
