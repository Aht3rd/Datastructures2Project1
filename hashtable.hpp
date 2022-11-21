#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "node.hpp"
#include <fstream>
#include <sstream>

class HashTable
{
private:
    const static int tableSize = 17760;
    Node *table[tableSize];
    Node *tmp;

public:
    int hash(string user);
    void insert(string user, string pass, int index);
    HashTable(string fileName);
    ~HashTable();
    Node *lookup(string id);
    void showAll();
};

#endif