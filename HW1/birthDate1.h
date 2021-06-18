#pragma once

#include<String>
#include<ctime>
#include<iostream>

using namespace std;

//Define the data structure for Person
struct Person 
{
	string name;
	int day;
	int month;
	int year;
};

//Method to calculate the age of the Person
int calcAge(Person student, int currDay, int currMonth, int currYear)
{
	int age = currYear - student.year;

	if (currMonth > student.month)
	{
		age++;
	}
	else if (currMonth == student.month && currDay >= student.day)
	{
		age++;
	}

	return age;
};