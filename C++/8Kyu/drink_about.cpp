/*

    Kids drink toddy.
    Teens drink coke.
    Young adults drink beer.
    Adults drink whisky.

Make a function that receive age, and return what they drink.

Rules:

    Children under 14 old.
    Teens under 18 old.
    Young under 21 old.
    Adults have 21 or more.

*/

#include <string>

std::string people_with_age_drink(int age) {
  return (age<14 ? "drink toddy":
          age<18 ? "drink coke":
          age<21 ? "drink beer":"drink whisky");
}
//this is the equivelent of saying if<14|else if<18...else drink whisky