#ifndef STUDENT_H 
#define STUDENT_H
#include <vector>
#include "person.h"
#include "course.h"
using namespace std;

class Student:public Person
{
  friend class University;

 protected:
  long id;
  int yearOfStudy;
  string major;
  long advisorID;
  vector<Course> coursesTaken; //will be linked to student and faculty
  static long nextStuID;

 public:
  Student(string myName, string scremail, string Addressy, string DOBirth, string gen, int Studying, string degree, long advising);
  void Print();

};
#endif
