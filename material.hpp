#include "material.h"

void Material::set_is_borrowed(const bool is_borrowed) {
    m_is_borrowed = is_borrowed;
}

bool Material::get_is_borrowed() const {
    return m_is_borrowed;
}
