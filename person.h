#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Person
{
 protected:
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:
  Person(string myName, string scremail, string Addressy, string DOBirth, string gen);

};
#endif
