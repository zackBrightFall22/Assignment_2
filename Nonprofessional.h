#include "Employee.h"

class Nonprofessional: public Employee{
private:
  int hours;
public:
  Nonprofessional(int hours);
  float calcSalary();
  float calcHealthCare();
  float calcVacation();
};
