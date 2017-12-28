#include "department.h"

long Department::nextDepId = 100;

Department::Department(string namey, string coordinates, long mobiusID)
{
  id = nextDepId++;
  name = namey;
  location = coordinates;
  chairID = mobiusID;
}

void Department::Print()
{
  cout << "Department ID: " << id <<endl;
  cout << "Department Name: " << name <<endl;
}
