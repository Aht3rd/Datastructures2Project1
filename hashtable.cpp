#include "hashtable.hpp"

int HashTable::hash(string user)
{
    int value = 0;
    for (long unsigned int i = 0; i < user.length(); i++)
    {
        value += int(user[i]);
    }
    value = ((value * 11) % (tableSize + 1));
    return value;
}

void HashTable::insert(string user, string pass, int index)
{
    tmp = new Node(user, pass);
    tmp->setNext(table[index]);
    this->table[index] = tmp;
}

HashTable::HashTable(string fileName)
{
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = nullptr;
    }
    ifstream inFile;
    inFile.open(fileName);
    string user;
    string pass;
    string line;
    while (!inFile.eof())
    {
        getline(inFile, line);
        if (line != "")
        {
            stringstream s(line);
            s >> user >> pass;
            s.clear();
            int index = hash(user);
            insert(user, pass, index);            
        }
    }
    inFile.close();
}

HashTable::~HashTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        while(table[i] != nullptr)
        {
            delete table[i];
            table[i] = table[i]->getNext();
        }
    }
}

Node *HashTable::lookup(string id)
{
    int index = hash(id);
    Node *current = table[index];
    while (current != nullptr && current->getUser() != id)
    {
        current = current->getNext();
    }
    return current;
}

void HashTable::showAll()
{
    for (int i = 0; i < tableSize; i++)
    {
        Node *current = table[i];
        while (current != nullptr)
        {
            cout << current->getUser() << " " << current->getPass() << endl;
            current = current->getNext();
        }
    }
}