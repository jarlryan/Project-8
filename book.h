/* book.h By Ryan Jarl
   Created on: Apr 3, 2021 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Book{
private:
	string author;
	string title;
	long int ISBN;
public:
	Book(){
		author = "No Name";
		title = "Unknown Title";
		ISBN = 0;
	}
	void print(ofstream&)const;
	void getData(ifstream&);
	long int getISBN() const;
};
