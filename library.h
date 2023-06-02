#ifndef LIBRARY
#define LIBRARY
#include "material.h"
#include "book.h"
#include "journal.h"
#include "dvd.h"
#include <vector>

class Library {
public:
    Library();
    ~Library();
    Library(const Library&);
    Library(const Library&&);
    void operator=(const Library&);
    void operator=(const Library&&);
    void set_book_count(const int);
    void set_dvd_count(const int);
    void set_journal_count(const int);
    int get_book_count() const;
    int get_dvd_count() const;
    int get_journal_count() const;
    void add_book(Book&);
    void add_dvd(Dvd&);
    void add_journal(Journal&);
    void rm_book(Book&);
    void rm_dvd(Dvd&);
    void rm_journal(Journal&);
    bool is_in_library(Material*);
    void take(Material*);
private:
    int m_book_count = 0;
    int m_dvd_count = 0;
    int m_journal_count = 0;
    std::vector<Material*> m_materials;
    bool rm_material(Material&);
};

#include "library.hpp"

#endif //LIBRARY