/*
Character recognition software is widely used to digitise printed texts.
Thus the texts can be edited, searched and stored on a computer.

When documents (especially pretty old ones written with a typewriter),
are digitised character recognition softwares often make mistakes.

Your task is correct the errors in the digitised text. You only have to
handle the following mistakes:

    S is misinterpreted as 5
    O is misinterpreted as 0
    I is misinterpreted as 1

The test cases contain numbers only by mistake
*/

//The inital solution I had was to use a simple for loop with conditional
//statments
function correct(string)
{
  let newstr="";
	for(var x=0;x<string.length;x++){
    if(string[x]==="5"){
      newstr+="S";
    }else if(string[x]==="0"){
      newstr+="O"
    }else if(string[x]==="1"){
      newstr+="I";
    }else{
      newstr+=string[x];
    }
  }
  return newstr;
}

//While legible to anyone whose played with code a little, this is extremely 
//ammature and shows I have much to learn about the syntax of JS. To that end
//the replace method can be used such that it finds each instance in a string
//and replaces it with the new input->string.replace(serchterm, replacement)
//and this search term can be implemented over the totallity of the string 
//with /word/g:where g is used as a modifier to indicated global replacement.
//Further this can be stacked:
function correct(string){
    return string.replace(/0/g,'O').replace(/5/g,'S').replace(/1/g,'I');
}