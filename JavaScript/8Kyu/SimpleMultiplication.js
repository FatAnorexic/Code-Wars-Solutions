//This kata is about multiplying a given number by eight if it is an even number and by nine otherwise.
function simpleMultiplication(number) {
    return number*(number%2? 9:8);
}

//More legible solution
function simpleMultiplication(number) {
    if(number % 2 === 0){
      return 8 * number;
    }
  return 9 * number;
}
