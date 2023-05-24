
#include <iostream>
// #include <fstream>
using namespace std;

int main() {
  // Create and open a text file
  ofstream MyFile("filename.txt");

  // Write to the file

  string s;

  s = "Files can be tricky, but it is fun enough!\n";
  MyFile << s;

  s = "F fun enough!\n";
  MyFile << s;

  s = "Files can b!\n";
  MyFile << s;  
  // Close the file
  MyFile.close();
}
