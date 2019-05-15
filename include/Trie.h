#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <assert.h>

class Trie
{
    // Fields
    protected:
        class Node;
        Node* _root;
        size_t _size = 0;

    // Methods
    public:
        // Constructors
        Trie();

        // Getters
        Node* root() {return _root;}
        size_t size(){return _size;}

        // Operators (and used functions)
        void printTrie(std::ostream&, std::string, Node*);
        void insertNextWord(std::string, const Node*);
        void insertAllWords(const Trie&);

        friend std::ostream& operator<<(std::ostream&, Trie&);
        Trie& operator=(const Trie&);
        Trie& operator=(Trie&&);

        // Modifications
        void insert(const std::string);
        Node* getLeaf(const std::string);
        Node* find(const std::string);
        bool isIn(const std::string);
        void clearFromLeaf(Node*);
        void erase(const std::string);
        void clear();
};

class Trie::Node
{
    public:
        // Fields
        char _data;
        bool _isWord = false;
        Node* _father = nullptr;
        Node* _firstSon = nullptr;
        Node* _next = nullptr; // next brother

        // Constructors
        Node(): _data('\0') {}
        Node(char data, Node* father): _data(data), _father(father) {}
        ~Node();

        // getters & setters
        bool getIsWord(){return _isWord;}
        void setIsWord(bool b){_isWord = b;}
        Node* getSon(char);
        void setNext(Node* node){_next = node;}

        // Methods
        Node* insertChild(const char);
        void deleteChild(Node*);
};


#endif // TRIE_H
