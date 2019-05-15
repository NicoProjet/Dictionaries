#include "Dictionary.h"

Dictionary& Dictionary::operator+=(const Dictionary& other)
{
    other.insertAllWords(*this);
    return *this;
}

