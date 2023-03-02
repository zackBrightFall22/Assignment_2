#include "Nonprofessional.h"

Nonprofessional::Nonprofessional(int h){
  hours = h;
}

float Nonprofessional::calcSalary(){
  //Weekly pay is $25 an hour
  return hours * 25;
}

float Nonprofessional::calcHealthCare(){
  //weekly HC contribution is 10% of gross pay
  return 0.10 * (hours * 25);
}

float Nonprofessional::calcVacation(){
  // One week of vacation per year for part time, 2 weeks per year for full time
  if (hours < 35)
    return 0.13;
  else
    return 0.26;
}