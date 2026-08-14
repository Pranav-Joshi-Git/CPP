#include <iostream>

using namespace std;

int main() {
  cout << "Hello World" << endl;
  return 0;
}

// without namespace std line
// std::cout << "Hello World" << std:endl;

// Though below code uses c header file, but it is run by cpp compiler
// So it is a valid CPP program

// #include <cstdio>
// using namespace std;

// int main(){
//     puts("Click on button");
//     puts("Create a new player");
//     puts("Add life to player");
//     return 0;
// }