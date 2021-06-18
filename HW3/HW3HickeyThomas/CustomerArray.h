#pragma once
#include<fstream>
#include "Customer.h"

Customer custList[n];

int globalClock = 0;

//Function to read data from file into array
void readFile(string fname)
{
	ifstream inFile;// 1. create a file object 
	inFile.open(fname);

	if (inFile)
	{
		for (int i = 0; i < n; i++)
		{
			inFile >> custList[i].id >> custList[i].fName >> custList[i].lName >> custList[i].amount >> custList[i].transType >> custList[i].balance;
		}
	}

	else
		cout << "File not found";

	inFile.close();
}

//Functions to calculate data for customers in the array
void calcTeller()
{
	for (int i = 0; i < n; i++)
	{
		int teller = randNum(1, 3);
		custList[i].teller = teller;
	}
}

void calcArrival()
{
	for (int i = 0; i < n; i++)
	{
		int time = randNum(1, 10);
		globalClock += time;
		custList[i].arrivalTime = globalClock;
	}
}

void calcService(Customer &customer)
{
	int waitTime = randNum(0, 5);
	int serviceTime = customer.arrivalTime + waitTime;
	customer.serviceTime = serviceTime;
}