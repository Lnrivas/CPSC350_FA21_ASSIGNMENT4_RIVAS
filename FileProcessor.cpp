/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun With Stacks
 * This is the implementation .cpp file for the FileProcessor class.
*/
#include "FileProcessor.h"

FileProcessor::FileProcessor() { // default constructor body, it's empty

}

FileProcessor::~FileProcessor() { // destructor body, it's empty

}

string FileProcessor::readFile(string inputFile) { // takes string representing the input file of DNA sequences and returns a string representing all DNA Sequences
  fstream fileStream;
  fileStream.open(inputFile, ios::in); // opens inputFile in read mode
  fileStream >> noskipws; // allows " " to be read correctly
  char character; // each character from the input file will be read into this variable
  string allDNASequences = "";

	if (fileStream.fail()) { // checks if file was opened incorrectly
    throw runtime_error("Input file not opened!");
	}
	else { // if file was opened correctly
		cout << "Input file opened successfully!" << endl;
    while (true) { // loops through entire file, character by character, until the end is reached
			fileStream >> character;
      if (!(character == 'A' || character == 'C' || character == 'T' || character == 'G' || character == '\n')) { // if invalid character in inputFile
        throw runtime_error("DNA sequence contains invalid character!");
      }
      allDNASequences += character;
			if (fileStream.eof()) { //breaks out of loop once the entire file has been read.
        break;
      }
		}
		fileStream.close();
    fileStream.clear();
	}
  return allDNASequences;
}

void FileProcessor::writeToFile(string outputFile, string outputString) { //takes string representing output file and writes the outputString to it
  fstream fileStream;
  fileStream.open(outputFile, ios::out); // opens outputFile in write mode
  if (fileStream.fail()) { // checks if file was opened incorrectly
    throw runtime_error("Output file not opened!");
  }
  else { // if file was opened correctly
    cout << "Output file opened successfully!" << endl;
  	fileStream << outputString; // writes outputString to output file all at once
  }
  fileStream.close();
}
