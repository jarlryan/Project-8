/* mp8bookDriver.cpp By Ryan Jarl
   Created on: Apr 3, 2021 */

#include <iostream>
#include <fstream>
#include <string>
#include "book.h"

using namespace std;

const int BOOKS = 10;
bool checkLibrary(Book Books[], int quantBooks, long int isbn, ofstream& output);

int main()
{
	ifstream input1, input2, input3;
	ofstream output;
	long int isbnSearch;
	input1.open("mp8book.txt");
	output.open("mp8output.txt");
	Book Book1 = Book();
	Book Book2;
	Book library[BOOKS];
	output << "Part 1: Testing The Book Class By Ryan Jarl" << endl << endl;
	output << "The Information For Book 1 Is: " << endl;
	Book1.print(output);
	Book2.getData(input1);
	output << "The Information For Book 2 Is: " << endl;
	Book2.print(output);
	output << "Book 2 Has ISBN: " << Book2.getISBN() << endl << endl;
	input1.close();
	output << "Part 2: Establishing The Small Library " << endl << endl;
	input2.open("mp8bookarray.txt");
	while(input2){
		for(int i = 0; i < BOOKS; i++){
			library[i].getData(input2);
			library[i].print(output);
		}
	}
	input2.close();
	output << "Part 3: Searching The Library For Books By ISBN " << endl << endl;
	input3.open("mp8bookISBN.txt");
	while(input3){
		input3 >> isbnSearch;
		input3.ignore('n', 10);
		checkLibrary(library, BOOKS, isbnSearch, output);
	}
	input3.close();
	output.close();
	return 0;
}
bool checkLibrary(Book Books[], int quantBooks, long int isbn, ofstream& output){
	output << "Checking For Book With ISBN: " << isbn << endl << endl;
	for(int i = 0; i < quantBooks; i++){
		if(Books[i].getISBN() == isbn){
			Books[i].print(output);
			return true;
		}
	}
	output << "ISBN: " << isbn << "  ...Book ISBN Not Found!" << endl << endl;
	return false;
}
