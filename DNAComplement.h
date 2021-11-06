/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun with Stacks
 * This is the header .h file for the DNAComplement class
*/
#include<iostream>

using namespace std;

class DNAComplement {
public:
  DNAComplement(); // default constructor
  ~DNAComplement(); // destructor
  string findComplement(string sequence); //returns the complement of the sequence
  string findReverseComplement(string complement); // returns the reverse of the complement

};
