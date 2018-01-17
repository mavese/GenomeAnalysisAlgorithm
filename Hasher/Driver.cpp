//Author: Matteo Mantese

#include <cstdlib>
#include <string>
#include<fstream>
#include "DnaHashTable.h"
using namespace std;

int main(int argc, char** argv) 
{
	//Get information from command line args
	int wordLength = atoi(argv[1]);
	string file = argv[2];
	// Build the hash table from the input file
	DnaHashTable table(wordLength);
	ifstream data(file);
	string line;
	if (data.is_open()) 
	{
		while (getline(data, line)) 
		{
			table.updateConsecutiveWords(line);
		}
	}
	table.printTable();
	data.close();
	return 0;
}