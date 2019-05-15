#include "DictionaryVector.h"

std::ostream& operator<<(std::ostream& os, const DictionaryVector& v)
{
    os << "[ ";
    for (size_t index = 0; index<v._dict.size(); index++)
    {
        os << v[index] << " ";
    }
    os << "]";
    return os;
}

DictionaryVector& DictionaryVector::operator=(const DictionaryVector& other)
{
    if(&other == this){return *this;}
    clear();
    _dict = other._dict;
    return *this;
}

DictionaryVector& DictionaryVector::operator=(DictionaryVector&& other)
{
    assert(this != &other);
    _dict = other._dict;
    other.clear();
    return *this;
}

void DictionaryVector::insert(const std::string& word)
{
    // went with indexes instead of iterator ... easier to read
    size_t index = 0;
    bool inserted = false;
    while (!inserted && index<size())
    {
        if (_dict[index] == word){inserted = true;}
        else if (_dict[index] > word){_dict.insert(_dict.begin()+index, word); inserted = true;}
        index++;
    }
    if (!inserted)
    {
        _dict.push_back(word);
    }
}

size_t DictionaryVector::find(const std::string& word)
{
    // /!\ return index > size() if not found
    // can use iterators to resolve that
    // or return -1
    size_t index = 0;
    bool found = false;
    while (!found && index < size())
    {
        if (_dict[index] == word){found = true;}
        else {index++;}
    }
    return index;
}

void DictionaryVector::erase(const std::string& word)
{
    size_t index = find(word);
    if (index < size()){_dict.erase(_dict.begin()+index);}
}

bool DictionaryVector::isIn(const std::string& word)
{
    return find(word) < size();
}

void DictionaryVector::insertAllWords(Dictionary& other) const
{
    for (size_t index = 0; index<_dict.size(); index++)
    {
        other.insert(_dict[index]);
    }
}








