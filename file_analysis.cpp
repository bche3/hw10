#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

int ReadFile(ifstream &inFile, int &totalUpper, int &totalLower,    int &totalDigits, int &totalPunct, int &totalSpace, int &        totalLines, int &totalPeriods, int &totalQuestion);

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

  ifstream inFile;
  inFile.open("dracula.txt");

  totalChars = ReadFile(inFile, totalUpper, totalLower, totalDigits, totalPunct, totalSpace, totalLines, totalPeriods, totalQuestion);
	
	cout  << "File \"dracula.txt\" contains the following:" << endl;
//         File "dracula.txt" contains the following:
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

}

int ReadFile(ifstream &inFile, int &totalUpper, int &totalLower, int &totalDigits, int &totalPunct, int &totalSpace, int &totalLines, int &totalPeriods, int &totalQuestion)
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
      totalDigits++ ;
    }

    if (ispunct(charVal))
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

    if (charVal == '?')
    {
      totalQuestion++ ;
    }

    count++;
  } while (true);

  
  return count;
}



	