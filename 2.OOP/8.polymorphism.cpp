#include <iostream>

using namespace std;

class One {

public:

  // Without virtual, a base-class pointer will call the base class's method,
  // even if the pointer is actually pointing to a child-class object.
  virtual void intro() { cout << "I am one" << endl; }
};

class Two : public One {

public:
  // Overrides One::intro().
  void intro() { cout << "I am two" << endl; }
};

class Three : public One {

public:
  // Overrides One::intro().
  void intro() { cout << "I am three" << endl; }
};

int main() {

  One a;
  Two b;
  Three c;

  // Normal polymorphism:
  // Each object calls its own version of intro().
  a.intro();
  b.intro();
  c.intro();

  // Base-class pointer.
  One *x;

  // x is pointing to a Two object.
  x = &b;

  // Because intro() is virtual,
  // Two's version is called.
  x->intro();

  // Now x points to a Three object.
  x = &c;

  // Because intro() is virtual,
  // Three's version is called.
  x->intro();

  return 0;
}