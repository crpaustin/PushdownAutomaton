#include "Machine.h"
using namespace std;

Machine::Machine(State** states, int numStates) {
  this->states = states;
  this->numStates = numStates;
}

Machine::~Machine() {
  for(int i = 0; i < numStates; i++) {
    delete states[i];
  }
  delete[] states;
}

void Machine::doStep(string input) {

}

void Machine::doAll(string input) {

}
