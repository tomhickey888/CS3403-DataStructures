#include "HW4.h"

int main()
{
	//Open dialog to read files in
	readFile();

	//Merge and sort seperate arrays into 1 consolidated array
	mergeSort(teamScoresList1, teamScoresList2, teamScoresList3);

	//Display output to console and file
	writeFile(teamScoresList4);

	//Create and fill arrays used for displaying statistics
	prepareStats();
	
	//Calculate statistics and display to console and file
	mostPoints();
	mostWins();
	leastPoints();
	leastWins();
	pointsGained();
	gamesWon();

	return 0;
}