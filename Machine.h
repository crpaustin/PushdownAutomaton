#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <stack>
#include "State.h"
using namespace std;

class Machine {
private:
  State** states;
  int numStates;
  int currentState;
  unsigned int currentInputChar;
public:
  Machine(State** states, int numStates);
  virtual ~Machine();
  void doStep(string alphabet, string input);
  void doAll(string alphabet, string input);
};

#endif
