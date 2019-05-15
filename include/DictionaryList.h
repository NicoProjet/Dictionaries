#ifndef DICTIONARYLIST_H
#define DICTIONARYLIST_H

#include <Dictionary.h>
#include <List.h>



class DictionaryList : public Dictionary, public List<std::string>
{
    public:
        DictionaryList() = default;
        virtual ~DictionaryList() = default;
        void insert (const std::string&);
        Place insert(Place, const std::string&);
        Place insert (Place, const_Place, const_Place);
        Place erase  (Place);
        Place find (const std::string&);
        bool isIn(const std::string&);
        void erase(const std::string&);
        DictionaryList& operator=(const DictionaryList&);
        DictionaryList& operator=(DictionaryList&&);
        void insertAllWords(Dictionary&) const;

    protected:

    private:
};

#endif // DICTIONARYLIST_H
