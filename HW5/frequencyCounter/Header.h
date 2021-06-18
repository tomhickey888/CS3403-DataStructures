#pragma once
#include<iostream>
#include<fstream>
#include "freqStruct.h";

using namespace std;

const int x = 26;

char alpha[x] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int readTxt(char array[])
{
	int n = 0;
	string fname = "inputFile.txt";

	ifstream inFile;
	inFile.open(fname);

	if (inFile)
	{
		while(inFile)
		{
			inFile >> array[n];
			n++;
		}

		return n;
	}

	else
	{
		cout << "File not found";
		return n;
	}

	inFile.close();
}

void printArray(int count, char array[])
{
	for (int i = 0; i < count; i++)
		cout << array[i] << ", ";
	cout << endl;
}

void writeArray(freq array[])
{
	string fname = "outputFile.txt";

	ofstream outFile;
	outFile.open(fname, ios::trunc);

	if (outFile)
	{
		outFile << "This is the frequency of each character: " << endl;
		for (int i = 0; i < x; i++)
			outFile << array[i].alpha << ": " << array[i].freq << endl;
		outFile << endl;
	}

	else
		cout << "File not found";

	outFile.close();
}

void printFreqArray(freq array[])
{
	for (int i = 0; i < x; i++)
		cout << array[i].alpha << ": " << array[i].freq << endl;
}

void frequencyCounter(int count, char rawArray[], freq array[])
{
	for (int z = 0; z < x; z++)
	{
		array[z].alpha = alpha[z];
	}

	for (int i = 0; i < count; i++)
	{
		char c = rawArray[i];
		c = toupper(c);

		for (int j = 0; j < x; j++)
		{
			if (c == array[j].alpha)
				array[j].freq++;
		}
	}
}

void sortArray(freq array[])
{
	for (int i = (x - 1); i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
			if (array[j - 1].freq < array[j].freq)
			{
				freq temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
	}
}
