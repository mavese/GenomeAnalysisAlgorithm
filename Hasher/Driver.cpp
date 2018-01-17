///*
// * FirstProjectDataStrucs.cpp
// *
// *  Created on: Jan 16, 2018
// *      Author: zakarota
// */
//
//#include "FirstProjectDataStrucs.h"
//
//FirstProjectDataStrucs::FirstProjectDataStrucs() {
//	// TODO Auto-generated constructor stub
//
//}
//
//FirstProjectDataStrucs::~FirstProjectDataStrucs() {
//	// TODO Auto-generated destructor stub
//}

//Author: Matteo Mantese

#include "DnaHashTable.h";

int main() {
	string line;
	int wordLength;

	// Get information from the user
	cout << "Enter size of word: ";
	cin >> wordLength;
	string file;
	cout << "Enter file name: ";
	cin >> file;

	// Build the hash table from the input file
	DnaHashTable table(wordLength);

	ifstream data(file);
	if (data.is_open()) {
		while (getline(data, line)) {
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
