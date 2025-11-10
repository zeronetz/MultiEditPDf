#pragma once

#include "CreateConfig.h"

#include <string>
#include <vector>

using std::string;
using std::vector;


 


class EditFromConfig {
private:
 string InputFilePath;
  int XCoord;
  int YCoord;
  string Signature;
  string FontPath;
  int FontSize;
string CfgPath;

vector<string> PDFs;
public:
void FindPDFs();
void FindConfigFiles();
void ReadConfig();
void SignPDF(string InputFilePath);
void EditPDFs();
};

