/*
In this kata we want to convert a string into an integer. The strings simply represent 
the numbers in words.

Examples:

    "one" => 1
    "twenty" => 20
    "two hundred forty-six" => 246
    "seven hundred eighty-three thousand nine hundred and nineteen" => 783919

Additional Notes:

    The minimum number is "zero" (inclusively)
    The maximum number, which must be supported is 1 million (inclusively)
    The "and" in e.g. "one hundred and twenty-four" is optional, in some cases it's 
    present and in others it's not
    All tested numbers are valid, you don't need to validate them
*/


#include <string>
#include <vector>

//My original solution with algorithm from: 7097511, srdalvi08@gmail.com
long parse_int(std::string number) {

    //This could be a map, which would save the need for a nested loop down the road.
  std::vector<std::string> word={
    "zero","one","two","three","four","five","six","seven","eight",
    "nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen","twenty","thirty",
    "forty","fifty","sixty","seventy","eighty","ninety","hundred",
    "thousand","million"
  };
  
  std::vector<int> digit={
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
    30,40,50,60,70,80,90,100,1000,1000000
  };
  //A vector for storing each imporatant word, along with an a vector for carrying an ordered
  //conversion of terms.
  std::vector<std::string> convert;
  std::vector<int> arr;
  std::string c="";
  
  //converting string to a list of words. 
  for(int x=0; x<=number.size();x++){
    if(number[x]==' '|| number[x]=='-'||x==number.size()){
      convert.push_back(c);
      c="";
    }
    else
      c+=number[x];
  }
  
  //double loop to map to an independent array
  //this will generate a list of ordered terms in the form of
  //numerical digits IE twenty thousand seven hundred sixty five->
  //[20,1000,7,100,60,5]
  for(int x=0;x<convert.size();x++){
    for(int y=0;y<word.size();y++){
      if(convert[x]==word[y])
        arr.push_back(digit[y]);
    }
  }
  
  long numb=0;
  //this is the algorithm I could not get correct orginally|sometimes it's important to not
  //overthink the problem. 
  for(int i=0;i<arr.size();i++){
    
    if(arr[i]>0 && arr[i]<100) numb+=arr[i];

    else if(arr[i]==1000 || arr[i]==1000000) numb*=arr[i];
    
    //This one may be confusing->[20,1000,7,100] 20007%100->7*99->693+20007=20700
    else if(arr[i]==100) numb+=99*(numb%100);
  }
  return numb;
}