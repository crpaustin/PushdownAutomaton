#include "FileIO.h"
using namespace std;

FileIO::FileIO() {
  file.open("input.txt");
}

FileIO::~FileIO() {
  if(file.is_open()) {
    file.close();
  }
}

bool FileIO::setFile(string filename) {
  if(file.is_open()) file.close();
  file.open(filename.c_str());
  if(file.is_open()) return true;
  return false;
}

void FileIO::closeFile() {
  if(file.is_open()) {
    file.close();
  }
}

string FileIO::getLine() {
  string output;
  getline(file, output);
  for(unsigned int i = 0; i < output.length(); i++) {
    if(output[i] == ' ') output.erase(output.begin()+i);
  }
  return output;
}

int FileIO::getNumber() {
  int output;
  file >> output;
  string trash;
  getline(file, trash);
  return output;
}

Transition** FileIO::getTransition() {
  string buffer;
  getline(file, buffer);
  int numSpaces = 0;
  for(unsigned int i = 0; i < buffer.length(); i++) {
    if(buffer[i] == ' ') numSpaces++;
  }
  Transition** output = new Transition*[numSpaces+1];
  int stateNum;
  int currentChar = 0;
  string stackChars[4];
  for(int i = 0; i < numSpaces + 1; i++) {
    stateNum = static_cast<int>(buffer[currentChar] - 48);
    currentChar += 2;
    for(int j = 0; j < 4; j++) {
      int prevChar = currentChar;
      while(buffer[currentChar] != ',' && buffer[currentChar] != ' ') currentChar++;
      stackChars[j] = buffer.substr(prevChar, currentChar - prevChar);
      currentChar++;
    }
    output[i] = new Transition(stateNum, stackChars[0], stackChars[1], stackChars[2], stackChars[3]);
  }
  return output;
}
