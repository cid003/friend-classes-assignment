#include "university.h"

bool University::failure = false;
bool University::success = true;

University::University()
{
  //leave constructor empty
}

University::~University()
{
  //leave deconstructor empty
}

//university functions are below + checking functions
//-----------------------------------------------------------------------------------------
bool University::checkFacultyVector(long IDcode)
{
  //this function checks faculty vector if any 'long' variable types exist 
  for(int i = 0; i < Facilities.size(); i++)
    {
      if(Facilities[i].id == IDcode)
	return University::success;
    }
  //otherwise...
  return University::failure;

}
//-----------------------------------------------------------------------------------
bool University::checkCoursesVector(long longtype)
{
  //this function checks courses vector for long id type
  for(int i = 0; i < Courses.size(); i++)
    {
      if(Courses[i].CRN == longtype)
	return University::success;
    }
  //otherwise...
  return University::failure;
}
//------------------------------------------------------------------------------------
bool University::checkStudentVector(long longtype)
{
  //this function checks student vector for long id type
  for(int i = 0; i < Students.size(); i++)
    {
      if(Students[i].id == longtype)
	return University::success;
    }
  //otherwise
  return University::failure;
}
//------------------------------------------------------------------------------------
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  if((depChairId != 0) && (!checkFacultyVector(depChairId)))
    {
      cout << "This Chair ID: " << depChairId << "is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  
  //declare department constructor(string, string, long) 
  Department construct(depName, depLoc, depChairId);

  //push contents into departments vector
  Departments.push_back(construct);

  return University::success; //success if process is complete

}
//-----------------------------------------------------------------------------
bool University::checkDepartmentVector1(string stringType)
{
  //this fuction checks departments vector if the major/other string type exists 
  for(int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].name == stringType)
	return University::success;
    }
  //otherwise...
  return University::failure; 

}
//----------------------------------------------------------------------------
bool University::checkDepartmentVector2(long longType)
{
  //this function checks the departments vector for  matching long type variables 
  for(int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].id == longType)
	return University::success;
    }
  
  //otherwise...
  return University::failure;
}
//----------------------------------------------------------------------------

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  //check if major and advisor id exist
  if((sMajor != "0") && (!checkDepartmentVector1(sMajor)))
    {
      cout << "This major: " << sMajor << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  else if((sAdvisorId != 0) && (!checkFacultyVector(sAdvisorId)))
    {
      cout << "This Advisor ID: " << sAdvisorId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  
  //declare student constructor(string, string, string, string, string, int, string, long)
  Student construct(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);

  //push contents into student vector
  Students.push_back(construct);
  return University::success; //return this when process is completed

}
//----------------------------------------------------------------------------

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  if((cTaughtBy != 0) && (!checkFacultyVector(cTaughtBy)))
    {
      cout << "This Faculty ID: " << cTaughtBy << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  else if(!checkDepartmentVector2(cDepId))
    {
      cout << "This department ID: " << cDepId << " is invlaid and doesn't exist." <<endl;
      return University::failure;
    }
  //declare course constructor(string, long, long, int)
  Course construct(cName, cDepId, cTaughtBy, cMaxSeat);
  
  //push contents into Courses vector
  Courses.push_back(construct);
  return University::success; //return this when process is completed

}
//----------------------------------------------------------------------------

bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  if(!checkDepartmentVector2(fDepId))
    {
      cout << "This department ID: " << fDepId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }

  //declare faculty constructor(string, string, string, string, string, float, int, long)
  Faculty construct(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);

  //push contents into facilities vector
  Facilities.push_back(construct);
  return University::success; //return this when process is completed

}
//----------------------------------------------------------------------------
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  //do a check just in case
  if(!checkFacultyVector(facultyId))
    {
      cout << "This faculty ID: " << facultyId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  cout <<"==================================================="<<endl;
  cout << "Courses Taught by Faculty ID#: " << facultyId <<endl;
  cout <<"==================================================="<<endl;

  for(int i = 0; i < Facilities.size(); i++)
    {
      if(Facilities[i].id == facultyId)
	{
	  for(int z = 0; z < Courses.size(); z++)
	    {
	      if(Facilities[i].id == Courses[z].isTaughtby)
	      Courses[z].Print();
	    }
	}
      cout << endl; //for spacing and formatting
    }
  return University::success; //return this if process is complete

}
//----------------------------------------------------------------------------

bool University::ListCoursesTakenByStudent(long studentId)
{
  //do a check just in case
  if(!checkStudentVector(studentId))
    {
      cout << "This student ID: " << studentId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }

  cout << "==================================================="<<endl;
  cout << "Courses Taken by Student ID#: "<< studentId << endl;
  cout << "==================================================="<<endl;

  for(int i = 0; i < Students.size(); i++)
    {
      if(Students[i].id == studentId) //matching id, display coursestaken vector for student
	{
	  for(int h = 0; h < Students[i].coursesTaken.size(); h++)
	    {
	      Students[i].coursesTaken[h].Print(); //open the vector from class student
	      cout << endl; //formatting and spacing
	    }
	}
    }

  return University::success;
 }
//----------------------------------------------------------------------------

bool University::ListFacultiesInDepartment(long departId)
{
  //run a check just in case
  if(!checkDepartmentVector2(departId))
    {
      cout << "This department ID: " << departId << " is invalid and doesn't exist. "<<endl;
      return University::success;
    }
  
  cout << "==================================================="<<endl;
  cout << "Faculties of Department ID#: " << departId <<endl;
  cout << "==================================================="<<endl;
  
  for(int i = 0; i < Departments.size(); i++) 
    {
      if(Departments[i].id == departId)
	{
	  for(int z = 0; z < Facilities.size(); z++)
	    {
	      if(Facilities[z].deptID == departId)
		{
		  Facilities[z].Print();
		}
	    }
	}
      
    }
  return University::success;
}
//----------------------------------------------------------------------------

bool University::ListStudentsOfAFaculty(long facultyId)
{
  //run a check just in case
  if(!checkFacultyVector(facultyId))
    {
      cout << "This faculty ID: " << facultyId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  
  cout << "===================================================" <<endl;
  cout << "Students of Faculty ID#: " << facultyId << endl;
  cout << "===================================================" <<endl;
  
  for(int i = 0; i < Facilities.size(); i++)
    {
      if(Facilities[i].id == facultyId)
	{
	  for(int z = 0; z < Students.size(); z++)
	    {
	      if(Students[z].advisorID == facultyId);
	      {
		Students[z].Print();
	      }
	    }
	}
      cout << endl;
    }
  
  return University::success;
}
//----------------------------------------------------------------------------
  
bool University::ListCoursesOfADepartment(long departId)
{
  if(!checkDepartmentVector2(departId))
    {
      cout << "This department course " << departId << " does not exist." <<endl;
      return University::failure;
    }
  
  cout << "=======================================================" <<endl;
  cout << "Courses of Department ID#: " << departId <<endl;
  cout << "=======================================================" <<endl;
  
  for(int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].id == departId)
	{
	  for(int z = 0; z < Courses.size(); z++)
	    {
	      if(departId == Courses[z].depID)
		{
		  Courses[z].Print();
		}
	    }
	}
      cout << endl;
    }
  
  return University::success;
}
//---------------------------------------------------------------------------
bool University::AddACourseForAStudent(long courseId, long stId)
{
  //check if student id exists
  if(!checkStudentVector(stId))
    {
      cout << "This student ID: " << stId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  //check if course id exists
  if(!checkCoursesVector(courseId))
    {
      cout << "This course number " << courseId << " is invalid and doesn't exist. " <<endl;
      return University::failure;
    }
  
  //check if there are available seats for the course and check if attributes match
  for(int i = 0; i < Students.size(); i++)
    {
      if(Students[i].id == stId) //get the student id a match to the desired course
	{
	  if(Courses[i].maxAvailSeats == Courses[i].assignedSeats) //if max seats = #of assigned seats
	    {
	      cout << "The Course with ID#: " << courseId << " is full." <<endl;
	      return University::failure;
	    }
	  else
	    {//if there are available seats, proceed with the following
	      for(int k = 0; k < Courses.size(); k++)
		{
		  if(Courses[k].CRN == courseId) //course id has match, push info into student vector
		    {
		      Students[i].coursesTaken.push_back(Courses[k]);
		      Courses[k].assignedSeats++;
		    }
		}//end of second forloop
	    }
	}
    }//end of first forloop
  
  return University::success; //return this if process is completed
}
//----------------------------------------------------------------------------
bool University::AssignDepartmentChair(long facultyId, long departId)
{
  //run a check to see if the faculty id and department id exist
  if(!checkFacultyVector(facultyId))
    {
      cout << "This faculty ID: " << facultyId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  if(!checkDepartmentVector2(departId))
    {
      cout << "This department ID: " << departId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }

  //if checks pass, assign faculty id to the departments vector in the id section
  for(int i = 0; i < Facilities.size(); i++)
    {
      if(facultyId == Facilities[i].id && departId == Facilities[i].deptID)
	{
	  for (int z = 0; z < Departments.size(); z++)
	    {
	      if (departId == Departments[z].id)
		{
		  Departments[z].chairID = facultyId;
		  return University::success;
		}
	    }//end of second forloop
	}
    }//end of first forloop

}
//----------------------------------------------------------------------------

bool University::AssignInstructorToCourse(long facultyId, long courseId)
{
  //run a check if the faculty id and course id exist
  if(!checkFacultyVector(facultyId))
    {
      cout << "This faculty ID: " << facultyId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  if(!checkCoursesVector(courseId))
    {
      cout << "This course number: " << courseId << " is invalid and doesn't exist." <<endl;
      return University::failure;
    }
  
  //if checks pass, assign faculty id to the courses vector in the CRN section
  for(int i = 0; i < Facilities.size(); i++)
    {
      if(facultyId == Facilities[i].id)
	{
	  for(int x = 0; i < Courses.size(); i++)
	    {
	      if(Facilities[i].deptID == Courses[x].depID)
		{
		  Courses[x].isTaughtby = Facilities[i].id;
		  return University::success;
		}
	    }//end of second forloop
	}
    }//end of first forloop
}
//----------------------------------------------------------------------------
bool University::ListDepartments()
{
  cout << "---------------------------------------"<<endl;
  cout << "         DEPARTMENTS INFO              "<<endl;
  cout << "---------------------------------------"<<endl;

  //cout the departments vector?
  for(int i = 0; i < Departments.size(); i++)
    {
      Departments[i].Print();
    }
}
//----------------------------------------------------------------------------

bool University::ListStudents()
{
  cout << "---------------------------------------"<<endl;
  cout << "         STUDENTS INFO                 "<<endl;
  cout << "---------------------------------------"<<endl;

  //cout the students vector?
  for(int i = 0; i < Students.size(); i++)
    {
      Students[i].Print();
    }
}
//----------------------------------------------------------------------------
bool University::ListCourses()
{
  cout << "---------------------------------------"<<endl;
  cout << "          COURSES INFO                 "<<endl;
  cout << "---------------------------------------"<<endl;

  //cout the courses vector?
  for(int i = 0; i < Courses.size(); i++)
    {
      Courses[i].Print();
    }
}
//----------------------------------------------------------------------------
bool University::ListFacilities()
{
  cout << "---------------------------------------"<<endl;
  cout << "           FACULTY INFO                "<<endl;
  cout << "---------------------------------------"<<endl;

  //cout the faculty vector?
  for(int i = 0; i < Facilities.size(); i++)
    {
      Facilities[i].Print();
    }
}

//----------------------------------------------------------------------------
bool University::ProcessTransactionFile (string fileName)
{
  fstream fin;
  string command;

  //variables for students and faculty
  string name, email, address, DateOfBirth, gender;

  //variables for students only
  int YearOfStudy;
  string major;
  long advisorID, stID;

  //variables for courses only
  string cName;
  long cdepID, taughtBy, CRN;
  int maxSeats;

  //variables for faculty only
  float salary;
  int YearOfExp;
  long fdepID, facultyID;

  //variables for department only
  string depName, depLoc;
  long depChairId, depID;

  fin.open(fileName.data());
  if(!fin)
    {
      cout << "This file cannot be opened because it doesn't exist or something isn't working. " <<endl;
    }
  else
    {
      while(fin >> command) //beginning of while loop
	{
	  if(command == "CreateNewDepartment")
	    {
	      fin >> depName;
	      fin >> depLoc;
	      fin >> depChairId;
	      CreateNewDepartment(depName, depLoc, depChairId);
	    }
	  if(command == "CreateNewStudent")
	    {
	      fin >> name;
	      fin >> email;
	      fin >> address;
	      fin >> DateOfBirth;
	      fin >> gender;
	      fin >> YearOfStudy;
	      fin >> major;
	      fin >> advisorID;
	      CreateNewStudent(name, email, address, DateOfBirth, gender, YearOfStudy, major, advisorID);
	    }
	  if(command == "CreateNewCourse")
	    {
	      fin >> cName;
	      fin >> cdepID;
	      fin >> taughtBy;
	      fin >> maxSeats;
	      CreateNewCourse(cName, cdepID, taughtBy,  maxSeats);
	    }
	  if(command == "CreateNewFaculty")
	    {
	      fin >> name;
	      fin >> email;
	      fin >> address;
	      fin >> DateOfBirth;
	      fin >> gender;
	      fin >> salary; 
	      fin >> YearOfExp;
	      fin >> fdepID;
	      CreateNewFaculty(name, email, address, DateOfBirth, gender, salary, YearOfExp, fdepID);
	    }
	  if(command == "ListCoursesTaughtByFaculty")
	    {
	      fin >> facultyID;
	      ListCoursesTaughtByFaculty(facultyID);
	    }
	  if(command == "ListCoursesTakenByStudent")
	    {
	      fin >> stID;
	      ListCoursesTakenByStudent(stID);
	    }
	  if(command == "ListFacultiesInDepartment")
	    {
	      fin >> depID;
	      ListFacultiesInDepartment(depID);
	    }
	  if(command == "ListStudentsOfAFaculty")
	    {
	      fin >> facultyID;
	      ListStudentsOfAFaculty(facultyID);
	    }
	  if(command == "ListCoursesOfADepartment")
	    {
	      fin >> depID;
	      ListCoursesOfADepartment(depID);
	    }
	  if(command == "AddACourseForAStudent")
	    {
	      fin >> CRN;
	      fin >> stID;
	      AddACourseForAStudent(CRN, stID);
	    }
	  if(command == "AssignDepartmentChair")
	    {
	      //fin long and long
	      fin >> facultyID >> depChairId;
	      AssignDepartmentChair(facultyID, depChairId);
	    }
	  if(command == "AssignInstructorToCourse")
	    {
	      //fin long and long
	      fin >> facultyID >> CRN;
	      AssignInstructorToCourse(facultyID, CRN);
	    }
	  if(command == "ListDepartments")
	    {
	      ListDepartments();
	    }
	  if(command == "ListStudents")
	    {
	      ListStudents();
	    }
	  if(command == "ListCourses")
	    {
	      ListCourses();
	    }
	  if(command == "ListFacilities")
	    {
	      ListFacilities();
	    }
	}//end of while loop
      
      fin.close();
    }//end of else

  return University::success; //return this when process is completed
}
//----------------------------------------------------------------------------

