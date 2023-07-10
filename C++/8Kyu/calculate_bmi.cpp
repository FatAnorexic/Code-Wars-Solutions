/*
Write function bmi that calculates body mass index (bmi = weight / height2).

if bmi <= 18.5 return "Underweight"

if bmi <= 25.0 return "Normal"

if bmi <= 30.0 return "Overweight"

if bmi > 30 return "Obese"
*/

//no need to get fancy, just clean execution on a few if statements. 1
std::string bmi(double w, double h){
    double bmi=w/h/h;   //to avoid any floating point inaccuracy with w/(h*h)

    if(bmi<=18.5) return "Underweight";
    if(bmi<=25.0) return "Normal";
    if(bmi<=30.0) return "Overweight";

    return "Obese";
}