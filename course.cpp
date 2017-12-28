#include "course.h" 

long Course::nextCRN = 200; 

Course::Course(string NamNam, long departID, long taughtBy, int maxSeats)
{
  CRN = nextCRN++;
  name = NamNam;
  depID = departID;
  maxAvailSeats = maxSeats;
  isTaughtby = taughtBy;
}

void Course::Print()
{
  cout << "CRN: " << CRN <<endl;
  cout << "Course Name: " << name <<endl;
}

