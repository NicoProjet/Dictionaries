#include "DictionaryList.h"

DictionaryList::Place DictionaryList::insert (Place p, const std::string& word){return List::insert(p, word);}
DictionaryList::Place DictionaryList::insert (Place p, const_Place p1, const_Place p2){return List::insert(p, p1, p2);}
DictionaryList::Place DictionaryList::erase (Place p){return List::erase(p);}

void DictionaryList::insert (const std::string& word) {
    unsigned int index = 0;
    bool inserted = false;
    Place p = begin();
    _Item* previous = nullptr;
    while (index < this->size() && !inserted){
        if ((*p.getCurrent())->info > word){
            if(previous){
                _Item* newItem = new _Item(word, *p.getCurrent());
                previous->next = newItem;
                ++ this->_size;
            }
            else insert(begin(), word);
            inserted = true;
        }
        else if ((*p.getCurrent())->info == word) {
            inserted = true;
            std::cout << "Element already in dictionary" << std::endl;
        }
        ++index;
        previous = *p.getCurrent();
        p = Place(this, &(*p.getCurrent())->next);
    }
    if (!inserted){insert(end(),word);}
}

DictionaryList::Place DictionaryList::find(const std::string& word)
{
    unsigned int index = 0;
    bool found = false;
    Place p = begin();
    while (index < this->size() && !found && (*p.getCurrent())->info<=word){
        if ((*p.getCurrent())->info == word) {
            found = true;
        }
        else {++index; p = Place(this, &(*p.getCurrent())->next);}
    }
    return p;
}

bool DictionaryList::isIn(const std::string& word)
{
    Place p = find(word);
    return (*p.getCurrent())->info == word;
}

void DictionaryList::erase(const std::string& word)
{
    Place p = find(word);
    if ((*p.getCurrent())->info == word) erase(p);
}

DictionaryList& DictionaryList::operator= (const DictionaryList& L) {
    if (this != &L) {clear(); insert(end(), L.begin(), L.end());}
    return *this;
}
DictionaryList& DictionaryList::operator= (DictionaryList&& L) {
    if (this != &L) {
        clear();
        _first = L._first; L._first = nullptr;
        _last  = L._size ? L._last : &_first; L._last = &L._first;
        _size  = L._size; L._size = 0;
    }
    return *this;
}

void DictionaryList::insertAllWords(Dictionary& other) const
{
    unsigned int index = 0;
    const_Place p = begin();
    while (index++ < _size)
    {
        other.insert((*p.getCurrent())->info);
        p++;
    }
}










