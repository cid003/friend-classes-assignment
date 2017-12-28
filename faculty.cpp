#include "faculty.h"

long Faculty::nextFacultyID = 600;

Faculty::Faculty(string myName, string scremail, string Addressy, string DOBirth, string gen, float MONEY, int Experience, long DeputyID):Person(myName, scremail, Addressy, DOBirth, gen)
{
  id = nextFacultyID++; //increment data by one
  salary = MONEY;
  yearOfExp = Experience;
  deptID = DeputyID;
}

void Faculty::Print()
{
  cout << "Faculty ID: " << id << endl;
  cout << "Faculty Member Name: " << name << endl;
}
