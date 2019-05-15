#ifndef DICTIONARYTRIE_H
#define DICTIONARYTRIE_H

#include <Dictionary.h>
#include <Trie.h>



class DictionaryTrie : public Dictionary, public Trie
{
    public:
        DictionaryTrie() = default;
        virtual ~DictionaryTrie() = default;
        void insert(const std::string& word){Trie::insert(word);}
        DictionaryTrie& operator=(const DictionaryTrie&);
        DictionaryTrie& operator=(DictionaryTrie&&);
        void insertNextWord(Dictionary&, Node*, std::string) const;
        void insertAllWords(Dictionary&) const;
};

#endif // DICTIONARYTRIE_H
