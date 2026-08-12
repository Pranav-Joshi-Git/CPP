#include <iostream>

using namespace std;

int main() {

    unsigned int x = 6; // Binary: 0110
    unsigned int y = 9; // Binary: 1001

    // Bitwise AND (&)
    // 0110
    // 1001
    // ----
    // 0000 = 0
    unsigned int bitwiseAnd = x & y;

    // Bitwise OR (|)
    // 0110
    // 1001
    // ----
    // 1111 = 15
    unsigned int bitwiseOr = x | y;

    // Bitwise XOR (^)
    // 0110
    // 1001
    // ----
    // 1111 = 15
    // 1 when the two bits are different.
    unsigned int bitwiseXor = x ^ y;

    // Bitwise NOT (~)
    // Flips every bit: 0 -> 1 and 1 -> 0.
    unsigned int bitwiseNot = ~x;

    // Left shift (<<)
    // 0110 << 1 = 1100 = 12
    // Effectively multiplies by 2 for positive integers.
    unsigned int leftShift = x << 1;

    // Right shift (>>)
    // 1001 >> 1 = 0100 = 4
    // Effectively divides by 2 for positive integers.
    unsigned int rightShift = y >> 1;

    cout << "x = " << x << " (0110)" << endl;
    cout << "y = " << y << " (1001)" << endl;

    cout << "x & y  = " << bitwiseAnd << endl;
    cout << "x | y  = " << bitwiseOr << endl;
    cout << "x ^ y  = " << bitwiseXor << endl;
    cout << "~x     = " << bitwiseNot << endl;
    cout << "x << 1 = " << leftShift << endl;
    cout << "y >> 1 = " << rightShift << endl;

    /*
    Common real-world uses of bitwise operations:

    &  -> Check or extract specific bits / flags.
    |  -> Set specific bits / combine flags.
    ^  -> Toggle bits.
    ~  -> Invert bits.
    << -> Create bit masks / shift bits.
    >> -> Extract bits / shift bits.

    Commonly used in:
    - Permissions and flags
    - Embedded systems
    - Networking
    - Operating systems
    - Device/hardware programming
    - Compression and low-level data processing
    */

    return 0;
}