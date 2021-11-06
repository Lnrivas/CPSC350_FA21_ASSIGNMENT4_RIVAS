/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun With Stacks
 * This is the main file, where our main method lives. If RPN is entered as command line argument, user can enter a calculation
 * in Postfix notation and the result will be output. If DNA is entered as command line argement, user is prompted to enter a file name,
 * DNA sequences are read from the file and their complements and reverse complements are output to file dnaoutput.txt
*/
#include "GenStack.h"
#include "RPNCalc.h"
#include "FileProcessor.h"
#include "DNAComplement.h"

int main(int argc, char** argv) {
  string RPN = "RPN";
  string DNA = "DNA";
  string inputFileName;
  string inputFileText;
  if (argv[1] == RPN) { // RPN calculator
    RPNCalc rp;
    string input;
    cout << "Enter a calculation in Postfix notation to be calculated: " << endl;
    getline(cin, input);
    cout << "Result: " << rp.calculate(input) << endl;
  } else if (argv[1] == DNA) { //DNA Complement
    FileProcessor fp;
    DNAComplement dnac;
    string allTextFromInputFile = "";
    string allTextForOutputFile = "";
    string oneDNASequence = "";
    string complement = "";
    string reverseComplement = "";
    cout << "Please enter input file to read from: " << endl;
    cin >> inputFileName;
    allTextFromInputFile = fp.readFile(inputFileName);
    for (int i = 0; i < allTextFromInputFile.size(); ++i) { //iterates through entire textfile input char by char
      if (allTextFromInputFile[i] == '\n') { //end of one sequence
        complement = dnac.findComplement(oneDNASequence);
        reverseComplement = dnac.findReverseComplement(complement);
        if (complement.size() != 0) { //prevents adding empty complement and reverse complement at end of file when input file ends with '\n'
          allTextForOutputFile += "Complement: " + complement + "\nReverse Complement: " + reverseComplement + "\n\n"; //adds all output text to this variable
        }
        oneDNASequence = ""; //resets oneDNASequence to empty so it can start populating with the next DNA sequence
        complement = ""; //resets complement to empty so it can start populating with the next DNA sequence complement
        reverseComplement = ""; //resets reverseComplement to empty so it can start populating with the next DNA sequence reverseComplement
        continue;
      }
      oneDNASequence += allTextFromInputFile[i];
    }
    fp.writeToFile("dnaoutput.txt", allTextForOutputFile); //writes all output text to file "dnaoutput.txt" all at once
  } else { //invalid command line arguments
    throw runtime_error("Must enter either RPN or DNA as command line argument when running program!");
  }
  return 0;
}
