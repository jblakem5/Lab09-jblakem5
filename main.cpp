// Lab09-jblakem5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Justin Blakeman
//Lab09
//COSC 2030
//December 9, 2018

#include "pch.h"
#include <iostream>
#include <map>			//do the hard part 
#include <string>
#include <fstream>
using namespace std;

////////////////////////////////BEGIN THE MEAT

void writeFile(ofstream & file, map<string, int> & tally);	//specialty red and write functions for our purposes
void readFile(fstream & file, map<string, int> & tally);

int main() {

	fstream theFile;
	string fileName;
	map<string, int> tally;

	//your basic opening of a file and such
	do {
		cout << "Enter The Name Of a File: ";
		cin >> fileName;
		theFile.open(fileName);
		cout << "Oops! I Could Not Open " << fileName << " !" << endl;	//opens the file if it can, infinte asking loop
	} while (!theFile.is_open());

	readFile(theFile, tally);		//read the opened file to theFile in function below
	theFile.close();
	ofstream outputFile("output.txt");		//create a file to output result
	writeFile(outputFile, tally);		//calss the writeFile function, does as implies	

	return 0;
}

void writeFile(ofstream & theFile, map<string, int> & tally) {
	for (map<string, int>::iterator iter = tally.begin(); iter != tally.end(); iter++) {
		string str = iter->first;		//move along each member, equal str each iter
		int i = iter->second;			//and the int
		while (i > 0) {
			i--;
			theFile << str << " ";		//write out to file
		}
	}
}

void readFile(fstream & theFile, map<string, int> & tally) { //help from Will Cary on this headache. "tally" easy in hindsight
	string input;
	while (theFile >> input) { //while there is stuff in tempfile
		++tally[input];
	}
}