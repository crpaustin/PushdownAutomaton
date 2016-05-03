#include <iostream>
#include <stack>
#include "Transition.h"
using namespace std;

class State {
private:
  int numTransitions;
  Transition* transition;
  bool isFinal;
public:
  State(int charCount, bool isFinal);
  virtual ~State();
  void addTransition(State newState, string popOffOne, string pushOnOne, string popOffTwo, string pushOnTwo);
  void doTransition(int input, Stack* stackOne, Stack* stackTwo);
}

State::State(int charCount, bool isFinal) {
  numTransitions = charCount;
  transitions = new Transition[numTransitions];
  for(int i = 0; i < numTransitions; i++) {
    transitions[i] = NULL;
  }
  this->isFinal = isFinal;
}

State::~State() {
  for(int i = 0; i < numTransitions; i++) {
    delete transitions[i];
  }
  delete transitions;
}

void State::addTransition(Transition* transition) {
  int currentTransition = 0;
  while(transitions[currentTransition] != NULL) currentTransition++;
  transitions[currentTransition] = transition;
}

void doTransition(int input, Stack* stackOne, Stack* stackTwo) {
  transitions[input].doTransition(stackOne, stackTwo);
}
