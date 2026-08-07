#include <iostream>

using namespace std;

// static local variable:
// Initialized only once and retains its value between function calls.
int lifeUp() {

    static int life = 3;

    // ++life: increment first, then return.
    // life++: return first, then increment.
    return ++life;
}

int main() {

    // Common qualifiers/specifiers:
    //
    // Modification qualifiers:
    // - const
    // - volatile
    // - mutable
    //
    // Storage duration / storage class specifiers:
    // - static
    // - extern
    // - register (legacy)
    // - auto (legacy as a storage class; reused in modern C++ for type deduction)

    const int maxLives = 5;
    // maxLives = 7; // Error: const variables cannot be modified.

    int life = 3;
    cout << "Starting game life: " << life << endl;

    life = lifeUp();
    cout << "Updated game life: " << life << endl;

    // The static variable inside lifeUp() retains its value,
    // so it continues from the previous call.
    life = lifeUp();
    cout << "Updated game life: " << life << endl;

    return 0;
}