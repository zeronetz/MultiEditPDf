
#include <iostream>

#include "CreateConfig.h"
#include "EditFromConfig.h"

using std::cin;
using std::cout;

int main() {

  int MenuSelection;
  cout << "\nWelcome to MultiEditPDF, Please Select a Menu Option by typing a number\n\n\n[1]-Create a new config\n=-=-=-=-=-=-=-=-=-=-\n[2]-Select a config from existing\n=-=-=-=-=-=-=-=-=-=-\n[3]-Quit\n=-=-=-=-=-=-=-=-=-=-\n=>";
  while (!(cin >> MenuSelection)) {
    cout << "Select a menu option by typing the corresponding number: ";
    cin.clear();
  }

  if (MenuSelection == 1) {
    CreateConfig config;
    config.GetConfigValues();
    config.WriteConfigToFile();
  } else if (MenuSelection == 2) {
    EditFromConfig configObj;
    configObj.FindConfigFiles();
    configObj.FindPDFs();
    configObj.ReadConfig();
    configObj.EditPDFs();

  } else {
    return 0;
  }

}
