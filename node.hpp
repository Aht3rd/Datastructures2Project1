#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    string user = " ";
    string pass = " ";
    Node *next = nullptr;

public:
    Node();
    Node(string user, string pass);
    string getUser();
    string getPass();
    void setNext(Node *nextNode);
    Node *getNext();
};

#endif