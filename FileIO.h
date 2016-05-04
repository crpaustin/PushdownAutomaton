#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include "Transition.h"
using namespace std;

class FileIO {
private:
  ifstream file;
public:
  FileIO();
  virtual ~FileIO();
  bool setFile(string filename);
  void closeFile();
  string getLine();
  int getNumber();
  // string* getSection();
  Transition** getTransition();
};

#endif
