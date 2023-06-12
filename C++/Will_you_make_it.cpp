/*You were camping with your friends far away from home, but when it's time to go back, you realize that 
your fuel is running out and the nearest pump is 50 miles away! You know that on average, your car runs 
on about 25 miles per gallon. There are 2 gallons left.

Considering these factors, write a function that tells you if it is possible to get to the pump or not.

Function should return true if it is possible and false if not.
*/
//one of the biggest mistakes made are simple ones
bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left)
{
  return mpg*fuel_left>=distance_to_pump;
  //for example this could be written as| return distance/fuel<=mpg
  //however this will create floating point round offs, that could result in errors being generated
  //instead moving terms around so that division is not needed, we ensure no additional roudning errors when testing.
}
