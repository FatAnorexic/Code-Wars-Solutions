/*Write a function to convert a name into initials. This kata strictly takes two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

Sam Harris => S.H

patrick feeney => P.F
*/

function abbrevName(name){
  var initial=[name[0]]
  for(let x=0; x<name.length;x++){
    if(name[x] === " "){
      initial.push(name[x+1]);
    }
  }
  return initial.map(el=>el.toUpperCase()).join(".");
}
