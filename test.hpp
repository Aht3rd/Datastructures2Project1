#ifndef TEST_HPP
#define TEST_HPP
#include "createEncrypted.hpp"
#include "createRaw.hpp"
#include "hashtable.hpp"
#include <iomanip>

class Test
{
private:
    string user;
    string pass;

public:
    Test();
    void legalTest();
    void illegalTest();
};

#endif