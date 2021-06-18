#pragma once
#include<time.h>
#include "Customer.h"

using namespace std;

const int queueSize = n;
int front = 0;
int rear = 0;
int numElements = 0;

Customer queueArray[queueSize];

//Function to determine if the circular queue is empty
bool isEmpty()
{
	bool status = true;

	if (numElements != 0)
		status = false;
	else
		status = true;

	return status;
}

//Function to determine if the circular queue is full
bool isFull()
{
	bool status = true;

	if (numElements < queueSize)
		status = false;
	else
		status = true;

	return status;
}

//Function to enqueue a customer into the circular queue
void enqueue(Customer customer)
{
	if (isFull())
		printf("The queue is full, you can't add more to the queue!");

	else
	{
		queueArray[rear] = customer;
		rear++;
		numElements++;
	}
}

//Function to dequeue a customer from the circular queue
void dequeue(Customer &cust)
{
	if (isEmpty())
		printf("The queue is empty, you can't dequeue yet!");

	else 
	{
		cust = queueArray[front];

		for (int i = 0; i < rear - 1; i++) 
		{
			queueArray[i] = queueArray[i + 1];
		}

		// decrement rear 
		rear--;
	}
}

//Function to enqueue the Customer list
void enqueueList(Customer custList[])
{
	for (int i = 0; i < queueSize; i++)
	{
		enqueue(custList[i]);
	}
}
