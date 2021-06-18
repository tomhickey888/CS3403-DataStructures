#pragma once
#include<iostream>
#include<ctime>

using namespace std;

const int n =35;

struct Customer 
{
	int id; // customer ID
	string fName; // // customer first name as either an array of char or a string
	string lName; // customer last name as either an array of char or a string
	double amount; //of deposit or withdrawal
	char transType; //Deposit or Withdrawal
	int arrivalTime;
	int serviceTime;
	double balance; // Account balance
	int teller; // a value between 1 and 3 
};

void displayArray(Customer custList[])
{
	for (int i = 0; i < n; i++)
	{
		cout << custList[i].id << " " << custList[i].fName << " " << custList[i].lName << " " << custList[i].amount << " " << custList[i].transType << " " << custList[i].arrivalTime << " " <<
			custList[i].serviceTime << " " << custList[i].balance << " " << custList[i].teller << endl;
	}
}

//Random number generator functions

void seedRand()
{
	srand(time(NULL));
}

int randNum(int min, int max)
{
	int num = std::rand() % max + min;
	return num;
}


