#include "Header.h";

//Array for raw input, and counted frequency
char inputArray[100];
freq freqArray[x];

int main()
{
	int count = readTxt(inputArray);
	cout << "The numbers in the file are: " << endl;
	printArray(count, inputArray);
	cout << endl;

	frequencyCounter(count, inputArray, freqArray);
	sortArray(freqArray);

	cout << "This is the frequency of each character: " << endl;
	printFreqArray(freqArray);
	cout << endl;

	writeArray(freqArray);
}