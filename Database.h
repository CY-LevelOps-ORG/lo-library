#ifndef DATABASE_H
#define DATABASE_H 1

#include <list>
#include "Book.h"
using namespace std;


class Database
{
private:
    bool        m_enable_newspapers;
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
    void    enable_newspapers(const bool enable);
};

#endif // DATABASE_H