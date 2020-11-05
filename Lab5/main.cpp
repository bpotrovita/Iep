#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class Book
{

public:
	int pageNumber;

	Book() { std::cout << "\nConstructing Book\n"; }

	Book(const int& pageNumber, const string& title, const string& author)
	: pageNumber(pageNumber),
	title(title),
	author(author)
	{};
	
	virtual ~Book()
	{
		std::cout << "\nDestructor Book\n";
	}
	
	Book(const Book &b2)
	{
		//This is a copy constructor;
		pageNumber = b2.pageNumber;
		title = b2.title;
		author = b2.author;
	}
	
        // This is not working properly.
	/*Book& operator = (const Book &rhs) 
	{
		std::cout << "\nAsigment operator called." << "\n";

		if(this != &rhs) // Self assigment check
		{
			delete [] data; // deallocate old memory
			size = rhs.size; // copy values

			data = new int [rhs.size]; // allocate new space
			for (int i = 0; i< size; i++)
				data[i] = rhs.data[i];
		}
		return *this;
	}*/
	Book& operator = (const Book &b)
	{
		std::cout << "\nAsigment operator called." << "\n";
		return *this;
	}
	
	string getTitle() 	{return title;}
	string getAuthor()	{return author;}

protected:
	string title;
	string author;

private:
	// int *data;
	// size_t size;
};


class ShortStory: public Book
{
	public:
		ShortStory(const ShortStory& shortStory): Book(shortStory), name(shortStory.name)
		{}

		ShortStory() { std::cout << "\nConstructing Book\n"; }

		~ShortStory() { std::cout << "\nDestructing ShortStory\n";}
		
		ShortStory& operator=(const ShortStory& story)
		{
			Book::operator=(story);
			name = story.name;
			return *this;
		}

	private:
		string name;
};

int main()
{	
	Book b1(20, "Cartea Junglei", "Autor1"); // Normal constructor is called here.
	Book b2 = b1; // Copy constructor is called here.
	Book b3;
	b3 = b1; //calls assigment operator; 

	std::cout << "\nPage number:" << b1.pageNumber << "\nTitle:" << b1.getTitle() << "\nAuthor:" << b1.getAuthor() << "\n";
	std::cout << "\nPage number:" << b2.pageNumber << "\nTitle:" << b2.getTitle() << "\nAuthor:" << b2.getAuthor() << "\n";
	
	ShortStory *shortStory = new ShortStory();
	Book *book = shortStory;
	delete book;
	getchar();

	return 0;
}