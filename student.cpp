#include "student.h"

long Student::nextStuID = 500;

Student::Student(string myName, string scremail, string Addressy, string DOBirth, string gen, int Studying, string degree, long advising):Person(myName, scremail, Addressy, DOBirth, gen)
{
  id = nextStuID++;
  yearOfStudy = Studying;
  advisorID = advising;
  major = degree;
}

void Student::Print()
{
  cout << "Student ID: " << id << endl;
  cout << "Student Name: " << name << endl;
}
