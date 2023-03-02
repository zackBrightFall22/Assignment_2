#include "Employee.h"

class Professional: public Employee{
private:
  int yearsWorked;
public:
  Professional(int yearsWorked);
  float calcSalary();
  float calcHealthCare();
  float calcVacation();
};