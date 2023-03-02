// Zack Bright
// zmbrfq@umsystem.edu
// CS303 Assignment 2
// Due Mar 6 2023

#include <iostream>
#include "Linked.h"
#include "Professional.h"
#include "Nonprofessional.h"
using namespace std;
#include <string>


int main() {

 /* Problem 1 */
  cout << "Problem 1 Output\n\n";

  // Instantiate new list of names
  Linked students;
// check if empty, should return true
  cout << students.empty() << "\n";
  // add some names to the list
  students.push_back("Zack");
  students.push_front("Harman");
  students.push_back("Rye");
  students.push_back("Monica");
  //check if empty again, should return false
  cout << students.empty() << "\n\n";
  // check front() returns Harman and back() returns Monica
  cout << students.front() << "\n";
  cout << students.back() << "\n\n";
  // pop some names from the list
  students.pop_back();
  students.pop_front();
  // check front() and back() return correct values given removal of old front and back
  cout << students.front() << "\n";
  cout << students.back() << "\n\n";

  // Check insert in middle of list works
  students.insert(1, "Jackson");
  // Check insert beyond end of list works
  students.insert(20, "Melody");
  // check find() works when name is in the list, should return index
  cout << students.find("Jackson") << "\n";
  // remove a student
  students.remove(1);
  // check that find() works when name is not in list, should return num_items
  cout << students.find("Jackson") << "\n\n";

  // I added this function to print the list
  students.printList();

  /* Problem 2 */
  cout << "\n\n\nProblem 2 Output\n\n";

  //Instantiate professional employee, set variables using defined virtual classes
  Professional manager(3);
  manager.setSalary(manager.calcSalary());
  manager.setHealthcare(manager.calcHealthCare());
  manager.setVacation(manager.calcVacation());
  //Output values test
  cout << "This week's gross pay: $" << manager.getSalary() << "\nHealth Care contributions this week: " << manager.getHealthCare() << "\nVacation days earned this week: " << manager.getVacation();

  cout << "\n\n";

  //Instantiate nonprofessional employee, set variables using defined virtual classes
  Nonprofessional cashier(38);
  cashier.setSalary(cashier.calcSalary());
  cashier.setHealthcare(cashier.calcHealthCare());
  cashier.setVacation(cashier.calcVacation());
  //Output values test
  cout << "This week's gross pay: $" << cashier.getSalary() << "\nHealth Care contributions this week: " << cashier.getHealthCare() << "\nVacation days earned this week: " << cashier.getVacation(); 

}