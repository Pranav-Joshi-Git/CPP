#include <cstdio>
#include <iostream>

using namespace std;

int main() {

    static const char *originalFile = "originalFile.txt";
    static const char *editedFile = "editedFile.txt";


    // fopen() opens a file.
    //
    // "w" → opens the file for writing.
    // If the file already exists, its previous contents are overwritten.
    // If the file doesn't exist, it is created.
    FILE *fileHandling = fopen(originalFile, "w");


    // fopen() can fail, so always check whether the file was opened.
    if (fileHandling == nullptr) {
        cout << "Failed to create/open the file" << endl;
        return 1;
    }


    // Once a file is opened, we should close it
    // when we are finished using it.
    fclose(fileHandling);


    // Rename the file.
    //
    // originalFile → editedFile
    if (rename(originalFile, editedFile) == 0) {
        cout << "File renamed successfully" << endl;
    } else {
        cout << "Failed to rename file" << endl;
    }


    // Delete/remove the file.
    if (remove(editedFile) == 0) {
        cout << "File deleted successfully" << endl;
    } else {
        cout << "Failed to delete file" << endl;
    }


    return 0;
}