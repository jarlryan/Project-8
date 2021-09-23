/* book.cpp By Ryan Jarl
   Created on: Apr 3, 2021 */
#include <iostream>
#include <fstream>
#include <string>
#include "book.h"


using namespace std;

	void Book::print(ofstream& output) const {
		output << left << setw(10) << "Author: " << author << endl;
		output << setw(10) << "Title: " << title << endl;
		output << setw(10) << "ISBN: " << ISBN << endl << endl;
	}
	void Book::getData(ifstream& input){
		getline(input, author);
		getline(input, title);
		input >> ISBN;
		input.ignore('\n', 10);
	}
	long int Book::getISBN() const {
		return ISBN;
	}
