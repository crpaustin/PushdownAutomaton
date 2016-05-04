#include "Transition.h"
using namespace std;

Transition::Transition(int newState, string popOffOne, string pushOnOne, string popOffTwo, string pushOnTwo) {
  this->newState = newState;
  this->popOffOne = popOffOne;
  this->pushOnOne = pushOnOne;
  this->popOffTwo = popOffTwo;
  this->pushOnTwo = pushOnTwo;
}

Transition::~Transition() {

}

int Transition::doTransition(stack<char>* stackOne, stack<char>* stackTwo) {
  if(popOffOne != "!") stackOne->pop();
  if(pushOnOne != "!") {
    for(unsigned int i = 0; i < pushOnOne.length(); i++) {
      stackOne->push(pushOnOne[i]);
    }
  }
  if(popOffTwo != "!") stackTwo->pop();
  if(pushOnTwo != "!") {
    for(unsigned int i = 0; i < pushOnTwo.length(); i++) {
      stackTwo->push(pushOnTwo[i]);
    }
  }
  return newState;
}
