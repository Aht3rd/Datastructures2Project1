#include "createEncrypted.hpp"

string createEncrypted::encryptPass(string password)
{
    string encryptedPass;
    string key = "blackjack";
    for (int i = 0; i < 9; i++)
    {
        char c1 = password[i];
        char c2 = key[i];
        int t1 = int(c1);
        int t2 = int(c2);
        int t3 = ((((t1 - 97) + (t2 - 97)) % 26) + 97);
        encryptedPass += char(t3);
    }
    return encryptedPass;
}

void createEncrypted::generateEncrypted(string raw)
{
    string outFileName = "encrypted.txt";
    ifstream inFile;
    ofstream outFile(outFileName, ios::out | ios::app);
    inFile.open(raw);
    string line = " ";
    string temp = " ";
    while (!inFile.eof())
    {
        getline(inFile, line);
        if (line != "")
        {
            stringstream s(line);
            s >> user >> temp;
            pass = encryptPass(temp);
            outFile << user << " " << pass << endl;
        }
    }
    inFile.close();
    outFile.close();
}