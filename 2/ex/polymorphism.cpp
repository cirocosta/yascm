#include <iostream>

using namespace std;

class Employee {
public:
  Employee(string aName, float aPayRate)
    : name(aName), payRate(aPayRate) {};

  string getName() const;
  float getPayRate() const;

  virtual float pay(float hoursWorked) const;
protected:
  string name;
  float payRate;
};

string Employee::getName() const
{
  return name;
}

float Employee::getPayRate () const
{
  return payRate;
}

float Employee::pay (float hoursWorked) const
{
  return hoursWorked * payRate;
}


class Manager : public Employee {
public:
  Manager(string aName,
          float aPayRate,
          bool isSalaried) :
  Employee(aName, aPayRate), salaried(isSalaried) {};

  bool getSalaried () const;
  virtual float pay(float hoursWorked) const;
protected:
  bool salaried;
};

bool Manager::getSalaried () const
{
  return salaried;
}

float Manager::pay (float hoursWorked) const
{
  cout << "Manager::pay called!" << endl;

  if (salaried)
    return payRate;

  return Employee::pay(hoursWorked);
}


int main(int argc, char const *argv[])
{
  Employee *empl;

  empl = new Manager("name", .3, true);
  cout << "Name: " << empl->getName() << endl;
  cout << "Payed: " << empl->pay(20.3) << endl;



  return 0;
}
