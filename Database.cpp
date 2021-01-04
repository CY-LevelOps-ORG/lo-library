#include <iostream>
#include <exception>
#include "Database.h"
using namespace std;

class BadBookIdError : public exception {
} badBookIDError;

Database::Database(/* args */)
{
}

Database::~Database()
{
}

void    Database::initialize() {
    // Initialize the database of books
    this->m_books.push_back(Book(1, "Alice In Wonderland", 2));
    this->m_books.push_back(Book(2, "Life of Pi", 2));
    this->m_books.push_back(Book(3, "Ironman", 3));
    this->m_books.push_back(Book(4, "Spiderman", 1));
    this->m_books.push_back(Book(5, "Wall Street Journal", 1, true));
    this->m_books.push_back(Book(6, "New York Times", 2, true));
}

void    Database::print_catalog() const {
    cout << "Catalog of Books" << endl;
    cout << "----------------" << endl;
    list<Book>::const_iterator it;
    for(it = this->m_books.begin(); it != this->m_books.end(); ++it) {
        if (it->m_newspaper && !this->m_enable_newspapers) {
            // Skip newspapers if they are not enabled.
            continue;
        }
        cout << it->m_id << ") " << it->m_name << ", ";
        if (it->m_available_copies > 0) {
            cout << it->m_available_copies << " copies available";
        } else {
            cout << "NOT AVAILABLE";
        }
        cout << endl;
    }
}

list<Book>::iterator    Database::find_book(const int book_id) {
    list<Book>::iterator it;
    for(it = this->m_books.begin(); it != this->m_books.end(); it++) {
        if (it->m_newspaper && !this->m_enable_newspapers) {
            // Skip news papers if they are not enabled
            continue;
        }
        if ((it->m_id == book_id) ) {
            // Found the selected book.
            return it;
        }
    }
    throw badBookIDError;
}

void    Database::checkout_book(const int book_id) {
    // Find the book and decrement the number of available copies
    try {
        list<Book>::iterator it = this->find_book(book_id);
        // Found the selected book.
        // Check if copies are available
        if (it->m_available_copies > 0) {
            it->m_available_copies--;
            cout << "Successfully checkedout " << it->m_name << endl;
        } else {
            cout << "Failed to checkout " << it->m_name << ", no available copies" << endl;
        }
    } catch (exception& e) {
        cerr << "Invalid book ID " << book_id << endl;
    }
}

void    Database::return_book(const int book_id) {
    // Find the book and increment the number of available copies
    try {
        list<Book>::iterator it = this->find_book(book_id);
        // Found the selected book.
        it->m_available_copies++;
        cout << "Successfully returned " << it->m_name << endl;
    } catch (exception& e) {
        cerr << "Invalid book ID " << book_id << endl;
    }
}

void    Database::enable_newspapers(const bool enable) {
    this->m_enable_newspapers = enable;
}
