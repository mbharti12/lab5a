#include "tddFuncs.h"
#include <iostream>
#include <cstring>
#include <string_view>
using std::cout;
using std::endl;

std::string convertLineNumber(int lineNumber) {
  std::string retVal{};
  if (lineNumber > 0) 
    retVal += " line: " + std::to_string(lineNumber);
  return retVal;
}

void assertEquals(const char * const expected, 
		  const char * const actual, 
		  const std::string & message,
		  int lineNumber) {
  std::string line = convertLineNumber(lineNumber);
  if ( std::string_view(expected) == actual ) {  // if they are equal
    cout << "PASSED: " << message << line <<  endl;;
  } else {
    cout << "   FAILED: " << message << line << endl 
	 << "     Expected: " << expected << " Actual: " << actual << endl; 
  }
}

void assertEquals(const char * const expected, 
		  const std::string & actual, 
		  const std::string & message,
		  int lineNumber) {
  assertEquals(std::string(expected),actual,message,lineNumber);
}

void assertTrue(bool expression,
		const std::string & message,
		int lineNumber) {
  std::string line = convertLineNumber(lineNumber);
  if (expression) {
    cout << "PASSED: " << message << line << endl;;
  } else {
    cout << "   FAILED: " << message << line << endl 
	 << "     Expected true, but was false " << endl;
  }
}

