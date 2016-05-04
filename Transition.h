#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <stack>
using namespace std;

class Transition {
private:
  int newState;
  string popOffOne;
  string pushOnOne;
  string popOffTwo;
  string pushOnTwo;
public:
  Transition(int newState, string popOffOne, string pushOnOne, string popOffTwo, string pushOnTwo);
  virtual ~Transition();
  int doTransition(stack<char>* stackOne, stack<char>* stackTwo);
};

#endif
