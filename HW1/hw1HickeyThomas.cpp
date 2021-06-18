#include "birthDate1.h"

using namespace std;

//Method to calculate the current time and get the Person's data
void calculateAge(Person student)
{
	//Calculate the current time from the system clock
	time_t now = time(0);
	tm* currTime = localtime(&now);
	int currYear = (currTime->tm_year + 1900);
	int currMonth = (currTime->tm_mon + 1);
	int currDay = currTime->tm_mday;

	//Variables for user input and returned data
	string currentDate = to_string(currMonth) + '-' + to_string(currDay) + '-' + to_string(currYear);
	string name;
	int year = 0;
	int month = 0;
	int day = 0;
	int age;
	
	//Check variable for input validation
	bool check = 0;

	//Gets the user input for the Person's name
	printf("Ener your name: ");
	getline (cin,name);
	student.name = name;

	//Validate user input for year before continuing
	do
	{
		printf("Enter birth year as 4 digt integer: ");
		cin >> year;

		if (year >= 1900 && year <= 2021){check = 1;}
		else { cout << "Year must be between 1900 and 2021" << endl; }

	} while (check == 0);

	//Set validated year in Person and reset check value	
	student.year = year;
	check = 0;

	//Validate user input for month before continuing
	do
	{
		printf("Enter birth month as a 2 digit integer: ");
		cin >> month;

		if (month >= 1 && month <= 12) { check = 1; }
		else { cout << "Month must be between 01 and 12" << endl; }

	} while (check == 0);

	//Set validated month in Person and reset check value		
	student.month = month;
	check = 0;

	//Validate user input for day before continuing
	do
	{
		printf("Enter birth day as a 2 digit integer: ");
		cin >> day;
		if (month == 9 || month == 4 || month == 6 || month == 11)
		{
			if (day > 0 && day <= 30) { check = 1; }
			else { cout << "That month has 30 days in it, and there is no day 0. Try again." << endl; }
		}
		else if (month == 02)
		{
			if (day > 0 && day <= 29) { check = 1; }
			else { cout << "February only has 28 days (or 29 if it was a leap year) and there is no day 0.  Try again." << endl; }
		}
		else
		{
			if (day > 0 && day <= 31) { check = 1; }
			else { cout << "That month has 31 days in it, and there is  no day 0.  Try again." << endl; }
		}

	} while (check == 0);

	//Set validated day in Person and reset check value	
	student.day = day;
	check = 0;

	//Calculate age of person
	age = calcAge(student, currDay, currMonth, currYear);

	//Display output
	cout << endl;
	printf("%s, age %d, was born on %d-%d-%d and today is %s", student.name.c_str(), age, student.month, student.day, student.year, currentDate.c_str());
	cout << endl << endl;
};

//Main method
int main()
{
	//Creates the Person
	Person student;

	//Passes the person into the method to be filled
	calculateAge(student);
	
	return 0;
};