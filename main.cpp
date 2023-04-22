#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main() 
{
	//Student Data
	const string studentData[] = {
		"1A,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Fidel,Mares,fmares@wgu.edu,29, 16,23,42,SOFTWARE"
	};

	
	//New Roster object
	Roster* classRoster = new Roster(5);
	for (int i = 0; i < 5; i++) {
		classRoster->parse(studentData[i]);
	};


	//Program header
	cout << "Course Title: C867 Scripting and Programming - Applications" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "WGU Student ID: 001413646" << endl;
	cout << "Name: Fidel Mares" << endl;

	
	cout << endl;
	cout << endl;


	//Prints all current students
	cout << "All Current Students: " << endl;
	classRoster->printAll();


	cout << endl;
	cout << endl;


	//Prints the average days in course
	cout << "Students Average Days in Course:" << endl;
	for (int i = 0; i < 5; i++) {
		classRoster->printaAverageDaysInCourse(classRoster->getStudentID(i));
	}


	cout << endl;
	cout << endl;


	//Prints all students with SOFTWARE degree, adjust DegreeProgram::SOFTWARE if a different degree is needed
	cout << "Students With Degree Program SOFTWARE:" << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);


	cout << endl;
	cout << endl;


	//Prints invalid student emails
	cout << "Invalid Student Email Addresses:" << endl;
	classRoster->printInvalidEmails();
	

	cout << endl;
	cout << endl;


	classRoster->remove("A3");


	cout << endl;
	cout << endl;


	cout << "All Current Students: " << endl;
	classRoster->printAll();


	cout << endl;
	cout << endl;


	classRoster->remove("A3");

	cout << endl;
	cout << endl;

	
	//Destructor
	classRoster->~Roster();
	cout << "Destructor called..." << endl;


	cout << endl;
	cout << endl;

}