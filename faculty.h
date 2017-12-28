#ifndef FACULTY_H
#define FACULTY_H

#include "person.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Faculty:public Person
{
  friend class University;

 protected:
  long id;
  float salary;
  int yearOfExp;
  long deptID;
  static long nextFacultyID;

 public:
  Faculty(string myName, string scremail, string Addressy, string DOBirth, string gen, float MONEY, int Experience, long DeputyID);
  void Print();

};
#endif
