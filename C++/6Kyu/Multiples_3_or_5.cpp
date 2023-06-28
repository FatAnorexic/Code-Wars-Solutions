/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in. Additionally, if the number 
is negative, return 0 (for languages that do have them).

Note: If the number is a multiple of both 3 and 5, only count it once.*/



int solution(int number) 
{
  int sum=0;  //set sum to 0, since our loop starts at 0, if number is negative, the loop will fail to execute and will return 0.
  for(int x=0;x<number;x++){
    if(x%3==0 || x%5==0)
      sum+=x;
  }
  return sum;
}
