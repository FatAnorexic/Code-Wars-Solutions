/*
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 
4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.
*/

//Once again, I turn to selection sort to order our list, then return the sum of the first two elements
//of the ordered list. However, a much more elegant soltion and possibly faster one is listed below this function
function sumTwoSmallestNumbers(numbers) {  
  var  minIndex=0, minVal=0;
  
  for(let x=0;x<numbers.length-1;x+=1){
    
    minIndex=x
    minVal=numbers[x]
    
    for(let y=x+1;y<numbers.length;y+=1){
      
      if(numbers[y]<minVal){
        
        minVal=numbers[y];
        minIndex=y;
        
      }
    }
    
    numbers[minIndex]=numbers[x];
    numbers[x]=minVal;
  }
  return numbers[0]+numbers[1];
}

//Better practice 
function sumTwoSmallestNumbers(numbers) {  
  numbers=numbers.sort(function(a,b){return a-b;});
  return numbers[0]+numbers[1];
}
