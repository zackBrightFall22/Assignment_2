#include "Professional.h"

Professional::Professional(int years){
  yearsWorked = years;
  vacation = 0;
  healthcare = 0;
}

float Professional::calcSalary(){
  //Salary based on seniority. Fun fact: My friend interviewed with Raytheon and they have a payscale based on seniortiy, so this seems realistic enough to me
  if (yearsWorked <= 1)
    return 2000;
  else if (yearsWorked <= 3)
    return 2500;
  else if (yearsWorked <= 5)
    return 3500;
  else
    return 4500;
}

float Professional::calcHealthCare(){
  // I kind of just made numbers up here based on my limited experince with employer healthcare
  if (yearsWorked <= 1)
    return 150;
  else if (yearsWorked <= 3)
    return 200;
  else if (yearsWorked <= 5)
    return 300;
  else
    return 350;
}

float Professional::calcVacation(){
  // About 3 weeks vacation for beginning employees, up to about a month once you have worked 5 years. Seems reasonable, maybe too idealistic
  if (yearsWorked <= 1)
    return 0.4;
  else if (yearsWorked <= 3)
    return 0.5;
  else if (yearsWorked <= 5)
    return 0.55;
  else
    return .6;
}