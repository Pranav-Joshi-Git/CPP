#include <iostream>
#include <string>

using namespace std;

class Phone {

  // Default values for data members.
  string _name = "";
  string _os = "";
  int _price = 0;

public:

  // Default constructor
  // If this constructor is moved to the private section,
  // objects cannot be created using: Phone samsungA1;
  // The caller must use a public constructor that accepts parameters.
  // This can be useful when we want to prevent creating objects
  // with default/ambiguous values.
  Phone();

  // Parameterized constructor
  Phone(const string &name, const string &os, const int &price);

  // Copy constructor
  Phone(const Phone &other);

  string getName() const {
    return _name;
  }

  // Destructor
  ~Phone();
};


// Default constructor
// In-class initializers provide the default values.
Phone::Phone() {
  cout << "Default constructor fired" << endl;
}


// Parameterized constructor
Phone::Phone(const string &name, const string &os, const int &price)
    : _name(name), _os(os), _price(price) {

  cout << "Parameterized constructor fired" << endl;
}


// Copy constructor
// Creates a new object by copying another Phone object.
Phone::Phone(const Phone &other)
    : _name(other._name),
      _os(other._os),
      _price(other._price) {

  cout << "Copy constructor fired" << endl;
}


// Destructor
// Automatically called when an object is destroyed.
Phone::~Phone() {
  cout << "Destructor called for " << _name << endl;
}


// ! Go through this:
// https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three

int main() {

  // Uses the default constructor.
  // Default values from the class are used.
  Phone samsungA1;

  cout << samsungA1.getName() << endl; // will return empty line


  // Uses the parameterized constructor.
  Phone onePlus8("One Plus 8", "Android Oxy", 799);

  cout << onePlus8.getName() << endl;


  // Uses the copy constructor.
  // Creates onePlus8s as a copy of onePlus8.
  Phone onePlus8s = onePlus8;


  // Destructor is automatically called when objects
  // go out of scope, usually in reverse order of creation.

  return 0;
}