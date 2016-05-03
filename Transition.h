#include <iostream>
#include <stack>
#include "State.h"
using namespace std;

class Transition {
private:
  State newState;
  string popOffOne;
  string pushOnOne;
  string popOffTwo;
  string pushOnTwo;
public:
  Transition(State newState, string popOffOne, string pushOnOne, string popOffTwo, string pushOnTwo);
  virtual ~Transition();
  State doTransition(Stack* stackOne, Stack* stackTwo);
}

Transition::Transition(State* newState, string popOffOne, string pushOnOne, string popOffTwo, string pushOnTwo) {
  this->newState = newState;
  this->popOffOne = popOffOne;
  this->pushOnOne = pushOnOne;
  this->popOffTwo = popOffTwo;
  this->pushOnTwo = pushOnTwo;
}

Transition::~Transition() {

}

State* Transition::doTransition(Stack* stackOne, Stack* stackTwo) {
  if(popOffOne != "") stackOne.pop();
  if(pushOnOne != "") {
    for(int i = 0; i < pushOnOne.length(); i++) {
      stackOne.push(pushOnOne[i]);
    }
  }
  if(popOffTwo != "") stackTwo.pop();
  if(pushOnTwo != "") {
    for(int i = 0; i < pushOnTwo.length(); i++) {
      stackTwo.push(pushOnTwo[i]);
    }
  }
  return newState;
}
