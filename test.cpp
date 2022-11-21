#include "test.hpp"

void Test::legalTest()
{
    createEncrypted object1;
    HashTable object2("raw.txt");
    HashTable object3("encrypted.txt");
    string look = "SMITH";
    cout << "Legal: " << endl
         << setw(14) << left << "Userid"
         << "Password    "
         << "  Result" << endl;
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
        case 0:
            look = "SMITH";
            break;

        case 1:
            look = "JOHNSON";
            break;

        case 2:
            look = "WILLIAMS";
            break;

        case 3:
            look = "JONES";
            break;

        case 4:
            look = "BROWN";
            break;
        }
        cout << setw(10) << left << object2.lookup(look)->getUser() << "    " << object2.lookup(look)->getPass();
        string test = object2.lookup(look)->getPass();
        if (object1.encryptPass(test) == object3.lookup(look)->getPass())
        {
            cout << "     match" << endl;
        }
        else
        {
            cout << "     no match" << endl;
        }
    }
}

void Test::illegalTest()
{
    createEncrypted object1;
    HashTable object2("raw.txt");
    HashTable object3("encrypted.txt");
    string look = "SMITH";
    cout << "Legal: " << endl
         << setw(14) << left << "Userid"
         << "Password    "
         << "  Result" << endl;
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
        case 0:
            look = "SMITH";
            break;

        case 1:
            look = "JOHNSON";
            break;

        case 2:
            look = "WILLIAMS";
            break;

        case 3:
            look = "JONES";
            break;

        case 4:
            look = "BROWN";
            break;
        }
        string test = object2.lookup(look)->getPass();
        if (test[0] != 'a')
        {
            test[0] = 'a';
        }
        else
        {
            test[0] = 'b';
        }
        cout << setw(10) << left << object2.lookup(look)->getUser() << "    " << test;
        if (object1.encryptPass(test) == object3.lookup(look)->getPass())
        {
            cout << "     match" << endl;
        }
        else
        {
            cout << "     no match" << endl;
        }
    }
}

Test::Test()
{
    createRaw object1;
    object1.generateRaw("lastNames.txt");
    createEncrypted object2;
    object2.generateEncrypted("raw.txt");
}