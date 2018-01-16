//Author: Matteo Mantese

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<bitset>
#include<cmath>
using namespace std;
vector<int> hashs;
int wordLength;

int hashWord(string word)
{
	int binary = 0;
	int wordNum;
	for (size_t i = 0; i < word.length(); i++)
	{
		switch (word.at(i))
		{
		case('a'):
			wordNum = 0;
			break;
		case('c'):
			wordNum = 1;
			break;
		case('g'):
			wordNum = 2;
			break;
		case('t'):
			wordNum = 3;
			break;
		}
		binary = binary << 2;
		binary |= wordNum;
	}
	hashs[binary] += 1;
	return binary;
}

int hashConsecutiveWords(string line, int LastInd)
{
	int wordNum;
	for (size_t i = wordLength; i < line.size(); i++)
	{
		LastInd = (LastInd << 2) & 256;
		switch (line.at(i))
		{
		case('a'):
			wordNum = 0;
			break;
		case('c'):
			wordNum = 1;
			break;
		case('g'):
			wordNum = 2;
			break;
		case('t'):
			wordNum = 3;
			break;
		}
		LastInd |= wordNum;
		hashs[LastInd] += 1;
	}
	return 0;
}

int main()
{
	string line;
	cout << "Enter size of word: ";
	cin >> wordLength;
	hashs = vector<int>(pow(4, wordLength),0);
	ifstream data("data.txt");
	if (data.is_open())
	{
		while (getline(data, line))
		{
			int initIdx = hashWord(line.substr(0, wordLength));
			cout << endl;
			hashConsecutiveWords(line, initIdx);
		}
	}
	data.close();
	cout << "finished";
	cin >> line;
	return 0;
}