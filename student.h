#ifndef student_h
#define student_h

#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student
{
public:
	const static int totalDays = 3;

	Student(); //Empty constructor
	Student(string studentId, string firstName, string lastName, string eMail, int age, int daysTotal[], DegreeProgram degreeProgram); //Full constructor

	//Getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysTotal();
	DegreeProgram getDegreeProgram();

	//Setters
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string eMail);
	void setAge(int age);
	void setDaysTotal(int daysTotal[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Prints
	void printStudentId();
	void printFirstName();
	void printLastName();
	void printEmail();
	void printAge();
	void printDaysTotal();
	void printDegreeProgram();
	void printAll();

	//Destructor
	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string eMail;
	int age;
	int daysTotal[totalDays];

	DegreeProgram degreeProgram;
};

#endif // !student_h