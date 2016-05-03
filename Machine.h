#include <iostream>
#include "State.h"
using namespace std;

class Machine {
private:
  State* states;
  int numStates;
public:
  Machine(State* states);
  virtual ~Machine();
  void doStep(string input);
  void doAll(string input);
}

Machine::Machine(State* states, int numStates) {
  this->states = states;
  this->numStates = numStates;
}

Machine::~Machine() {

}

void Machine::doStep(string input) {

}

void Machine::doAll(string input) {

}
