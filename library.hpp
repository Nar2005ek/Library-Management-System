#include "library.h"

Library::Library() {}

Library::~Library() = default;

Library::Library(const Library& other) {
    m_book_count = other.m_book_count;
    m_dvd_count = other.m_dvd_count;
    m_journal_count = other.m_journal_count;
}

Library::Library(const Library&& other) {
    m_book_count = other.m_book_count;
    m_dvd_count = other.m_dvd_count;
    m_journal_count = other.m_journal_count;
}

void Library::operator=(const Library& other) {
    m_book_count = other.m_book_count;
    m_dvd_count = other.m_dvd_count;
    m_journal_count = other.m_journal_count;
}

void Library::operator=(const Library&& other) {
    m_book_count = other.m_book_count;
    m_dvd_count = other.m_dvd_count;
    m_journal_count = other.m_journal_count;
}

void Library::set_book_count(const int book_count) {
    m_book_count = book_count;
}

void Library::set_dvd_count(const int dvd_count) {
    m_dvd_count = dvd_count;
}

void Library::set_journal_count(const int journal_count) {
    m_journal_count = journal_count;
}

int Library::get_book_count() const {
    return m_book_count;
}

int Library::get_dvd_count() const {
    return m_dvd_count;
}

int Library::get_journal_count() const {
    return m_journal_count;
}

void Library::add_book(Book& obj) {
    m_materials.push_back(&obj);
    ++m_book_count;
}

void Library::add_dvd(Dvd& obj) {
    m_materials.push_back(&obj);
    ++m_dvd_count;
}

void Library::add_journal(Journal& obj) {
    m_materials.push_back(&obj);
    ++m_journal_count;
}

void Library::rm_book(Book& obj) {
    if(rm_material(obj)) {
        --m_book_count;
        std::cout << "successfull" << '\n';
        return;
    }
    std::cout << "no such book" << '\n';
}

void Library::rm_dvd(Dvd& obj) {
    m_materials.pop_back();
    --m_dvd_count;
}

void Library::rm_journal(Journal& obj) {
    m_materials.pop_back();
    --m_journal_count;
}

bool Library::is_in_library(Material* ptr) {
    for(int i = 0; i < m_materials.size(); ++i) {
        if(ptr == m_materials[i]) {
            return true;
        }
    }
    return false;
}

void Library::take(Material* ob) {
    if(is_in_library(ob)) {
        if(!(ob->get_is_borrowed())) {
            ob->set_is_borrowed(true);
            std::cout << "success" << '\n';
            return;
        }
        std::cout << "book is borrowed" << '\n';
    }
    std::cout << "no such book" << '\n';
}

bool Library::rm_material(Material& obj) {
    for(auto it = m_materials.begin(); it != m_materials.end(); ++it) {
        if(*it == &obj) {
            m_materials.erase(it);
            return true;
        }
    }
    return false;
}