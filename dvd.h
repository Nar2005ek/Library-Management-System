#ifndef DVD
#define DVD
#include <iostream>
#include "material.h"

class Dvd : public Material {
public:
    Dvd();
    ~Dvd();
    Dvd(const Dvd&);
    Dvd( Dvd&&);
    Dvd& operator= (const Dvd&);
    Dvd& operator= (Dvd&&);
    void set_year(int);
    void set_duration(int);
    void set_title(std::string);
    void set_director(std::string);
    void use() override;
    bool is_borrowed() override;
private:
    void my_swap(Dvd&) noexcept;
    int m_year = 0;
    int m_duration = 0;
    std::string m_title = "";
    std::string m_director = "";
};

#include "dvd.hpp"

#endif//DVD