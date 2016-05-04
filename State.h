#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <stack>
#include "Transition.h"
using namespace std;

class State {
private:
  int numTransitions;
  Transition** transitions;
  bool isFinal;
public:
  State(int charCount, bool isFinal);
  virtual ~State();
  void addTransition(Transition** transition);
  int doTransition(int input, stack<char>* stackOne, stack<char>* stackTwo);
};

#endif
