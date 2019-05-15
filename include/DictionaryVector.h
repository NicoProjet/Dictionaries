#ifndef DICTIONARYVECTOR_H
#define DICTIONARYVECTOR_H

#include <Dictionary.h>
#include <vector>
#include <assert.h>



class DictionaryVector : public Dictionary
{
    private:
        std::vector<std::string> _dict;

    public:
        DictionaryVector() = default;
        virtual ~DictionaryVector() = default;

        friend std::ostream& operator<<(std::ostream&, const DictionaryVector&);
        std::string& operator[](size_t index){return _dict[index];}
        const std::string& operator[](size_t index) const {return _dict[index];}
        DictionaryVector& operator=(const DictionaryVector&);
        DictionaryVector& operator=(DictionaryVector&&);

        size_t size(){return _dict.size();}
        void insert(const std::string& word);
        size_t find(const std::string& word);
        void erase(const std::string& word);
        bool isIn(const std::string& word);
        void clear(){_dict.clear();}
        void insertAllWords(Dictionary&) const;

};

#endif // DICTIONARYVECTOR_H
