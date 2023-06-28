/*
You are given an array (which will have a length of at least 3, but could be very large) 
containing integers. The array is either entirely comprised of odd integers or entirely 
comprised of even integers except for a single integer N. Write a method that takes the 
array as an argument and returns this "outlier" N.
Examples

[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
*/

function findOutlier(integers){
    //creating two seperate lists of even and odd numbers
  let odd=integers.filter(function(integers){
    return integers%2!=0
  });
  //this is similar to list comprehension with python
  let even=integers.filter(function(integers){
    return integers%2==0
  });
  //The smallest array wins
  return (odd.length<even.length ? odd[0]:even[0]);
}

//similarly a much cleaner version would look like:
function findOutlier(integers){
    let odd=integers.filter(x=>x%2!=0);
    let even=integers.filter(x=>x%2==0);
    return (odd.length<even.length ? odd[0]:even[0]);
}
