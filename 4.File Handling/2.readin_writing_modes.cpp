#include <cstdio>
#include <iostream>

using namespace std;


// Maximum number of characters that fgets() can read
// into the buffer in one call.
//
// The buffer is temporary memory used while reading
// data from the file.
constexpr int maxbuffer = 1024;


int main() {

    const char *fileName = "myFile.txt";
    const char *information = "lorem ipsum dolor sit amet\n";


    // fopen() opens the file using the specified mode.
    //
    // "w" → Write mode
    //        Creates the file if it doesn't exist.
    //        If the file already exists, its previous contents are overwritten.
    //
    // "a" → Append mode
    //        Creates the file if it doesn't exist.
    //        New content is added to the end of the existing file.
    //
    // FILE *fileHandler = fopen(fileName, "w");
    // FILE *fileHandler = fopen(fileName, "a");


    // Example of writing information to the file:
    //
    // for (int i = 0; i < 50; i++) {
    //     fputs(information, fileHandler);
    // }


    // Character buffer used to temporarily store
    // data read from the file.
    char buffer[maxbuffer];


    // "r" → Read mode.
    // The file must already exist.
    FILE *fileHandler = fopen(fileName, "r");


    // Always check whether the file was opened successfully.
    if (fileHandler == nullptr) {
        cout << "Failed to open file" << endl;
        return 1;
    }


    // fgets() reads a line/string from the file into buffer.
    //
    // maxbuffer → maximum number of characters to read
    // fileHandler → source file
    //
    // The loop continues until fgets() reaches the end of the file
    // and returns nullptr.

    while (fgets(buffer, maxbuffer, fileHandler)) {

        // fputs() writes the contents of buffer to stdout.
        // stdout represents the standard output (usually the console).
        fputs(buffer, stdout);
    }


    // Once we are finished working with the file,
    // we should close it.
    fclose(fileHandler);


    return 0;
}