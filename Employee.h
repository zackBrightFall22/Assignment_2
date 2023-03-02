#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Base abstract class
class Employee{
protected:
  float salary;
  float healthcare;
  float vacation;
public:
// Pure virtual functions to be implemented in derived classes
  virtual float calcSalary() = 0;
  virtual float calcHealthCare() = 0;
  virtual float calcVacation() = 0;
//Setters and getters
  float getSalary() {return salary;}
  float getHealthCare() {return healthcare;}
  float getVacation() {return vacation;}
  void setSalary(float s) {salary = s;}
  void setVacation(float v) {vacation = v;}
  void setHealthcare(float h) {healthcare = h;}

};

