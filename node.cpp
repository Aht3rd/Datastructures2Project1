#include "node.hpp"

Node::Node()
{
    this->user = " ";
    this->pass = " ";
    this->next = nullptr;
}

Node::Node(string user, string pass)
{
    this->user = user;
    this->pass = pass;
    this->next = nullptr;
}

string Node::getUser()
{
    return this->user;
}

string Node::getPass()
{
    return this->pass;
}

void Node::setNext(Node *nextNode)
{
    this->next = nextNode;
}

Node *Node::getNext()
{
    return this->next;
}