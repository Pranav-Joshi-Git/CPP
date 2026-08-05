#include <iostream>
#include <cstdint>

using namespace std;

int main() {

    // 1 byte = 8 bits

    cout << "char                 : " << sizeof(char) * 8 << " bits\n";

    cout << "short int            : " << sizeof(short int) * 8 << " bits\n";
    cout << "int                  : " << sizeof(int) * 8 << " bits\n";
    cout << "long int             : " << sizeof(long int) * 8 << " bits\n";
    cout << "long long int        : " << sizeof(long long int) * 8 << " bits\n\n";

    // Unsigned types have the same size as their signed counterparts,
    // but cannot store negative values. They use that space for a larger positive range.
    cout << "unsigned short int   : " << sizeof(unsigned short int) * 8 << " bits\n";
    cout << "unsigned int         : " << sizeof(unsigned int) * 8 << " bits\n";
    cout << "unsigned long int    : " << sizeof(unsigned long int) * 8 << " bits\n";
    cout << "unsigned long long   : " << sizeof(unsigned long long int) * 8 << " bits\n\n";

    // Fixed-width integer types (from <cstdint>).
    // Types like long int and long long int may vary based on system
    // So use these when you need a guaranteed size across all platforms.
    // Example: int16_t is always 16 bits, uint16_t is always an unsigned 16-bit integer.
    cout << "int16_t              : " << sizeof(int16_t) * 8 << " bits\n";
    cout << "uint16_t             : " << sizeof(uint16_t) * 8 << " bits\n\n";

    // Integer literals can be written in decimal, hexadecimal and binary.
    int decimal = 22;
    int hexadecimal = 0x16;
    int binary = 0b00010110;

    cout << "Decimal     : " << decimal << endl;
    cout << "Hexadecimal : " << hexadecimal << endl;
    cout << "Binary      : " << binary << endl;

    return 0;
}