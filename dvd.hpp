#include <iostream>
#include "dvd.h"
#include "material.h"

Dvd::Dvd() = default;

Dvd::~Dvd() = default;

void Dvd::my_swap(Dvd& th) noexcept {
    std::swap(m_director,th.m_director);
    std::swap(m_duration,th.m_duration);
    std::swap(m_year,th.m_year);
    std::swap(m_title,th.m_title);
    set_is_borrowed(th.get_is_borrowed());
}

Dvd::Dvd(const Dvd& th) {
    m_director = th.m_director;
    m_duration = th.m_duration;
    m_title = th.m_title; 
    m_year = th.m_year;
    set_is_borrowed(get_is_borrowed());
}

Dvd::Dvd( Dvd&& th) {
   my_swap(th);
}

Dvd& Dvd::operator= (const Dvd& th) {
    if (this != &th)
    {
        Dvd tmp{th};
        my_swap(tmp);
    }
    return *this;
}

Dvd& Dvd::operator= (Dvd&& th) {
    if (this != &th)
    {
        my_swap(th);
    }
    return *this;
}

void Dvd::set_year(int year) {
    m_year = year;
}

void Dvd::set_duration(int dur) {
    m_duration = dur;
}

void Dvd::set_title(std::string title) {
    m_title = title;
}

void Dvd::set_director(std::string dir) {
    m_director = dir;
}

void Dvd::use() {
    std::cout << "You are watching, relax and enjoy";
}

bool Dvd::is_borrowed() {
    return get_is_borrowed();
}
