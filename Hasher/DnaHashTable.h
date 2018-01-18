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
#include<string>

using namespace std;

class DnaHashTable {
private:
	vector<int> hashs;
	int wordLength;
	int hashWord(string);
	vector<int> hashConsecutiveWords(string, int);
	int getLetterVal(char);


public:
	DnaHashTable(int);
	virtual ~DnaHashTable();
	int updateWord(string);
	vector<int> updateConsecutiveWords(string, int);
	void printTable();

	/**
	 * update for one word
	 * updateConsecutive for consecutive words
	 * getCount for one word
	 * getCountConsecutive for consecutive words
	 * Print table
	 */

};

#endif /* DNAHASHTABLE_H_ */
