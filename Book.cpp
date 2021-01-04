#include "Book.h"

Book::Book(const int id, const string name, const int total_copies) : 
    m_id(id), 
    m_name(name), 
    m_available_copies(total_copies)
{
}

Book::Book(const Book& other) :
    m_id(other.m_id),
    m_name(other.m_name),
    m_available_copies(other.m_available_copies)
{

}

