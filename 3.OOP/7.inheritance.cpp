#include <iostream>
#include <string>

using namespace std;


class Money {

public:
    void gotMoney(){
        cout << "Got 5k USD in my account" << endl;
    }

};

class Man {

    string _name;
    int _age;

    // Private by default.
    // Making the default constructor private means
    // a Man object cannot be created directly with Man man;
    Man() {}


    // Friend gives Superman direct access to Man's private members.
    // Normally, Superman cannot access _age because _age is private.
    //
    // Friend should be used carefully because it weakens encapsulation.
    // Prefer getters/setters or protected members when they are enough
    // to provide the required access.
    friend class Superman;


protected:

    // Protected members can be accessed by the class
    // and its child/inherited classes.
    Man(const string &name, const int &age)
        : _name(name), _age(age) {}

    void run() {
        cout << "I can run" << endl;
    }


public:

    void sayName() const;
};


// Method defined outside the class.
void Man::sayName() const {
    cout << "My name is: " << _name
         << " and age is: " << _age << endl;
}


// Superman inherits from Man.
class Superman : public Man {

    bool _flight;

public:

    // Calls the protected Man constructor.
    Superman(const string &name)
        : Man(name, 26) {}

    // Overriding the inherited run() method.
    //
    // _age is private in Man, but Superman can access it
    // because Superman is declared as a friend of Man.
    void run() {
        cout << "I can run at light speed at age: " << _age << endl;
    }
};


// Spiderman also inherits from Man.
class Spiderman : public Man, public Money { //Multiple inheritance

    bool _webbing;

public:

    // Calls the protected Man constructor.
    Spiderman(const string &name)
        : Man(name, 19) {}

    // Overriding the inherited run() method.
    void run() {
        cout << "I can run at normal speed" << endl;
    }
};


int main() {

    Superman clark("Kent");

    // Inherited from Man.
    clark.sayName();

    // Superman's own version of run().
    clark.run();


    Spiderman peter("Peter");

    // Inherited from Man.
    peter.sayName();

    // Spiderman's own version of run().
    peter.run();

    peter.gotMoney();


    return 0;
}