/*
Complete the solution so that it returns true if the first argument(string) passed 
in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false

*/

#include <string>
bool solution(std::string const &str, std::string const &ending) {
    return str.size()>=ending.size() && str.compare(str.size()-ending.size(),std::string::npos,ending)==0;
}

//Another perfectly acceptable solution
bool solution(std::string const &str, std::string const &ending) {
    if(ending.size()>str.size())
      return false;
    return std::equal(ending.rbegin(),ending.rend(), str.rbegin());
}