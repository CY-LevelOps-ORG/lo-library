#ifndef DATABASE_H
#define DATABASE_H 1

#include <list>
#include "Book.h"
using namespace std;


class Database
{
private:
    list<Book>  m_books;
private:
    list<Book>::iterator    find_book(const int book_id);
public:
    Database();
    ~Database();
    void    initialize();
    void    print_catalog() const;
    void    checkout_book(const int book_id);
    void    return_book(const int book_id);
};

#endif // DATABASE_H