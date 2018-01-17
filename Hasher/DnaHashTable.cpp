/*
 * DnaHashTable.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: Matteo Mantese
 *      Edited by Hani Girgis
 */

#include "DnaHashTable.h"
#include<cmath>

DnaHashTable::DnaHashTable(int w) {
	wordLength = w;
	hashs = new vector<int>(pow(4, wordLength), 0);
}

DnaHashTable::~DnaHashTable() {
	hashs->clear();
	delete hashs;
}

int DnaHashTable::hashWord(string word) {
	int binary = 0;
	int wordNum;
	for (size_t i = 0; i < word.length(); i++) {
		wordNum = getLetterVal(word.at(i));
		binary = binary << 2;
		binary |= wordNum;
	}
	return binary;
}

vector<int> DnaHashTable::hashConsecutiveWords(string line, int lastInd) {
	int wordNum;
	vector<int> resultList;
	for (size_t i = wordLength; i < line.size(); i++) {
		lastInd = (lastInd << 2) & 256;
		wordNum = getLetterVal(line.at(i));
		lastInd |= wordNum;
		resultList.push_back(lastInd);
		// hashs[LastInd] += 1;
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
	hashs[idx] += 1;
	return idx;
}

void DnaHashTable::updateConsecutiveWords(string line)
{
	vector<int> nums = hashConsecutiveWords(line, updateWord(line.substr(0, wordLength)));
	for (int i = 0; i < nums.size(); i++)
	{
		hashs[nums[i]] += 1;
	}
}

void DnaHashTable::printTable()
{
	for (size_t i = 0; i < hashs; i++)
	{
		if(hashs[i] != 0)
		{
			cout << i + " " + hashs[i];
		}
	}
}