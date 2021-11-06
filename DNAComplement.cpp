/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun With Stacks
 * This is the implementation .cpp file for the DNAComplement class.
*/
#include "DNAComplement.h"

DNAComplement::DNAComplement() { // default constructor

}

DNAComplement::~DNAComplement() { // destructor

}

string DNAComplement::findComplement(string sequence) { // returns the complement of the sequence
  string result = "";
  for (int i = 0; i < sequence.size(); ++i) {
    if (sequence[i] == 'A') {
      result += 'T';
    } else if (sequence[i] == 'C') {
      result += 'G';
    } else if (sequence[i] == 'T') {
      result += 'A';
    } else if (sequence[i] == 'G') {
      result += 'C';
    }
  }
  return result;
}

string DNAComplement::findReverseComplement(string complement) { // returns the reverse of the complement
  char temp;
  for (int i = 0; i < complement.size() / 2; ++i) {
    temp = complement[i];
    complement[i] = complement[complement.size()-1-i];
    complement[complement.size()-1-i] = temp;
  }
  return complement;
}
