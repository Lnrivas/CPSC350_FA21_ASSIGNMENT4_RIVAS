/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun With Stacks
 * This is the implementation .cpp file for the RPNCalc class.
*/
#include "RPNCalc.h"

RPNCalc::RPNCalc() { // default constructor
  gs = new GenStack<int>();
}

RPNCalc::~RPNCalc() { //  default destructor
  delete gs;
}

int RPNCalc::calculate(string input) { // this method takes the entire user input as a parameter and returns the final calulation
      stringstream iss(input);
      string word;
      while(iss >> word) { // word is each thing in between spaces
        int first;
        int second;
        if (word == "+" || word == "-" || word == "*" || word == "/" || word == "%") { //if word is an operator
          second = gs->pop();
          first = gs->pop();
          if (word == "+") {
            gs->push(first + second);
          } else if (word == "-") {
            gs->push(first - second);
          } else if (word == "*") {
            gs->push(first * second);
          } else if (word == "/") {
            gs->push(first / second);
          } else if (word == "%") {
            gs->push(first % second);
          }
        } else { //if word is a number
          int intToPush = stoi(word);
          gs->push(intToPush);
        }
      }
  if (gs->getSize() != 1) {
    throw runtime_error("Invalid input!"); // stack should only have one element in it at the end which is the result of the entire calculation
  }
  return gs->pop();
}
