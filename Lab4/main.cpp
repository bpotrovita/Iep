#include <iostream>
#include <string.h>

using namespace std;

class Book
{

public:
	int pageNumber;

	Book() {}

	Book(const int& pageNumber, const string& title, const string& author)
	: pageNumber(pageNumber),
	title(title),
	author(author)
	{};
	
	~Book()
	{
		std::cout << "\nDestructor\n";
	}
	
	Book(const Book &b2)
	{
		//This is a copy constructor;
		pageNumber = b2.pageNumber;
		title = b2.title;
		author = b2.author;
	}
	
	Book& operator = (const Book &b)
	{
		std::cout << "\nAsigment operator called." << "\n";
		return *this;
	}
	
	string getTitle() 	{return title;}
	string getAuthor()	{return author;}

private:
	string title;
	string author;
};

int main()
{	
	Book b1(20, "Cartea Junglei", "Autor1"); // Normal constructor is called here.
	Book b2 = b1; // Copy constructor is called here.
	Book b3;
	b3 = b1; //calls assigment operator; 

	std::cout << "\nPage number:" << b1.pageNumber << "\nTitle:" << b1.getTitle() << "\nAuthor:" << b1.getAuthor() << "\n";
	std::cout << "\nPage number:" << b2.pageNumber << "\nTitle:" << b2.getTitle() << "\nAuthor:" << b2.getAuthor() << "\n";

	return 0;
}