#ifndef CREATERAW_HPP
#define CREATERAW_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;

class createRaw
{
private:
    string user;
    string pass;
    string generatePassword();

public:
    void generateRaw(string namesFile);
};

#endif