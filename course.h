#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Course
{
  friend class University;

 protected:
  long CRN;
  int maxAvailSeats;
  string name;
  long depID;
  long assignedSeats;
  long isTaughtby;
  static long nextCRN; //initialize to 200

 public:
  Course(string NamNam, long departID, long taughtBy, int maxSeats);
  void Print();

};
#endif
