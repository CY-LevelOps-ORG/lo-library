#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;


class Book {
public:
    const int       m_id;
    const string    m_name;
    int             m_available_copies;

    Book(const int id, const string name, const int total_copies);
    Book(const Book& other);
};

#endif // BOOK_H