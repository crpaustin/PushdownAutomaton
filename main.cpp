#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main() {
  string alphabet; // sigma - character alphabet
  int numStates = 0; // number of states;
  string finalStates; // F - finals states

  // Get input file
  string fileName; // Input file name
  FileIO fileInput(); // Input file object
  cout << "Please specify input file name: ";
  getline(cin, fileName);
  while(!fileInput.setFile(fileName)) {
    cout << "File open failed." << endl << "Please specify another file name: ";
    getline(cin, fileName);
  }

  // Get alphabet
  alphabet = fileInput.getLine();
  // Get number of states
  numStates = fileInput.getNumber();
  // Get final states
  finalStates = fileinput.getLine();

  // Make state objects
  State* states = new State[numStates];
  for(int i = 0; i < numStates; i++) {
    bool isFinal = false;
    for(unsigned int j = 0; j < finalStates.length(); j++) {
      if(finalStates[j] == static_cast<char>(i + 48)) isFinal = true;
    }
    states[i] = new State(alphabet.length(), isFinal);
  }

  // Get transitions
  string* transitionInput;
  for(int i = 0; i < numStates; i++) {
    for(unsigned int j = 0; j < alphabet.length(); j++) {
      transitionInput = fileInput.getSection();
      states[j].addTransition(transitionInput[0], transitionInput[1], transitionInput[2], transitionInput[3], transitionInput[4]);
    }
  }

  // Close file
  fileInput.closeFile();
  cout << "File read successfully." << endl;

  // Main loop
  string input;
  int runType; // Step by step or fast run
  bool invalid; // Invalid input marker
  cout << "Type an input or -q to quit." << endl << "Input: ";
  getline(cin, input);
  while(input != "-q") {

    // Check for invalid characters
    invalid = false; // Innocent until proven guilty
    for(unsigned int i = 0; i < input.length() && !invalid; i++) {
      bool found = false;
      for(int j = 0; j < alphabet.length(); j++) {
        if(input[i] == alphabet[j]) found = true;
      }
      if(!found) {
        cout << "Invalid input." << endl;
        invalid = true;
      }
    }
    // If character is invalid, start over
    if(invalid) {
      cout << "Type an input or -q to quit." << endl << "Input: ";
      getline(cin, input);
      continue;
    }

    // Get run type - step by step or fast run
    runType = 0;
    while(runType < 1 || runType > 2) {
      cout << "(1) Step By Step" << endl << "(2) Fast Run" << endl << "Choice: ";
      cin >> runType;
    }
    if(runType == 1) {
      machine.doStep(input);
    } else {
      machine.doAll(input);
    }
    cout << "Type an input or -q to quit." << endl << "Input: ";
    getline(cin, input);
  }

  // Remove used memory
  for(int i = 0; i < numStates; i++) delete states[i];
  delete[] states;
  // End
  return 0;
}
