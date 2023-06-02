#ifndef BOOK
#define BOOK
#include "material.h"
#include <iostream>

class Book : public Material {
public:
    Book();
    Book(const Book&);
    Book(Book&&);
    Book& operator=(const Book&);
    Book& operator=(Book&&);
    int get_year() const;
    int get_pages() const;
    std::string get_genre() const;
    std::string get_author() const;
    std::string get_title() const;
    void set_year(const int);
    void set_pages(const int);
    void set_genre(const std::string&);
    void set_author(const std::string&);
    void set_title(const std::string&);
    void use() override;
    bool is_borrowed() override;
private:
    void my_swap(Book&) noexcept;
    std::string m_title = "";
    std::string m_author = "";
    int m_year = 0;
    std::string m_genre = "";
    int m_pages = 0;
};

#include "book.hpp"

#endif //BOOK