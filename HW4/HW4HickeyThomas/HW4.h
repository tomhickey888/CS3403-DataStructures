#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include "TeamScores.h"

//Number of rows in each input file and size of the raw data arrays
const int n = 10; 

//Strings for input and output filenames
string inputFile = "list";
string outputFile = "output.txt";
string inOut;

//Struct arrays used for reading from files
TeamScores teamScoresList1[n]; //Raw data array 1
TeamScores teamScoresList2[n]; //Raw data array 2
TeamScores teamScoresList3[n]; //Raw data array 3
TeamScores teamScoresList4[n * 3]; //Merged data array
int z = sizeof(teamScoresList4) / sizeof(teamScoresList4[0]); //Size of the merged data array

//Struct arrays used for calculating statistics 
TeamScores teamsPoints[(n * 3) / 2]; //Array for calculating points scored by teams
TeamScores teamsGames[(n * 3) / 2]; //Array for calculating number of games won by teams
int x = sizeof(teamsPoints) / sizeof(teamsPoints[0]); //Size of the statistics arrays

//Read data from text file fname into array of name array
void readTxt(string index, TeamScores array[])
{
	inOut = "txt";
	string fname = inputFile + index + "." + inOut;

	ifstream inFile;
	inFile.open(fname);

	if (inFile)
	{
		for (int i = 0; i < n; i++)
		{
			inFile >> array[i].team1 >> array[i].team2 >> array[i].score1 >> array[i].score2;
		}
	}

	else
		cout << "File not found";

	inFile.close();
}

//Read data from CSV file fname into array of name array
void readCsv(string index, TeamScores array[])
{
	inOut = "csv";
	string fname = inputFile + index + "." + inOut;
	string temp;

	ifstream inFile;
	inFile.open(fname);

	if (inFile)
	{
		for (int i = 0; i < n; i++)
		{
			getline(inFile, array[i].team1, ',');
			getline(inFile, array[i].team2, ',');
			getline(inFile, temp, ',');
			array[i].score1 = stoi(temp);
			getline(inFile, temp);
			array[i].score2 = stoi(temp);
		}
	}

	else
		cout << "File not found";

	inFile.close();
}

//Read data from JSON file fname into array of name array
void readJson(string index, TeamScores array[])
{
	inOut = "json";
	string fname = inputFile + index + "." + inOut;
	string temp;

	ifstream inFile;
	inFile.open(fname);

	if (inFile)
	{
		getline(inFile, temp);

		for (int i = 0; i < n; i++)
		{
			getline(inFile, temp);

			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, array[i].team1, '"');
			getline(inFile, temp);

			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, array[i].team2, '"');
			getline(inFile, temp);

			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			array[i].score1 = stoi(temp);
			getline(inFile, temp);

			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			getline(inFile, temp, '"');
			array[i].score2 = stoi(temp);
			getline(inFile, temp);

			getline(inFile, temp);
			getline(inFile, temp);
		}
	}

	else
		cout << "File not found";

	inFile.close();
}

void readFile()
{
	int filetype;
	bool loop = true;

	while (loop)
	{
		cout << "What filetype are you reading in?" << endl << "1: Text Files (.txt)" << endl << "2: CSV Files (.csv)" << endl << "3: JSON Files (.json)" << endl << endl;
		cout << "Choose 1, 2 or 3 from above: ";
		cin >> filetype;
		cout << endl;

		switch (filetype)
		{
			case 1:
				//process .txt file
				readTxt("1", teamScoresList1);
				readTxt("2", teamScoresList2);
				readTxt("3", teamScoresList3);
				loop = false;
				break;

			case 2:
				//process .csv file
				readCsv("1", teamScoresList1);
				readCsv("2", teamScoresList2);
				readCsv("3", teamScoresList3);
				loop = false;
				break;

			case 3:
				//process .json file
				readJson("1", teamScoresList1);
				readJson("2", teamScoresList2);
				readJson("3", teamScoresList3);
				loop = false;
				break;

			default:
				cout << endl << "Please enter either 1, 2 or 3 for the option of your choice" << endl << endl;
		}
	}
}

//Function for swapping array elements
void swap(TeamScores* xp, TeamScores* yp)
{
	TeamScores temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort for the sort portion of the mergeSort function 
void bubbleSortTeam(TeamScores arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j].team1 > arr[j + 1].team1) swap(&arr[j], &arr[j + 1]);
		}
	}
}

void bubbleSortScore(TeamScores arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j].score1 < arr[j + 1].score1) swap(&arr[j], &arr[j + 1]);
		}
	}
}

void mergeSort(TeamScores array1[], TeamScores array2[], TeamScores array3[])
{
	TeamScores* target = NULL;
	int inc = 0;

	//Merge Arrays
	for (int i = 1; i < 4; i++)
	{
		if (i == 1) target = array1;
		else if (i == 2) target = array2;
		else if (i == 3) target = array3;

		for (int j = 0; j < n; j++)
		{
			teamScoresList4[inc] = target[j];
			inc++;
		}
	}

	//Sort Merged Array
	bubbleSortTeam(teamScoresList4, z);
}

void writeFile(TeamScores array[])
{
	//Output merged and sorted array to file and the screen
	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::trunc);

	if (outFile)
	{
		outFile << "Merged and Sorted Files:" << endl << "Team 1\t\t" << "Team 2\t\t" << "Score 1\t\t" << "Score 2\t\t" << endl;
		cout << "Merged and Sorted Files:" << endl << "Team 1\t\t" << "Team 2\t\t" << "Score 1\t\t" << "Score 2\t\t" << endl;

		for (int i = 0; i < (n * 3); i++)
		{
			outFile << array[i].team1 << "\t\t" << array[i].team2 << "\t\t" << array[i].score1 << "\t\t" << array[i].score2 << endl;
			cout << array[i].team1 << "\t\t" << array[i].team2 << "\t\t" << array[i].score1 << "\t\t" << array[i].score2 << endl;
		}

		outFile << endl;
		cout << endl;
	}

	else
		cout << "File not found";

	outFile.close();
}

void prepareStats()
{
	//Create array to list number of points for each team
	for (int i = 0; i < x; i++)
	{
		int k = 0;

		if (i == 0) k = 1;
		else k = i * 2;

		teamsPoints[i] = teamScoresList4[k];
	}

	for (int i = 0; i < x; i++)
		teamsPoints[i].score1 = 0;

	//Create array to list number of games won for each team
	for (int i = 0; i < x; i++)
	{
		teamsGames[i].team1 = teamsPoints[i].team1;
		teamsGames[i].score1 = teamsPoints[i].score1;
	}

	//Calculate the number of points gained by each team
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < z; j++)
		{
			if (teamScoresList4[j].team1 == teamsPoints[i].team1)
				teamsPoints[i].score1 += teamScoresList4[j].score1;

			if (teamScoresList4[j].team2 == teamsPoints[i].team1)
				teamsPoints[i].score1 += teamScoresList4[j].score2;
		}
	}

	//Calculate the number of games won by each team
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < z; j++)
		{
			if (teamScoresList4[j].team1 == teamsGames[i].team1)
			{
				if (teamScoresList4[j].score1 > teamScoresList4[j].score2)
					teamsGames[i].score1++;
			}

			if (teamScoresList4[j].team2 == teamsGames[i].team1)
			{
				if (teamScoresList4[j].score2 > teamScoresList4[j].score1)
					teamsGames[i].score1++;
			}
		}
	}
	
	bubbleSortScore(teamsPoints, x);
	bubbleSortScore(teamsGames, x);
}

//Calculate and output how many points each team gained
void pointsGained()
{
	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::app);

	cout << "Points scored for each team" << endl << "Team\tPoints" << endl;
	outFile << "Points scored for each team" << endl << "Team\tPoints" << endl;

	for (int i = 0; i < x; i++)
	{
		cout << teamsPoints[i].team1 << "\t" << teamsPoints[i].score1 << endl;
		outFile << teamsPoints[i].team1 << "\t" << teamsPoints[i].score1 << endl;
	}

	cout << endl;
	outFile << endl;

	outFile.close();
}

//Calculate and output how many games each team won
void gamesWon()
{
	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::app);

	cout << "Games won for each team" << endl << "Team\tWins" << endl;
	outFile << "Games won for each team" << endl << "Team\tWins" << endl;

	for (int i = 0; i < x; i++)
	{
		cout << teamsGames[i].team1 << "\t" << teamsGames[i].score1 << endl;
		outFile << teamsGames[i].team1 << "\t" << teamsGames[i].score1 << endl;
	}

	cout << endl;
	outFile << endl;

	outFile.close();
}

//Calculate and output which team won the most games
void mostWins()
{
	string team = teamsGames[0].team1;
	int points = teamsGames[0].score1;

	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::app);

	cout << "Team With Most Wins:\t" << team << "\t\t" << points << " wins" << endl;
	outFile << "Team With Most Wins:\t" << team << "\t\t" << points << " wins" << endl;

	for (int i = 1; i < x; i++)
	{
		if (points == teamsGames[i].score1)
		{
			if (team != teamsGames[i].team1)
			{
				cout << "Tie for first!" << endl;
				outFile << "Tie for first!" << endl;
				team = teamsGames[i].team1;
				points = teamsGames[i].score1;
				cout << "Tied for Most Wins:\t" << team << "\t\t" << points << " wins" << endl;
				outFile << "Tied for Most Wins:\t" << team << "\t\t" << points << " wins" << endl;
			}
		}
	}

	cout << endl;
	outFile << endl;

	outFile.close();
}

//Calculate and output which team won the least games
void leastWins()
{
	string team = teamsGames[x - 1].team1;
	int points = teamsGames[x - 1].score1;

	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::app);

	cout << "Team With Least Wins:\t" << team << "\t\t" << points << " wins" << endl;
	outFile << "Team With Least Wins:\t" << team << "\t\t" << points << " wins" << endl;

	for (int i = x-1; i >= 0; i--)
	{
		if (points == teamsGames[i].score1)
		{
			if (team != teamsGames[i].team1)
			{
				cout << "Tie for last!" << endl;
				outFile << "Tie for last!" << endl;
				team = teamsGames[i].team1;
				points = teamsGames[i].score1;
				cout << "Tied for Least Wins:\t" << team << "\t\t" << points << " wins" << endl;
				outFile << "Tied for Least Wins:\t" << team << "\t\t" << points << " wins" << endl;
			}
		}
	}

	cout << endl;
	outFile << endl;

	outFile.close();
}

//Calculate and output which team gained the most total points
void mostPoints()
{
	string team = teamsPoints[0].team1;
	int points = teamsPoints[0].score1;

	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::app);

	cout << "Highest Scoring Team:\t" << team << "\t\t" << points << " points" << endl;
	outFile << "Highest Scoring Team:\t" << team << "\t\t" << points << " points" << endl;

	for (int i = 1; i < x; i++)
	{
		if (points == teamsGames[i].score1)
		{
			if (team != teamsGames[i].team1)
			{
				cout << "Tie for first!" << endl;
				outFile << "Tie for first!" << endl;
				team = teamsGames[i].team1;
				points = teamsGames[i].score1;
				cout << "Tied for Highest Score:\t" << team << "\t\t" << points << " points" << endl;
				outFile << "Tied for Highest Score:\t" << team << "\t\t" << points << " points" << endl;
			}
		}
	}

	cout << endl;
	outFile << endl;

	outFile.close();
}

//Calculate and output which team gained the fewest total points
void leastPoints()
{
	string team = teamsPoints[x - 1].team1;
	int points = teamsPoints[x - 1].score1;

	string fname = inOut + inputFile + outputFile;
	ofstream outFile;
	outFile.open(fname, ios::app);

	cout << "Lowest Scoring Team:\t" << team << "\t\t" << points << " points" << endl;
	outFile << "Lowest Scoring Team:\t" << team << "\t\t" << points << " points" << endl;

	for (int i = x - 1; i >= 0; i--)
	{
		if (points == teamsGames[i].score1)
		{
			if (team != teamsGames[i].team1)
			{
				cout << "Tie for last!" << endl;
				outFile << "Tie for last!" << endl;
				team = teamsGames[i].team1;
				points = teamsGames[i].score1;
				cout << "Tied for Lowest Score:\t" << team << "\t\t" << points << " points" << endl;
				outFile << "Tied for Lowest Score:\t" << team << "\t\t" << points << " points" << endl;
			}
		}
	}

	cout << endl;
	outFile << endl;

	outFile.close();
}
