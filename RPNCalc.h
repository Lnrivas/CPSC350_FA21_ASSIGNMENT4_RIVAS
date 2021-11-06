/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 4 - Having Fun with Stacks
 * This is the header .h file for the RPNCalc class
*/
#include "GenStack.h"
#include <sstream>

using namespace std;

class RPNCalc {
public:
  RPNCalc(); // default constructor
  ~RPNCalc(); // default destructor
  int calculate(string input); // this method takes the entire user input as a parameter and returns the final calulation
private:
  GenStack<int> *gs; //creates a doubly linked list based stack of ints
};
