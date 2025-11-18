# MultiEditPDF  
MultiEditPDf is a cross-platform console application designed to allow for quick and easy editing of many PDF files.  

## Current features  
-Creation of plaintext configuration files   
-Insertion of text    
&emsp;+Choice of fonts from system installed  
&emsp;+Choice of font size  
-Insertion of current date    
&emsp;+Support for multiple date formats  
### Coming soon (tm)
-Font Color choice  
-Insertion of images  
-Editing password protected PDFs  
-Making multiple edits to a single file

## Dependencies
Cmake 4+   
C++ compiler for target platform  
PDFWriter (automatically downloaded from git by cmake)

## Usage
Build from source
```bash
git clone
cd MultiEditPDF
mkdir build && cd build

cmake ..
cmake --build . --parallel 4

./MultiEditPDF
```

