#include "State.h"
using namespace std;

State::State(int charCount, bool isFinal) {
  this->numTransitions = charCount;
  // this->transitions = new Transition*[numTransitions];
  // for(int i = 0; i < numTransitions; i++) {
  //   transitions[i] = NULL;
  // }
  this->finalState = isFinal;
}

State::~State() {
  for(int i = 0; i < numTransitions; i++) {
    delete transitions[i];
  }
  delete[] transitions;
}

void State::addTransition(Transition** transition) {
  this->transitions = transition;
}

int State::doTransition(int input, stack<char>* stackOne, stack<char>* stackTwo) {
  return transitions[input]->doTransition(stackOne, stackTwo);
}

bool State::isFinal() {
  return finalState;
}
