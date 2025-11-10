#pragma once

#include <ctime>
#include <string>

using std::string;

class CreateConfig {
private:
  string FontPath;
  int FontSize;
  int XCoord;
  int YCoord;
  string UserText;
  bool DateBool;
  
  int DateType;
  string ConfigName;
  char Date[80];
  time_t t = time(0);

public:
  void GetConfigValues();
  void WriteConfigToFile();
  
  

};