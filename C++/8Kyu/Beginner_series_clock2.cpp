/*
Clock shows h hours, m minutes and s seconds after midnight.

Your task is to write a function which returns the time since midnight in milliseconds.
Example:

h = 0
m = 1
s = 1

result = 61000

Input constraints:

    0 <= h <= 23
    0 <= m <= 59
    0 <= s <= 59
*/

//There are a 1000 miliseconds per second, 60 seconds per minute, and 60 minutes per hour(60*60)
int past(int h, int m, int s) {
  return 1000*(s+m*60+h*60*60);
}