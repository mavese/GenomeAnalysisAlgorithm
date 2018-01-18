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
	ifstream data(file.c_str());
	string line;
	bool isHeader = false;
	vector<int> results;
	int lastInd;
	if (data.is_open()) 
	{
		while (getline(data, line)) 
		{
			lastInd = 0;
			isHeader = false;
			if (line == ">chr2L")
			{
				isHeader = true;
			}
			if (!isHeader)
			{
				if (!results.empty())
				{
					lastInd = results.back();
					results.clear();
					results = table.updateConsecutiveWords(line, lastInd);
				}
				else
				{
					int i = 0;
					for (i; i < line.size(); i++)
					{
						lastInd = table.updateWord(line.substr(i, wordLength));
						if (lastInd != -1)
						{
							results = table.updateConsecutiveWords(line.substr(i + wordLength, line.size()-(i+wordLength)), lastInd);
							break;
						}
					}
				}
			}
		}
	}
	table.printTable();
	data.close();
	return 0;
}