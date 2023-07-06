/*
Write two functions that convert a roman numeral to and from an integer value. 
Multiple roman numeral values will be tested for each function.

Modern Roman numerals are written by expressing each digit separately starting
with the left most digit and skipping any digit with a value of zero. In Roman 
numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is 
written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in 
descending order: MDCLXVI.

Input range : 1 <= n < 4000

In this kata 4 should be represented as IV, NOT as IIII (the "watchmaker's four").
Examples

to roman:
2000 -> "MM"
1666 -> "MDCLXVI"
1000 -> "M"
 400 -> "CD"
  90 -> "XC"
  40 -> "XL"
   1 -> "I"

from roman:
"MM"      -> 2000
"MDCLXVI" -> 1666
"M"       -> 1000
"CD"      -> 400
"XC"      -> 90
"XL"      -> 40
"I"       -> 1

Help
Symbol 	Value
I 	    1
IV 	    4
V 	    5
X 	    10
L 	    50
C 	    100
D 	    500
M 	    1000
*/


#include <string>
#include <vector>
#include <unordered_map>

class RomanHelper{
  public:
    std::string to_roman(int n){
      //could probably use a map->refactor later
      std::vector<std::string> numeral={
        "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
        };
      std::vector<int> numbers={
        1000,900,500,400,100,90,50,40,10,9,5,4,1
        };
      
      std::string rn="";

      //There are 13 elements in each of our vectors we wish to iterate through.
      //while our number is greater than our numbers vector, we will continue
      //to add the the symbol from the numeral vector, subtracting that amount
      //from n with each iteration of the while loop.

      for(int x=0;x<13;x++){
        while(n>=numbers[x]){
          rn+=numeral[x];
          n-=numbers[x];
        }
      }
      
      return rn;
    }
    int from_roman(std::string rn){
        //creating a dictionary of our terms so we can iterate through the entire string
        //in one for loop. 
      std::unordered_map<char,int> map={
        {'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}
      };
      
      int sum=0, s=rn.size();

      //This loop can be a bit confusing. For each iteration we're taking our strings x element,
      //and mapping this to the unordered_map above. IE rn[x]='M' then map[rn[x]]={'M',1000}.
      //The two if statements are checks for our sum. the else statement is our normal condition:
      //IE rn="MMXI"-> 0+=map[rn[0]]={,1000}, 1000+=map[rn[1]]={,1000}, 2000+=...
      //the if statement is a catch for numerals like CM, IV, IX...
      //IE if rn="XIV"=> 0+=10, (if flag)-> I<V=> 10-=1=9, 9+=5->14="XIV"

      for(int x=0; x<s;x++){ 
        if(map[rn[x]]<map[rn[x+1]] && x+1<s) sum-=map[rn[x]];
        else sum+=map[rn[x]]; 
      }
      return sum;
    }
} RomanNumerals;

//There are plenty of ways to do this without needing things like vectors or maps. Here's another
//solution for converting rn to n. 
class RomanHelper{
    public:
    //...
    //...
    //...
    int from_roman(std::string rn){
      std::vector<int> n;
      
      for(auto x:rn){
         switch(x){
            case 'M':n.push_back(1000); break;
            case 'D':n.push_back(500); break;
            case 'C':n.push_back(100); break;
            case 'L':n.push_back(50); break;
            case 'X':n.push_back(10); break;
            case 'V':n.push_back(5); break;
            case 'I':n.push_back(1); break;
        }
      }
      
      
      int number=n.back(); //IE [1000,10,1] number=1;
      int s=n.size();
      
      for(auto x=0;x<s-1;x++){
        //the method mentioned earlier
        if(n[x]>=n[x+1]) number+=n[x]; 
        //IE [1000,500,10,1] num+=1000->+500->+10->+1==1511
        else number-=n[x];
        //IE [1000,500,1,10] num+=1000->+500->-1(1499)->+10==1509
      }
      return number;
} RomanNumerals;