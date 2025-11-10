#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

#include "CreateConfig.h"

using std::cin;
using std::cout;
using std::string;

void CreateConfig::GetConfigValues() {
  cout << "\nEnter a filename for this configuration (must not contain spaces "
          "or "
          "special characters)\n[Enter text]: ";
  while (!(cin >> ConfigName)) {
    cout << "Enter a name for the configuration file (must not contain spaces "
            "or special characters): ";
    cin.clear();
  }
  
  ConfigName = ConfigName + "_multieditpdfcfg";

  cout << "\nWhat text would you like to write in the PDFs?\n[Enter text]: ";
  cin.ignore();
  getline(cin, UserText);

  cout << "\nWould you like to include the date after that?\n[1. yes]\n[0. "
          "no]\n[Enter 1, or 0]: ";
  while (!(cin >> DateBool)) {
    cout << "Type '1' for 'yes', or '0' for 'no' to continue: ";
    cin.clear();
  }
  cin.ignore();
  if (DateBool) {

    cout
        << "\nIn which format would you like the date printed?\n[1. "
           "dd/mm/yyyy]\n[2. "
           "mm/dd/yyyy]\n[3. dd/mm/yy]\n[4. mm/dd/yy]\n[Enter 1, 2, 3, or 4]: ";
    while (!cin >> DateType) {
      cout << "Choose 1, 2, 3, or 4 to continue: ";
      cin.clear();
    }
    if (DateType == 1)
      strftime(Date, 80, "%d/%m/%Y", localtime(&t));
    else if (DateType == 2)
      strftime(Date, 80, "%m/%d/%Y", localtime(&t));
    else if (DateType == 3)
      strftime(Date, 80, "%m/%d/%y", localtime(&t));
    else if (DateType == 4)
      strftime(Date, 80, "%d/%m/%y", localtime(&t));
    UserText = UserText + " " + Date;
  }
cin.ignore();
  cout << "\nAt which x coordinate would you like to place your text?\nhint: "
          "coordinate checking website: "
          "https://pdf-cordinate-extractor.vercel.app/\n[Enter only X "
          "coordinate as a number]: ";
  while (!(cin >> XCoord)) {
    cout << "Enter the X coordinate as a number: ";
    cin.clear();
  }
  cin.ignore();
  cout << "\nAt which y coordinate would you like to place your text?\n[Enter "
          "only Y coordinate as a number]: ";
  while (!(cin >> YCoord)) {
    cout << "Enter the Y coordinate as a number: ";
    cin.clear();
  }
cin.ignore();
  cout << "\nEnter the full path to the font you would like to use.\nhint: "
          "Fonts on Windows are usually found at C:/Windows/Fonts\n[Enter the "
          "path to a font]: ";
  while (!(cin >> FontPath)) {
    cout << "Enter the path to a font: ";
    cin.clear();
  }
  cin.ignore();
  cout << "\nEnter the font size you would like to use.\n[Enter the size as a "
          "number]: ";
  while (!(cin >> FontSize)) {
    cout << "Enter a size as a number: ";
    cin.clear();
  }
  cin.ignore();
}


void CreateConfig::WriteConfigToFile(){
    std::ofstream NewConfig(ConfigName);
    NewConfig << XCoord << "\n" << YCoord << "\n" << UserText << "\n" << FontPath << "\n" << FontSize;
    NewConfig.close();
}