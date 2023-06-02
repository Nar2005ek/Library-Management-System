#include "book.h"
#include <iostream>

Book::Book() {}

Book::Book(const Book& other) {
    set_is_borrowed(other.get_is_borrowed());
    m_author = other.m_author;
    m_genre = other.m_genre;
    m_pages = other.m_pages;
    m_title = other.m_title;
    m_year = other.m_year;
}

Book::Book(Book&& other) {
    my_swap(other);
}

Book& Book::operator=(const Book& other) {
    if(this != &other) {    
       Book tmp{other};
       my_swap(tmp);
    }
    return *this;
}

Book& Book::operator=(Book&& other) {
    if(this != &other) {
        my_swap(other);
    }
    return *this;
}

int Book::get_year() const
{
    return m_year;
}

int Book::get_pages() const {
    return m_pages;
}

std::string Book::get_genre() const {
    return m_genre;
}

std::string Book::get_author() const {
    return m_author;
}

std::string Book::get_title() const {
    return m_title;
}

void Book::set_year(const int year) {
    m_year = year;
}

void Book::set_pages(const int pages) {
    m_pages = pages;
}

void Book::set_genre(const std::string& genre) {
    m_genre = genre;
}
 
void Book::set_author(const std::string& author) {
    m_author = author;
}

void Book::set_title(const std::string& title) {
    m_title = title;
}

void Book::use() {
    if(is_borrowed()) {
        std::cout << "You Are Reading" << '\n';
    }
}

bool Book::is_borrowed() {
    return get_is_borrowed();
}

void Book::my_swap(Book& th)noexcept {
    std::swap(m_author,th.m_author);
    std::swap(m_genre,th.m_genre);
    std::swap(m_pages,th.m_pages);
    std::swap(m_year,th.m_year);
    std::swap(m_title,th.m_title);
    set_is_borrowed(th.get_is_borrowed());
}
