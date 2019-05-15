#include "Trie.h"

/*
*   Class Trie::Node
*/
Trie::Node::~Node()
{
    Node* current = _firstSon;
    Node* next = nullptr;
    while (current != nullptr)
    {
        next = current->_next;
        delete current;
        current = next;
    }
}

Trie::Node* Trie::Node::getSon(char letter)
{
    Node* current = _firstSon;
    bool found = false;
    while (!found)
    {
        if (current == nullptr){found = true;}
        else if (letter < current->_data){found = true; current = nullptr;}
        else if (letter == current->_data){found = true;}
        if (!found){current = current->_next;}
    }
    return current;
}

Trie::Node* Trie::Node::insertChild(const char letter)
{
    Node* newNode = nullptr;
    bool inserted = false;
    Node* current = _firstSon;
    Node* previous = nullptr;

    while (!inserted)
    {
        // insert letter
        if (current == nullptr) // letter not found
        {
            newNode = new Node(letter, this);
            if (_firstSon == nullptr) {_firstSon = newNode;}
            else
            {
                previous->_next = newNode;
            }
            current = newNode;
            inserted = true;
        }
        else if (letter < current->_data) // current data is greater than letter
        {
            newNode = new Node(letter, this);
            if (previous != nullptr) {previous->_next = newNode;}
            else {_firstSon = newNode;}
            newNode->_next = current;
            current = newNode;
            inserted = true;
        }
        // letter already inserted
        else if (current->_data == letter){inserted = true;}
        // go to next son
        else {
            previous = current;
            current = current->_next;
        }
    }
    return current;
}

void Trie::Node::deleteChild(Node* node)
{
    if (node == _firstSon){_firstSon = node->_next;}
    else {
        Node* current = _firstSon->_next;
        Node* previous = _firstSon;
        bool deleted = false;

        while (!deleted && current != nullptr)
        {
            if (node == current){previous->setNext(current->_next); deleted = true;}
            else {previous = current; current = current->_next;}
        }
    }
    delete node;
}









/*
*   Class Trie
*/

Trie::Trie(){_root = new Node();}

void Trie::printTrie(std::ostream& os, std::string word, Node* node)
{
    // 1) print word
    if (node == nullptr){return;}
    if (node != _root){word += node->_data;}
    if (node->_isWord){os << word << " ";}

    // 2) spread to children
    Node* current = node->_firstSon;
    while (current!=nullptr)
    {
        printTrie(os, word, current);
        current = current->_next;
    }
}

void Trie::insertNextWord(std::string word, const Node* node)
{
    if (node == nullptr){return;}
    //if (node != _root){word += node->_data;}
    if (node->_data != '\0'){word += node->_data;}
    if (node->_isWord){insert(word);}

    Node* current = node->_firstSon;
    while (current!=nullptr)
    {
        insertNextWord(word, current);
        current = current->_next;
    }
}

void Trie::insertAllWords(const Trie& t)
{
    insertNextWord("", t._root);
}

std::ostream& operator<<(std::ostream& os, Trie& t)
{
    os << "[ ";
    t.printTrie(os, "", t._root);
    os << "]";
    return os;
}

Trie& Trie::operator=(const Trie& other)
{
    if(&other == this){return *this;}
    clear();
    insertAllWords(other);
    return *this;
}

Trie& Trie::operator=(Trie&& other)
{
    assert(this != &other);
    std::swap(this->_size, other._size);
    std::swap(this->_root, other._root);
    other.clear();
    return *this;
}






void Trie::insert(const std::string word)
{
    Node* current = _root;
    for (size_t index=0; index<word.size();index++)
    {
        current = current->insertChild(word[index]);
    }
    if (!current->_isWord){this->_size++; current->setIsWord(true);}
    else {std::cout << "Element already in Trie" << std::endl;}
}

Trie::Node* Trie::getLeaf(const std::string word)
{
    // returns leaf from a string, doesnt have to be a word in dictionary
    Node* current = _root;
    size_t index = 0;
    while (current != nullptr && index < word.size())
    {
        current = current->getSon(word[index++]);
    }
    return current;
}

Trie::Node* Trie::find(const std::string word)
{
    return getLeaf(word);
}

bool Trie::isIn(const std::string word)
{
    Node* node = getLeaf(word);
    return node != nullptr && node->_isWord;
}

void Trie::clearFromLeaf(Node* node)
{
    Node* father = nullptr;
    // if (no son) and (not a word) and (not root)
    if (node->_firstSon == nullptr  &&  !node->_isWord  &&  node != _root)
    {
        father = node->_father;
        father->deleteChild(node);
        clearFromLeaf(father);
    }
}

void Trie::erase(const std::string word)
{
    Node* node = getLeaf(word);
    if (node == nullptr || !node->_isWord){std::cout << "Word not in Trie" << std::endl;}
    else{node->setIsWord(false); clearFromLeaf(node); _size--;}
}

void Trie::clear()
{
    delete _root;
    _root = new Node();
    _size = 0;
}





