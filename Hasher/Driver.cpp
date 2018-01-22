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
	string leftOver = "";
	if (data.is_open()) 
	{
		while (getline(data, line)) 
		{
			lastInd = 0;
			isHeader = false;
			if (line.at(0) == '>')
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
					for (int i = 0; i < line.size(); i++)
					{
						if (line.size() >= i + wordLength)
							{
								if (leftOver.size() > 0)
								{
									lastInd = table.updateWord(leftOver + line.substr(i, wordLength - leftOver.size()));
									leftOver = leftOver.substr(1, leftOver.size() - 2);//strip first character
								}
								else
								{
									lastInd = table.updateWord(line.substr(i, wordLength));
								}
								if (lastInd != -1)
								{
									results = table.updateConsecutiveWords(line.substr(i + wordLength, line.size()-(i+wordLength)), lastInd);
									break;
								}
						}
						else
						{
							leftOver = line.substr(i, wordLength - 1);
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