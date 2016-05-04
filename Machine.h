#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include "State.h"
using namespace std;

class Machine {
private:
  State** states;
  int numStates;
public:
  Machine(State** states, int numStates);
  virtual ~Machine();
  void doStep(string input);
  void doAll(string input);
};

#endif
