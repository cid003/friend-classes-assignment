#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "department.h"
#include "student.h"
#include "faculty.h"
#include "course.h"
using namespace std;

class University
{
 protected:
  vector<Department>Departments;
  vector<Student>Students;
  vector<Course>Courses;
  vector<Faculty>Facilities;
  static bool failure;
  static bool success;

 public:
  University();
  ~University();
  bool checkDepartmentVector2(long longType);
  bool checkDepartmentVector1(string stringType);
  bool checkStudentVector(long longtype);
  bool checkFacultyVector(long IDcode);
  bool checkCoursesVector(long longtype);
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  // bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);
  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFacilities();

  bool ProcessTransactionFile(string fileName);

};
#endif
