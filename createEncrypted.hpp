#ifndef CREATEENCRYPTED_HPP
#define CREATEENCRYPTED_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class createEncrypted
{
private:
    string user;
    string pass;

public:
    void generateEncrypted(string raw);
    string encryptPass(string password);
};

#endif