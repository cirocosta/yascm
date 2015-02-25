#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
  Base();
  virtual ~Base();
  // two-phase initialization
  virtual void init();
  // making it 'abstract'
  virtual void printClassName() = 0;
};

class Derived : public Base
{
public:
  Derived();
  virtual ~Derived();
  virtual void printClassName();
};

Base::Base () {}
void Base::init () {this->printClassName();}
Base::~Base() {}

Derived::Derived () : Base() {this->init();}
Derived::~Derived () {}
void Derived::printClassName () {cout << "Derived" << endl; }

int main(int argc, char const *argv[])
{
  /* code */
  Derived * d = new Derived();

  delete d;

  return 0;
}
