/*
 * DnaHashTable.h
 *
 *  Created on: Jan 16, 2018
 *      Author: zakarota
 */

#ifndef DNAHASHTABLE_H_
#define DNAHASHTABLE_H_

#include <vector>
#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include<bitset>

using namespace std;

class DnaHashTable {
private:
	vector<int> * hashs;
	int wordLength;
	int hashWord(string);
	vector<int> hashConsecutiveWords(string, int);
	int getLetterVal(char);


public:
	DnaHashTable(int);
	virtual ~DnaHashTable();

	/**
	 * update for one word
	 * updateConsecutive for consecutive words
	 * getCount for one word
	 * getCountConsecutive for consecutive words
	 * Print table
	 */

};

#endif /* DNAHASHTABLE_H_ */
