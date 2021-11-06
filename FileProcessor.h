/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun with Stacks
 * This is the header .h file for the FileProcessor class
*/
#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

class FileProcessor {
public:
  FileProcessor(); // default constructor
  ~FileProcessor(); // default deconstructor
  string readFile(string inputFile); // takes string representing the input file of DNA sequences and returns a string representing all DNA Sequences
  void writeToFile(string outputFile, string outputString); //takes string representing output file and writes the outputString to it
};
