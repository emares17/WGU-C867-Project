#include "student.h"

//Default values to Student constructor
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->eMail = "";
	this->age = 0;
	for (int i = 0; i < totalDays; i++) {
		this->daysTotal[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

//Full Student constructor
Student::Student(string studentID, string firstName, string lastName, string eMail, int age, int daysTotal[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->eMail = eMail;
	this->age = age;
	for (int i = 0; i < totalDays; i++) {
		this->daysTotal[i] = daysTotal[i];
	}
	this->degreeProgram = degreeProgram;
}

//Getters
string Student::getStudentId() //getStudentId
{
	return studentID;
}

string Student::getFirstName() //getFirstName
{
	return firstName;
}

string Student::getLastName() //getLastName
{
	return lastName;
}

string Student::getEmail() //getEmail
{
	return eMail;
}

int Student::getAge() //getAge
{
	return age;
}

int* Student::getDaysTotal() //getDaysTotal
{
	return daysTotal;
}

DegreeProgram Student::getDegreeProgram() //getDegreeProgram
{
	return degreeProgram;
}


//Setters
void Student::setStudentId(string studentID) //setStudentId
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) //setFirstName
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName) //setLastName
{
	this->lastName = lastName;
}

void Student::setEmail(string eMail) //setEmail
{
	this->eMail = eMail;
}

void Student::setAge(int age) //setAge
{
	this->age = age;
}

void Student::setDaysTotal(int daysTotal[]) //setTotalDays
{
	for (int i = 0; i < totalDays; i++) {
		this->daysTotal[i] = daysTotal[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) //setDegreeProgram 
{
	this->degreeProgram = degreeProgram;
}


//Prints
void Student::printStudentId() //printStudentId
{
	cout << studentID << endl;
	return;
}

void Student::printFirstName() //printFirstName
{
	cout << firstName << endl;
	return;
}

void Student::printLastName() //printLastName
{
	cout << lastName << endl;
	return;
}

void Student::printEmail() //printEmail
{
	cout << eMail << endl;
	return;
}

void Student::printAge() //printAge
{
	cout << age << endl;
	return;
}

void Student::printDaysTotal() //printDaysTotal
{
	for (int i = 0; i < totalDays; i++) {
		cout << daysTotal[i] << ", ";
	}
}

void Student::printDegreeProgram() //printDegreeProgram
{
	string degreeString;
	
	switch (degreeProgram) {
	case SECURITY:
		degreeString = "SECURITY";
		break;
	case NETWORK:
		degreeString = "NETWORK";
		break;
	case SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	default:
		degreeString = "SECURITY";
	}
	
	cout << degreeString << endl;
	return;
}

void Student::printAll() //printAll
{
	string degreeString;
	
	switch (degreeProgram) {
	case SECURITY:
		degreeString = "SECURITY";
		break;
	case NETWORK:
		degreeString = "NETWORK";
		break;
	case SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	default:
		degreeString = "ERROR";
		break;
	}

	cout << studentID << "   First Name: " << getFirstName() << "   Last Name: " << getLastName() << "   Age: " << getAge() << "   daysInCourse: {" << getDaysTotal()[0] << ", " << getDaysTotal()[1]
		<< ", " << getDaysTotal()[2] << "}   Degree Program: " << degreeString << " " << endl;
	return;
}


//Destructor
Student::~Student()
{

}