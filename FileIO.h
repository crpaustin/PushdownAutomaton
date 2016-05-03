#include <iostream>
#include <fstream>
using namespace std;

class FileIO {
private:
  ifstream file;
public:
  FileIO();
  virtual ~FileIO();
  bool setFile(string filename);
  void FileIO::closeFile();
  string getLine();
  int getNumber();
  string getSection();
}

FileIO::FileIO() {

}

FileIO::~FileIO() {
  if(file.is_open()) {
    file.close();
  }
}

bool FileIO::setFile(string filename) {
  if(file.is_open()) file.close();
  file.open(filename);
  if(file.is_open()) return true;
  return false;
}

void FileIO::closeFile() {
  if(file.is_open()) {
    file.close();
  }
}

string getLine() {
  string output;
  getline(file, output);
  for(unsigned int i = 0; i < output.length(); i++) {
    if(output[i] == ' ') output.erase(output.begin()+i);
  }
  return output;
}

int getNumber() {
  int output;
  file >> output;
  return output;
}

string* getSection() {
  string output[5];
  string buffer;
  getline(file, buffer, ' ');
  int currentChar = 0;
  int currentIndex = 0;
  while(currentIndex < 5) {
    int prevChar = currentChar;
    while(buffer[currentChar] != ',') currentChar++;
    output[currentIndex] = buffer.substr(prevChar, currentChar - prevChar);
    currentChar++;
    currentIndex++;
  }
  // for(unsigned int i = 0; i < output.length(); i++) {
  //   if(output[i] == ',') output.erase(output.begin()+i);
  // }
  return output;
}
