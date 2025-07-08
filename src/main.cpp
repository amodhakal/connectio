#include "main.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: ./connectio [computer]" << endl;
    return 1;
  }

  string opponentType = argv[1];
  if (opponentType == "computer") {
    return playComputer();
  }

  cerr << "Invalid opponent type given" << endl;
  return 1;
}
