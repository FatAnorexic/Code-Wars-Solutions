/*
Your task is to write function factorial.

https://en.wikipedia.org/wiki/Factorial
*/

//one way to go about this would be to simply create a variable
//and multiply it by n while reducing n by one each loop, so long
//as n>1
long long factorial(int n){
  long fact=1;
  while(n>1){
    fact*=n;
    n--;
  }
  return fact; // Insert brilliant solution here
}

//another is to use recursion
long long factorial(int n){
    return n>0 ? n*factorial(n-1):1;
}