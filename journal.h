#ifndef JOURNAL
#define JOURNAL
#include <iostream>
#include "material.h"

class Journal : public Material {
public:
    Journal();
    ~Journal();
    Journal(const Journal&);
    Journal (Journal&&);
    Journal& operator= (const Journal&);
    Journal& operator=(Journal&&);
    void set_title(int);
    void set_volume(int);
    void set_issue(const std::string&);
    void set_year(int);
    void set_subject(const std::string&);
    int get_title();
    int get_volume();
    std::string get_issue();
    int get_year();
    std::string get_subject();
    void use() override;
    bool is_borrowed() override; 
private:
    void my_swap(Journal&)noexcept;
    int  m_title = 0;
    int m_volume = 0;
    int m_year = 0;
    std::string m_issue = "";
    std::string m_subject = "";
};
#include "journal.hpp"

#endif //JOURNAL