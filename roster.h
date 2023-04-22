#ifndef roster_h
#define roster_h

#include<iostream>
#include "degree.h"
#include "student.h"


class Roster
{
public:
	int index;
	int maxStudents;
	Student* classRosterArray[5];

	string getStudentID(int index);

	Roster(int maxStudents);
	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	
	//Prints
	void printAll();
	void printaAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//Destructor
	~Roster();
};


#endif // !roster_h