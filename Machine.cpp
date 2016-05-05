#include "Machine.h"
using namespace std;

Machine::Machine(State** states, int numStates) {
  this->states = states;
  this->numStates = numStates;
  this->currentState = 0;
  this->currentInputChar = 0;
}

Machine::~Machine() {
  for(int i = 0; i < numStates; i++) {
    delete states[i];
  }
  delete[] states;
}

void Machine::doLambda() {
  // Lambda input
  if(states[0]->isFinal()) {
    cout << "Input accepted." << endl;
  } else {
    cout << "Input rejected." << endl;
  }
}

void Machine::doStep(string alphabet, string input) {
  // Stacks one and two
  stack<char>* stackOne = new stack<char>;
  stack<char>* stackTwo = new stack<char>;
  // Reset state
  currentState = 0;
  currentInputChar = 0;
  int choice = 1;
  // Main step by step loop
  while(choice == 1 && currentInputChar != input.length()) {
    // Output the current state and wait for next instruction
    cout << "Current State: " << currentState << endl;
    cout << "Current Input: " << input[currentInputChar] << endl;
    cout << "Stack One Top: " << (stackOne->empty() ? '!' : stackOne->top()) << endl;
    cout << "Stack Two Top: " << (stackTwo->empty() ? '!' : stackTwo->top()) << endl;
    cout << "(1) Do Step" << endl << "(2) Finish" << endl;
    cout << "Choice: ";
    cin >> choice;
    cin.ignore(256, '\n');
    while(choice < 1 || choice > 2) {
      cin >> choice;
      cin.ignore(256, '\n');
    }
    // Do next step before looping again
    if(choice == 1) {
      int charPos = 0;
      while(alphabet[charPos] != input[currentInputChar]) charPos++;
      currentState = states[currentState]->doTransition(charPos, stackOne, stackTwo);
      if(currentState == -1) {
        cout << "Input rejected." << endl;
        delete stackOne;
        delete stackTwo;
        return;
      }
      currentInputChar++;
    }
  }
  // Loop that finishes anything that's left
  if(choice == 2) {
    while(currentInputChar != input.length()) {
      int charPos = 0;
      while(alphabet[charPos] != input[currentInputChar]) charPos++;
      currentState = states[currentState]->doTransition(charPos, stackOne, stackTwo);
      if(currentState == -1) {
        cout << "Input rejected." << endl;
        delete stackOne;
        delete stackTwo;
        return;
      }
      currentInputChar++;
    }
  }
  if(currentInputChar == input.length() && stackOne->empty() && stackTwo->empty() && states[currentState]->isFinal()) {
    cout << "Input accepted." << endl;
  } else {
    cout << "Input rejected." << endl;
  }
  // Remove finished stacks
  delete stackOne;
  delete stackTwo;
}

void Machine::doAll(string alphabet, string input) {
  // Stacks one and two
  stack<char>* stackOne = new stack<char>;
  stack<char>* stackTwo = new stack<char>;
  // Reset state
  currentState = 0;
  currentInputChar = 0;
  // Loop that finishes anything that's left
  while(currentInputChar != input.length()) {
    int charPos = 0;
    while(alphabet[charPos] != input[currentInputChar]) charPos++;
    currentState = states[currentState]->doTransition(charPos, stackOne, stackTwo);
    if(currentState == -1) {
      cout << "Input rejected." << endl;
      delete stackOne;
      delete stackTwo;
      return;
    }
    currentInputChar++;
  }
  if(currentInputChar == input.length() && stackOne->empty() && stackTwo->empty() && states[currentState]->isFinal()) {
    cout << "Input accepted." << endl;
  } else {
    cout << "Input rejected." << endl;
  }
  // Remove finished stacks
  delete stackOne;
  delete stackTwo;
}
