#include <iostream>
#include <string.h>
#include <memory>
#include <string>

using namespace std;

struct NumberOfCards
{
	explicit NumberOfCards(int numberOfCards)
	: val(numberOfCards) {}
	int val;
};

struct SuiteOfCards
{
	explicit SuiteOfCards(string suiteOfCards)
	: val(suiteOfCards) {}
	string val;
};

class DeckOfCards
{
public:
	DeckOfCards(const NumberOfCards& numberOfCards, const SuiteOfCards& suiteOfCards)
		: numberOfCards(numberOfCards),
		  suiteOfCards(suiteOfCards)
	{};
private:
	NumberOfCards numberOfCards;
	SuiteOfCards suiteOfCards;
};

class Book
{
public:
	Book() { std::cout << "\nConstruct Book\n"; }

	Book(const int& pageNumber, const string& title, const string& author)
	: pageNumber(pageNumber),
	title(title),
	author(author)
	{};
	
	virtual ~Book() = 0;

	Book& operator = (const Book &b)
	{
		std::cout << "\nAsigment operator called." << "\n";
		return *this;
	}

	void ShowInfo()
	{
		std::cout << "\nNumber of pages: " << pageNumber << endl;
		std::cout << "\nAuthor is: " << getAuthor() << endl;
		std::cout << "\nTitle is: " << getTitle() << endl;
	}
	
	int GetNumber() const        {return pageNumber;}
	string getTitle() const	     {return title;}
	string getAuthor() const     {return author;}

protected:
	Book(const Book &rhs)
	{
		std::cout << "\nCopyConstructor\n";
		pageNumber = rhs.pageNumber;
		title = rhs.title;
		author = rhs.author;
	};

private:
	int pageNumber;
	string title;
	string author;
};

Book::~Book()
{
	std::cout << "\nDestructor Book\n";
}

class ShortStory: public Book
{
	public:
		ShortStory(const int& numberOfPages, const string& storyName, const string& storyAuthor, const string& name);
			Book(numberOfPages, storyName, storyAuthor),
			name(name)
		{std::cout << "Construct ShortStory."};

		~ShortStory() { std::cout << "\nDestruct ShortStory\n";}

		ShortStory(const ShortStory &shortStory): Book(shortStory), name(shortStory.name);
		{};
		
		ShortStory &operator=(const ShortStory &story)
		{
			Book::operator=(story);
			name = story.name;
			return *this;
		}
	
	public:
		string name;
	private:
		Book *book;
};

void provideAccessBook(ShortStory *shortStory)
{
	shortStory->ShowInfo();
}

int main()
{	
	std::auto_ptr<ShortStory> shortStory1(new ShortStory(23,"The Adventure", "Mark Twain", "Name1"));

	std::shared_ptr<ShortStory> shortStory2(new ShortStory(45, "Pam", "MihaiEminescu", "Name2"));
	std::shared_ptr<Book> shortStory3(shortStory2);

	shortStory2 = shortStory3;

	shortStory1->ShowInfo();

	// intem 15
	provideAccessBook(shortStory2.get());
	shortStory3->ShowInfo();

	DeckOfCards *deckOfCards = new DeckOfCards(NumberOfCards(52), SuiteOfCards("There are 4 suite colors.");
	
	shortStory2->ShowInfo();

	return 0;
}