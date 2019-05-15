#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>

class Dictionary
{
    // Methods
    public:
        Dictionary() = default;
        virtual ~Dictionary() = default;
        virtual void insertAllWords(Dictionary&) const = 0;
        virtual void insert(const std::string&) = 0;

        Dictionary& operator+=(const Dictionary&);
};

#endif // DICTIONARY_H
