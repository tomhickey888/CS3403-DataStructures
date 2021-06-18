#pragma once
#include<random>
#include<ctime>
#include<iostream>
#include<fstream>

using namespace std;

//Definition of the structure that makes up each node of the linked list
struct ListNode
{
//The pointer to the next Node of the Linked List
ListNode* next;
//The data portion of the list can contain any data type, in this case it will store our random integers
int value;
};

//Constant int used for the random number generator and array sizes
const int n = 30;
//The head of the Linked List has no data value, just a pointer to the first true node of the list and will always remain the same
ListNode* head;
//Creates an array for values currently sent into Linked List and an index integer for the array
int linkedList[n];
int ll = 0;
//Creates an array for duplicate values to be stored and an index integer for the array
int duplicates[n];
int d = 0;

//The method to display our linked list data to the console
void displayLinkedList()
{
	//Create a pointer to travel down the list and start it at the head and an incrementer to count the number of items in the list
	ListNode* currPtr = head;
	int l = 0;

	printf("\nThe Values in the LinkedList are:\n");

	//So long as our pointer has not reached the null value at the end of the list, print the value that it points to and move to the next node
	while (currPtr)
	{
		printf(" %d   ", currPtr->value);
		currPtr = currPtr->next;
		l++;
	}

	printf("\nThere are %i values in the LinkedList\n", l);
}

//The method to write our linked list data to a file
void fileLinkedList() 
{
	//Opens a file for us to record results in
	ofstream myfile("output.txt", ios::app);

	ListNode* currPtr = head;
	int l = 0;

	myfile << endl << "The Values in the LinkedList are:" << endl;

	while (currPtr)
	{
		myfile << currPtr->value << "  ";
		currPtr = currPtr->next;
		l++;
	}

	myfile << endl << "There are " << l << " values in the LinkedList" << endl;

	myfile.close();
}

//The method used to generate random numbers into an array to be used as data in the linked list and write them to console and file
void generateRandoms(int  randomlist[])
{
	ofstream myfile("output.txt");
	srand(time(NULL));
	printf("\nThe Randomly-Generated Values Are:\n");
	myfile << "The Randomly-Generated Vaules Are:" << endl;
	for (int r = 0; r < n; r++)
	{
		randomlist[r] = std::rand() % 58 + 1;
		printf(" %d   ", randomlist[r]);
		myfile << randomlist[r] << "  ";
	}
	cout << endl;
	myfile << endl;
	myfile.close();
}

//The method used to write the array of duplicate entries to the console and the file
void displayDuplicates()
{
	ofstream myfile("output.txt", ios::app);
	printf("\nThe Duplicate Values Are:\n");
	myfile << endl << "The Duplicate Values Are:" << endl;
	for (int r = 0; r < n; r++)
	{
		if (duplicates[r] != 0)
		{
			printf(" %d   ", duplicates[r]);
			myfile << duplicates[r] << "  ";
		}
	}
	printf("\n\n");
	myfile << endl << endl;
	myfile.close();
}

//This function adds new nodes to the linked list  
void addNode(int num)
{
	//Create an array to check for duplicate entries and a check variable
	linkedList[ll] = num;
	bool dupCheck = true;
	//Begin a loop for control with check variable
	while (dupCheck)
	{
		for (int i = 0; i < ll; i++)
		{
			if (num == linkedList[i])
			{
				duplicates[d] = num;
				d++;
				dupCheck = false;
				break;
			}
		}
		//Increment the index for the linkedList array and break if you find a duplicate
		ll++;
		if (dupCheck == false) { break; }
		//Duplicate check is complete
		dupCheck = false;
		//Creates a list node pointer for the new node, one to traverse the list with starting at the head, and one for the previous list node
		ListNode* newNode;
		ListNode* currPtr;
		ListNode* prevPtr;
		//Creates the new list node structure and stores the value passed into the method from Array 1 into it
		newNode = new ListNode;
		newNode->value = num;
		//Declares this as the current last node in the list by making the pointer to the next node null in case it is the last node
		newNode->next = NULL;
		//If the head is empty than the list is as well, so we make the head point to our new node as the first node in the linked list
		if (!head) 
		{ 
			head = newNode;
		}	 
		else
		{
			//Otherwise we traverse the list from beginning to end tracking the current node and previous node
			currPtr = head;
			prevPtr = head;
			//Check variable for breaking out of loops later when placement is found
			bool check = true;
			//While there is a non-null node to check
			while (currPtr)
			{
				//Check for possible hours at the beginning of list:
				if (currPtr == head && newNode->value < currPtr->value)
				{
					newNode->next = currPtr;
					head = newNode;
					break;
				}
				//Check for placement in the middle of list:
				if (currPtr->next)
				{
					while (currPtr->next)
					{
						if (newNode->value < currPtr->value)
						{
							newNode->next = currPtr;
							prevPtr->next = newNode;
							check = false;
							break;
						}

						else
						{
							prevPtr = currPtr;
							currPtr = currPtr->next;
						}
					}
				}
				//Break if placement was found in the middle of the list
				if (check == false) { break; }
				//Actions for if you reach the end of the list without finding placement:
				if (newNode->value < currPtr->value)
				{
					newNode->next = currPtr;
					prevPtr->next = newNode;
					break;
				}

				else if(newNode->value > currPtr->value)
				{ 
					currPtr->next = newNode; 
					break;
				}
			}
		}
	}
}