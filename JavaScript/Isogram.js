/*
An isogram is a word that has no repeating letters, consecutive or non-consecutive. 
Implement a function that determines whether a string that contains only letters is an isogram. 
Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

isIsogram "Dermatoglyphics" = true
isIsogram "moose" = false
isIsogram "aba" = false
*/


//This was considered the most clever and best practices solution.
function isIsogram(str){
    return new Set(str.toLowerCase()).size==str.length;
  }

//The solution I came up with is nowhere near as elegant, but gets much more into
//the sausage of what's going on
function isIsogram(str){
    for(var x=0;x<str.length;x++){
      for(var y=x+1;y<str.length;y++){
        if(str[y].toLowerCase()==str[x].toLowerCase()){
          return false;
        }
      }
    }
    return true;
  }