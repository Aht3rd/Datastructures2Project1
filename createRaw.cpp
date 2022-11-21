#include "createRaw.hpp"

string createRaw::generatePassword()
{
    string password = " ";
    for (int i = 0; i < 9; i++)
    {
        int r = ((rand() % 26) + 97);
        password += char(r);
    }
    return password;
}

void createRaw::generateRaw(string namesFile)
{
    string outFileName = "raw.txt";
    ifstream inFile;
    ofstream outFile(outFileName, ios::out | ios::app);
    inFile.open(namesFile);
    string line = " ";
    while (!inFile.eof())
    {
        getline(inFile, line);
        stringstream s(line);
        s >> user;
        pass = generatePassword();
        outFile << user << " " << pass << endl;
    }
    inFile.close();
    outFile.close();
}
