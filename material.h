#ifndef MATERIAL
#define MATERIAL
#include <iostream>
#include<utility>

class Material {
public:
    virtual void use() = 0;
    virtual bool is_borrowed() = 0;
    void set_is_borrowed(const bool);
    bool get_is_borrowed() const;
private:
    bool m_is_borrowed = false;
};

#include "material.hpp"

#endif //MATERIAL