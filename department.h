#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string> 
#include <vector>
#include <iostream>
using namespace std;

class Department
{
  friend class University;
  
 protected:
  long id;
  string name;
  string location;
  long chairID; //faculty staff ids can go in here
  static long nextDepId; //initialize to 100
  
 public:
  Department(string namey, string coordinates, long mobiusID);
  void Print();

};
#endif
