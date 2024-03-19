#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Book class
class Book
{
private:
    string title;
    string author;
    int year;

public:
    // Constructor
    Book(string _title, string _author, int _year) : title(_title), author(_author), year(_year) {}

    // Getter methods
    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getYear() const
    {
        return year;
    }

    // Display method
    void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

// Library class
class Library
{
private:
    vector<Book> books;

public:
    // Add a book to the library
    void addBook(const Book &book)
    {
        books.push_back(book);
    }

    // Remove a book from the library by title
    void removeBook(const string &title)
    {
        books.erase(remove_if(books.begin(), books.end(),
                              [&](const Book &book)
                              { return book.getTitle() == title; }),
                    books.end());
    }

    // Display all books in the library
    void displayAllBooks() const
    {
        cout << "Books in the library:" << endl;
        for (const auto &book : books)
        {
            book.display();
            cout << "-------------------------" << endl;
        }
    }

    // Search for a book by title
    void searchByTitle(const string &title) const
    {
        bool found = false;
        for (const auto &book : books)
        {
            if (book.getTitle() == title)
            {
                cout << "Book found:" << endl;
                book.display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Book with title '" << title << "' not found." << endl;
        }
    }
};

int main()
{
    Library library;

    // Adding books to the library
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("1984", "George Orwell", 1949));

    // Display all books
    library.displayAllBooks();

    cout << endl;

    // Remove a book
    cout << "Removing '1984' from the library..." << endl;
    library.removeBook("1984");

    // Display all books after removal
    library.displayAllBooks();

    cout << endl;

    // Search for a book
    cout << "Searching for 'To Kill a Mockingbird'..." << endl;
    library.searchByTitle("To Kill a Mockingbird");

    cout << endl;

    // Search for a book that doesn't exist
    cout << "Searching for 'Moby Dick'..." << endl;
    library.searchByTitle("Moby Dick");

    return 0;
}