/*
Complete the function so that it finds the average of the three scores
passed to it and returns the letter value associated with that grade.

Numerical Score 	Letter Grade

90 <= score <= 100 	'A'
80 <= score < 90 	'B'
70 <= score < 80 	'C'
60 <= score < 70 	'D'
0 <= score < 60 	'F'

Tested values are all between 0 and 100. Theres is no need to check for
negative values or values greater than 100.
*/

//The solution I came up with
char getGrade(int a, int b, int c) {
  int avg=(a+b+c)/3;
  
  return avg>=90 ? 'A':
         avg>=80 ? 'B':
         avg>=70 ? 'C':
         avg>=60 ? 'D':'F';
}

//the best practices solution by other users:
//markshark05, Vakulich, VladPavlik,
//Terrazas Carlos 6697806, IvanQC8620540,
//nippalapalli, jahnavideepthi, Ashok Bogisetti,
//kakanska, mohamedYousseif
char getGrade(int a, int b, int c) {
  int avg = (a + b + c) / 3;
  switch(avg){
  case 90 ... 100: return 'A';
  case 80 ... 89: return 'B';
  case 70 ... 79: return 'C';
  case 60 ... 69: return 'D';
  default: return 'F';
  }
}