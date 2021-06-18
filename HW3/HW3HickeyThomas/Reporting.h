#pragma once
#include<fstream>
#include "Customer.h"
#include "Teller.h"

using namespace std;

int totalWaitTime = 0;
int transTotal = 0;

void customerReporting(Customer customer[])
{
	string type;

	//Display to console and file:
	for (int i = 0; i < n; i++)
	{
		
		int waitTime = customer[i].serviceTime - customer[i].arrivalTime;
		totalWaitTime += waitTime;

		if (customer[i].transType == 'D')
			type = "Deposit";
		else
			type = "Withdrawal";

		cout << "Cust name: " << customer[i].fName << " " << customer[i].lName << endl;
		cout << "Balance: $" << customer[i].balance << endl;
		cout << "Transaction: $" << customer[i].amount << " " << type << endl;
		cout << "Arrival time: " << customer[i].arrivalTime << endl;
		cout << "Service time: " << customer[i].serviceTime << endl;
		cout << "Wait time: " << waitTime << endl;
		cout << endl;
	}
}

	void tellerReporting()
	{
		int total = 0;
		int deposits = 0;
		int withdrawals = 0;

		//Display to console and file
		for (int i = 1; i <= 3; i++)
		{
			cout << endl;
			cout << "Teller " << i << " Reporting" << endl;
			cout << "Transactions: " << tellerTotal(i) << endl;
			total += tellerTotal(i);

			cout << "Deposits: " << tellerD(i) << endl;
			deposits += tellerD(i);

			cout << "Withdrawals: " << tellerW(i) << endl;
			withdrawals += tellerW(i);
			cout << endl;
		}

		transTotal = total;

		cout << "Total Transactions for all Tellers:" << endl;
		cout << "Total Deposits: " << deposits << endl;
		cout << "Total Withdrawals: " << withdrawals << endl;
		cout << "Total Transactions: " << total << endl;
		cout << endl;
	}

	void systemReporting()
	{
		//Write to both screen and file:
		cout << endl;
		cout << "Total Wait Time: " << totalWaitTime << endl;

		cout << "Average Transactions:" << endl;

		for (int i = 1; i <= 3; i++)
		{
			int average = tellerTotal(i) / transTotal;
			cout << "Teller " << i << ": " << average << endl;
		}

		cout << endl;
	}

	void writeFile(string fname, Customer customer[])
	{
		ofstream outFile; 
		outFile.open(fname);

		if (outFile)
		{
			string type;

			//Display to console and file:
			for (int i = 0; i < n; i++)
			{

				int waitTime = customer[i].serviceTime - customer[i].arrivalTime;
				totalWaitTime += waitTime;

				if (customer[i].transType == 'D')
					type = "Deposit";
				else
					type = "Withdrawal";

				outFile << "Cust name: " << customer[i].fName << " " << customer[i].lName << endl;
				outFile << "Balance: $" << customer[i].balance << endl;
				outFile << "Transaction: $" << customer[i].amount << " " << type << endl;
				outFile << "Arrival time: " << customer[i].arrivalTime << endl;
				outFile << "Service time: " << customer[i].serviceTime << endl;
				outFile << "Wait time: " << waitTime << endl;
				outFile << endl;
			}

			int total = 0;
			int deposits = 0;
			int withdrawals = 0;

			//Display to console and file
			for (int i = 1; i <= 3; i++)
			{
				outFile << endl;
				outFile << "Teller " << i << " Reporting" << endl;
				outFile << "Transactions: " << tellerTotal(i) << endl;
				total += tellerTotal(i);

				outFile << "Deposits: " << tellerD(i) << endl;
				deposits += tellerD(i);

				outFile << "Withdrawals: " << tellerW(i) << endl;
				withdrawals += tellerW(i);
				outFile << endl;
			}

			transTotal = total;
			outFile << "Total Transactions for all Tellers:" << endl;
			outFile << "Total Deposits: " << deposits << endl;
			outFile << "Total Withdrawals: " << withdrawals << endl;
			outFile << "Total Transactions: " << total << endl;
			outFile << endl;
			outFile << endl;
			outFile << "Total Wait Time: " << totalWaitTime << endl;

			outFile << "Average Transactions:" << endl;

			for (int i = 1; i <= 3; i++)
			{
				int average = tellerTotal(i);
				outFile << "Teller " << i << ": " << average << endl;
			}

			outFile << endl;
		}

		else
			cout << "File not found";

		outFile.close();
	}