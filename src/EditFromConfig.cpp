#include "EditFromConfig.h"
#include "CreateConfig.h"
#include "../build/_deps/pdfhummus-src/PDFWriter/AbstractContentContext.h"
#include "../build/_deps/pdfhummus-src/PDFWriter/PDFModifiedPage.h"
#include "../build/_deps/pdfhummus-src/PDFWriter/PDFWriter.h"

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>



using std::cin;
using std::cout;
using std::string;



void EditFromConfig::FindPDFs() {
  string PdfSearchPath;
  int count = 0;
  string tempstring;
  cout << "Where are the PDFs you would like to edit?\n[Enter the full path to a directory]: ";
  while (!(cin >> PdfSearchPath)) {
    cout << "Enter a directory to continue: ";
    cin.clear();
  } 
  cout << "\nSearching for PDFs...\n";
  for (const std::filesystem::directory_entry &entry :
       std::filesystem::directory_iterator(PdfSearchPath)) {
    if (entry.path().extension() == ".pdf") {
      tempstring = entry.path();
      PDFs.push_back(tempstring);
      count++;
    }
  }
  if (count == 0)
    cout << "Couldn't find any PDFs in the specified directory." << "\n";
  else {
    cout << "Found " << count << " PDFs in " << PdfSearchPath << "\n";
  }
}
 
void EditFromConfig::FindConfigFiles() {
  
  cout << "Where is the Config you would like to use?\n[Enter the full path to a config file]: ";
  while (!(cin >> CfgPath)) {
    cout << "Enter the path to a config to continue: ";
    cin.clear();
  } 
  cout << "\nSearching for your config...\n";

  if (std::filesystem::exists(CfgPath))
    cout << "\nFound your config.\n";
  else {
    cout << "Couldn't find your config at the specified path" << "\n";
  }
}



void EditFromConfig::ReadConfig(){
    string line;
    vector<string> EditArgs;
    std::ifstream config(CfgPath);
    cout << CfgPath;
    while (getline(config, line)) {
        EditArgs.push_back(line);

    }
    XCoord = stoi(EditArgs[0]);
    YCoord = stoi(EditArgs[1]);
    Signature = EditArgs[2];
    FontPath = EditArgs[3];
    FontSize = stoi(EditArgs[4]);

}

void EditFromConfig::SignPDF(string InputFilePath) {

cout << "\n" << FontPath << "\n" << Signature;
  PDFWriter pdfWriter;

  pdfWriter.ModifyPDF(InputFilePath, ePDFVersion13, "");

  PDFModifiedPage modifiedPage(&pdfWriter, 0);

  AbstractContentContext *contentContext = modifiedPage.StartContentContext();
  AbstractContentContext::TextOptions opt(pdfWriter.GetFontForFile(FontPath),
                                          FontSize, AbstractContentContext::eGray, 0);

  contentContext->WriteText(XCoord, YCoord, Signature, opt);

  modifiedPage.EndContentContext();
  modifiedPage.WritePage();

  pdfWriter.EndPDF();
}

void EditFromConfig::EditPDFs(){
    for (string PdfInst: PDFs){
        cout << "\n" << PdfInst;
        SignPDF(PdfInst);
    }


}




