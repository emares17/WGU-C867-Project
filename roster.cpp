#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <regex>

using namespace std;


//Constructor
Roster::Roster(int maxStudents) 
{
	this->maxStudents = maxStudents;
	this->index = 0;

	for (int i = 0; i < maxStudents; i++) {
		this->classRosterArray[i] = new Student;
	}

	return;
}


//Destructor
Roster::~Roster() 
{
	
};


//Parse and extract from studentData string using stringstream.
//map is used to match enumerated values with their degree.
void Roster::parse(string studentData)
{
	stringstream ss(studentData);
	string line;

	map<string, DegreeProgram> degreeMap = {
		{"SECURITY", SECURITY},
		{"NETWORK", NETWORK},
		{"SOFTWARE", SOFTWARE}
	};

	while (getline(ss, line)) {
		stringstream fields(line);
		string studentID, firstName, lastName, eMail, ageString, days1String, days2String, days3String, degreeString;
		int age, days1, days2, days3;
		DegreeProgram degree;

		getline(fields, studentID, ',');
		getline(fields, firstName, ',');
		getline(fields, lastName, ',');
		getline(fields, eMail, ',');
		getline(fields, ageString, ',');
		getline(fields, days1String, ',');
		getline(fields, days2String, ',');
		getline(fields, days3String, ',');
		getline(fields, degreeString, ',');

		age = stoi(ageString);
		days1 = stoi(days1String);
		days2 = stoi(days2String);
		days3 = stoi(days3String);

		auto degreeIter = degreeMap.find(degreeString);
		if (degreeIter != degreeMap.end()) {
			degree = degreeIter->second;
			add(studentID, firstName, lastName, eMail, age, days1, days2, days3, degree);
		}
		else {
			cout << "Degree was not found: " << degreeString << endl;
			continue;
		}
		
	}
}


//Returns the student id as a string.
string Roster::getStudentID(int index)
{
	string sId = classRosterArray[index]->getStudentId();
	return sId;
}


//Creates a new Student object and adds it to the classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) 
{

	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[index++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}


//Prints all currents student data in classRosterArray
void Roster::printAll() 
{
	for (int i = 0; i < maxStudents; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else {
			classRosterArray[i]->printAll();
		}
	}
	return;
}


//Prints the average days in course from every student in classRosterArray
void Roster::printaAverageDaysInCourse(string studentID) 
{
	for (int i = 0; i < maxStudents; i++) {
		if (studentID == classRosterArray[i]->getStudentId()) {
			int* days = classRosterArray[i]->getDaysTotal();
			int count = 0;
			for (int j = 0; j < 3; j++) {
				count += days[j];
			}
			double averageDays = count / 3.0;
			cout << "Student ID: " << studentID << "	Average days in course: " << averageDays << endl;
		}
	}
}


//Prints specific student degrees from classRosterArray; the specific degree is asked for in the main.cpp file
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) 
{
	for (int i = 0; i < index; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->printAll();
		}
	}
}


//Checks for valid emails using a regular expression, loops through the classRosterArray and prints out the invalid emails.
void Roster::printInvalidEmails() 
{
	regex regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	for (int i = 0; i < index; i++) {
		string email = this->classRosterArray[i]->getEmail();
		if (!regex_match(email, regex)) {
			cout << classRosterArray[i]->getStudentId() << " Email " << email << " Is invalid" << endl;
		}
	}
}


//When method is called from main.cpp it will first remove the matching required student ID, when called the second time
//an error cout will output the student was not found as it has been removed from the classRosterArray
void Roster::remove(string studentID)
{
	bool found = false;

	for (int i = 0; i < maxStudents; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		} 
		else if (studentID == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			found = true;
			break;
		}
	}

	if (found) {
		cout << "Student ID " << studentID << " was removed." << endl;
	}
	else {
		cout << "Student ID " << studentID << " was not found." << endl;
	}
}