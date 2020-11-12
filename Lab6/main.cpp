#include <iostream>
#include <string.h>
#include <algorithm>
#include <memory>
#include <mutex>

std::mutex mtx;

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

	void showInfo()
	{
		std::cout <<"\nNumber of pages: " << pageNumber << endl;
		std::cout <<"\nAuthor is: " << getAuthor() << endl;
		std::cout <<"\nTitle is: " << getTitle() << endl;
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
		Book *book;
};

void printNumberOfPages(std::shared_ptr<Book> book)
{
	mtx.lock();
	std::cout << "\nMutex locked\n";
	book->showInfo();
	std::cout << "\nMutex unlocked\n";
	mtx.unlock();
}

void provideAccessBook(Book *book)
{
	book->showInfo();
}

int main()
{	
	std::auto_ptr<Book> book1(new Book(23, "Ham", "IonCreanga"));

	std::shared_ptr<Book> book2(new Book(45, "Pam", "MihaiEminescu"));
	std::shared_ptr<Book> book3(book2);

	book2 = book3;

	book1->showInfo();
	provideAccessBook(book2.get());
	book3->showInfo();

	printNumberOfPages(book2);

	return 0;
}