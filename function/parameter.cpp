#include <iostream>
#include <string>
using namespace std;

void myFunction(string fname) {
  cout << fname << " Refsnes\n";
}

int main() {
  myFunction("Liam");
  myFunction("Jenny");
  myFunction("Anja");
  
  return 0;
}

/*
Output

Liam Refsnes
Jenny Refsnes
Anja Refsnes
*/
