#include "DictionaryTrie.h"

DictionaryTrie& DictionaryTrie::operator=(const DictionaryTrie& other)
{
    if(&other == this){return *this;}
    clear();
    Trie::insertAllWords(other);
    return *this;
}

DictionaryTrie& DictionaryTrie::operator=(DictionaryTrie&& other)
{
    assert(this != &other);
    std::swap(this->_size, other._size);
    std::swap(this->_root, other._root);
    other.clear();
    return *this;
}

void DictionaryTrie::insertNextWord(Dictionary& other, Node* node, std::string word) const
{
    if (node == nullptr){return;}
    if (node != _root){word += node->_data;}
    if (node->_isWord){other.insert(word);}

    Node* current = node->_firstSon;
    while (current!=nullptr)
    {
        insertNextWord(other, current, word);
        current = current->_next;
    }
}

void DictionaryTrie::insertAllWords(Dictionary& other) const
{
    insertNextWord(other, _root, "");
}
