#include "ListNode.H"

int main()
{
	//Create an array to store the random numbers
	int randomlist[n];

	//Generate the random numbers into the array and print the array to console and a file output.txt
	generateRandoms(randomlist); 
	
	//Pass each number in the array into the function to add it to the linked list
    for (int r = 0; r < n; r++)
		addNode(randomlist[r]);

	//Print the LinkedList to the console
	displayLinkedList();

	//Print the LinkedList to the output file
	fileLinkedList();

	//Print the array of duplicate numbers to the console and the file
	displayDuplicates();

	return 0; 
}