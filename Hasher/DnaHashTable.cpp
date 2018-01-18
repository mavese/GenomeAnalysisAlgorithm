/*
 * DnaHashTable.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: Matteo Mantese
 *      Edited by Hani Girgis
 */

#include "DnaHashTable.h"
#include<cmath>

DnaHashTable::DnaHashTable(int w) 
{
	wordLength = w;
	hashs = vector<int>(pow(4, wordLength), 0);
}

DnaHashTable::~DnaHashTable() 
{
	hashs.clear();
	vector<int>().swap(hashs);
}

int DnaHashTable::hashWord(string word) 
{
	if(word.size() < wordLength)
	{
		return -1;
	}
	int binary = 0;
	int wordNum;
	for (size_t i = 0; i < word.size(); i++) 
	{
		wordNum = getLetterVal(word.at(i));
		if(wordNum != -1)
		{
			binary = binary << 2;
			binary |= wordNum;
		}
		else
		{
			return -1;
		}
	}
	return binary;
}

vector<int> DnaHashTable::hashConsecutiveWords(string line, int lastInd) 
{
	int letterCount = wordLength;
	int wordNum;
	int mask = pow(2, 2*wordLength) -1;
	vector<int> resultList;
	for (int i = 0; i < line.size(); i++) 
	{
		wordNum = getLetterVal(line.at(i));
		if(wordNum != -1)
		{
			lastInd = (lastInd << 2) & mask;
			lastInd |= wordNum;
			letterCount++;
			if (letterCount >= wordLength)
			{
				resultList.push_back(lastInd);
			}
		}
		else
		{
			letterCount = 0;
		}
	}
	return resultList;
}

int  DnaHashTable::getLetterVal(char c)
{
	switch (c) 
	{
		case ('a'):
		case ('A'):
			return 0;
			break;
		case ('c'):
		case ('C'):
			return 1;
			break;
		case ('g'):
		case ('G'):
			return 2;
			break;
		case ('t'):
		case ('T'):
			return 3;
			break;
	}
	return-1;
}

int DnaHashTable::updateWord(string word)
{
	int idx = hashWord(word);
	if (idx != -1)
	{
		hashs[idx] += 1;
	}
	return idx;
}

vector<int> DnaHashTable::updateConsecutiveWords(string line, int lastInd)
{
	vector<int> nums = hashConsecutiveWords(line, lastInd);
	for (int i = 0; i < nums.size(); i++)
	{
		hashs[nums[i]] += 1;
	}
	return nums;
}

void DnaHashTable::printTable()
{
	string word = "";
	int tempi;
	for (size_t i = 0; i < hashs.size(); i++)
	{
		if(hashs[i] != 0)
		{
			tempi = i;
			word.clear();
			for (int idx = 0; idx < wordLength; idx++)
			{
				switch(tempi & 3)
				{
					case(0):
						word = 'A' + word;
						break;
					case(1):
						word = 'C' + word;
						break;
					case(2):
						word = 'G' + word;
						break;
					default:
						word = 'T' + word;
						break;
				}
				tempi = tempi >> 2;
			}
			cout << word << " " << hashs[i]<<endl;
		}
	}
}