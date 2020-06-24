// ===========================================================================
// file: file_analysis.cpp
// ============================================================================
// Programmer: Brian Che
// Date: 06/24/20
// Class: CSCI 123 ("Intro to Prgramming Using C++")
// Time: MWTR 10:40am
// Instructor: Dr. Rodriguez
// Project: File Analysis
//
// Description:
// 		Analyze the contents of an external file, which will be the
//		"dracula.txt" file, and count the number of uppercase, lowercase,
//		digit, punctuation, whitespace, lines, periods, and question mark
//		characters.
//
// ============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

//function prototype

int ReadFile(ifstream &inFile, int &totalUpper, int &totalLower,
	int &totalDigits, int &totalPunct, int &totalSpace, int &totalLines,
    int &totalPeriods, int &totalQuestion);



// ==== main ==================================================================
//
// ============================================================================

int main()
{
	int totalChars;
	int totalUpper;
	int totalLower;
	int totalDigits;
	int totalPunct;
	int totalSpace;
	int totalLines;
	int totalPeriods;
	int totalQuestion;

	// Extract dracula.txt file and initialize it as inFile
	ifstream inFile;
	inFile.open("dracula.txt");

	// Call function to determine numbers of these factors
	totalChars = ReadFile(inFile, totalUpper,totalLower, totalDigits,
		totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion);


	// Display the values to the user through the pass by reference variables
	cout  << "File \"dracula.txt\" contains the following:" << endl
	      << totalChars;

	cout << "  Uppercase letters:     " << setw(14) << totalUpper << endl;    
	cout << "  Lowercase letters:     " << setw(14) << totalLower << endl;
	cout << "  Digits:                " << setw(14) << totalDigits << endl;
	cout << "  Punctuation Characters:" << setw(14) << totalPunct << endl;
	cout << "  Whitespace Characters: " << setw(14) << totalSpace << endl;
	cout << "  Lines:                 " << setw(14) << totalLines << endl;
	cout << "  Total Periods:         " << setw(14) << totalPeriods << endl;
	cout << "  Total Question Marks:  " << setw(14) << totalQuestion << endl;
	cout << "  Total characters read: " << setw(14) << totalChars << endl;

	return 0;
} // End of "main"



// ==== ReadFile ==============================================================
//
// This function calculates the number of uppercase letters, lowercase letters,
// digits, punctuation, whitespaces, lines, periods, and question marks.
//
// Input:
//
// Output:
//
// =============================================================================

int ReadFile(ifstream &inFile, int &totalUpper, int &totalLower,
	int &totalDigits, int &totalPunct, int &totalSpace, int &totalLines,
	int &totalPeriods, int &totalQuestion)
{
	char charVal;
	int count = 0;

	do
	{
		inFile.get(charVal);

		if (inFile.eof())
		{
			break;
		}

		if (isupper(charVal))
		{
			totalUpper++ ;
		}

		if (islower(charVal))
		{
			totalLower++ ;
		}

		if (isdigit(charVal))
		{
			totalPunct++ ;
		}

		if (isspace(charVal))
		{
			totalSpace++ ;
		}

		if (charVal == '\n')
		{
			totalLines++ ;
		}


		if (charVal == '.')
		{
			totalPeriods++ ;
		}
		

		if (charval == '?')
		{
			totalQuestions++ ;
		}

		++count;
		
	} while (true);

	return count;
} // End of "ReadFile"