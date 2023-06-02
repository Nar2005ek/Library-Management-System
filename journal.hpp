#include "journal.h"
#include "material.h"

Journal::Journal() = default;

Journal::~Journal() = default;

Journal::Journal(const Journal& th) {
    m_volume = th.m_volume;
    m_issue = th.m_issue;
    m_year = th.m_year;
    m_subject = th.m_subject;
    m_title = th.m_title;
    bool tmp {get_is_borrowed()};
    set_is_borrowed(tmp);

}

Journal::Journal(Journal&& th) {
    my_swap(th);
}
 
Journal& Journal::operator= (const Journal& tmp) {
    if(this != &tmp)
    {
        Journal tmp1{tmp};
        my_swap(tmp1);
    }
    return *this;
}

Journal& Journal::operator= (Journal&& th) {
    if (this != &th)
    {
        my_swap(th);
    }
    return *this;
}

void Journal::set_title(int title) {
    m_title = title;
}

void Journal::set_volume(int vol) {
    m_volume = vol;
}

void Journal::set_issue(const std::string& issue) {
    m_issue = issue;
}

void Journal::set_year(int year) {
    m_year = year;
}

void Journal::set_subject(const std::string& subj) {
    m_subject = subj;
}

int Journal::get_title() {
    return m_title;
}

int Journal::get_volume() {
    return m_volume;
}

std::string Journal::get_issue() {
    return m_issue;
}

int Journal::get_year() {
    return m_year;
}

std::string Journal::get_subject() {
    return m_subject;
}

void Journal::use() {
    std::cout << "looking at beautiful pictures  " ;
}

bool Journal::is_borrowed() {
    return get_is_borrowed();
} 

void Journal::my_swap(Journal& th)noexcept {
    std::swap(m_volume,th.m_volume);
    std::swap(m_issue,th.m_issue);
    std::swap(m_year,th.m_year);
    std::swap(m_subject,th.m_subject);
    std::swap(m_title,th.m_title);
    bool tmp{th.get_is_borrowed()};
    set_is_borrowed(tmp);
}