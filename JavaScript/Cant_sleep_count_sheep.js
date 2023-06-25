/*
If you can't sleep, just count sheep!!
Task:
Given a non-negative integer, 3 for example, return a string with a murmur:
 "1 sheep...2 sheep...3 sheep...". Input will always be valid, i.e. no negative integers
 */

 var countSheep = function (num){
    str=""
    for(var x=0;x<num;x+=1){
        //I'm taking the nth element in our loop, adding 1 and converting it to a string
        //then adding that to another string called sheep, and this all gets appended
        //to the string declared initially as str. Technically it should be let str=""
      str+=String(x+1)+" sheep...";
    }
    return str;
  }