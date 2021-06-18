#include "Customer.h"
#include "CustomerArray.h"
#include "CustomerQueue.h"
#include "Teller.h"
#include "Reporting.h"

using namespace std;

int main()
{
	//Seed the random number generator
	seedRand();

	//Read the file data into the Customer List
	readFile("input.txt");
	
	//Generate the teller number for each customer
	calcTeller();

	//Generate the arrival time for each customer
	calcArrival();

	//Enqueue each customer
	enqueueList(custList);

	//Dequeue and process each customer
	for (int i = 0; i < n; i++)
	{
		dequeue(custList[i]);
		teller(custList[i]);
		calcService(custList[i]);
	}

	//Perform reporting functions
	customerReporting(custList);
	tellerReporting();
	systemReporting();
	writeFile("output.txt", custList);

	return 0;
}

